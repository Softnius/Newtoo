#pragma once

#include "UIEvent.h"

namespace Newtoo
{

    class MouseEvent : public UIEvent
    {
    public:

        MouseEvent
        (
            DOMString type,
            bool aBubbles = false,
            bool aCancelable = false,
            Window* aView = 0,
            long aDetail = 0,
            long aScreenX = 0,
            long aScreenY = 0,
            long aClientX = 0,
            long aClientY = 0,
            short aButton = 0,
            unsigned short aButtons = 0,
            EventTarget* aRelatedTarget = 0,
            bool aCtrlKey = false,
            bool aShiftKey = false,
            bool aAltKey = false,
            bool aMetaKey = false
        );

        long screenX() const                { return mScreenX; }
        long screenY() const                { return mScreenY; }
        long clientX() const                { return mClientX; }
        long clientY() const                { return mClientY; }

        bool ctrlKey() const                { return mCtrlKey; }
        bool shiftKey() const               { return mShiftKey; }
        bool altKey() const                 { return mAltKey; }
        bool metaKey() const                { return mMetaKey; }

        short button() const                { return mButton; }
        unsigned short buttons() const      { return mButtons; }

        EventTarget* relatedTarget() const  { return mRelatedTarget; }

        bool getModifierState(DOMString keyArg);

        //Из стандарта CSSOM и CSSOM View

        double pageX();
        double pageY();
        double offsetX();
        double offsetY();
        double x();
        double y();

    protected:

        long mScreenX;
        long mScreenY;
        long mClientX;
        long mClientY;

        short mButton;
        unsigned short mButtons;

        EventTarget* mRelatedTarget;

        bool mCtrlKey;
        bool mShiftKey;
        bool mAltKey;
        bool mMetaKey;
    };

}
