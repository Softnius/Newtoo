#include "LinkStyle.h"
#include "CSSStyleSheet.h"

namespace Newtoo
{

    LinkStyle::LinkStyle()
        :mSheet(new CSSStyleSheet(0))
    {}

    LinkStyle::LinkStyle(StyleSheet* aRefStyleSheet)
        :mSheet(aRefStyleSheet->clone())
    {}

}
