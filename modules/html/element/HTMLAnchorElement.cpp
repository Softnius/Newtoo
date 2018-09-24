#include "HTMLAnchorElement.h"

namespace Newtoo
{

    HTMLAnchorElement::HTMLAnchorElement()
    {}
    HTMLAnchorElement::HTMLAnchorElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    Node* HTMLAnchorElement::cloneNode(bool deep)
    {
        return new HTMLAnchorElement(*this, deep);
    }

}
