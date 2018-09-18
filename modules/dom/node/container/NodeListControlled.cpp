#include "NodeListControlled.h"
#include "../Node.h"

namespace Newtoo
{

    NodeListControlled::NodeListControlled(NodeList& reference, Node* parent)
    {
        for(unsigned i = 0; i < reference.length(); i++)
            parent->appendChild(reference.item(i)->cloneNode(true));
    }

    Node* NodeListControlled::insertAt(unsigned long index, Node* child)
    {
        mControl.insert(mControl.begin() + index, child);

        return child; //mControl.at(index);
    }

    Node* NodeListControlled::popAt(unsigned long index)
    {
        Node* ret = mControl.at(index);
        mControl.erase(mControl.begin() + index);
        return ret;
    }

    Node* NodeListControlled::pushBack(Node* child)
    {
        mControl.push_back(child);

        return child; //mControl.back();
    }

}
