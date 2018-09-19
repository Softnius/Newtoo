#include "CSSStyleRule.h"

#include "../../assembly/CSSSelectorParser.h"

namespace Newtoo
{

#define WHITESPACE_CHAR ' '

    CSSStyleRule::CSSStyleRule(DOMString aCssText, CSSRule *parent)
        :CSSRule(STYLE_RULE, parent)
    {
        setCssText(aCssText);
    }

    CSSRule* CSSStyleRule::clone()
    {
        return new CSSStyleRule(*this);
    }

    DOMString CSSStyleRule::cssText()
    {
        DOMString ret = mSelectorText;
        ret += " { ";
        ret = ret.append_(style().cssText());
        ret += " } ";
        return ret;
    }
    void CSSStyleRule::setCssText(DOMString aCssText)
    {
        if(!aCssText.has("{"))
            return;

        unsigned long indexOfOpenBracket = aCssText.indexOf("{");
        // если char равен одному байту

        DOMString selText = aCssText.substring(0, indexOfOpenBracket);
        while(selText.endsWith(" "))
            selText = selText.substring(0, selText.size() - 1);

        setSelectorText(selText);

        style().setCssText(aCssText.substring(indexOfOpenBracket + 1,
                          aCssText.size() - indexOfOpenBracket - 1),
                          CSSSelectorParser::computePriorityString(mSelectorText));

    }
    void CSSStyleRule::setSelectorText(DOMString aText)
    {
        while(aText.startsWithChar(WHITESPACE_CHAR))
            aText = aText.substring(1, aText.size() - 1);

        mSelectorText = aText;
    }

}
