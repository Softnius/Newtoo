#pragma once

#include "../CSS.h"

#include <vector>

namespace Newtoo
{

    class CSSStyleValue
    {
    public:

        enum ValueType
        {
            STYLE_VALUE,
            UNPARSED_VALUE,
            VARIABLE_REFERENCE_VALUE,
            TRANSFORN_VALUE,
            POSITION_VALUE,
            KEYWORD_VALUE,
            NUMERIC_VALUE,
            IMAGE_VALUE,
            UNIT_VALUE,
            MATH_VALUE,
            MATH_SUM,
            MATH_PRODUCT,
            MATH_NEGATE,
            MATH_INVERT,
            MATH_MIN,
            MATH_MAX
        };

        static CSSStyleValue parse(USVString property, USVString cssText);
        static std::vector<CSSStyleValue> parseAll(USVString property, USVString cssText);
    };

}
