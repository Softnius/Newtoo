#include "DOMParser.h"
#include "DOMImplementation.h"
#include "../assembly/HTMLParser.h"

namespace Newtoo
{

    Document* parseFromString(DOMString str, DOMString type)
    {
        if(type == TextHtml or type == ApplicationXhtmlXml) // HTML парсер
        {
            Document* ret = new Document();
            HTMLParserOutput output = HTMLParser::parseHtmlFromString(str);

            for(unsigned i = 0; i < output.size(); i++)
                ret->appendChild(output[i]);
            return ret;
        }
        else if(type == ImageSvgXml) // SVG парсер
        {
            return 0;
        }
        else if(type == TextXml or type == ApplicationXml) // XML парсер
        {
            return 0;
        }
        return 0;
    }

}
