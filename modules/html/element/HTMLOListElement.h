#pragma once

#include "HTMLElement.h"

namespace Newtoo
{

    class HTMLOListElement : public HTMLElement
    {
    public:

        HTMLOListElement();

        Node* cloneNode(bool deep = false) override;

        bool reserved()                                 { return getAttributeBool("reserved"); }
        void setReserved(bool aReserved)                { setAttributeBool("reserved", aReserved); }

        signed long start()                             { return getAttributeSignedLong("start"); }
        void setStart(signed long aStart)               { setAttributeSignedLong("start", aStart); }

        DOMString type()                                { return getAttribute("type"); }
        void setType(DOMString aType)                   { setAttribute("type", aType); }

        HTMLOListElement(HTMLOListElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}

    private:

    };

}
