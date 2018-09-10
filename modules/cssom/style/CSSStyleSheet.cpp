#include "CSSStyleSheet.h"

#include "../../assembly/CSSRuleBuilder.h"

namespace Newtoo
{

    CSSStyleSheet::CSSStyleSheet(CSSRule* aOwnerRule)
        :mOwnerRule(aOwnerRule)
    {}

    StyleSheet* CSSStyleSheet::clone()
    {
        return new CSSStyleSheet(*this);
    }

#define QUOTE '\"'
#define ALTERNATIVE_QUOTE '\''
#define CLOSE_RULE_CHAR '}'
#define CLOSE_SINGLE_RULE_CHAR ';'
#define OPEN_RULE_CHAR '{'

#define noInRule deep == 0

#define split(ind) \
DOMString next = target->substring(ind + 1, target->size() - ind - 1); \
*target = target->substring(0, ind); \
rules.push_back(next); \
target = &rules.back(); \

    std::vector<DOMString> toRuleList(DOMString text)
    {
        std::vector<DOMString> rules;
        rules.push_back(text);

        DOMString* target = &rules.back();

        bool inString = false;
        unsigned int deep = 0;
        char quote = 0;

        signed long i = 0;

        while(true)
        {
            char c = target->item(i);

            if(i == (int)target->size())
                break;

            if(!inString)
            {
                if(c == QUOTE or c == ALTERNATIVE_QUOTE)
                {
                    inString = true;
                    quote = c;
                    continue;
                }
                else if(c == OPEN_RULE_CHAR)
                {
                    deep++;
                }
                else if(c == CLOSE_RULE_CHAR)
                {
                    deep--;
                    if(noInRule)
                    {
                        split(i);
                    }
                }
                else if(c == CLOSE_SINGLE_RULE_CHAR and noInRule)
                {
                    split(i);
                }
            } else
            {
                if(c == quote)
                {
                    inString = false;
                }
            }

            i++;
        }
        return rules;
    }

    unsigned long CSSStyleSheet::insertRule(DOMString rule, unsigned long index)
    {
        std::vector<DOMString> rules = toRuleList(rule);

        for(unsigned i = 0; i < rules.size(); i++)
            cssRules().insertRule(CSSRuleBuilder::createRule(rules[i]), index + i);

        return index;
    }

    RaisesExceptionVoid CSSStyleSheet::deleteRule(unsigned long index)
    {
        if(index >= cssRules().length())
            return RaisesExceptionVoid(DOMException(IndexSizeError));

        cssRules().removeRule(index);

        return RaisesExceptionVoid();
    }

    void CSSStyleSheet::appendCSS(DOMString rules)
    {
        std::vector<DOMString> list = toRuleList(rules);

        for(unsigned i = 0; i < list.size(); i++)
            cssRules().appendRule(CSSRuleBuilder::createRule(list[i]));
    }

}
