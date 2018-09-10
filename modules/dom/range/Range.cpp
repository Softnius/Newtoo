#include "Range.h"

#include "../node/Document.h"
#include "../node/Text.h"

namespace Newtoo
{

    Range::Range()
        :mStartContainer(0),
         mStartOffset(0),
         mEndContainer(0),
         mEndOffset(0),
         mCommonAncestorContainer(0)
    {}

    Range::Range(Range& reference)
        :mStartContainer(reference.mStartContainer),
         mStartOffset(reference.mStartOffset),
         mEndContainer(reference.mEndContainer),
         mEndOffset(reference.mEndOffset),
         mCommonAncestorContainer(reference.mCommonAncestorContainer)
    {}

    bool Range::collapsed()
    {
        return startContainer() == endContainer() and startOffset() == endOffset();
    }

    void Range::setStart(Node* node, unsigned long offset)
    {
        mStartContainer = node;
        mStartOffset = offset;

        if(mEndContainer != 0)
            setupCommonAncestorContainer();
    }
    void Range::setEnd(Node* node, unsigned long offset)
    {
        mEndContainer = node;
        mEndOffset = offset;

        if(mStartContainer != 0)
            setupCommonAncestorContainer();
    }

    void Range::setStartQuickly(Node* node, unsigned long offset)
    {
        mStartContainer = node;
        mStartOffset = offset;
    }
    void Range::setEndQuickly(Node* node, unsigned long offset)
    {
        mEndContainer = node;
        mEndOffset = offset;
    }

    RaisesExceptionVoid Range::setStartBefore(Node* node)
    {
        if(node->previousSibling() != 0)
        {
            setStart(node->previousSibling(), 0);

            return RaisesExceptionVoid();
        }
        else return RaisesExceptionVoid(DOMException(NotFoundError));
    }
    RaisesExceptionVoid Range::setStartAfter(Node* node)
    {
        if(node->nextSibling() != 0)
        {
            setStart(node->nextSibling(), 0);

            return RaisesExceptionVoid();
        }
        else
        {
            return RaisesExceptionVoid(DOMException(NotFoundError));
        }
    }
    RaisesExceptionVoid Range::setEndBefore(Node* node)
    {
        if(node->previousSibling() != 0)
        {
            setEnd(node->previousSibling(), 0);

            return RaisesExceptionVoid();
        }
        else return RaisesExceptionVoid(DOMException(NotFoundError));
    }
    RaisesExceptionVoid Range::setEndAfter(Node* node)
    {
        if(node->nextSibling() != 0)
        {
            setEnd(node->nextSibling(), 0);

            return RaisesExceptionVoid();
        }
        else
        {
            return RaisesExceptionVoid(DOMException(NotFoundError));
        }
    }
    void Range::collapse(bool toStart)
    {
        if(toStart)
        {
            setEnd(mStartContainer, mStartOffset);
        } else
        {
            setStart(mEndContainer, mEndOffset);
        }
    }
    void Range::selectNode(Node* node)
    {
        setStartQuickly(node, 0);
        if(node->nodeType() != Node::TEXT_NODE)
        {
            setEndQuickly(node, 0);
        }else
        {
            Text* text = (Text*)node;
            setEndQuickly(node, text->length());
        }
        setupCommonAncestorContainer();
    }
    void Range::selectNodeContents(Node* node)
    {
        if(node->hasChildNodes())
        {
            setStartQuickly(node->firstChild(), 0);
            if(node->lastChild()->nodeType() != Node::TEXT_NODE)
            {
                setEndQuickly(node->lastChild(), 0);
            }else
            {
                Text* text = (Text*)node->lastChild();
                setEndQuickly(node->lastChild(), text->length());
            }
            setupCommonAncestorContainer();
        }
    }

    Range* Range::cloneRange()
    {
        return new Range(*this);
    }

#define PRE_RANGE_STATE 0 // Перед областью (Начало не найдено)
#define IN_RANGE_STATE 1 // В области (Начало найдено)
#define BEYOND_RANGE_STATE 2 // За областью (Конец найден), цикл можно останавливать

    enum IntersectionCheckResult
    {
        NOT_FOUND = -2,
        PRE_RANGE = -1,
        IN_RANGE = 0,
        BEYOND_RANGE = 1
    };

    struct IntersectionCheck
    {
        IntersectionCheck() :state(PRE_RANGE_STATE), result(PRE_RANGE) {}

        signed short state;
        IntersectionCheckResult result;
    };

    bool CheckRangeIntersectionRecursive(NodeList& list, IntersectionCheck& isearch, Node* start,
                                         Node* end, Node* target, signed long offset = -1,
                                         unsigned long endOffset = 0, unsigned long startOffset = 0)
    {
        for(unsigned i = 0; i < list.length(); i++)
        {
            bool beyondOffset = false;

            if(offset != -1)
            {
                if(list.item(i) == end)
                {
                    if(offset >= (int)endOffset)
                    {
                        beyondOffset = true;
                        isearch.state++;
                    }
                } else if(list.item(i) == start)
                {
                    if(offset < (int)startOffset)
                    {
                        beyondOffset = true;
                        isearch.state--;
                    }
                }
            }

            if(list.item(i) == start)
                isearch.state++;

            else if(list.item(i) == target)
            {
                switch(isearch.state)
                {
                    case PRE_RANGE_STATE:
                    {
                        isearch.result = PRE_RANGE;
                        break;
                    };
                    case IN_RANGE_STATE:
                    {
                        isearch.result = IN_RANGE;
                        break;
                    };
                }
                return 0; // узел найден, результаты есть, завершить поиск
            }

            if(!beyondOffset)
            {
                if(list.item(i) == end)
                    isearch.state++;
            }else
            {
                if(list.item(i) == start)
                    isearch.state++;
            }

            if(isearch.state != BEYOND_RANGE_STATE)
                CheckRangeIntersectionRecursive(list.item(i)->childNodes(), isearch, start, end, target);

            else isearch.result = BEYOND_RANGE; // если найден конец, дальше искать не надо
        }

        return 0;
    }

    bool Range::intersectsNode(Node* node)
    {
        if(mCommonAncestorContainer != 0)
        {
            IntersectionCheck* isearch = new IntersectionCheck();

            CheckRangeIntersectionRecursive(mCommonAncestorContainer->childNodes(), *isearch,
                                            this->startContainer(), this->endContainer(), node);

            bool found = isearch->result == IN_RANGE;
            delete isearch;

            return found;
        }
        return NOT_FOUND;
    }

    void Range::setupCommonAncestorContainer()
    {
        unsigned long startContainerDepth = mStartContainer->depth();
        unsigned long endContainerDepth = mEndContainer->depth();

        if(startContainerDepth < endContainerDepth)
            mCommonAncestorContainer = mStartContainer->parentNode();

        else if(startContainerDepth > endContainerDepth)
            mCommonAncestorContainer = mEndContainer->parentNode();

        else if(startContainerDepth == endContainerDepth)
            mCommonAncestorContainer = mEndContainer->parentNode();
    }

    signed short Range::compareBoundaryPoints(CompareHow how, Range* sourceRange)
    {
        IntersectionCheck* isearch = new IntersectionCheck();

        if(sourceRange->mCommonAncestorContainer == 0)
            return 0;

        switch(how)
        {
            case START_TO_START:
            {
                CheckRangeIntersectionRecursive
                (
                            mCommonAncestorContainer->childNodes(), *isearch,
                            this->startContainer(), this->startContainer(),
                            sourceRange->startContainer()
                );
                break;
            }
            case START_TO_END:
            {
                CheckRangeIntersectionRecursive
                (
                            mCommonAncestorContainer->childNodes(), *isearch,
                            this->startContainer(), this->startContainer(),
                            sourceRange->endContainer()
                );
                break;
            }
            case END_TO_END:
            {
                CheckRangeIntersectionRecursive
                (
                            mCommonAncestorContainer->childNodes(), *isearch,
                            this->endContainer(), this->endContainer(),
                            sourceRange->endContainer()
                );
                break;
            }
            case END_TO_START:
            {
                CheckRangeIntersectionRecursive
                (
                            mCommonAncestorContainer->childNodes(), *isearch,
                            this->endContainer(), this->endContainer(),
                            sourceRange->startContainer()
                );
                break;
            }
        }

        IntersectionCheckResult result = isearch->result;
        delete isearch;

        return result;
    }

    bool Range::isPointInRange(Node* node, unsigned long offset)
    {
        IntersectionCheck* isearch = new IntersectionCheck();

        if(mCommonAncestorContainer == 0)
            return 0;

        CheckRangeIntersectionRecursive
        (
                    mCommonAncestorContainer->childNodes(), *isearch,
                    this->startContainer(), this->endContainer(),
                    node, offset, this->mEndOffset, this->mStartOffset
        );

        bool result = isearch->result == IN_RANGE;
        delete isearch;

        return result;
    }

    signed short Range::comparePoint(Node* node, unsigned long offset)
    {
        IntersectionCheck* isearch = new IntersectionCheck();

        if(mCommonAncestorContainer == 0)
            return 0;

        CheckRangeIntersectionRecursive
        (
                    mCommonAncestorContainer->childNodes(), *isearch,
                    this->startContainer(), this->endContainer(),
                    node, offset, this->mEndOffset, this->mStartOffset
        );

        signed short result = isearch->result;
        delete isearch;

        return result;
    }

    void Range::insertNode(Node* node)
    {
        if(mStartContainer == 0)
            return;

        if(mEndContainer != 0)
        {

            if(!collapsed())
                deleteContents();

            if(mStartContainer->nodeType() == Node::TEXT_NODE and node->nodeType() == Node::TEXT_NODE)
            {
                Text* textStart = (Text*)mStartContainer;
                Text* textNode = (Text*)node;
                textStart->insertData(mStartOffset, textNode->data());
                setStart(mStartContainer, mStartOffset + 1);
                collapse(true);
            }
            else if(mStartContainer->nodeType() == Node::TEXT_NODE)
            {
                Text* textStart = (Text*)mStartContainer;
                Text* textContinue = textStart->splitText(mStartOffset).returnType();
                textStart->after(textContinue);
                textStart->after(node);
                setStart(textContinue, 0);
                collapse(true);
            }
            else
            {
                mStartContainer->after(node);
                setStart(node, 0);
                collapse(true);
            }

        } else // когда нужно вставить в самое начало, а не после выделенного фрагмента
        {
            mStartContainer->before(node);
            setStart(node, 0);
            collapse(true);
        }
    }

    void Range::deleteContents()
    {
        if(mCommonAncestorContainer == 0)
            return;

        Node* newStart;
        unsigned long newOffset = 0;

        if(mStartContainer->nodeType() == Node::TEXT_NODE)
        {
            newStart = mStartContainer;
            newOffset = mStartOffset;
        } else
        {
            newStart = mStartContainer->previousSibling();
            if(newStart == 0)
                newStart = mCommonAncestorContainer->firstChild();
        }

        if(mStartContainer->depth() == mEndContainer->depth())
        {
            if(mStartContainer != mEndContainer)
            {
                for(unsigned i = mStartContainer->index(); i < mEndContainer->index() + 1; i++)
                {
                    Node* item = mCommonAncestorContainer->childNodes().item(i);

                    if(item == mStartContainer)
                    {
                        if(item->nodeType() == Node::TEXT_NODE)
                        {
                            Text* text = (Text*)item;
                            text->setData(text->substringData(0, mStartOffset).returnType());
                        }
                        else item->remove();
                    }
                    else if(item == mEndContainer)
                    {
                        if(item->nodeType() == Node::TEXT_NODE)
                        {
                            Text* text = (Text*)item;
                            text->setData(text->substringData(mEndOffset, text->length() - mEndOffset)
                                          .returnType());
                        }
                        else item->remove();
                    }
                    else item->remove();
                }
            } else
            {
                if(mStartContainer->nodeType() == Node::TEXT_NODE)
                {
                    Text* text = (Text*)mStartContainer;
                    text->deleteData(mStartOffset, mEndOffset - mStartOffset);
                }
                else mStartContainer->remove();
            }

            setStart(newStart, newOffset);
            collapse(true);
        }
    }

    void toStringRecursive(bool inRange, NodeList& list, DOMString* str, Range& range)
    {
        for(unsigned i = 0; i < list.length(); i++)
        {
            Node* item = list.item(i);

            if(item == range.startContainer() or item == range.endContainer())
            {
                if(inRange == true)
                    break;
            }

            if(item->nodeType() == Node::TEXT_NODE)
            {
                if(inRange)
                {
                    Text* textItem = (Text*)item;
                    *str = str->append_(textItem->data());
                }
            }
            else
            {
                toStringRecursive(inRange, item->childNodes(), str, range);
            }

            if(item == range.startContainer() or item == range.endContainer())
            {
                if(inRange == false)
                    inRange = true;
            }
        }
    }

    DOMString Range::toString()
    {
        if(mCommonAncestorContainer == 0)
            return DOMString("Setup range firstly!");

        DOMString ret = "";

        if(mStartContainer->nodeType() == Node::TEXT_NODE)
        {
            Text* startText = (Text*)mStartContainer;

            RaisesException<DOMString> startStr
                    = startText->substringData(mStartOffset, startText->length() - mStartOffset);

            if(startStr.hasException())
            {
                return startStr.exception().name();
            } else
            {
                ret = startStr.returnType();
            }
        }

        toStringRecursive(false, mCommonAncestorContainer->childNodes(), &ret, *this);

        if(mEndContainer->nodeType() == Node::TEXT_NODE)
        {
            Text* endText = (Text*)mEndContainer;

            RaisesException<DOMString> endStr
                    = endText->substringData(0, mEndOffset);

            if(endStr.hasException())
            {
                return endStr.exception().name();
            } else
            {
                ret += endStr.returnType();
            }

            if(mStartContainer == mEndContainer)
            {
                RaisesException<DOMString> str
                        = endText->substringData(mStartOffset, mEndOffset - mStartOffset);

                if(str.hasException())
                {
                    ret = str.exception().name();
                } else
                {
                    ret = str.returnType();
                }
            }
        }
        return ret;
    }

    DocumentFragment* Range::cloneContents()
    {
        DocumentFragment* ret = new DocumentFragment();
        ret->appendChild(new Text(toString()));

        return ret;
    }
    DocumentFragment* Range::extractContents()
    {
        DocumentFragment* ret = cloneContents();
        deleteContents();

        return ret;
    }
    void Range::surroundContents(Node* newParent)
    {
        DocumentFragment* frag = extractContents();
        insertNode(newParent);

        for(unsigned i = 0; i < frag->childNodes().length(); i++)
            newParent->appendChild(frag->childNodes().item(i));

        delete frag;

        selectNode(newParent);
    }

}
