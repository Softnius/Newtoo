#pragma once

#include "Node.h"

namespace Newtoo
{

    class DocumentType : public Node
    {
    public:

        Node* cloneNode(bool deep = false) override;

        DOMString nodeName() override;

        DocumentType(DOMString aName, DOMString aPublicId, DOMString aSystemId);

        DOMString name() const              { return mName; }
        DOMString publicId() const          { return mPublicId; }
        DOMString systemId() const          { return mSystemId; }

        DocumentType(DocumentType& reference, bool deep)
            :Node(reference, deep),
             mName(reference.mName),
             mPublicId(reference.mPublicId),
             mSystemId(reference.mSystemId)
        {}

    private:

        DOMString mName;
        DOMString mPublicId;
        DOMString mSystemId;
    };

}
