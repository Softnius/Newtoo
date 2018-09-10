#pragma once

#include <vector>

namespace Newtoo
{

    class Node;

    class NodeList
    {
    public:

        unsigned long length() const;
        Node* item(unsigned long index);
        bool empty();

    protected:

        std::vector<Node*> mControl;
    };

}
