#pragma once

#include "../../html/element/collection/HTMLCollection.h"
#include "../../html/DocumentAndElementEventHandlers.h"
#include "../../cssom/misc/ScrollBehavior.h"
#include "container/NamedNodeMap.h"
#include "../reflect/DOMTokenList.h"
#include "../DOMString.h"
#include "../geometry/DOMRect.h"
#include "Node.h"


namespace Newtoo
{

    class CSSStyleDeclaration;

    enum ScrollLogicalPosition
    {
        START,
        CENTER,
        END,
        NEAREST
    };

    class Element : public Node
    {
    public:
        Element();

        Element(DOMString aLocalName);
        Element(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix = "");

        Node* cloneNode(bool deep = false) override;

        DOMString nodeName() override;

        DOMString textContent() override final;
        void setTextContent(DOMString aPlainText) override final;

        DOMString namespaceURI() const          { return mNamespaceURI; }
        DOMString prefix() const                { return mPrefix; }
        DOMString localName() const             { return mLocalName; }
        DOMString tagName();

        DOMString id()                          { return getAttribute("id"); }
        void setId(DOMString aId)               { setAttribute("id", aId); }

        DOMString className()                   { return getAttribute("class"); }
        void setClassName(DOMString aClassName) { setAttribute("class", aClassName); }

        DOMTokenList classList()                { return reflectTo("class"); }


        //DOMString slot() const                  { return mSlot; }
        //void setSlot(DOMString aSlot)           { mSlot = aSlot; }

        bool hasAttributes();

        NamedNodeMap& attributes()              { return mAttributes; }

        DOMString getAttribute(DOMString qualifiedName);
        DOMString getAttributeNS(DOMString aNamespace, DOMString localName);

        void setAttribute(DOMString qualifiedName, DOMString value);
        void setAttributeNS(DOMString aNamespace, DOMString qualifiedName, DOMString value);

        void removeAttribute(DOMString qualifiedName);
        void removeAttributeNS(DOMString aNamespace, DOMString localName);

        bool hasAttribute(DOMString qualifiedName);
        bool hasAttributeNS(DOMString aNamespace, DOMString localName);

        Attr* getAttributeNode(DOMString qualifiedName);
        Attr* getAttributeNodeNS(DOMString aNamespace, DOMString localName);

        void appendAttributeNode(Attr* aAttr);

        Element* previousElementSibling();
        Element* nextElementSibling();

        //ShadowRoot* attachShadow(ShadowRootInit init);
        //ShadowRoot* shadowRoot();

        //Element* closest(DOMString selectors);
        bool matches(DOMString selectors);

        HTMLCollection getElementsByTagName(DOMString localName);
        HTMLCollection getElementsByTagNameNS(DOMString aNamespace, DOMString localName);
        HTMLCollection getElementsByClassName(DOMString classNames);

        Element* getElementById(DOMString aId);

        unsigned long collectionIndex();

        DOMString innerHTML();
        void setInnerHTML(DOMString aHTML);

        DOMString outerHTML();
        void setOuterHTML(DOMString aHTML);

        enum class ElementKind
        {
            Element,
            HTMLElement,
            SVGElement
        };

        virtual ElementKind getElementKind();

        bool isHTMLElement();
        bool isSVGElement();

        DOMTokenList reflectTo(DOMString attrName);

        //Из стандарта CSSOM и CSSOM View

        CSSStyleDeclaration& style();

        std::vector<DOMRect> getClientRects();
        DOMRect getBoundingClientRect();
        void scrollIntoView();
        void scrollIntoView(bool arg);
        void scroll(ScrollBehavior behavior, double left, double top);
        void scroll(double x, double y);
        void scrollTo(ScrollBehavior behavior, double left, double top);
        void scrollTo(double x, double y);
        void scrollBy(ScrollBehavior behavior, double left, double top);
        void scrollBy(double x, double y);

        double scrollTop();
        void setScrollTop(double aScrollTop);
        double scrollLeft();
        void setScrollLeft(double aScrollLeft);

        double scrollWidth();
        double scrollHeight();
        double clientTop();
        double clientLeft();
        double clientWidth();
        double clientHeight();

        Element(Element& reference, bool deep)
            :Node(reference, deep),
             mNamespaceURI(reference.mNamespaceURI),
             mPrefix(reference.mPrefix),
             mLocalName(reference.mLocalName),
             mAttributes(reference.attributes(), this)
        {}

    protected:

        DOMString mNamespaceURI;
        DOMString mPrefix;
        DOMString mLocalName;

        NamedNodeMap mAttributes;

        void setAttributeBool(DOMString qualifiedName, bool value);
        bool getAttributeBool(DOMString qualifiedName);
        void setAttributeSignedLong(DOMString qualifiedName, signed long value);
        signed long getAttributeSignedLong(DOMString qualifiedName);

    };

}
