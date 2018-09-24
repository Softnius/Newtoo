#include "HTMLTitleElement.h"

namespace Newtoo
{

    HTMLTitleElement::HTMLTitleElement()
    {}
    HTMLTitleElement::HTMLTitleElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    Node* HTMLTitleElement::cloneNode(bool deep)
    {
        return new HTMLTitleElement(*this, deep);
    }

}
