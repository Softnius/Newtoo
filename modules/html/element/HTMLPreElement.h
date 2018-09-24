#pragma once

#include "HTMLElement.h"

namespace Newtoo
{

    class HTMLPreElement : public HTMLElement
    {
    public:

        HTMLPreElement();
        HTMLPreElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix = "");

        Node* cloneNode(bool deep = false) override;

        HTMLPreElement(HTMLPreElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}
    };

}
