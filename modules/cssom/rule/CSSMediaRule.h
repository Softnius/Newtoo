#pragma once

#include "CSSRule.h"
#include "../media/MediaList.h"

namespace Newtoo
{

    class CSSMediaRule : public CSSRule
    {
    public:
        CSSMediaRule(CSSRule* parent = 0);

        MediaList& media()                                      { return mMedia; }

    private:

        MediaList mMedia;
    };

}
