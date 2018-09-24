#include "HTMLAddressElement.h"

namespace Newtoo
{

    HTMLAddressElement::HTMLAddressElement()
    {}

    HTMLAddressElement::HTMLAddressElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    Node* HTMLAddressElement::cloneNode(bool deep)
    {
        return new HTMLAddressElement(*this, deep);
    }

}
