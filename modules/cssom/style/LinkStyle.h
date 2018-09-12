#pragma once

#include "StyleSheet.h"

namespace Newtoo
{

    class LinkStyle
    {
    public:

        const unsigned long NoStyleSheet = 0;

        LinkStyle();
        LinkStyle(StyleSheet* aRefStyleSheet);

        StyleSheet* sheet() const                           { return mSheet; }

    protected:

        StyleSheet* mSheet;
    };

}
