#pragma once

#include "../cssom/rule/CSSRule.h"

namespace Newtoo
{

    const char CSSAnnotationPrefix = '@';
    const char CSSMediaRulePrefix[] = "@media";
    const char CSSFontFaceRulePrefix[] = "@fontface";
    const char CSSImportRulePrefix[] = "@import";
    const char CSSKeyframesRulePrefix[] = "@keyframes";
    const char CSSNamespaceRulePrefix[] = "@namespace";
    const char CSSPageRulePrefix[] = "@page";

    class CSSRuleBuilder
    {
    public:

        static CSSRule* createRule(DOMString text);
    };

}
