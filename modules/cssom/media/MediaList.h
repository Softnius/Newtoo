#pragma once

#include "../../dom/DOMString.h"

#include <vector>

namespace Newtoo
{

    class MediaList
    {
    public:

          DOMString mediaText();
          unsigned long length();
          DOMString* item(unsigned long index);
          void appendMedium(DOMString medium);
          void deleteMedium(DOMString medium);

    private:

        std::vector<DOMString> mList;
    };

}
