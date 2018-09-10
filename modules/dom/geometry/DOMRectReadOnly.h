#pragma once

/*

     Смотрите подробную документацию к интерфейсу DOMRectReadOnly на MDN
     https://developer.mozilla.org/ru/docs/Web/API/DOMRectReadOnly

*/

namespace Newtoo
{

    class DOMRectReadOnly
    {
    public:

        DOMRectReadOnly(int aX, long aY, int aWidth, long aHeight);

        static DOMRectReadOnly fromRect(int aX = 0, long aY = 0, int aWidth = 0, long aHeight = 0)
        {
            return DOMRectReadOnly(aX, aY, aWidth, aHeight);
        }

        int x() const           { return mX; }
        long y() const          { return mY; }
        int width() const       { return mWidth; }
        long height() const     { return mHeight; }

        int left()              { return x(); }
        long top()              { return y(); }
        int right()             { return x() + width(); }
        long bottom()           { return y() + height(); }

    protected:

        int     mX;
        long    mY;
        int     mWidth;
        long    mHeight;
    };

}
