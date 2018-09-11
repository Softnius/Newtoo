#pragma once

#include "DOMString.h"

namespace Newtoo
{

    class Document;
    class DocumentType;

    typedef Document HTMLDocument;
    typedef Document XMLDocument;

    class DOMImplementation
    {
    public:

        DOMImplementation() {}

        static XMLDocument* createDocument(); /* alias */
        static XMLDocument* createXMLDocument();
        static DocumentType* createDocumentType(DOMString aName, DOMString aPublicId, DOMString aSystemId);
        static HTMLDocument* createHTMLDocument();
    };

}
