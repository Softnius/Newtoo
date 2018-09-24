#include "HTMLImageElement.h"

namespace Newtoo
{

    HTMLImageElement::HTMLImageElement(unsigned long aWidth, unsigned long aHeight)
    {
        setWidth(aWidth);
        setHeight(aHeight);
    }
    HTMLImageElement::HTMLImageElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix,
                                       unsigned long aWidth, unsigned long aHeight)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {
        setWidth(aWidth);
        setHeight(aHeight);
    }

    Node* HTMLImageElement::cloneNode(bool deep)
    {
        return new HTMLImageElement(*this, deep);
    }

}
