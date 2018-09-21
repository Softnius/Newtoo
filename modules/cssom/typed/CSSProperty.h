#pragma once

#include "CSSStyleValue.h"

namespace Newtoo
{

    class CSSProperty
    {
    public:

        CSSProperty(USVString aName, USVString aPriority, CSSStyleValue aValue);

        USVString name()                        { return mName; }
        USVString priority()                    { return mPriority; }
        CSSStyleValue& value()                  { return mValue; }

    private:

        USVString mName, mPriority;
        CSSStyleValue mValue;
    };

}
