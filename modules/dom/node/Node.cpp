#include "Node.h"

#include "Document.h"
#include "Element.h"
#include "Text.h"

namespace Newtoo
{

    Node::Node() {}

    Node::Node(NodeType type)
        :mParent(0),
         mNodeType(type)
    {}

    Node* Node::cloneNode(bool deep)
    {
        return new Node(*this, deep);
    }

    DOMString Node::nodeName()
    {
        return DOMString("undefined");
    }

    bool Node::hasTextValue()
    {
        return false;
    }
    DOMString Node::nodeValue()
    {
        return DOMString("");
    }
    DOMString Node::textContent()
    {
        return DOMString("");
    }

    void Node::setNodeValue(DOMString aPlainText)
    {}
    void Node::setTextContent(DOMString aPlainText)
    {}

    Document* Node::ownerDocument()
    {
        Node* current = parentNode();
        while(current != 0)
        {
            if(current->nodeType() == DOCUMENT_NODE)
                return (Document*)current;

            current = current->parentNode();
        }

        return 0;
    }

    Element* Node::parentElement()
    {
        if(mParent == 0)
            return 0;

        if(mParent->nodeType() != ELEMENT_NODE)
            return 0;

        return (Element*)mParent;
    }

    Node* Node::firstChild()
    {
        return childNodes().item(0);
    }
    Node* Node::lastChild()
    {
        return childNodes().item(childNodes().length() - 1);
    }
    Node* Node::previousSibling()
    {
        if(parentNode() == 0)
            return 0;

        unsigned long ind = index();

        if(ind == 0)
            return 0;

        else return parentNode()->childNodes().item(ind - 1);
    }
    Node* Node::nextSibling()
    {
        if(parentNode() == 0)
            return 0;

        return parentNode()->childNodes().item(index() + 1);
    }

    unsigned short Node::compareDocumentPosition(Node* other)
    {
        if(isEqualNode(other)) return DOCUMENT_POSITION_EQUALS;

        if(this->ownerDocument() != other->ownerDocument())
            return DOCUMENT_POSITION_DISCONNECTED;

        if(other->containsDeep(this))
            return DOCUMENT_POSITION_CONTAINS;
        else if(this->containsDeep(other))
            return DOCUMENT_POSITION_CONTAINED_BY;

        NodeList& parentChilds = parentNode()->childNodes();

        for(unsigned i = 0; i < parentChilds.length(); i++)
        {
            if(parentChilds.item(i) == this)
                return DOCUMENT_POSITION_FOLLOWING;
            else if(parentChilds.item(i) == other)
                return DOCUMENT_POSITION_PRECEDING;
        }

        return 0; // DOCUMENT_POSITION_UNDEFINED
    }

    bool Node::isEqualNode(Node* other)
    {
        return this == other;
    }

    bool Node::containsDeep(Node* other)
    {
        for(unsigned i = 0; i < childNodes().length(); i++)
        {
            if(childNodes().item(i) == other)
                return true;

            else if(childNodes().item(i)->hasChildNodes())
            {
                if(childNodes().item(i)->containsDeep(other))
                    return true;
            }
        }
        return false;
    }

    bool Node::contains(Node* other)
    {
        for(unsigned i = 0; i < childNodes().length(); i++)
        {
            if(childNodes().item(i) == other)
                return true;
        }
        return false;
    }

    bool Node::hasChildNodes()
    {
        return !mChildNodes.empty();
    }

    HTMLCollection Node::children()
    {
        return HTMLCollection(&mChildNodes);
    }

    Element* Node::firstElementChild()
    {
        for(unsigned i = 0; i < childNodes().length(); i++)
        {
            if(childNodes().item(i)->nodeType() == ELEMENT_NODE)
            {
                return (Element*)childNodes().item(i);
            }
        }
        return 0;
    }
    Element* Node::lastElementChild()
    {
        HTMLCollection collection = children();
        return collection.item(collection.length() - 1);
    }

    unsigned long Node::childElementCount()
    {
        unsigned long ret = 0;
        for(unsigned i = 0; i < childNodes().length(); i++)
        {
            if(childNodes().item(i)->nodeType() == ELEMENT_NODE)
                ret++;
        }

        return ret;
    }

    void findElementByTagName(Element* p, DOMString aTagName, NodeList& list)
    {
        for(unsigned i = 0; i < list.length(); i++)
        {
            if(list.item(i)->nodeType() == Node::ELEMENT_NODE)
            {
                Element* elm = (Element*)list.item(i);

                if(elm->tagName() == aTagName)
                {
                    p = elm;
                }
                else findElementByTagName(p, aTagName, elm->childNodes());
            }
        }
    }

    Element* Node::getElementByTagName(DOMString aTagName)
    {
        Element* ret = 0;
        findElementByTagName(ret, aTagName, childNodes());
        return ret;
    }

    unsigned long Node::index()
    {
        for(unsigned i = 0; i < parentNode()->childNodes().length(); i++)
        {
            if(parentNode()->childNodes().item(i) == this)
                return i;
        }
        return 0;
    }

    unsigned long Node::depth()
    {
        unsigned long ret = 0;
        Node* current = parentNode();

        while(current != 0)
        {
            current = current->parentNode();
            ret++;
        }
        return ret;
    }

    Node* Node::insertChild(Node* node, unsigned long aIndex)
    {
        bindChild(node);
        return mChildNodes.insertAt(aIndex, node);
    }

    Node* Node::insertBefore(Node* node, Node* child)
    {
        return insertChild(node, child->index());
    }
    Node* Node::insertAfter(Node* node, Node* child)
    {
        return insertChild(node, child->index() + 1);
    }

    Node* Node::appendChild(Node* node)
    {
        bindChild(node);
        return mChildNodes.pushBack(node);
    }
    Node* Node::replaceChild(Node* node, Node* child)
    {
        insertChild(node, child->index());
        return removeChild(child);
    }

    Node* Node::removeChild(Node* child)
    {
        Node* ret = mChildNodes.popAt(child->index());
        ret->setParentNode(0);
        return ret;
    }

    void Node::prepend(Node* child)
    {
        insertChild(child, 0);
    }
    void Node::append(Node* child)
    {
        appendChild(child);
    }

    void Node::prepend(DOMString textNodeContents)
    {
        insertChild((Node*)new Text(textNodeContents), 0);
    }
    void Node::append(DOMString textNodeContents)
    {
        appendChild((Node*)new Text(textNodeContents));
    }

    Node* Node::before(Node* node)
    {
        if(parentNode() != 0)
            parentNode()->insertBefore(node, this);

        return node;
    }
    Node* Node::after(Node* node)
    {
        if(parentNode() != 0)
            parentNode()->insertAfter(node, this);

        return node;
    }

    Node* Node::before(DOMString textNodeContents)
    {
        if(parentNode() == 0)
            return 0;

        return parentNode()->insertBefore
        (
            (Node*)new Text(textNodeContents), this
        );
    }
    Node* Node::after(DOMString textNodeContents)
    {
        if(parentNode() == 0)
            return 0;

        return parentNode()->insertAfter
        (
            (Node*)new Text(textNodeContents), this
        );
    }

    void Node::remove()
    {
        if(parentNode() != 0)
            parentNode()->removeChild(this);
    }

    void Node::bindChild(Node* child)
    {
        child->unbind();
        child->setParentNode(this);
    }

}
