#include "StyleSheetList.h"

namespace Newtoo
{

    StyleSheetList::StyleSheetList()
    {

    }

    StyleSheet* StyleSheetList::item(unsigned long index)
    {
        if(index >= length())
            return 0;

        return mList[index];
    }

    unsigned long StyleSheetList::length()
    {
        return mList.size();
    }

    void StyleSheetList::appendStyleSheet(StyleSheet* aStyleSheet)
    {
        mList.push_back(aStyleSheet);
    }

}
