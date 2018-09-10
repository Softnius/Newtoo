#pragma once

class EventTarget;

#include <vector>

namespace Newtoo
{

    class EventSequence
    {
    public:

        EventSequence();

        unsigned long size()         { return mArray.size(); }

        EventTarget* at(const unsigned aIndex);
        void push(EventTarget* aEventTarget);

    private:

        /*
            unsigned mSize;
            EventTarget* mData;
        */
        std::vector<EventTarget*> mArray;
    };

}
