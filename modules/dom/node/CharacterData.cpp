#include "CharacterData.h"
#include "../exception/DOMException.h"

namespace Newtoo
{

    Node* CharacterData::cloneNode(bool deep)
    {
        return new CharacterData(*this, deep);
    }

    DOMString CharacterData::nodeName()
    {
        return DOMString("#character-data");
    }

    DOMString CharacterData::nodeValue()
    {
        return mData;
    }
    DOMString CharacterData::textContent()
    {
        return mData;
    }

    void CharacterData::setNodeValue(DOMString aPlainText)
    {
        mData = aPlainText;
    }
    void CharacterData::setTextContent(DOMString aPlainText)
    {
        mData = aPlainText;
    }

    CharacterData::CharacterData(DOMString aData)
        :Node(TEXT_NODE), mData(aData)
    {}

    unsigned long CharacterData::length()
    {
        return mData.length();
    }

    RaisesException<DOMString> CharacterData::substringData(unsigned long offset, unsigned long count)
    {
        if(offset + count <= mData.length())
        {
            return RaisesException<DOMString>(DOMString(mData.substring(offset, count)));
        }
        else return RaisesException<DOMString>(DOMException(IndexSizeError));
    }

    RaisesExceptionVoid CharacterData::appendData(DOMString arg)
    {
        mData = mData.concat(arg);

        return RaisesExceptionVoid();
    }
    RaisesExceptionVoid CharacterData::insertData(unsigned long offset, DOMString arg)
    {
        if(offset < mData.length())
        {
            DOMString str = mData.substring(0, offset); // начало

            str = str.concat(arg); // аргумент
            str = str.concat(mData.substring(offset, mData.length() - offset)); // конец

            mData = str;

            return RaisesExceptionVoid();
        }
        else return RaisesExceptionVoid(DOMException(IndexSizeError));
    }
    RaisesExceptionVoid CharacterData::deleteData(unsigned long offset, unsigned long count)
    {
        if(offset + count <= mData.length())
        {
            mData = mData.erase(offset, count);

            return RaisesExceptionVoid();
        }
        else return RaisesExceptionVoid(DOMException(IndexSizeError));
    }
    RaisesExceptionVoid CharacterData::replaceData(unsigned long offset, unsigned long count,
                                                     DOMString arg)
    {
        if(offset + count <= mData.length())
        {
            mData = mData.replace(offset, count, arg);

            return RaisesExceptionVoid();
        }
        else return RaisesExceptionVoid(DOMException(IndexSizeError));
    }
    void CharacterData::replaceData(DOMString target, DOMString arg)
    {
        mData = mData.replace(target, arg);
    }


}
