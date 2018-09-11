#include "DOMImplementation.h"
#include "node/DocumentType.h"
#include "node/Document.h"
#include "../html/element/HTMLElement.h"

namespace Newtoo
{

    XMLDocument* DOMImplementation::createDocument()
    {
        return createXMLDocument();
    }
    XMLDocument* DOMImplementation::createXMLDocument()
    {
        XMLDocument* ret = new Document();
        ret->appendChild(new DocumentType("html", "", ""));
        ret->appendChild(Document::createElement("html"));
        ret->childNodes().item(1)->appendChild(Document::createElement("head"));
        ret->childNodes().item(1)->appendChild(Document::createElement("body"));
        return ret;
    }
    XMLDocument* DOMImplementation::createHTMLDocument()
    {
        return createDocument();
    }
    DocumentType* DOMImplementation::createDocumentType(DOMString aName, DOMString aPublicId, DOMString aSystemId)
    {
        return new DocumentType(aName, aPublicId, aSystemId);
    }

}
