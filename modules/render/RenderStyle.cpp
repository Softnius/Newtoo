#include "RenderStyle.h"

namespace Newtoo
{

    RenderStyle::RenderStyle(CSSStyleDeclaration aFrom)
    {
        aFrom.cssText();
    }

}
