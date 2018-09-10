#pragma once

#include "../exception/RaisesException.h"
#include "../DOMString.h"
#include "Node.h"

#include <iostream>

using namespace std;

namespace Newtoo
{

    class CharacterData : public Node
    {
    public:

        Node* cloneNode(bool deep = false) override;

        DOMString nodeName() override;

        DOMString nodeValue() override final;
        DOMString textContent() override final;

        void setNodeValue(DOMString aPlainText) override final;
        void setTextContent(DOMString aPlainText) override final;

        CharacterData(DOMString aData);

        DOMString data() const              { return mData; }
        void setData(DOMString aData)       { mData = aData; }

        RaisesException<DOMString> substringData(unsigned long offset, unsigned long count);

        RaisesExceptionVoid appendData(DOMString arg);
        RaisesExceptionVoid insertData(unsigned long offset, DOMString arg);
        RaisesExceptionVoid deleteData(unsigned long offset, unsigned long count);
        RaisesExceptionVoid replaceData(unsigned long offset, unsigned long count, DOMString arg);
        void replaceData(DOMString target, DOMString arg); // умная замена подстроки

        unsigned long length();

        CharacterData(CharacterData& reference, bool deep)
            :Node(reference, deep),
             mData(reference.mData)
        {}

        CharacterData() {}

    private:

        DOMString mData;
    };

}
