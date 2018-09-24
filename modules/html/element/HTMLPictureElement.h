#pragma once

#include "HTMLElement.h"

namespace Newtoo
{

    class HTMLPictureElement : public HTMLElement
    {
    public:

        HTMLPictureElement();
        HTMLPictureElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix = "");

        Node* cloneNode(bool deep = false) override;

        HTMLPictureElement(HTMLPictureElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}
    };

}
