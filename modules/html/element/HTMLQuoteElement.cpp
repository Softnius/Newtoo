#include "HTMLQuoteElement.h"

namespace Newtoo
{

    HTMLQuoteElement::HTMLQuoteElement()
    {}
    HTMLQuoteElement::HTMLQuoteElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    Node* HTMLQuoteElement::cloneNode(bool deep)
    {
        return new HTMLQuoteElement(*this, deep);
    }

}
