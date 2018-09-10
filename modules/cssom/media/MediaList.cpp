#include "MediaList.h"

namespace Newtoo
{

    unsigned long MediaList::length()
    {
        return mList.size();
    }

    DOMString* MediaList::item(unsigned long index)
    {
        if(index < length())
            return &mList[index];

        return 0;
    }

    void MediaList::appendMedium(DOMString medium)
    {
        mList.push_back(medium);
    }
    void MediaList::deleteMedium(DOMString medium)
    {
        for(unsigned i = 0; i < length(); i++)
        {
            if(mList[i] == medium)
            {
                mList.erase(mList.begin() + i);
                break;
            }
        }
    }
    DOMString MediaList::mediaText()
    {
        DOMString str;
        for(unsigned i = 0; i < length(); i++)
            str = str.append_(mList[i]);

        return str;
    }

}
