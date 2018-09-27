#include "HTMLImageElement.h"

namespace Newtoo
{

    HTMLImageElement::HTMLImageElement(unsigned long aWidth, unsigned long aHeight)
    {
        setWidth(aWidth);
        setHeight(aHeight);
    }
    HTMLImageElement::HTMLImageElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix,
                                       unsigned long aWidth, unsigned long aHeight)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {
        setWidth(aWidth);
        setHeight(aHeight);
    }

    CSSStyleDeclaration HTMLImageElement::userAgentStyle()
    {
        CSSStyleDeclaration st;
        st.setProperty("display", "inline-block", UAPropertyPriority);
        st.setProperty("height", "auto", UAPropertyPriority);
        st.setProperty("width", "auto", UAPropertyPriority);
        return st;
    }

    Node* HTMLImageElement::cloneNode(bool deep)
    {
        return new HTMLImageElement(*this, deep);
    }

}
