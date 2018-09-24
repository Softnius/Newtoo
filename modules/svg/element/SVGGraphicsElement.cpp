#include "SVGGraphicsElement.h"

namespace Newtoo
{

    SVGGraphicsElement::SVGGraphicsElement()
    {}
    SVGGraphicsElement::SVGGraphicsElement(DOMString aNamespace, DOMString qualifiedName,
                                           DOMString aPrefix)
        :SVGElement(aNamespace, qualifiedName, aPrefix)
    {}

}
