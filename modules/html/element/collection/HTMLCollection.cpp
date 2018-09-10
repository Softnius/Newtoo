#include "HTMLCollection.h"
#include "../../../dom/node/Element.h"

namespace Newtoo
{

    HTMLCollection::HTMLCollection(NodeList* aNodeList, Mode aMode, DOMString aArg, DOMString aArg2)
        :mArg(aArg), mArg2(aArg2), mMode(aMode), mNodeListRef(aNodeList)
    {}

    unsigned long HTMLCollection::length()
    {
        unsigned long ret = 0;

        for(unsigned i = 0; i < mNodeListRef->length(); i++)
        {
            if(mNodeListRef->item(i)->nodeType() == Node::ELEMENT_NODE)
            {
                if(acceptToCollection((Element*)mNodeListRef->item(i)))
                    ret++;
            }
        }

        return ret;
    }

    bool HTMLCollection::acceptToCollection(Element* childElement)
    {
        bool accept = true;
        switch(mMode)
        {
            case NORMAL:
                break;

            case BY_CLASS_NAME:
            {
                if(childElement->className() != mArg)
                    accept = false;
                break;
            }
            case BY_TAG_NAME:
            {
                if(childElement->localName() != mArg)
                    accept = false;
                break;
            }
            case BY_TAG_NAME_NS:
            {
            if(childElement->namespaceURI() != mArg or childElement->localName() != mArg2)
                accept = false;
            break;
            }
            case BY_NAME:
            {
                Attr* nameAttr = childElement->getAttributeNode("name");

                if(nameAttr->value() != mArg or nameAttr == 0)
                    accept = false;
                break;
            }
            case IMAGES:
            {
                if(childElement->localName() != "image" or childElement->localName() != "img")
                    accept = false;
                break;
            }
            case EMBEDS:
            {
                if(childElement->localName() != "embed")
                    accept = false;
                break;
            }
            case LINKS:
            {
                if(childElement->localName() != "a")
                    accept = false;
                break;
            }
            case FORMS:
            {
                if(childElement->localName() != "form")
                    accept = false;
                break;
            }
            case SCRIPTS:
            {
                if(childElement->localName() != "script")
                    accept = false;
                break;
            }
        }
        return accept;
    }

    Element* HTMLCollection::item(unsigned long index)
    {
        if(index < length())
        {
            unsigned long in = 0;

            for(unsigned i = 0; i < mNodeListRef->length(); i++)
            {
                Node* child = mNodeListRef->item(i);

                if(child->nodeType() == Node::ELEMENT_NODE)
                {
                    Element* childElement = (Element*)child;

                    if(acceptToCollection(childElement))
                    {
                        if(index == in)
                            return childElement;
                        in++;
                    }
                }
            }
            return 0;
        }
        else return 0;
    }
    Element* HTMLCollection::namedItem(DOMString name)
    {
        for(unsigned i = 0; i < mNodeListRef->length(); i++)
        {
            if(mNodeListRef->item(i)->nodeType() == Node::ELEMENT_NODE)
            {
                if(mNodeListRef->item(i)->nodeName() == name)
                    return (Element*)mNodeListRef->item(i);
            }
        }
        return 0;
    }

}
