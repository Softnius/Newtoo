#include "CSSProperty.h"

namespace Newtoo
{

    CSSProperty::CSSProperty(USVString aName, USVString aPriority, CSSStyleValue aValue)
        :mName(aName), mPriority(aPriority), mValue(aValue)
    {}

}
