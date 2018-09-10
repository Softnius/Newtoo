#include "RaisesException.h"

namespace Newtoo
{

    RaisesExceptionVoid::RaisesExceptionVoid(DOMException exception)
        :mHasException(true), mException(exception)
    {}

    RaisesExceptionVoid::RaisesExceptionVoid()
        :mHasException(false), mException("")
    {}

}
