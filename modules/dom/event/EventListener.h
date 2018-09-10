#pragma once

class Event;

namespace Newtoo
{

    class EventListener
    {
    public:
        EventListener();

        void handleEvent(Event event);
    };

}
