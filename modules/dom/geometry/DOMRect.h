#pragma once

#include "DOMRectReadOnly.h"

/*
    DOMRect - тоже, что и DOMRectReadOnly за исключением того, что
    свойства доступны для записи.
*/

namespace Newtoo
{

    class DOMRect : public DOMRectReadOnly
    {
    public:

        DOMRect(int aX, long aY, int aWidth, long aHeight);

        static DOMRect fromRect(int aX = 0, long aY = 0, int aWidth = 0, long aHeight = 0)
        {
            return DOMRect(aX, aY, aWidth, aHeight);
        }
        static DOMRect fromRect(DOMRectReadOnly& aRect)
        {
            return DOMRect(aRect.x(), aRect.y(), aRect.width(), aRect.height());
        }

        void setX(int aX);
        void setY(int aY);
        void setWidth(int aWidth);
        void setHeight(int aHeight);
    };

}
