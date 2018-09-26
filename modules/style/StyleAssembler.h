#pragma once

#include "../dom/node/Element.h"

namespace Newtoo
{

    class StyleAssembler
    {
    public:

        static CSSStyleDeclaration cascade(Element* element); // [NewObject]
    };

}
