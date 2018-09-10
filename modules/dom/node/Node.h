#pragma once

#include "../event/EventTarget.h"
#include "../DOMString.h"
#include "../../misc/USVString.h"
#include "../../html/element/collection/HTMLCollection.h"
#include "container/NodeListControlled.h"

namespace Newtoo
{

    class Document;
    class Element;

    class Node : public EventTarget
    {
    public:

        Node();

        enum NodeType
        {
            ELEMENT_NODE = 1,
            ATTRIBUTE_NODE = 2,
            TEXT_NODE = 3,
            CDATA_SECTION_NODE = 4,
            PROCESSING_INSTRUCTION_NODE = 7,
            COMMENT_NODE = 8,
            DOCUMENT_NODE = 9,
            DOCUMENT_TYPE_NODE = 10,
            DOCUMENT_FRAGMENT_NODE = 11
        };

        Node(NodeType type);

        NodeType nodeType() const       { return mNodeType; }
        virtual DOMString nodeName();
        USVString baseURI();

        Document* ownerDocument();

        Node* parentNode() const        { return mParent; }
        Element* parentElement();

        bool hasChildNodes();

        NodeList& childNodes()          { return mChildNodes; }

        Node* firstChild();
        Node* lastChild();
        Node* previousSibling();
        Node* nextSibling();

        virtual bool hasTextValue();
        virtual DOMString nodeValue();
        virtual DOMString textContent();

        virtual void setNodeValue(DOMString aPlainText);
        virtual void setTextContent(DOMString aPlainText);

        virtual void normalize() {}

        virtual Node* cloneNode(bool deep = false);

        enum
        {
            DOCUMENT_POSITION_EQUALS = 0x00,
            DOCUMENT_POSITION_DISCONNECTED = 0x01,
            DOCUMENT_POSITION_PRECEDING = 0x02,
            DOCUMENT_POSITION_FOLLOWING = 0x04,
            DOCUMENT_POSITION_CONTAINS = 0x08,
            DOCUMENT_POSITION_CONTAINED_BY = 0x10,
            DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC = 0x20
        };

        bool isEqualNode(Node* other);

        unsigned short compareDocumentPosition(Node* other);

        bool containsDeep(Node* other);
        bool contains(Node* other);

        DOMString* lookupPrefix(DOMString aNamespace);
        DOMString* lookupNamespaceURI(DOMString prefix);
        bool isDefaultNamespace(DOMString aNamespace)
        { aNamespace.clear(); return true; }// я вообще не понял, что это

        Node* insertChild(Node* node, unsigned long aIndex);
        Node* insertBefore(Node* node, Node* child);
        Node* insertAfter(Node* node, Node* child);
        Node* appendChild(Node* node);
        Node* replaceChild(Node* node, Node* child);
        Node* removeChild(Node* child);

        Element* querySelector(DOMString selectors);
        NodeList querySelectorAll(DOMString selectors);

        HTMLCollection children();
        Element* firstElementChild();
        Element* lastElementChild();
        unsigned long childElementCount();

        Element* getElementByTagName(DOMString aTagName);

        void prepend(Node* child); /* alias */
        void append(Node* child); /* alias */

        void prepend(DOMString textNodeContents);
        void append(DOMString textNodeContents);

        Node* before(Node* node);
        Node* after(Node* node);

        Node* before(DOMString textNodeContents);
        Node* after(DOMString textNodeContents);

        unsigned long index();
        unsigned long depth();

        void remove();

        Node(Node& reference, bool deep)
            :mParent(0), mNodeType(reference.nodeType())
        {
            if(deep) mChildNodes = NodeListControlled(reference.childNodes(), this);
        }

    protected:

        void bindChild(Node* child);
        inline void unbind() { remove(); }

        void setParentNode(Node* aParent) { mParent = aParent; }

        NodeListControlled mChildNodes;

        Node* mParent;

        NodeType mNodeType;
    };

}
