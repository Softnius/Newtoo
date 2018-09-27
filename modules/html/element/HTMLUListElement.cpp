#include "HTMLUListElement.h"

namespace Newtoo
{

    HTMLUListElement::HTMLUListElement()
    {}
    HTMLUListElement::HTMLUListElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    CSSStyleDeclaration HTMLUListElement::userAgentStyle()
    {
        CSSStyleDeclaration st;
        st.setProperty("display", "block", UAPropertyPriority);
        st.setProperty("margin-bottom", "0.5em", UAPropertyPriority);
        st.setProperty("margin-top", "0.5em", UAPropertyPriority);
        st.setProperty("padding-left", "35px", UAPropertyPriority);
        return st;
    }

    Node* HTMLUListElement::cloneNode(bool deep)
    {
        return new HTMLUListElement(*this, deep);
    }

}
