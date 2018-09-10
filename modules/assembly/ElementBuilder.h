#pragma once

#include "../dom/node/Element.h"

namespace Newtoo
{

    const char HTMLDivElementTagName[] = "div";
    const char HTMLParagraphElementTagName[] = "p";

    class ElementBuilder
    {
    public:
        static Element* createElement(DOMString name, DOMString namespaceURI = "");
    };

}
