#include "HTMLPictureElement.h"

namespace Newtoo
{

    HTMLPictureElement::HTMLPictureElement()
    {}
    HTMLPictureElement::HTMLPictureElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    Node* HTMLPictureElement::cloneNode(bool deep)
    {
        return new HTMLPictureElement(*this, deep);
    }

}
