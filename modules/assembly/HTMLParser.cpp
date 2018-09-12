#include "HTMLParser.h"
#include "../dom/node/Document.h"

namespace Newtoo
{

#define CLOSE_BRACKET_CHAR '>'
#define OPEN_BRACKET_CHAR '<'
#define EQUALS_CHAR '='
#define QUOTE_CHAR '\"'
#define QUOTE_ALTERNATIVE_CHAR '\''
#define CLOSE_TAG_CHAR '/'
#define WHITESPACE_CHAR ' '

    std::vector<Node*> HTMLParser::parseHtmlFromString(DOMString str)
    {
        std::vector<Node*> list;

        Node* newNode = 0;
        unsigned long level = 0;
        bool inString = false;
        bool inBracket = false;
        bool inValue = false;
        bool inName = false;
        bool closeTag = false;
        char quotes = 0;

        DOMString text;
        DOMString inner;
        DOMString value;

        unsigned long strsize = str.size();
        for(unsigned long i = 0; i < strsize; i++)
        {
            char c = str[i];

            if(!inString)
            {

                if(c == QUOTE_CHAR || c == QUOTE_ALTERNATIVE_CHAR)
                {
                    inString = true;
                    quotes = c;
                }
                else if(c == OPEN_BRACKET_CHAR)
                {
                    if(level == 0)
                    {
                        if(!text.empty())
                        {
                            list.push_back((Node*)Document::createTextNode(text));
                        }

                        inName = true;
                        inBracket = true;
                        closeTag = true;
                    }
                }
                else if(c == CLOSE_BRACKET_CHAR)
                {
                    if(inBracket)
                    {
                        inBracket = false;
                    }
                }
                else
                {

                }

            } else
            {
                if(c == quotes)
                {
                    inString = false;
                }
            }

            if(level > 0)
                inner += c;
            else
            {
                if(inBracket)
                {
                    if(inValue)
                        value += c;
                }
                else
                    text += c;
            }

            if(i == strsize - 1 and !text.empty())
            {
                list.push_back((Node*)Document::createTextNode(text));
            }
        }

        return list;
    }

}
