#pragma once

#include "CharacterData.h"

namespace Newtoo
{

    class Text : public CharacterData
    {
    public:

        Node* cloneNode(bool deep = false) override;

        DOMString nodeName() override;

        bool hasTextValue() override final;

        Text(DOMString aData);

        RaisesException<Text*> splitText(unsigned long offset);
        DOMString wholeText(); // незавершенный метод

        Text(Text& reference, bool deep)
            :CharacterData(reference, deep)
        {}

        Text() {}
    };

}
