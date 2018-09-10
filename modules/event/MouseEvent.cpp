#include "MouseEvent.h"

namespace Newtoo
{

   MouseEvent::MouseEvent(DOMString type, bool aBubbles, bool aCancelable,
                          Window* aView, long aDetail, long aScreenX, long aScreenY, long aClientX,
                          long aClientY, short aButton, unsigned short aButtons,
                          EventTarget* aRelatedTarget, bool aCtrlKey, bool aShiftKey, bool aAltKey,
                          bool aMetaKey)

       :UIEvent(type, aBubbles, aCancelable, aView, aDetail), mScreenX(aScreenX), mScreenY(aScreenY),
        mClientX(aClientX), mClientY(aClientY), mButton(aButton), mButtons(aButtons),
        mRelatedTarget(aRelatedTarget), mCtrlKey(aCtrlKey), mShiftKey(aShiftKey), mAltKey(aAltKey),
        mMetaKey(aMetaKey)
   {}

}
