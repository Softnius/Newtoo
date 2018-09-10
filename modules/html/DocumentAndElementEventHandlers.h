#pragma once

#include "../dom/event/EventHandler.h"

namespace Newtoo
{

    class DocumentAndElementEventHandlers
    {
    public:

        EventHandler& oncopy()                      { return mOncopy; }
        EventHandler& oncut()                       { return mOncut; }
        EventHandler& onpaste()                     { return mOnpaste; }

        void setOncopy(EventHandler fn)             { mOncopy = fn; }
        void setOncut(EventHandler fn)              { mOncut = fn; }
        void setOnpaste(EventHandler fn)            { mOnpaste = fn; }

    private:

        EventHandler mOncopy;
        EventHandler mOncut;
        EventHandler mOnpaste;
    };

}
