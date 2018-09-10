#include "HTMLAddressElement.h"

namespace Newtoo
{

    HTMLAddressElement::HTMLAddressElement()
    {}

    Node* HTMLAddressElement::cloneNode(bool deep)
    {
        return new HTMLAddressElement(*this, deep);
    }

}
