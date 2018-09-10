#include "HTMLPictureElement.h"

namespace Newtoo
{

    HTMLPictureElement::HTMLPictureElement()
    {}

    Node* HTMLPictureElement::cloneNode(bool deep)
    {
        return new HTMLPictureElement(*this, deep);
    }

}
