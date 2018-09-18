#pragma once

#include "../../exception/RaisesException.h"
#include "../Node.h"
#include "../Attr.h"

#include <vector>

namespace Newtoo
{
    class Element;

    class NamedNodeMap
    {
    public:

        NamedNodeMap(NamedNodeMap& reference, Element* newOwner);
        NamedNodeMap() {}

        unsigned long length();

        Attr* item(unsigned long index);

        Attr* setNamedItem(Attr* arg);
        Attr* setNamedItemNS(Attr* arg);

        RaisesException<Attr*> getNamedItem(DOMString name);
        RaisesException<Attr*> getNamedItemNS(DOMString namespaceURI, DOMString localName);

        RaisesException<Attr*> removeNamedItem(DOMString name);
        RaisesException<Attr*> removeNamedItemNS(DOMString namespaceURI, DOMString localName);

        void appendItem(Attr* arg);

    private:

        std::vector<Attr*> mAttrs;
    };

}
