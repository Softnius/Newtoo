#pragma once

#include "HTMLElement.h"

namespace Newtoo
{

    class HTMLAddressElement : public HTMLElement
    {
    public:

        HTMLAddressElement();
        HTMLAddressElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix = "");

        CSSStyleDeclaration userAgentStyle() override;

        Node* cloneNode(bool deep = false) override;

        HTMLAddressElement(HTMLAddressElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}
    };

}
