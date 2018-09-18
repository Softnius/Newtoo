#pragma once

#include "../dom/node/Element.h"

namespace Newtoo
{

    const char HTMLDivElementTagName[] = "div";
    const char HTMLParagraphElementTagName[] = "p";
    const char HTMLStyleElementTagName[] = "style";

    class ElementBuilder
    {
    public:
        static Element* createElement(DOMString name, DOMString namespaceURI = "");
    };

}
