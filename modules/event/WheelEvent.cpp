#include "WheelEvent.h"

namespace Newtoo
{

    WheelEvent::WheelEvent(DOMString type, bool aBubbles, bool aCancelable,
                           Window* aView, long aDetail, long aScreenX, long aScreenY, long aClientX,
                           long aClientY, short aButton, unsigned short aButtons,
                           EventTarget* aRelatedTarget, bool aCtrlKey, bool aShiftKey, bool aAltKey,
                           bool aMetaKey, double aDeltaX, double aDeltaY,
                           double aDeltaZ, DeltaMode aDeltaMode)

        :MouseEvent(type, aBubbles, aCancelable, aView, aDetail, aScreenX, aScreenY, aClientX, aClientY,
         aButton, aButtons, aRelatedTarget, aCtrlKey, aShiftKey, aAltKey, aMetaKey), mDeltaX(aDeltaX),
         mDeltaY(aDeltaY), mDeltaZ(aDeltaZ), mDeltaMode(aDeltaMode)
    {}

}
