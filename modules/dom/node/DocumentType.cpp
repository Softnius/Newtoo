#include "DocumentType.h"

namespace Newtoo
{

    DocumentType::DocumentType(DOMString aName, DOMString aPublicId, DOMString aSystemId)
        :Node(DOCUMENT_TYPE_NODE), mName(aName), mPublicId(aPublicId), mSystemId(aSystemId)
    {}

    Node* DocumentType::cloneNode(bool deep)
    {
        return new DocumentType(*this, deep);
    }

    DOMString DocumentType::nodeName()
    {
        return mName;
    }

}
