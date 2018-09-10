#include "HTMLPreElement.h"

namespace Newtoo
{

    HTMLPreElement::HTMLPreElement()
    {}

    Node* HTMLPreElement::cloneNode(bool deep)
    {
        return new HTMLPreElement(*this, deep);
    }

}
