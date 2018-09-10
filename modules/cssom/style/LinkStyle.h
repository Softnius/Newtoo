#pragma once

#include "StyleSheet.h"

namespace Newtoo
{

    class LinkStyle
    {
    public:

        LinkStyle();
        LinkStyle(StyleSheet* aRefStyleSheet);

        StyleSheet* sheet() const                           { return mSheet; }

    protected:

        StyleSheet* mSheet;
    };

}
