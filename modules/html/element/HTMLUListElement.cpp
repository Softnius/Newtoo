#include "HTMLUListElement.h"

namespace Newtoo
{

    HTMLUListElement::HTMLUListElement()
    {}
    HTMLUListElement::HTMLUListElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    Node* HTMLUListElement::cloneNode(bool deep)
    {
        return new HTMLUListElement(*this, deep);
    }

}
