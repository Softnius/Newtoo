#pragma once

#include "../../dom/node/Element.h"
#include "../../dom/DOMStringMap.h"
#include "../../dom/event/GlobalEventHandlers.h"
#include "misc/ElementContentEditable.h"

namespace Newtoo
{

    class HTMLElement : public Element, public ElementContentEditable, public GlobalEventHandlers,
            public DocumentAndElementEventHandlers
    {
    public:

        HTMLElement();
        HTMLElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix = "");

        Node* cloneNode(bool deep = false) override;

        DOMString title()                           { return getAttribute("title"); }
        void setTitle(DOMString aTitle)             { setAttribute("title", aTitle); }
        DOMString lang()                            { return getAttribute("lang"); }
        void setLang(DOMString aLang)               { setAttribute("lang", aLang); }

        bool translate()                            { return getAttributeBool("translate"); }
        void setTranslate(bool aTranslate)          { setAttributeBool("translate", aTranslate); }
        DOMString dir()                             { return getAttribute("dir"); }
        void setDir(DOMString aDir)                 { setAttribute("dir", aDir); }

        DOMStringMap& dataset()                     { return mDataset; }

        bool hidden()                               { return getAttributeBool("hidden"); }
        void setHidden(bool aHidden)                { setAttributeBool("hidden", aHidden); }

        void click();

        signed long tabIndex()                      { return getAttributeSignedLong("tabindex"); }
        void setTagIndex(signed long aTabIndex)     { setAttributeSignedLong("tabindex", aTabIndex); }

        void focus();
        void blur();

        DOMString accessKey()                       { return getAttribute("accesskey"); }
        void setAccessKey(DOMString aAccessKey)     { setAttribute("accesskey", aAccessKey); }

        bool draggable()                            { return getAttributeBool("draggable"); }
        void setDraggable(bool aDraggable)          { setAttributeBool("draggable", aDraggable); }
        bool spellcheck()                           { return getAttributeBool("spellcheck"); }
        void setSpellcheck(bool aSpellcheck)        { setAttributeBool("spellcheck", aSpellcheck); }

        void forceSpellCheck();

        DOMString innerText(); // работает так же, как и textContent, но должно работать не так же
        void setInnerText(DOMString aInnerText); // то же, что и setTextContent

        ElementKind getElementKind() override;

        //Из стандарта CSSOM и CSSOM View

        Element* offsetParent();
        signed long offsetTop();
        signed long offsetLeft();
        signed long offsetWidth();
        signed long offsetHeight();

        DOMString contentEditable();
        void setContentEditable(DOMString aContentEditable);
        bool isContentEditable();

        HTMLElement(HTMLElement& reference, bool deep)
            :Element(reference, deep),
             mDataset(reference.mDataset)
        {}

    protected:

        DOMStringMap mDataset;
    };

    class HTMLSemanticElement : public HTMLElement
    {
    public:

        HTMLSemanticElement();
        HTMLSemanticElement(DOMString aNamespace, DOMString qualifiedName,DOMString aPrefix = "");

        CSSStyleDeclaration userAgentStyle() override;

        Node* cloneNode(bool deep = false) override;

        HTMLSemanticElement(HTMLSemanticElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}
    };

    typedef HTMLSemanticElement HTMLUnknownElement;
    typedef HTMLSemanticElement HTMLHeadElement;
    typedef HTMLSemanticElement HTMLBodyElement;
    typedef HTMLSemanticElement HTMLArticleElement;
    typedef HTMLSemanticElement HTMLSectionElement;
    typedef HTMLSemanticElement HTMLNavElement;
    typedef HTMLSemanticElement HTMLAsideElement;
    typedef HTMLSemanticElement HTMLHeaderElement;
    typedef HTMLSemanticElement HTMLFooterElement;
    typedef HTMLSemanticElement HTMLParagraphElement;
    typedef HTMLSemanticElement HTMLDListElement;
    typedef HTMLSemanticElement HTMLDDElement;
    typedef HTMLSemanticElement HTMLDTElement;
    typedef HTMLSemanticElement HTMLFigureElement;
    typedef HTMLSemanticElement HTMLFigCaptionElement;
    typedef HTMLSemanticElement HTMLMainElement;
    typedef HTMLSemanticElement HTMLDivElement;

}
