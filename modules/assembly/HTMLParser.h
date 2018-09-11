#pragma once

#include "../dom/DOMString.h"
#include "../dom/node/Node.h"

#include <vector>

namespace Newtoo
{

    class HTMLParser
    {
    public:

        static std::vector<Node*> parseHtmlFromString(DOMString str);
    };

}
