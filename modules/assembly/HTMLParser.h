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
    };

}
