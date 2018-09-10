#pragma once

#include "CSSKeyframeRule.h"
#include "../../cssom/rule/CSSRuleList.h"

namespace Newtoo
{

    class CSSKeyframesRule : public CSSRule
    {
    public:
        CSSKeyframesRule(CSSRule* parent = 0);

        CSSOMString name() const                                { return mName; }
        void setName(CSSOMString aName)                         { mName = aName; }
        CSSRuleList& cssRules()                                 { return mCssRules; }

        void appendRule(CSSOMString rule);
        void deleteRule(CSSOMString select);
        CSSKeyframeRule* findRule(CSSOMString select);

    private:

        CSSOMString mName;
        CSSRuleList mCssRules;
    };

}
