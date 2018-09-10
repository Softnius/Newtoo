#pragma once

#include "CSSRule.h"

namespace Newtoo
{

    class CSSNamespaceRule : public CSSRule
    {
    public:

        CSSNamespaceRule(CSSRule* parent = 0);

        DOMString namespaceURI() const                          { return mNamespaceURI; }
        DOMString prefix() const                                { return mPrefix; }

    private:

        DOMString mNamespaceURI;
        DOMString mPrefix;
    };

}
