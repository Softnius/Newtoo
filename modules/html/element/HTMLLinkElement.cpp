#include "HTMLLinkElement.h"

namespace Newtoo
{

    HTMLLinkElement::HTMLLinkElement()
    {}
    HTMLLinkElement::HTMLLinkElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    Node* HTMLLinkElement::cloneNode(bool deep)
    {
        return new HTMLLinkElement(*this, deep);
    }

}
