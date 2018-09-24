#include "SVGElement.h"

namespace Newtoo
{

    SVGElement::SVGElement()
    {}
    SVGElement::SVGElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :Element(aNamespace, qualifiedName, aPrefix)
    {}

    HTMLElement::ElementKind SVGElement::getElementKind()
    {
        return ElementKind::SVGElement;
    }

}
