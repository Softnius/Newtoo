#pragma once

#include "CSSRule.h"
#include "../style/CSSStyleDeclaration.h"

namespace Newtoo
{

    class ElementCSSInlineStyle : public CSSRule
    {
    public:
        ElementCSSInlineStyle(CSSRule* parent = 0);

        CSSStyleDeclaration& style()                            { return mStyle; }

        DOMString cssText() override final;
        void setCssText(DOMString aCssText) override final;

    private:

        CSSStyleDeclaration mStyle;
    };

}
