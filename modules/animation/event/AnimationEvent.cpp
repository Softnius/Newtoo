#include "AnimationEvent.h"

namespace Newtoo
{

    AnimationEvent::AnimationEvent(DOMString aType, bool aBubbles, bool aCancelable,
        CSSOMString aAnimationName, double aElapsedTime, CSSOMString aPseudoElement)
        :Event(aType, aBubbles, aCancelable), mAnimationTime(aAnimationName), mElapsedTime(aElapsedTime),
          mPseudoElement(aPseudoElement)
    {}

}
