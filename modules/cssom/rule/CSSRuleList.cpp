#include "CSSRuleList.h"
#include "CSSRule.h"

namespace Newtoo
{

    CSSRule* CSSRuleList::item(unsigned long index)
    {
        if(index >= length())
            return 0;

        return mList[index];
    }

    CSSRuleList::CSSRuleList(CSSRuleList& reference)
    {
        for(unsigned i = 0; i < reference.mList.size(); i++)
            appendRule(reference.mList[i]->clone());
    }

    unsigned long CSSRuleList::length()
    {
        return mList.size();
    }

    void CSSRuleList::appendRule(CSSRule* aRule)
    {
        mList.push_back(aRule);
    }
    void CSSRuleList::insertRule(CSSRule* aRule, unsigned long index)
    {
        mList.insert(mList.begin() + index, aRule);
    }
    void CSSRuleList::removeRule(unsigned long index)
    {
        mList.erase(mList.begin() + index);
        mList.shrink_to_fit();
    }

}
