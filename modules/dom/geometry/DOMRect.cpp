#include "DOMRect.h"

namespace Newtoo
{

    DOMRect::DOMRect(int aX, long aY, int aWidth, long aHeight)
        :DOMRectReadOnly(aX, aY, aWidth, aHeight)
    {}

    void DOMRect::setX(int aX)
    {
        mX = aX;
    }
    void DOMRect::setY(int aY)
    {
        mY = aY;
    }
    void DOMRect::setWidth(int aWidth)
    {
        mWidth = aWidth;
    }
    void DOMRect::setHeight(int aHeight)
    {
        mHeight = aHeight;
    }

}
