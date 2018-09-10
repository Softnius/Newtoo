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

    typedef HTMLElement HTMLUnknownElement;
    typedef HTMLElement HTMLHeadElement;
    typedef HTMLElement HTMLBodyElement;
    typedef HTMLElement HTMLArticleElement;
    typedef HTMLElement HTMLSectionElement;
    typedef HTMLElement HTMLNavElement;
    typedef HTMLElement HTMLAsideElement;
    typedef HTMLElement HTMLHeaderElement;
    typedef HTMLElement HTMLFooterElement;
    typedef HTMLElement HTMLParagraphElement;
    typedef HTMLElement HTMLDListElement;
    typedef HTMLElement HTMLDDElement;
    typedef HTMLElement HTMLDTElement;
    typedef HTMLElement HTMLFigureElement;
    typedef HTMLElement HTMLFigCaptionElement;
    typedef HTMLElement HTMLMainElement;
    typedef HTMLElement HTMLDivElement;

}
