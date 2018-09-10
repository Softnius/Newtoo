#include "Comment.h"

namespace Newtoo
{

    Comment::Comment(DOMString aData)
    {
        appendData(aData);
    }

    Node* Comment::cloneNode(bool deep)
    {
        return new Comment(*this, deep);
    }

    DOMString Comment::nodeName()
    {
        return DOMString("#comment");
    }

}
