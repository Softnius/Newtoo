#include "HTMLAnchorElement.h"

namespace Newtoo
{

    HTMLAnchorElement::HTMLAnchorElement()
    {}

    Node* HTMLAnchorElement::cloneNode(bool deep)
    {
        return new HTMLAnchorElement(*this, deep);
    }

}
