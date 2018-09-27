#pragma once

#include "HTMLElement.h"

namespace Newtoo
{

    class HTMLSourceElement : public HTMLElement
    {
    public:

        HTMLSourceElement();
        HTMLSourceElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix = "");

        CSSStyleDeclaration userAgentStyle() override;

        Node* cloneNode(bool deep = false) override;

        DOMString src()                                     { return getAttribute("src"); }
        void setSrc(DOMString aSrc)                         { setAttribute("src", aSrc); }

        DOMString Type()                                    { return getAttribute("type"); }
        void setType(DOMString aType)                       { setAttribute("type", aType); }

        DOMString srcset()                                  { return getAttribute("srcset"); }
        void setSrcset(DOMString aSrcset)                   { setAttribute("srcset", aSrcset); }

        DOMString sizes()                                   { return getAttribute("sizes"); }
        void setSizes(DOMString aSizes)                     { setAttribute("sizes", aSizes); }

        DOMString media()                                   { return getAttribute("media"); }
        void setMedia(DOMString aMedia)                     { setAttribute("media", aMedia); }

        HTMLSourceElement(HTMLSourceElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}

    private:

    };

}
