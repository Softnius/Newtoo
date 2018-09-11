#include "DOMParser.h"
#include "DOMImplementation.h"

namespace Newtoo
{

    Document* parseFromString(DOMString str, DOMString type)
    {
        if(type == TextHtml or type == ApplicationXhtmlXml) // HTML парсер
        {

        }
        else if(type == ImageSvgXml) // SVG парсер
        {

        }
        else if(type == TextXml or type == ApplicationXml) // XML парсер
        {

        }
        return 0;
    }

}
