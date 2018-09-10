#pragma once

#include "../dom/node/Node.h"

namespace Newtoo
{

    class XMLSerialiser
    {
    public:

        DOMString serializeToString(Node* root);
    };

}
