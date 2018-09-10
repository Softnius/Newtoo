#pragma once

#include "StyleSheet.h"

#include <vector>

namespace Newtoo
{

    class StyleSheetList final
    {
    public:

        StyleSheetList();

        StyleSheet* item(unsigned long index);
        unsigned long length();

    private:

        void appendStyleSheet(StyleSheet* aStyleSheet);

        std::vector<StyleSheet*> mList;
    };

}
