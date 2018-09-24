#include "HTMLSourceElement.h"

namespace Newtoo
{

    HTMLSourceElement::HTMLSourceElement()
    {}
    HTMLSourceElement::HTMLSourceElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    Node* HTMLSourceElement::cloneNode(bool deep)
    {
        return new HTMLSourceElement(*this, deep);
    }

}
