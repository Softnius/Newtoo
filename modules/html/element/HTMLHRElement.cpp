#include "HTMLHRElement.h"

namespace Newtoo
{

    HTMLHRElement::HTMLHRElement()
    {}

    Node* HTMLHRElement::cloneNode(bool deep)
    {
        return new HTMLHRElement(*this, deep);
    }

}
