#pragma once

#include "HTMLElement.h"

namespace Newtoo
{

    class HTMLBaseElement : public HTMLElement
    {
    public:

        HTMLBaseElement();

        Node* cloneNode(bool deep = false) override;

        DOMString href()                                { return getAttribute("href"); }
        void setHref(DOMString aHref)                   { setAttribute("href", aHref); }

        DOMString target()                              { return getAttribute("target"); }
        void setTarget(DOMString aTarget)               { setAttribute("target", aTarget); }

        HTMLBaseElement(HTMLBaseElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}

    private:

    };

}
