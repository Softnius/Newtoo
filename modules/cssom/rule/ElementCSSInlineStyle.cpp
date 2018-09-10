#include "ElementCSSInlineStyle.h"

namespace Newtoo
{

    ElementCSSInlineStyle::ElementCSSInlineStyle(CSSRule *parent)
        :CSSRule(STYLE_RULE, parent)
    {

    }

    DOMString ElementCSSInlineStyle::cssText()
    {
        return style().cssText();
    }
    void ElementCSSInlineStyle::setCssText(DOMString aCssText)
    {
        style().setCssText(aCssText);
    }

}
