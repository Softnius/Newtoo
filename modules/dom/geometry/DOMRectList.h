#pragma once

#include "DOMRect.h"

#include <vector>

namespace Newtoo
{

    class DOMRectList
    {
    public:

        unsigned long length() const;
        DOMRect* item(unsigned long index);
        bool empty();

    protected:

        std::vector<DOMRect*> mControl;
    };

}
