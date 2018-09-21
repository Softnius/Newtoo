#pragma once

#include "CSSProperty.h"

namespace Newtoo
{

    class StylePropertyMapReadOnly
    {
    public:

        CSSStyleValue* get(USVString property);
        bool has(USVString property);
        unsigned long length();
        unsigned long size(); // alias

    protected:

        std::vector<CSSProperty> mProperties;
    };

}
