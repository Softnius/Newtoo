#include "DOMRectList.h"

namespace Newtoo
{

    unsigned long DOMRectList::length() const
    {
        return mControl.size();
    }

    DOMRect* DOMRectList::item(unsigned long index)
    {
        if(index < mControl.size())
            return mControl[index];
        else return 0;
    }

    bool DOMRectList::empty()
    {
        return length() == 0;
    }

}
