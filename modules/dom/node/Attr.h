#pragma once

#include "../DOMString.h"

namespace Newtoo
{

    class Element;

    class Attr
    {
    public:

        Attr() {}

        // взял из Attr.cpp, т.к ругается на underfined reference
        Attr* clone(Element* newOwner)
        {
            return new Attr(*this, newOwner);
        }

        Attr(DOMString aName, DOMString aValue = "", Element* aOwnerElement = 0, DOMString aPrefix = "")
            :mName(aName), mPrefix(aPrefix), mOwnerElement(aOwnerElement), mValue(aValue)
        {}
        Attr(DOMString aNamespace, DOMString aLocalName, DOMString aValue = "", Element* aOwnerElement = 0,
             DOMString aPrefix = "")
        :mNamespaceURI(aNamespace), mLocalName(aLocalName), mPrefix(aPrefix), mOwnerElement(aOwnerElement),
          mValue(aValue)
        {}

        DOMString name() const                         { return mName; }
        DOMString namespaceURI() const                 { return mNamespaceURI; }
        DOMString localName() const                    { return mLocalName; }
        DOMString prefix() const                       { return mPrefix; }

        Element* ownerElement()                        { return mOwnerElement; }
        void setOwnerElement(Element* aOwnerElement)  { mOwnerElement = aOwnerElement; }

        bool specifed()                                { return true; }

        DOMString value();
        void setValue(DOMString aValue);

        DOMString* valueRaw()                          { return &mValue; }

        Attr(Attr& reference, Element* newOwner)
            :mName(reference.mName),
             mNamespaceURI(reference.mName),
             mLocalName(reference.mLocalName),
             mPrefix(reference.mPrefix),
             mOwnerElement(newOwner),
             mValue(reference.mValue)
        {}

        ~Attr();

    protected:

        DOMString mName;
        DOMString mNamespaceURI;
        DOMString mLocalName;
        DOMString mPrefix;

        Element* mOwnerElement;

        DOMString mValue;
    };

}
