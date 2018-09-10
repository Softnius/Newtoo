#pragma once

#include "CSSRule.h"
#include "../style/CSSStyleDeclaration.h"

namespace Newtoo
{

    class CSSFontFaceRule : public CSSRule
    {
    public:

        CSSFontFaceRule(CSSRule* parent = 0);

        CSSStyleDeclaration& style()                            { return mStyle; }

    private:

        CSSStyleDeclaration mStyle;
    };

}
