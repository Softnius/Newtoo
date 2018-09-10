#pragma once

#include "../../cssom/rule/CSSRule.h"
#include "../../cssom/CSSOMString.h"
#include "../../cssom/style/CSSStyleDeclaration.h"

namespace Newtoo
{

    class CSSKeyframeRule : public CSSRule
    {
    public:
        CSSKeyframeRule(CSSRule* parent = 0);

        CSSOMString keyText()                                   { return mKeyText; }
        void setKeyText(CSSOMString aKeyText)                   { mKeyText = aKeyText; }
        CSSStyleDeclaration* style() const                      { return mStyle; }

    private:

        CSSOMString mKeyText;
        CSSStyleDeclaration* mStyle;
    };

}
