#include "HTMLOListElement.h"

namespace Newtoo
{

    HTMLOListElement::HTMLOListElement()
    {}

    Node* HTMLOListElement::cloneNode(bool deep)
    {
        return new HTMLOListElement(*this, deep);
    }

}
