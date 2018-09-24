#pragma once

#include "../../html/element/HTMLElement.h"

namespace Newtoo
{

    class SVGSVGElement;
    class SVGUseElement;

    class SVGElement : public Element, public GlobalEventHandlers, public DocumentAndElementEventHandlers
    {
    public:

        SVGElement();
        SVGElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix);

        DOMString nonce()                        { return getAttribute("nonce"); }
        void setNonce(signed long aNonce)        { setAttribute("nonce", aNonce); }

        signed long tabIndex()                      { return getAttributeSignedLong("tabindex"); }
        void setTagIndex(signed long aTabIndex)     { setAttributeSignedLong("tabindex", aTabIndex); }

        void focus();
        void blur();

        ElementKind getElementKind() override;

        SVGSVGElement* ownerSVGElement();
        SVGElement* viewportElement();
        SVGElement* correspondingElement();
        SVGUseElement* correspondingUseElement();
    };

}
