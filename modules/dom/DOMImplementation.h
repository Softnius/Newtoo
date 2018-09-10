#pragma once

class DocumentType;
class HTMLDocument;
class XMLDocument;

namespace Newtoo
{

    class DOMImplementation
    {
    public:

        XMLDocument* createDocument(); /* alias */
        XMLDocument* createXMLDocument();
        DocumentType* createDocumentType();
        HTMLDocument* createHTMLDocument();
    };

}
