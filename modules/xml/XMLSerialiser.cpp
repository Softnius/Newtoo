#include "XMLSerialiser.h"
#include "../assembly/HTMLSerializer.h"

namespace Newtoo
{

    DOMString XMLSerialiser::serializeToString(Node* root)
    {
        HTMLSerializerNodeSequence list;
        list.push_back(root);

        return HTMLSerializer::serializeToString(list);
    }

}
