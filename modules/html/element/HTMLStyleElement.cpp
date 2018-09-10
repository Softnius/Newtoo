#include "HTMLStyleElement.h"

namespace Newtoo
{

    HTMLStyleElement::HTMLStyleElement()
    {}

    Node* HTMLStyleElement::cloneNode(bool deep)
    {
        return new HTMLStyleElement(*this, deep);
    }

}
