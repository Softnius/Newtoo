#include "Event.h"

namespace Newtoo
{

    Event::Event(DOMString aType, bool aBubbles, bool aCancelable)
        :mType(aType),
         mEventPhase(NONE),
         mCancelBubble(false),
         mBubbles(aBubbles),
         mCancelable(aCancelable),
         mDefaultPrevented(false),
         mComposed(false),
         mIsTrusted(true)
    {}

    Event::Event() :mEventPhase(NONE), mCancelBubble(false), mBubbles(false), mCancelable(false),
        mDefaultPrevented(false), mComposed(false), mIsTrusted(true) {}

    void Event::initEvent(DOMString aType, bool aBubbles, bool aCancelable)
    {
        mType = aType;
        mEventPhase = NONE;
        mCancelBubble = false;
        mBubbles = aBubbles;
        mCancelable = aCancelable;
        mDefaultPrevented = false;
        mIsTrusted = true;
    }

}
