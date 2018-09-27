#include "HTMLPreElement.h"

namespace Newtoo
{

    HTMLPreElement::HTMLPreElement()
    {}
    HTMLPreElement::HTMLPreElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    CSSStyleDeclaration HTMLPreElement::userAgentStyle()
    {
        CSSStyleDeclaration st;
        st.setProperty("display", "block", UAPropertyPriority);
        st.setProperty("font-family", "\"Courier New\"", UAPropertyPriority);
        st.setProperty("margin-bottom", "0.5em", UAPropertyPriority);
        st.setProperty("margin-top", "0.5em", UAPropertyPriority);
        st.setProperty("white-space", "pre", UAPropertyPriority);
        return st;
    }

    Node* HTMLPreElement::cloneNode(bool deep)
    {
        return new HTMLPreElement(*this, deep);
    }

}
