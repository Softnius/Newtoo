#pragma once

#include "../dom/event/Event.h"

class Window;

namespace Newtoo
{

    class UIEvent : public Event
    {
    public:

        UIEvent(DOMString type, bool aBubbles = false, bool aCancelable = false, Window* aView = 0,
                long aDetail = 0);

        Window* view() const { return mView; }
        long detail() const { return mDetail; }

    protected:

        Window* mView;
        long mDetail;
    };

}
