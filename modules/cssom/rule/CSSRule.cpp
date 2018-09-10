#include "CSSRule.h"
#include "CSSImportRule.h"

namespace Newtoo
{

    CSSRule::CSSRule(RuleType aType, CSSRule* parent)
        :mType(aType), mParentRule(parent)
    {}

    CSSRule* CSSRule::clone()
    {
        return new CSSRule(*this);
    }

    CSSStyleSheet* CSSRule::parentStyleSheet()
    {
        if(mParentRule->type() == RuleType::IMPORT_RULE)
        {
            CSSImportRule* i = (CSSImportRule*)mParentRule;
            return &i->styleSheet();
        }

        return 0;
    }

}
