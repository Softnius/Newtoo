#pragma once

#include "node/Document.h"

namespace Newtoo
{

    const char TextHtml[] = "text/html";
    const char TextXml[] = "text/xml";
    const char ApplicationXml[] = "application/xml";
    const char ApplicationXhtmlXml[] = "application/xhtml+xml";
    const char ImageSvgXml[] = "image/svg+xml";

    class DOMParser
    {
    public:
        DOMParser();

        static Document* parseFromString(DOMString str, DOMString type = "text/html");
    };

}
