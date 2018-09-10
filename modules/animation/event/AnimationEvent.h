#pragma once

#include "../../dom/event/Event.h"
#include "../../cssom/CSSOMString.h"

namespace Newtoo
{

    class AnimationEvent : public Event
    {
    public:

        AnimationEvent(DOMString aType, bool aBubbles = false, bool aCancelable = false,
                       CSSOMString aAnimationName = "", double aElapsedTime = 0.0,
                       CSSOMString aPseudoElement = "");

        CSSOMString animationName() const                       { return mAnimationTime; }
        double elapsedTime() const                              { return mElapsedTime; }
        CSSOMString pseudoElement() const                       { return mPseudoElement; }

    private:

        CSSOMString mAnimationTime;
        double mElapsedTime;
        CSSOMString mPseudoElement;
    };

}
