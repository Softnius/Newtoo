#pragma once

#include "../../../dom/event/Event.h"
#include "../../../dom/DOMString.h"

namespace Newtoo
{

    class MediaQueryListEvent : public Event
    {
    public:

        MediaQueryListEvent(DOMString aMedia = "", bool aMatches = false);

        DOMString media() const                 { return mMedia; }
        bool matches() const                    { return mMatches; }

    protected:

        DOMString mMedia;
        bool mMatches;

    };

}
