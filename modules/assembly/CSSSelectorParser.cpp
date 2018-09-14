#include "CSSSelectorParser.h"
#include "../html/element/HTMLElement.h"

#include <string>

namespace Newtoo
{

#define WHITESPACE_CHAR ' '
#define WHITESPACE_STR " "
#define SPLIT_LIST_STR ","
#define PSEUDO_ELEMENT_STR "::"
#define ID_CHAR '#'
#define CLASS_CHAR '.'
#define PSEUDO_CLASS_CHAR ':'
#define COMPARE_OPEN_CHAR '['
#define COMPARE_CLOSE_CHAR ']'
#define COMPARE_EQUALS_CHAR '='
#define COMPARE_ENDS_WITH_MODE_CHAR '$'
#define COMPARE_STARTS_WITH_MODE_CHAR '^'
#define COMPARE_STARTS_WITH_PREFIX_MODE_CHAR '|'
#define COMPARE_CONTAINS_MODE_CHAR '*'
#define COMPARE_CONTAINS_ITEM_MODE_CHAR '~'
#define UNIVERSAL_CHAR '*'
#define QUOTE_CHAR '\"'
#define QUOTE_ALTERNATIVE_CHAR '\''
#define CHILD_COMBINATOR_CHAR '>'
#define NEXT_SIBLING_COMBINATOR_CHAR '+'
#define SUBSEQUENT_SIBLING_COMBINATOR_CHAR '~'
#define FUNCTION_ARG_BEGIN_CHAR '('
#define FUNCTION_ARG_END_CHAR ')'
#define PREFIX_END_STR "-"

    std::vector<DOMString> selectorList(DOMString selectors)
    {
        std::vector<DOMString> ret;

        char* pseudoElementStart = (char*)selectors.find(PSEUDO_ELEMENT_STR);
        if(pseudoElementStart != 0)
        {
            unsigned long pseudoElementIndex = pseudoElementStart - selectors.raw();
            selectors = selectors.substring(0, pseudoElementIndex);
        }

        char* split = (char*)selectors.find(SPLIT_LIST_STR);

        if(split == 0)
        {
            ret.push_back(selectors);
            return ret;
        }

        // Разрубить текст на список селекторы

        ret.push_back(selectors);
        DOMString* target = &ret.back();
        split = (char*)target->find(SPLIT_LIST_STR);
        do
        {
            unsigned long index = split - target->raw();
            DOMString secondPiece = target->substring(index + 1, target->size() - index - 1);
            *target = target->substring(0, index);
            ret.push_back(secondPiece);
            target = &ret.back();
            split = (char*)target->find(SPLIT_LIST_STR);
        }
        while(split != 0);

        return ret;
    }

    enum CompareMode
    {
        Equals,
        Contains,
        ContainsItem,
        StartsWith,
        StartsWithPrefix,
        EndsWith
    };

    enum SwitchCombinator
    {
        NoSwitch,
        Descendant,
        Child,
        NextSibling,
        SubsequentSibling
    };

    bool CSSSelectorParser::elementMatches(Element* element, DOMString list)
    {
        std::vector<DOMString> selectors = selectorList(list);

        for(unsigned s = 0; s < selectors.size(); s++)
        {
            if(elementMatchesItem(element, selectors[s]))
                return true;
        }
        return false;
    }

    bool CSSSelectorParser::elementMatchesItem(Element* element, DOMString text)
    {
        std::vector<Element*> elementsToCompare;
        elementsToCompare.push_back(element);

        CompareMode compareMode = Equals;
        SwitchCombinator switchCombinator = NoSwitch;
        DOMString content;
        DOMString value2;
        bool inString = false;
        char quote = 0;

        for(signed long i = text.length() - 1; i != -1; i--)
        {
            char c = text[i];

            if(!inString)
            {

                if(c == ID_CHAR)
                {
                    bool discard = true;
                    for(unsigned i = 0 ; i < elementsToCompare.size(); i++)
                    {
                        if(elementsToCompare[i]->id() == content)
                        {
                            discard = false;
                            break;
                        }
                    }
                    if(discard)
                        return false;
                    content.clear();
                }
                else if(c == CLASS_CHAR)
                {
                    bool discard = true;
                    for(unsigned i = 0 ; i < elementsToCompare.size(); i++)
                    {
                        if(elementsToCompare[i]->classList().contains(content))
                        {
                            discard = false;
                            break;
                        }
                    }
                    if(discard)
                        return false;
                    content.clear();
                }
                else if(c == WHITESPACE_CHAR)
                {
                    if(!content.empty())
                    {
                        bool discard = true;
                        for(unsigned i = 0 ; i < elementsToCompare.size(); i++)
                        {
                            if(elementsToCompare[i]->tagName() == content) {
                                discard = false;
                                break;
                            }
                        }
                        if(discard)
                            return false;
                        content.clear();
                    }
                    if(switchCombinator == NoSwitch)
                        switchCombinator = Descendant;
                }
                else if(c == UNIVERSAL_CHAR)
                {
                    content.clear();
                }
                else if(c == PSEUDO_CLASS_CHAR)
                {
                    bool discard = true;

                    if(content == "active")
                    {
                    }
                    else if(content == "press")
                    {
                    }
                    else if(content == "hover")
                    {
                    }
                    else if(content == "focus")
                    {
                    }
                    else if(content == "visited")
                    {
                    }
                    else if(content == "disabled")
                    {
                        for(unsigned i = 0 ; i < elementsToCompare.size(); i++)
                        {
                            RaisesException<Attr*> d
                                    = elementsToCompare[i]->attributes().getNamedItem("disabled");
                            if(!d.hasException())
                            {
                                if(d.returnType()->value() == "true")
                                {
                                    discard = false;
                                    break;
                                }
                            }
                        }
                    }
                    else if(content == "enabled")
                    {
                        for(unsigned i = 0 ; i < elementsToCompare.size(); i++)
                        {
                            RaisesException<Attr*> d
                                    = elementsToCompare[i]->attributes().getNamedItem("disabled");
                            if(!d.hasException())
                            {
                                if(d.returnType()->value() == "false")
                                {
                                    discard = false;
                                    break;
                                }
                            }
                        }
                    }
                    else if(content == "even-child")
                    {
                        for(unsigned i = 0 ; i < elementsToCompare.size(); i++)
                        {
                            if(elementsToCompare[i]->parentNode() != 0)
                            {
                                if(elementsToCompare[i]->index() % 2 != 0)
                                {
                                    discard = false;
                                    break;
                                }
                            }
                        }
                    }
                    else if(content == "odd-child")
                    {
                        for(unsigned i = 0 ; i < elementsToCompare.size(); i++)
                        {
                            if(elementsToCompare[i]->parentNode() != 0)
                            {
                                if(elementsToCompare[i]->index() % 2 == 0)
                                {
                                    discard = false;
                                    break;
                                }
                            }
                        }
                    }
                    else if(content == "first-child")
                    {
                        for(unsigned i = 0 ; i < elementsToCompare.size(); i++)
                        {
                            if(elementsToCompare[i]->parentNode() != 0)
                            {
                                if(elementsToCompare[i]->parentElement()->firstElementChild()
                                        == elementsToCompare[i])
                                {
                                    discard = false;
                                    break;
                                }
                            }
                        }
                    }
                    else if(content == "last-child")
                    {
                        for(unsigned i = 0 ; i < elementsToCompare.size(); i++)
                        {
                            if(elementsToCompare[i]->parentNode() != 0)
                            {
                                if(elementsToCompare[i]->parentElement()->lastElementChild()
                                        == elementsToCompare[i])
                                {
                                    discard = false;
                                    break;
                                }
                            }
                        }
                    }
                    else if(content == "empty")
                    {
                        for(unsigned i = 0 ; i < elementsToCompare.size(); i++)
                        {
                            if(elementsToCompare[i]->childNodes().empty())
                            {
                                discard = false;
                                break;
                            }
                        }
                    }

                    if(discard)
                        return false;
                    content.clear();
                }
                else if(c == CHILD_COMBINATOR_CHAR)
                {
                    switchCombinator = Child;
                }
                else if(c == NEXT_SIBLING_COMBINATOR_CHAR)
                {
                    switchCombinator = NextSibling;
                }
                else if(c == SUBSEQUENT_SIBLING_COMBINATOR_CHAR)
                {
                    switchCombinator = SubsequentSibling;
                }
                else if(c == COMPARE_EQUALS_CHAR)
                {
                    compareMode = Equals;
                    value2 = content;
                    content.clear();
                }
                else if(c == COMPARE_STARTS_WITH_MODE_CHAR)
                {
                    compareMode = StartsWith;
                }
                else if(c == COMPARE_STARTS_WITH_PREFIX_MODE_CHAR)
                {
                    compareMode = StartsWithPrefix;
                }
                else if(c == COMPARE_ENDS_WITH_MODE_CHAR)
                {
                    compareMode = EndsWith;
                }
                else if(c == COMPARE_CONTAINS_MODE_CHAR)
                {
                    compareMode = Contains;
                }
                else if(c == COMPARE_CONTAINS_ITEM_MODE_CHAR)
                {
                    compareMode = ContainsItem;
                }
                else if(c == COMPARE_CLOSE_CHAR)
                {
                    content.clear();
                }
                else if(c == COMPARE_OPEN_CHAR)
                {

                    switch(compareMode)
                    {
                        case Equals:
                        {
                            bool discard = true;
                            for(unsigned i = 0 ; i < elementsToCompare.size(); i++)
                            {
                                if(elementsToCompare[i]->getAttribute(content) == value2)
                                {
                                    discard = false;
                                    break;
                                }
                            }
                            if(discard)
                                return false;
                            content.clear();
                            break;
                        }
                        case StartsWith:
                        {
                            bool discard = true;
                            for(unsigned i = 0 ; i < elementsToCompare.size(); i++)
                            {
                                if(elementsToCompare[i]->getAttribute(content).startsWith(value2))
                                {
                                    discard = false;
                                    break;
                                }
                            }
                            if(discard)
                                return false;
                            content.clear();
                            break;
                        }
                        case StartsWithPrefix:
                        {
                            bool discard = true;
                            for(unsigned i = 0 ; i < elementsToCompare.size(); i++)
                            {
                                if(elementsToCompare[i]->getAttribute(content)
                                        .startsWith(value2+PREFIX_END_STR))
                                {
                                    discard = false;
                                    break;
                                }
                            }
                            if(discard)
                                return false;
                            content.clear();
                            break;
                        }
                        case EndsWith:
                        {
                            bool discard = true;
                            for(unsigned i = 0 ; i < elementsToCompare.size(); i++)
                            {
                                if(elementsToCompare[i]->getAttribute(content).endsWith(value2))
                                {
                                    discard = false;
                                    break;
                                }
                            }
                            if(discard)
                                return false;
                            content.clear();
                            break;
                        }
                        case Contains:
                        {
                            bool discard = true;
                            for(unsigned i = 0 ; i < elementsToCompare.size(); i++)
                            {
                                if(elementsToCompare[i]->getAttribute(content).has(value2))
                                {
                                    discard = false;
                                    break;
                                }
                            }
                            if(discard)
                                return false;
                            content.clear();
                            break;
                        }
                        case ContainsItem:
                        {
                            bool discard = true;
                            for(unsigned i = 0 ; i < elementsToCompare.size(); i++)
                            {
                                DOMString noLastItem = WHITESPACE_STR;
                                noLastItem += value2 + WHITESPACE_STR;
                                if
                                (
                                    elementsToCompare[i]->getAttribute(content).startsWith(value2)
                                or  elementsToCompare[i]->getAttribute(content).endsWith(value2)
                                or  elementsToCompare[i]->getAttribute(content).has(noLastItem)
                                )
                                {
                                    discard = false;
                                    break;
                                }
                            }
                            if(discard)
                                return false;
                            content.clear();
                            break;
                        }
                    }
                    content.clear();
                }
                else if(c == QUOTE_CHAR or c == QUOTE_ALTERNATIVE_CHAR)
                {
                    quote = c;
                    inString = true;
                }
                else
                {
                    content.prependCharToThis(c);

                    switch(switchCombinator)
                    {
                        case NoSwitch:
                        {
                            break;
                        }
                        case Descendant:
                        {
                            switchCombinator = NoSwitch;

                            std::vector<Element*> newElementsToCompare;
                            for(unsigned f = 0; f < elementsToCompare.size(); f++)
                            {
                                Element* p = elementsToCompare[f]->parentElement();
                                while(p != 0)
                                {
                                    newElementsToCompare.push_back(p);
                                    p = p->parentElement();
                                }
                            }
                            elementsToCompare.clear();
                            for(unsigned f = 0; f < newElementsToCompare.size(); f++)
                                elementsToCompare.push_back(newElementsToCompare[f]);
                            break;
                        }
                        case Child:
                        {
                            switchCombinator = NoSwitch;

                            std::vector<Element*> newElementsToCompare;
                            for(unsigned f = 0; f < elementsToCompare.size(); f++)
                            {
                                if(elementsToCompare[f]->parentElement() != 0)
                                {
                                    newElementsToCompare.push_back(elementsToCompare[f]
                                                                   ->parentElement());
                                }
                            }
                            elementsToCompare.clear();
                            for(unsigned f = 0; f < newElementsToCompare.size(); f++)
                                elementsToCompare.push_back(newElementsToCompare[f]);
                            break;
                        }
                        case NextSibling:
                        {
                            switchCombinator = NoSwitch;

                            std::vector<Element*> newElementsToCompare;
                            for(unsigned f = 0; f < elementsToCompare.size(); f++)
                            {
                                Element* n = elementsToCompare[f]->previousElementSibling();
                                while(n != 0)
                                {
                                    newElementsToCompare.push_back(n);
                                    n = n->previousElementSibling();
                                }
                            }
                            elementsToCompare.clear();
                            for(unsigned f = 0; f < newElementsToCompare.size(); f++)
                                elementsToCompare.push_back(newElementsToCompare[f]);
                            break;
                        }
                        case SubsequentSibling:
                        {
                            switchCombinator = NoSwitch;

                            std::vector<Element*> newElementsToCompare;
                            for(unsigned f = 0; f < elementsToCompare.size(); f++)
                            {
                                if(elementsToCompare[f]->parentElement() != 0)
                                {
                                    HTMLCollection children =
                                            elementsToCompare[f]->parentElement()->children();

                                    for(unsigned a = 0; a < children.length(); a++)
                                    {
                                        // тут может быть что-то не так
                                        if(children.item(a) != element)
                                            newElementsToCompare.push_back(children.item(a));
                                    }
                                }
                            }
                            elementsToCompare.clear();
                            for(unsigned f = 0; f < newElementsToCompare.size(); f++)
                                elementsToCompare.push_back(newElementsToCompare[f]);
                            break;
                        }
                    }

                    if(i == 0)
                    {
                        bool discard = true;
                        for(unsigned i = 0 ; i < elementsToCompare.size(); i++)
                        {
                            if(elementsToCompare[i]->tagName() == content) {
                                discard = false;
                                break;
                            }
                        }
                        if(discard)
                            return false;
                    }
                }

            } // if(inString)
            else
            {
                if(c == quote)
                {
                    inString = false;
                } else
                {
                    content.prependCharToThis(c);
                }
            }

        }
        return true;
    }

#define TAG_WEIGHT 1
#define CLASS_WEIGHT 9 // вычитая TAG_WEIGHT
#define ID_WEIGHT 99 // вычитая TAG_WEIGHT

#define CLASS_WEIGHT_FULL 10
#define ID_WEIGHT_FULL 100

    unsigned long CSSSelectorParser::computePriority(DOMString text)
    {
        unsigned long ret = 0;
        bool whitespaceBefore = false;

        if(text[0] == CLASS_CHAR) {}
        else if(text[0] == ID_CHAR) {}
        else if(text[0] == WHITESPACE_CHAR) {}
        else
        {
            whitespaceBefore = true;
            ret = 1;
        }

        for(unsigned i = 0; i < text.size(); i++)
        {
            if(text[i] == WHITESPACE_CHAR)
            {
                if(!whitespaceBefore)
                {
                    whitespaceBefore = true;
                    ret += TAG_WEIGHT;
                }
                break;
            }
            else if(text[i] == ID_CHAR)
            {
                if(whitespaceBefore)
                {
                    whitespaceBefore = false;
                    ret += ID_WEIGHT;
                } else
                {
                    ret += ID_WEIGHT_FULL;
                }
                break;
            }
            else if(text[i] == CLASS_CHAR)
            {
                if(whitespaceBefore)
                {
                    whitespaceBefore = false;
                    ret += CLASS_WEIGHT;
                } else
                {
                    ret += CLASS_WEIGHT_FULL;
                }
                break;
            }
            else
            {
                whitespaceBefore = false;
            }
        }
        return ret;
    }
    DOMString CSSSelectorParser::computePriorityString(DOMString text)
    {
        DOMString ret;
        ret.fromLong(computePriority(text));
        return ret;
    }

}
