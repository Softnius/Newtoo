#include "Screen.h"

namespace Newtoo
{

    Screen::Screen(long aAvailWidth, long aAvailHeight, long aWidth, long aHeight,
                    unsigned long aColorDepth, unsigned long aPixelDepth)
        :mAvailWidth(aAvailWidth), mAvailHeight(aAvailHeight), mWidth(aWidth), mHeight(aHeight),
          mColorDepth(aColorDepth), mPixelDepth(aPixelDepth)
    {}

}
