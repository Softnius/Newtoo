#include "LinkStyle.h"

namespace Newtoo
{

    LinkStyle::LinkStyle()
    {

    }

    LinkStyle::LinkStyle(StyleSheet* aRefStyleSheet)
        :mSheet(aRefStyleSheet->clone())
    {}

}
