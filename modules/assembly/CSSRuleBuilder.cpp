#include "CSSRuleBuilder.h"

#include "../cssom/rule/CSSStyleRule.h"

namespace Newtoo
{

    CSSRule* CSSRuleBuilder::createRule(DOMString text)
    {
        if(text.size() < 10)
            return 0;

        if(text.startsWithChar(CSSAnnotationPrefix))
        {

            if(text.startsWith(CSSKeyframesRulePrefix))
            {

            }
            else if(text.startsWith(CSSFontFaceRulePrefix))
            {

            }
            else if(text.startsWith(CSSMediaRulePrefix))
            {

            }
            else if(text.startsWith(CSSNamespaceRulePrefix))
            {

            }
            else if(text.startsWith(CSSPageRulePrefix))
            {

            }
            else if(text.startsWith(CSSImportRulePrefix))
            {

            }
            return 0;

        }
        else // значит это CSSStyleRule
        {
            return new CSSStyleRule(text);
        }
    }

}
