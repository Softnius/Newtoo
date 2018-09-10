#pragma once

#include "../../cssom/style/LinkStyle.h"
#include "Node.h"

namespace Newtoo
{

    class ProcessingInstruction : public Node, public LinkStyle
    {
    public:

        Node* cloneNode(bool deep = false) override;

        DOMString nodeName() override;

        ProcessingInstruction(DOMString aTarget);
        ProcessingInstruction() {}

        DOMString target() const            { return mTarget; }
        void setTarget(DOMString aTarget)   { mTarget = aTarget; }

        ProcessingInstruction(ProcessingInstruction& reference, bool deep)
            :Node(reference, deep),
             mTarget(reference.mTarget)
        {}

    private:

        DOMString mTarget;
    };

}
