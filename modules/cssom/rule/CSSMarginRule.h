#pragma once

#include "CSSRule.h"
#include "../style/CSSStyleDeclaration.h"

namespace Newtoo
{

    class CSSMarginRule : public CSSRule
    {
    public:
        CSSMarginRule(CSSRule* parent = 0);

        CSSStyleDeclaration& style()                            { return mStyle; }

    private:

        CSSStyleDeclaration mStyle;
    };

}
