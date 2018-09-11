#include "HTMLParser.h"

namespace Newtoo
{

#define CLOSE_BRACKET_CHAR '>'
#define OPEN_BRACKET_CHAR '<'
#define EQUALS_CHAR '='
#define QUOTE_CHAR '\"'
#define QUOTE_ALTERNATIVE_CHAR '\''
#define FORCE_SIGNLE_TAG_CHAR '/' // игнорируется

    std::vector<Node*> HTMLParser::parseHtmlFromString(DOMString str)
    {
        std::vector<Node*> list;

        unsigned int level = 0;
        Node* targetParent = 0;
        bool inString = false;
        char quotes = 0;

        DOMString inQuotes;

        for(unsigned i = 0; i < str.size(); i++)
        {
            char c = str[i];

            if(!inString)
            {
                if(c == QUOTE_CHAR or c == QUOTE_ALTERNATIVE_CHAR)
                {
                    inQuotes.clear();
                    inString = true;
                    quotes = c;
                }
                else if(c == OPEN_BRACKET_CHAR)
                {

                }
                else if(c == CLOSE_BRACKET_CHAR)
                {

                }
                else if(c == EQUALS_CHAR)
                {

                }
                else if(c == FORCE_SIGNLE_TAG_CHAR) {}
            }
            else
            {
                if(c == quotes)
                    inString = false;
                else
                    inQuotes = inQuotes.append_(c);
            }
        }

        return list;
    }

}
