#pragma once

#include "HTMLElement.h"

namespace Newtoo
{

    class HTMLHeadingElement : public HTMLElement
    {
    public:

        enum Rank
        {
            H1, H2, H3, H4, H5, H6
        };

        HTMLHeadingElement(Rank aRank = H1);
        HTMLHeadingElement(DOMString aNamespace, DOMString qualifiedName,DOMString aPrefix = "",
                           Rank aRank = H1);

        CSSStyleDeclaration userAgentStyle() override;

        Node* cloneNode(bool deep = false) override;

        Rank rank() const                          { return mRank; }
        void setRank(Rank aRank)                   { mRank = aRank; }

        HTMLHeadingElement(HTMLHeadingElement& reference, bool deep)
            :HTMLElement(reference, deep), mRank(reference.mRank)
        {}

    private:

        Rank mRank;
    };

}
