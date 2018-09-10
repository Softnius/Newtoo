#include "StyleSheet.h"

namespace Newtoo
{

    StyleSheet::StyleSheet()
    {

    }

    StyleSheet* StyleSheet::clone()
    {
        return new StyleSheet(*this);
    }

}
