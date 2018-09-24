#include "HTMLPreElement.h"

namespace Newtoo
{

    HTMLPreElement::HTMLPreElement()
    {}
    HTMLPreElement::HTMLPreElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    Node* HTMLPreElement::cloneNode(bool deep)
    {
        return new HTMLPreElement(*this, deep);
    }

}
