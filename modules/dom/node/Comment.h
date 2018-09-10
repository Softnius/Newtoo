#pragma once

#include "CharacterData.h"

namespace Newtoo
{

    class Comment : public CharacterData
    {
    public:

        Node* cloneNode(bool deep = false) override;

        DOMString nodeName() override;

        Comment(DOMString aData);

        Comment(Comment& reference, bool deep)
            :CharacterData(reference, deep)
        {
            mNodeType = COMMENT_NODE;
        }
    };

}
