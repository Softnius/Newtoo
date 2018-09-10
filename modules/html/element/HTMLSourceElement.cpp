#include "HTMLSourceElement.h"

namespace Newtoo
{

    HTMLSourceElement::HTMLSourceElement()
    {}

    Node* HTMLSourceElement::cloneNode(bool deep)
    {
        return new HTMLSourceElement(*this, deep);
    }

}
