#pragma once

#include <vector>

namespace Newtoo
{

    class CSSRule;

    class CSSRuleList
    {
    public:

        CSSRuleList() {}

        CSSRule* item(unsigned long index);
        unsigned long length();

        CSSRuleList(CSSRuleList& reference);

        void appendRule(CSSRule* aRule);
        void insertRule(CSSRule* aRule, unsigned long index);
        void removeRule(unsigned long index);

    private:

        std::vector<CSSRule*> mList;
    };

}
