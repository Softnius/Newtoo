#include "HTMLOListElement.h"

namespace Newtoo
{

    HTMLOListElement::HTMLOListElement()
    {}
    HTMLOListElement::HTMLOListElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    CSSStyleDeclaration HTMLOListElement::userAgentStyle()
    {
        CSSStyleDeclaration st;
        st.setProperty("display", "block", UAPropertyPriority);
        st.setProperty("padding-left", "40px", UAPropertyPriority);
        st.setProperty("list-style-type", "decimal", UAPropertyPriority);
        st.setProperty("margin-bottom", "0.5em", UAPropertyPriority);
        st.setProperty("margin-top", "0.5em", UAPropertyPriority);
        return st;
    }

    Node* HTMLOListElement::cloneNode(bool deep)
    {
        return new HTMLOListElement(*this, deep);
    }

}
