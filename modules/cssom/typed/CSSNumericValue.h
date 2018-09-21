#pragma once

#include "CSSStyleValue.h"

namespace Newtoo
{

    class CSSNumericValue : public CSSStyleValue
    {
    public:

        CSSNumericValue();

        enum CSSNumericType
        {
            length,
            angle,
            time,
            frequency,
            resolution,
            flex,
            percent
        };

        CSSNumericType type();

        static CSSNumericValue parse(USVString cssText);
    };

}
