#include "MediaQueryListEvent.h"

namespace Newtoo
{

    MediaQueryListEvent::MediaQueryListEvent(DOMString aMedia, bool aMatches)
        :mMedia(aMedia), mMatches(aMatches)
    {}

}
