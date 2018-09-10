#include "HTMLLinkElement.h"

namespace Newtoo
{

    HTMLLinkElement::HTMLLinkElement()
    {}

    Node* HTMLLinkElement::cloneNode(bool deep)
    {
        return new HTMLLinkElement(*this, deep);
    }

}
