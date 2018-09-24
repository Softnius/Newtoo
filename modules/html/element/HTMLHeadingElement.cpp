#include "HTMLHeadingElement.h"

namespace Newtoo
{

    HTMLHeadingElement::HTMLHeadingElement(Rank aRank)
        :mRank(aRank)
    {}
    HTMLHeadingElement::HTMLHeadingElement(DOMString aNamespace, DOMString qualifiedName,
                                           DOMString aPrefix, Rank aRank)
        :HTMLElement(aNamespace, qualifiedName, aPrefix), mRank(aRank)
    {}

    Node* HTMLHeadingElement::cloneNode(bool deep)
    {
        return new HTMLHeadingElement(*this, deep);
    }

}
