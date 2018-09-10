#include "Text.h"

#include "Document.h"

namespace Newtoo
{

    Text::Text(DOMString aData)
        :CharacterData(aData)
    {}

    RaisesException<Text*> Text::splitText(unsigned long offset)
    {
        if(offset < length() - 1 and offset > 0)
        {
            Text* newObject = ownerDocument()->createTextNode
                    (substringData(offset, length() - offset).returnType());

            deleteData(0, offset);

            return RaisesException<Text*>(newObject);
        }
        else return RaisesException<Text*>(DOMException(IndexSizeError));
    }
    DOMString Text::wholeText()
    {
        return data();
    }

    Node* Text::cloneNode(bool deep)
    {
        return new Text(*this, deep);
    }

    DOMString Text::nodeName()
    {
        return DOMString("#text");
    }

    bool Text::hasTextValue()
    {
        return true;
    }

}
