#pragma once

#include "../../dom/event/EventHandler.h"
#include "../../dom/event/EventTarget.h"
#include "../../dom/DOMString.h"

namespace Newtoo
{

    class MediaQueryList : public EventTarget
    {
    public:

        DOMString media();
        bool matches();

        void addListener(EventListener* listener);
        void removeListener(EventListener* listener);

        EventHandler& onchange()                                { return mOnchange; }
        void setOnchange(EventHandler fn)                       { mOnchange = fn;}

    private:

        EventHandler mOnchange;

    };

}
