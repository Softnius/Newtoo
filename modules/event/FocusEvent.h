#pragma once

#include "UIEvent.h"

namespace Newtoo
{

    class FocusEvent : public UIEvent
    {
    public:
        FocusEvent(DOMString type, bool aBubbles = false, bool aCancelable = false, Window* aView = 0,
                   long aDetail = 0, EventTarget* aRelatedTarget = 0);

        EventTarget* relatedTarget() const { return mRelatedTarget; }

    protected:

        EventTarget* mRelatedTarget;
    };

}
