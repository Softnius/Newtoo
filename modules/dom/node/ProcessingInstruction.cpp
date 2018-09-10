#include "ProcessingInstruction.h"

namespace Newtoo
{

    ProcessingInstruction::ProcessingInstruction(DOMString aTarget)
        :Node(PROCESSING_INSTRUCTION_NODE), mTarget(aTarget)
    {}

    Node* ProcessingInstruction::cloneNode(bool deep)
    {
        return new ProcessingInstruction(*this, deep);
    }

    DOMString ProcessingInstruction::nodeName()
    {
        return mTarget;
    }

}
