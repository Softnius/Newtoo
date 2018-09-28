#include "HTMLIFrameElement.h"
#include "../../dom/node/Document.h"
#include "../../window/Window.h"

namespace Newtoo
{

    HTMLIFrameElement::HTMLIFrameElement()
        :mContentDocument(new Document()), mContentWindow(0)
    {}

    HTMLIFrameElement::HTMLIFrameElement(DOMString aNamespace, DOMString qualifiedName,
                                             DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix), mContentDocument(new Document()),
         mContentWindow(0)
    {}

    CSSStyleDeclaration HTMLIFrameElement::userAgentStyle()
    {
        CSSStyleDeclaration st;
        st.setProperty("overflow", "scroll", UAPropertyPriority);
        st.setProperty("border", "2px inset", UAPropertyPriority);
        st.setProperty("height", "150px", UAPropertyPriority);
        st.setProperty("width", "300px", UAPropertyPriority);
        return st;
    }

    Node* HTMLIFrameElement::cloneNode(bool deep)
    {
        return new HTMLIFrameElement(*this, deep);
    }

}
