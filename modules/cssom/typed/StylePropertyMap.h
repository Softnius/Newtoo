#pragma once

#include "StylePropertyMapReadOnly.h"

namespace Newtoo
{

    class StylePropertyMap : public StylePropertyMapReadOnly
    {
    public:
        StylePropertyMap();

        void set(USVString property, CSSStyleValue value);
        void append(USVString property, CSSStyleValue value);
        void set(USVString property, USVString value);
        void append(USVString property, USVString value);
        void delete_(USVString property);
        void clear();
    };

}

