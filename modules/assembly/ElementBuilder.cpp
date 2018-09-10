#include "ElementBuilder.h"

#include "../html/element/HTMLImageElement.h"

namespace Newtoo
{

    Element* ElementBuilder::createElement(DOMString name, DOMString namespaceURI)
    {
        if(name == HTMLDivElementTagName)
        {
            return new HTMLDivElement(namespaceURI, name);
        }
        else if(name == HTMLParagraphElementTagName)
        {
            return new HTMLParagraphElement(namespaceURI, name);
        }

        return new HTMLUnknownElement(namespaceURI, name);
    }

}
