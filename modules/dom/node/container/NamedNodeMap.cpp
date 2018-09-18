#include "NamedNodeMap.h"

namespace Newtoo
{

    NamedNodeMap::NamedNodeMap(NamedNodeMap& reference, Element* newOwner)
    {
        for(unsigned i = 0; i < reference.length(); i++)
            setNamedItem(item(i)->clone(newOwner));
    }

    unsigned long NamedNodeMap::length()
    {
        return mAttrs.size();
    }

    Attr* NamedNodeMap::item(unsigned long index)
    {
        if(index < mAttrs.size())
            return mAttrs[index];
        else return 0;
    }

    Attr* NamedNodeMap::setNamedItem(Attr* arg)
    {
        for(unsigned i = 0; i < length(); i++)
        {
            if(item(i)->name() == arg->name())
            {
                mAttrs.erase(mAttrs.begin() + i);
                mAttrs.insert(mAttrs.begin() + i, arg);
                return item(i);
            }
        }
        mAttrs.push_back(arg);
        return item(length() - 1);
    }
    Attr* NamedNodeMap::setNamedItemNS(Attr* arg)
    {
        for(unsigned i = 0; i < length(); i++)
        {
            if(item(i)->namespaceURI() == arg->namespaceURI()
               and item(i)->localName() == arg->localName())
            {
                mAttrs.erase(mAttrs.begin() + i);
                mAttrs.insert(mAttrs.begin() + i, arg);
                return item(i);
            }
        }
        mAttrs.push_back(arg);
        return item(length() - 1);
    }

    RaisesException<Attr*> NamedNodeMap::getNamedItem(DOMString name)
    {
        for(unsigned i = 0; i < length(); i++)
        {
            if(item(i)->name() == name)
            {
                return RaisesException<Attr*>(item(i));
            }
        }
        return RaisesException<Attr*>(DOMException(NotFoundError));
    }
    RaisesException<Attr*> NamedNodeMap::getNamedItemNS(DOMString namespaceURI, DOMString localName)
    {
        for(unsigned i = 0; i < length(); i++)
        {
            if(item(i)->namespaceURI() == namespaceURI
               and item(i)->localName() == localName)
            {
                return RaisesException<Attr*>(item(i));
            }
        }
        return RaisesException<Attr*>(DOMException(NotFoundError));
    }

    RaisesException<Attr*> NamedNodeMap::removeNamedItem(DOMString name)
    {
        for(unsigned i = 0; i < length(); i++)
        {
            if(item(i)->name() == name)
            {
                Attr* removed = item(i);
                mAttrs.erase(mAttrs.begin() + i);
                return RaisesException<Attr*>(removed);
            }
        }
        return RaisesException<Attr*>(DOMException(NotFoundError));
    }
    RaisesException<Attr*> NamedNodeMap::removeNamedItemNS(DOMString namespaceURI, DOMString localName)
    {
        for(unsigned i = 0; i < length(); i++)
        {
            if(item(i)->namespaceURI() == namespaceURI
               and item(i)->localName() == localName)
            {
                Attr* removed = item(i);
                mAttrs.erase(mAttrs.begin() + i);
                return RaisesException<Attr*>(removed);
            }
        }
        return RaisesException<Attr*>(DOMException(NotFoundError));
    }
    void NamedNodeMap::appendItem(Attr* arg)
    {
        mAttrs.push_back(arg);
    }

}
