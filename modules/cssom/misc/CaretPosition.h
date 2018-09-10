#pragma once

#include "../../dom/geometry/DOMRect.h"
#include "../../dom/node/Node.h"

namespace Newtoo
{

    class CaretPosition
    {
    public:

        CaretPosition(Node* aOffsetNode, unsigned long aOffset = 0);

        Node* offsetNode() const                    { return mOffsetNode; }
        unsigned long offset() const                { return mOffset; }
        DOMRect& getClientRect();

    private:

        Node* mOffsetNode;
        unsigned long mOffset;
    };

}
