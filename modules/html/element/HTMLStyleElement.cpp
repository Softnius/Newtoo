#include "HTMLStyleElement.h"
#include "../../cssom/style/CSSStyleSheet.h"
#include "../../cssom/rule/CSSRule.h"

namespace Newtoo
{

    HTMLStyleElement::HTMLStyleElement()
    {}

    HTMLStyleElement::HTMLStyleElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    Node* HTMLStyleElement::cloneNode(bool deep)
    {
        return new HTMLStyleElement(*this, deep);
    }

    DOMString HTMLStyleElement::innerHTML()
    {
        DOMString html;

        CSSStyleSheet* s = (CSSStyleSheet*)sheet();

        for(unsigned i = 0; i < s->cssRules().length(); i++)
        {
            html += s->cssRules().item(i)->cssText();
        }
        return html;
    }
    void HTMLStyleElement::setInnerHTML(DOMString aHTML)
    {
        if(sheet() == (StyleSheet*)NoStyleSheet)
            return;

        CSSStyleSheet* s = (CSSStyleSheet*)sheet();

        for(unsigned i = 0; i < s->cssRules().length(); i++)
        {
            s->cssRules().removeRule(i);
        }
        s->appendCSS(aHTML);
    }

}
