#include "ElementBuilder.h"

#include "../html/element/HTMLAddressElement.h"
#include "../html/element/HTMLAnchorElement.h"
#include "../html/element/HTMLBaseElement.h"
#include "../html/element/HTMLHeadingElement.h"
#include "../html/element/HTMLHRElement.h"
#include "../html/element/HTMLImageElement.h"
#include "../html/element/HTMLLinkElement.h"
#include "../html/element/HTMLOListElement.h"
#include "../html/element/HTMLPictureElement.h"
#include "../html/element/HTMLPreElement.h"
#include "../html/element/HTMLQuoteElement.h"
#include "../html/element/HTMLSourceElement.h"
#include "../html/element/HTMLStyleElement.h"
#include "../html/element/HTMLTitleElement.h"
#include "../html/element/HTMLUListElement.h"
#include "../html/element/HTMLIFrameElement.h"

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
            output.name = tagname.substring(splitterIndex + 1, tagname.size() - splitterIndex - 1).toLower_();
        }
        return output;
    }

    Element* ElementBuilder::createElement(DOMString name, DOMString namespaceURI)
    {
        TagNameParserOutput tagname = parseTagName(name);

        if(tagname.name == HTMLAddressElementTagName)
        {
            return new HTMLAddressElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLAnchorElementTagName)
        {
            return new HTMLAnchorElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLBaseElementTagName)
        {
            return new HTMLBaseElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLHeading1ElementTagName)
        {
            return new HTMLHeadingElement(namespaceURI, tagname.name, tagname.prefix,
                                          HTMLHeadingElement::H1);
        }
        else if(tagname.name == HTMLHeading2ElementTagName)
        {
            return new HTMLHeadingElement(namespaceURI, tagname.name, tagname.prefix,
                                          HTMLHeadingElement::H2);
        }
        else if(tagname.name == HTMLHeading3ElementTagName)
        {
            return new HTMLHeadingElement(namespaceURI, tagname.name, tagname.prefix,
                                          HTMLHeadingElement::H3);
        }
        else if(tagname.name == HTMLHeading4ElementTagName)
        {
            return new HTMLHeadingElement(namespaceURI, tagname.name, tagname.prefix,
                                          HTMLHeadingElement::H4);
        }
        else if(tagname.name == HTMLHeading5ElementTagName)
        {
            return new HTMLHeadingElement(namespaceURI, tagname.name, tagname.prefix,
                                          HTMLHeadingElement::H5);
        }
        else if(tagname.name == HTMLHeading6ElementTagName)
        {
            return new HTMLHeadingElement(namespaceURI, tagname.name, tagname.prefix,
                                          HTMLHeadingElement::H6);
        }

        else if(tagname.name == HTMLHRElementTagName)
        {
            return new HTMLHRElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLImageElementTagName or tagname.name == HTMLImageElementTagName)
        {
            return new HTMLImageElement(namespaceURI, HTMLImageElementTagName, tagname.prefix);
        }

        else if(tagname.name == HTMLLinkElementTagName)
        {
            return new HTMLLinkElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLOListElementTagName)
        {
            return new HTMLOListElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLPictureElementTagName)
        {
            return new HTMLPictureElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLQuoteElementTagName)
        {
            return new HTMLQuoteElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLSourceElementTagName)
        {
            return new HTMLSourceElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLTitleElementTagName)
        {
            return new HTMLTitleElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLUListElementTagName)
        {
            return new HTMLUListElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLDivElementTagName)
        {
            return new HTMLDivElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLBodyElementTagName)
        {
            return new HTMLBodyElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLArticleElementTagName)
        {
            return new HTMLArticleElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLSectionElementTagName)
        {
            return new HTMLSectionElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLNavElementTagName)
        {
            return new HTMLNavElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLAsideElementTagName)
        {
            return new HTMLAsideElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLHeaderElementTagName)
        {
            return new HTMLHeaderElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLDListElementTagName)
        {
            return new HTMLDListElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLDDElementTagName)
        {
            return new HTMLDDElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLDTElementTagName)
        {
            return new HTMLDTElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLFigureElementTagName)
        {
            return new HTMLFigureElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLFigCaptionElementTagName)
        {
            return new HTMLFigCaptionElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLMainElementTagName)
        {
            return new HTMLMainElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLStyleElementTagName)
        {
            return new HTMLStyleElement(namespaceURI, tagname.name, tagname.prefix);
        }

        else if(tagname.name == HTMLIFrameElementTagName)
        {
            return new HTMLIFrameElement(namespaceURI, tagname.name, tagname.prefix);
        }

        return new HTMLUnknownElement(namespaceURI, tagname.name, tagname.prefix);
    }

}
