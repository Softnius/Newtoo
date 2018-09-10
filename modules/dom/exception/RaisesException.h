#pragma once

#include "DOMException.h"

namespace Newtoo
{

    template <typename T>
    class RaisesException
    {
    public:

        bool hasException() const               { return mHasException; }

        DOMException exception() const         { return mException; }
        T& returnType()                         { return mReturnType; }

        RaisesException(DOMException exception)
            :mHasException(true), mException(exception)
        {}

        RaisesException(T returnType)
            :mHasException(false), mException(""), mReturnType(returnType)
        {}

    private:

        bool mHasException;

        //union
        //{
            DOMException mException;
            T mReturnType;
        //};
    };

    class RaisesExceptionVoid
    {
    public:

        RaisesExceptionVoid(DOMException exception);
        RaisesExceptionVoid();

        bool hasException() const               { return mHasException; }

        DOMException& exception()               { return mException; }

    private:

        bool mHasException;

        DOMException mException;
    };

}
