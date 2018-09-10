#pragma once

namespace Newtoo
{

    class Screen final
    {
    public:

        Screen(long aAvailWidth, long aAvailHeight, long aWidth, long aHeight,
               unsigned long aColorDepth, unsigned long aPixelDepth);

        long availWidth() const                         { return mAvailWidth; }
        long availHeight() const                        { return mAvailHeight; }
        long width() const                              { return mWidth; }
        long height() const                             { return mHeight; }
        unsigned long colorDepth() const                { return mColorDepth; }
        unsigned long pixelDepth() const                { return mPixelDepth; }

    private:

        long mAvailWidth;
        long mAvailHeight;
        long mWidth;
        long mHeight;
        unsigned long mColorDepth;
        unsigned long mPixelDepth;
    };

}
