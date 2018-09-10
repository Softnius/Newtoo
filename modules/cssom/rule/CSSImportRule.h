#pragma once

#include "CSSRule.h"

namespace Newtoo
{

    class CSSImportRule : public CSSRule
    {
    public:
        CSSImportRule(CSSRule* parent = 0);

        DOMString href() const                                  { return mHref;}
        MediaList& media()                                      { return mMedia; }
        CSSStyleSheet& styleSheet()                             { return mStyleSheet; }

    private:

        DOMString mHref;
        MediaList mMedia;
        CSSStyleSheet mStyleSheet;
    };

}
