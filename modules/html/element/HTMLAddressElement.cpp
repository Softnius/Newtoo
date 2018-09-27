#include "HTMLAddressElement.h"

namespace Newtoo
{

    HTMLAddressElement::HTMLAddressElement()
    {}

    HTMLAddressElement::HTMLAddressElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    CSSStyleDeclaration HTMLAddressElement::userAgentStyle()
    {
        CSSStyleDeclaration st;
        st.setProperty("display", "block", UAPropertyPriority);
        st.setProperty("font-style", "italics", UAPropertyPriority);
        return st;
    }

    Node* HTMLAddressElement::cloneNode(bool deep)
    {
        return new HTMLAddressElement(*this, deep);
    }

}
