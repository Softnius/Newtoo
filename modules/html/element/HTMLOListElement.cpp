#include "HTMLOListElement.h"

namespace Newtoo
{

    HTMLOListElement::HTMLOListElement()
    {}
    HTMLOListElement::HTMLOListElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    Node* HTMLOListElement::cloneNode(bool deep)
    {
        return new HTMLOListElement(*this, deep);
    }

}
