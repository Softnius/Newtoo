#pragma once

#include "../dom/DOMString.h"

#include <vector>

namespace Newtoo
{

    const char DatasetPrefix[] = "data-";

    class DOMStringMap
    {
    public:

        DOMStringMap();

        DOMString get(DOMString name);
        void set(DOMString name, DOMString value);
        void remove(DOMString name);

    private:

        struct Pair
        {
            DOMString name, value;
        };
        std::vector<Pair> mPairs;

    protected:

        std::vector<Pair>& pairs()                  { return mPairs; }
    };

}
