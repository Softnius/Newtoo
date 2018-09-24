#pragma once

#include "HTMLElement.h"

namespace Newtoo
{

    class HTMLUListElement : public HTMLElement
    {
    public:

        HTMLUListElement();
        HTMLUListElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix = "");

        Node* cloneNode(bool deep = false) override;

        HTMLUListElement(HTMLUListElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}
    };

}
