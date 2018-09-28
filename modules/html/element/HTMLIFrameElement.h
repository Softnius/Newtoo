#pragma once

#include "HTMLElement.h"

namespace Newtoo
{

    class Window;

    class HTMLIFrameElement : public HTMLElement
    {
    public:

        HTMLIFrameElement();
        HTMLIFrameElement(DOMString aNamespace, DOMString qualifiedName,DOMString aPrefix = "");

        CSSStyleDeclaration userAgentStyle() override;

        Node* cloneNode(bool deep = false) override;

        DOMString srcdoc()                                  { return getAttribute("srcdoc"); }
        void setSrcdoc(DOMString aSrcdoc)                   { setAttribute("srcdoc", aSrcdoc); }

        DOMString src()                                     { return getAttribute("src"); }
        void setSrc(DOMString aSrc)                         { setAttribute("src", aSrc); }

        DOMString name()                                    { return getAttribute("name"); }
        void setName(DOMString aName)                       { setAttribute("name", aName); }

        DOMTokenList sandbox()                              { return reflectTo("sandbox"); }

        bool allowFullscreen()                      { return getAttributeBool("allowFullscreen"); }
        void setAllowFullscreen(bool aAFS)          { setAttributeBool("allowFullscreen", aAFS); }

        bool allowPaymentRequest()                  { return getAttributeBool("allowPaymentRequest"); }
        void setAllowPaymentRequest(bool aAPR)      { setAttributeBool("allowPaymentRequest", aAPR); }

        bool allowUserMedia()                       { return getAttributeBool("allowUserMedia"); }
        void setAllowUserMedia(bool aAUM)           { setAttributeBool("allowUserMedia", aAUM); }

        DOMString width()                                   { return getAttribute("width"); }
        void setWidth(DOMString aWidth)                     { setAttribute("width", aWidth); }

        DOMString height()                                  { return getAttribute("height"); }
        void setHeight(DOMString aHeight)                   { setAttribute("height", aHeight); }

        DOMString referrerPolicy()                          { return getAttribute("referrerpolicy"); }
        void setReferrerPolicy(DOMString aReferrerPolicy)
        { setAttribute("referrerpolicy", aReferrerPolicy); }

        Document* contentDocument() const                   { return mContentDocument; }
        Window* contentWindow() const                       { return mContentWindow; }

        HTMLIFrameElement(HTMLIFrameElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}

    protected:

        Document* mContentDocument;
        Window* mContentWindow;
    };

}
