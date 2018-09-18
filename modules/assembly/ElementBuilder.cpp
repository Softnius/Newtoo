#include "ElementBuilder.h"

#include "../html/element/HTMLImageElement.h"
#include "../html/element/HTMLStyleElement.h"

namespace Newtoo
{

#define AFTER_PREFIX_CHAR ':'

    struct TagNameParserOutput
    {
        bool hasPrefix;
        DOMString name, prefix;
    };
    TagNameParserOutput parseTagName(DOMString tagname)
    {
        TagNameParserOutput output;
        char* splitterRef = (char*)tagname.findChar(AFTER_PREFIX_CHAR);
        if(splitterRef == 0)
        {
            output.hasPrefix = false;
            output.name = tagname;
        } else
        {
            unsigned long splitterIndex = splitterRef - tagname.raw();
            output.hasPrefix = true;
            output.prefix = tagname.substring(0, splitterIndex - 1);
            output.name = tagname.substring(splitterIndex + 1, tagname.size() - splitterIndex - 1);
        }
        return output;
    }

    Element* ElementBuilder::createElement(DOMString name, DOMString namespaceURI)
    {
        TagNameParserOutput tagname = parseTagName(name);

        if(tagname.name == HTMLDivElementTagName)
        {
            return new HTMLDivElement(namespaceURI, tagname.name, tagname.prefix);
        }
        else if(tagname.name == HTMLParagraphElementTagName)
        {
            return new HTMLParagraphElement(namespaceURI, tagname.name, tagname.prefix);
        }
        else if(tagname.name == HTMLStyleElementTagName)
        {
            return new HTMLStyleElement(namespaceURI, tagname.name, tagname.prefix);
        }
        return new HTMLUnknownElement(namespaceURI, tagname.name, tagname.prefix);
    }

}
