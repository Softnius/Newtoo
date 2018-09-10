#include "CSSStyleRule.h"

#include "../../assembly/CSSSelectorParser.h"

namespace Newtoo
{

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
        char* openBracket = (char*)aCssText.findChar('{');

        if(openBracket == 0)
            return;

        unsigned long indexOfOpenBracket = openBracket - (char*)&aCssText;
        // если char равен одному байту

        setSelectorText(aCssText.substring(0, indexOfOpenBracket));

        style().setCssText(aCssText.substring(indexOfOpenBracket + 1,
                          aCssText.size() - indexOfOpenBracket - 1),
                          CSSSelectorParser::computePriorityString(mSelectorText));
    }

}
