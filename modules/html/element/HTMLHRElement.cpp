#include "HTMLHRElement.h"

namespace Newtoo
{

    HTMLHRElement::HTMLHRElement()
    {}
    HTMLHRElement::HTMLHRElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    Node* HTMLHRElement::cloneNode(bool deep)
    {
        return new HTMLHRElement(*this, deep);
    }

}
