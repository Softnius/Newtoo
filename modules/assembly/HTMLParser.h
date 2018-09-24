#pragma once

#include "../dom/DOMString.h"
#include "../dom/node/Node.h"

#include <vector>

namespace Newtoo
{

    typedef std::vector<Node*> HTMLParserOutput;

    class HTMLParser
    {
    public:

        static HTMLParserOutput parseHtmlFromString(DOMString str);
        static HTMLParserOutput parseSvgFromString(DOMString str); // может и не нужно

        static unsigned long tokenListSizeFromString(DOMString str); // debug

#ifdef n2DEBUG
        static DOMString tokenInfo(DOMString tag); // работает только для тегов
#endif
    };

}
