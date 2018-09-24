#include "HTMLBaseElement.h"

namespace Newtoo
{

    HTMLBaseElement::HTMLBaseElement()
    {}
    HTMLBaseElement::HTMLBaseElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    Node* HTMLBaseElement::cloneNode(bool deep)
    {
        return new HTMLBaseElement(*this, deep);
    }

}
