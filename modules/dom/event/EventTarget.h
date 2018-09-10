#pragma once

#include "EventListener.h"

class DOMString;
class Event;


namespace Newtoo
{

    class EventTarget
    {
    public:
        EventTarget();

        void addEventListener(DOMString type, EventListener* callback, bool capture = false);
        void removeEventListener(DOMString type, EventListener* callback, bool capture = false);
        bool dispatchEvent(Event event);

        virtual ~EventTarget() {}
    };

}
