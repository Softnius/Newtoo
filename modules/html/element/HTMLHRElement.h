#pragma once

#include "HTMLElement.h"

namespace Newtoo
{

    class HTMLHRElement : public HTMLElement
    {
    public:

        HTMLHRElement();

        Node* cloneNode(bool deep = false) override;

        HTMLHRElement(HTMLHRElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}
    };

}
