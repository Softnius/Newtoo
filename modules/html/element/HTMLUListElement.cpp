#include "HTMLUListElement.h"

namespace Newtoo
{

    HTMLUListElement::HTMLUListElement()
    {}

    Node* HTMLUListElement::cloneNode(bool deep)
    {
        return new HTMLUListElement(*this, deep);
    }

}
