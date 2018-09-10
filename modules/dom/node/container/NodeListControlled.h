#pragma once

#include "NodeList.h"

namespace Newtoo
{

    class NodeListControlled : public NodeList
    {
    public:

        NodeListControlled(NodeList& reference, Node* parent);
        NodeListControlled() {}

        Node* insertAt(unsigned long index, Node* child);
        Node* popAt(unsigned long index);
        Node* pushBack(Node* child);
    };

}
