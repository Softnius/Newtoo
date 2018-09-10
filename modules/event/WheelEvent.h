#pragma once

#include "MouseEvent.h"

namespace Newtoo
{

    class WheelEvent : public MouseEvent
    {
    public:

        enum DeltaMode
        {
            DELTA_PIXEL = 0x00,
            DELTA_LINE  = 0x01,
            DELTA_PAGE  = 0x02
        };

        WheelEvent
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
            bool aMetaKey = false,
            double aDeltaX = 0.0,
            double aDeltaY = 0.0,
            double aDeltaZ = 0.0,
            DeltaMode aDeltaMode = DELTA_PIXEL
        );

        double deltaX() const           { return mDeltaX; }
        double deltaY() const           { return mDeltaY; }
        double deltaZ() const           { return mDeltaZ; }

        DeltaMode deltaMode();

    protected:

        double mDeltaX;
        double mDeltaY;
        double mDeltaZ;

        DeltaMode mDeltaMode;
    };

}
