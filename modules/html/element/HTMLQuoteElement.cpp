#include "HTMLQuoteElement.h"

namespace Newtoo
{

    HTMLQuoteElement::HTMLQuoteElement()
    {}
    HTMLQuoteElement::HTMLQuoteElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    CSSStyleDeclaration HTMLQuoteElement::userAgentStyle()
    {
        CSSStyleDeclaration st;
        st.setProperty("display", "block", UAPropertyPriority);
        return st;
    }

    Node* HTMLQuoteElement::cloneNode(bool deep)
    {
        return new HTMLQuoteElement(*this, deep);
    }

}
