#include "HTMLHRElement.h"

namespace Newtoo
{

    HTMLHRElement::HTMLHRElement()
    {}
    HTMLHRElement::HTMLHRElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    CSSStyleDeclaration HTMLHRElement::userAgentStyle()
    {
        CSSStyleDeclaration st;
        st.setProperty("border", "2px solid inherit", UAPropertyPriority);
        st.setProperty("box-sizing", "border-box", UAPropertyPriority);
        st.setProperty("display", "block", UAPropertyPriority);
        st.setProperty("height", "2px", UAPropertyPriority);
        return st;
    }

    Node* HTMLHRElement::cloneNode(bool deep)
    {
        return new HTMLHRElement(*this, deep);
    }

}
