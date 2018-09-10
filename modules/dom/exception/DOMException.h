#pragma once

#include "../DOMString.h"

namespace Newtoo
{

    const char IndexSizeError [] = "IndexSizeError";
    const char HierarchyRequestError [] = "HierarchyRequestError";
    const char WrongDocumentError [] = "WrongDocumentError";
    const char InvalidCharacterError [] = "InvalidCharacterError";
    const char NoModificationAllowedError [] = "NoModificationAllowedError";
    const char NotFoundError [] = "NotFoundError";
    const char NotSupportedError [] = "NotSupportedError";
    const char InvalidStateError [] = "InvalidStateError";
    const char SyntaxError [] = "SyntaxError";
    const char InvalidModificationError [] = "InvalidModificationError";
    const char NamespaceError [] = "NamespaceError";
    const char InvalidAccessError [] = "InvalidAccessError";
    const char SecurityError [] = "SecurityError";
    const char NetworkError [] = "NetworkError";
    const char AbortError [] = "AbortError";
    const char URLMismatchError [] = "URLMismatchError";
    const char QuotaExceededError [] = "QuotaExceededError";
    const char TimeoutError [] = "TimeoutError";
    const char InvalidNodeTypeError [] = "InvalidNodeTypeError";
    const char DataCloneError [] = "DataCloneError";
    const char EncodingError [] = "EncodingError";
    const char NotReadableError [] = "NotReadableError";
    const char UnknownError [] = "UnknownError";
    const char ConstraintError [] = "ConstraintError";
    const char DataError [] = "DataError";
    const char TransactionInactiveError [] = "TransactionInactiveError";
    const char ReadOnlyError [] = "ReadOnlyError";
    const char VersionError [] = "VersionError";
    const char OperationError [] = "OperationError";
    const char NotAllowedError [] = "NotAllowedError";

    class DOMException
    {
    public:

        DOMException(DOMString errorName);

        DOMString name() const              { return mName; }
        DOMString message() const;

    private:

        DOMString mName;
    };

}
