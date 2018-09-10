#include "UIEvent.h"

namespace Newtoo
{

    UIEvent::UIEvent(DOMString type, bool aBubbles, bool aCancelable, Window* aView, long aDetail)
        : Event(type, aBubbles, aCancelable), mView(aView), mDetail(aDetail)
    {}

}
