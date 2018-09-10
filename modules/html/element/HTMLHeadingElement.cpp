#include "HTMLHeadingElement.h"

namespace Newtoo
{

    HTMLHeadingElement::HTMLHeadingElement(Rank aRank)
        :mRank(aRank)
    {}

    Node* HTMLHeadingElement::cloneNode(bool deep)
    {
        return new HTMLHeadingElement(*this, deep);
    }

}
