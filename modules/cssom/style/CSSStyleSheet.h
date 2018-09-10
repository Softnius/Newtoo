#pragma once

#include "StyleSheet.h"
#include "../../dom/DOMString.h"
#include "../rule/CSSRuleList.h"
#include "../../dom/exception/RaisesException.h"

namespace Newtoo
{

    class CSSRule;

    class CSSStyleSheet : public StyleSheet
    {
    public:

        CSSStyleSheet(CSSRule* aOwnerRule = 0);

        StyleSheet* clone() override;

        CSSRule* ownerRule() const                          { return mOwnerRule; }
        CSSRuleList& cssRules()                             { return mCssRules; }
        unsigned long insertRule(DOMString rule, unsigned long index);
        RaisesExceptionVoid deleteRule(unsigned long index);

        void appendCSS(DOMString rules);

        CSSStyleSheet(CSSStyleSheet& reference)
            :StyleSheet(reference),
             mOwnerRule(reference.mOwnerRule),
             mCssRules(reference.mCssRules)
        {}

    private:

        CSSRule* mOwnerRule;
        CSSRuleList mCssRules;
    };

}
