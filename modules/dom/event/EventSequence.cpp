#include "EventSequence.h"

namespace Newtoo
{

    EventSequence::EventSequence() {}

    EventTarget* EventSequence::at(const unsigned aIndex)
    {
        return mArray[aIndex];
    }
    void EventSequence::push(EventTarget* aEventTarget)
    {
        mArray.push_back(aEventTarget);
    }

}
