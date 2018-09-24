#pragma once

#include "SVGElement.h"

namespace Newtoo
{

    class DOMRect;
    class DOMMatrix;
    class SVGAnimatedTransformList;

#define SVGBoundingBoxOptions   \
bool fill = true,               \
bool stroke = false,            \
bool markers = false,           \
bool clipped = false

    class SVGGraphicsElement : public SVGElement
    {
    public:

        SVGGraphicsElement();
        SVGGraphicsElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix);

        SVGAnimatedTransformList& transform();

        DOMRect& getBBox(SVGBoundingBoxOptions);
        DOMMatrix& getCTM();
        DOMMatrix& getScreenCTM();
    };

}
