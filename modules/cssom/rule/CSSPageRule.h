#pragma once

#include "CSSRule.h"
#include "../style/CSSStyleDeclaration.h"

namespace Newtoo
{

    class CSSPageRule : public CSSRule
    {
    public:
        CSSPageRule(CSSRule* parent = 0);

        DOMString selectorText() const                          { return mSelectorText; }
        void setSelectorText(DOMString aText)                   { mSelectorText = aText; }
        CSSStyleDeclaration& style()                            { return mStyle; }

    private:

        DOMString mSelectorText;
        CSSStyleDeclaration mStyle;
    };
}
