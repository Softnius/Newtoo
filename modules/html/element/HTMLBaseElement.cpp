#include "HTMLBaseElement.h"

namespace Newtoo
{

    HTMLBaseElement::HTMLBaseElement()
    {}

    Node* HTMLBaseElement::cloneNode(bool deep)
    {
        return new HTMLBaseElement(*this, deep);
    }

}
