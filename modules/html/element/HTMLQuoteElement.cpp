#include "HTMLQuoteElement.h"

namespace Newtoo
{

    HTMLQuoteElement::HTMLQuoteElement()
    {}

    Node* HTMLQuoteElement::cloneNode(bool deep)
    {
        return new HTMLQuoteElement(*this, deep);
    }

}
