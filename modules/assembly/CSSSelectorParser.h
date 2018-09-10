#pragma once

#include "../dom/node/Element.h"

namespace Newtoo
{

    class CSSSelectorParser
    {
    public:

        static bool elementMatches(Element* element, DOMString list);
        static bool elementMatchesItem(Element* element, DOMString text);
        static unsigned long computePriority(DOMString text);
        static DOMString computePriorityString(DOMString text);
    };

}
