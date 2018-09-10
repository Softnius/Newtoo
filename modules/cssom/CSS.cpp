#include "CSS.h"

namespace Newtoo
{

    DOMString CSS::escape(DOMString ident)
    {
        ident = ident.append_(EscapeChar);
        return ident;
    }

}
