#pragma once

#include "HTMLElement.h"

namespace Newtoo
{

    class HTMLTitleElement : public HTMLElement
    {
    public:

        HTMLTitleElement();
        HTMLTitleElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix = "");

        Node* cloneNode(bool deep = false) override;

        DOMString text()                                { return getAttribute("text"); }
        void setText(DOMString aText)                   { setAttribute("text", aText); }

        HTMLTitleElement(HTMLTitleElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}

    private:

    };

}
