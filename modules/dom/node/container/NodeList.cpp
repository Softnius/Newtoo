#include "NodeList.h"

namespace Newtoo
{

    unsigned long NodeList::length() const
    {
        return mControl.size();
    }

    Node* NodeList::item(unsigned long index)
    {
        if(index < mControl.size())
            return mControl[index];
        else return 0;
    }

    bool NodeList::empty()
    {
        return length() == 0;
    }

}
