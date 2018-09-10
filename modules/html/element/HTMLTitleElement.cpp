#include "HTMLTitleElement.h"

namespace Newtoo
{

    HTMLTitleElement::HTMLTitleElement()
    {}

    Node* HTMLTitleElement::cloneNode(bool deep)
    {
        return new HTMLTitleElement(*this, deep);
    }

}
