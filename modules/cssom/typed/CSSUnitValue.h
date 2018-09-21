#pragma once

#include "CSSNumericValue.h"

namespace Newtoo
{

    class CSSUnitValue : public CSSNumericValue
    {
    public:

        CSSUnitValue();

        double value();
        void setValue(double aValue);
        USVString unit();
    };

}
