#include "HTMLLinkElement.h"

namespace Newtoo
{

    HTMLLinkElement::HTMLLinkElement()
    {}
    HTMLLinkElement::HTMLLinkElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    CSSStyleDeclaration HTMLLinkElement::userAgentStyle()
    {
        CSSStyleDeclaration st;
        st.setProperty("display", "none", UAPropertyPriority);
        return st;
    }

    Node* HTMLLinkElement::cloneNode(bool deep)
    {
        return new HTMLLinkElement(*this, deep);
    }

}
