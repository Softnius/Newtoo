#include "FocusEvent.h"

namespace Newtoo
{

    FocusEvent::FocusEvent(DOMString type, bool aBubbles, bool aCancelable, Window* aView,
                           long aDetail, EventTarget* aRelatedTarget)

        :UIEvent(type, aBubbles, aCancelable, aView, aDetail), mRelatedTarget(aRelatedTarget)
    {}

}
