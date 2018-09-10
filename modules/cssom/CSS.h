#pragma once

#include "../dom/DOMString.h"

namespace Newtoo
{

    const char EscapeChar[] = " ";

    class CSS
    {
    public:

        static DOMString escape(DOMString ident);
    };

}
