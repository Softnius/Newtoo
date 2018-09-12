#pragma once

#include "../html/element/HTMLElement.h"

namespace Newtoo
{

    typedef std::vector<Node*> HTMLSerializerNodeSequence;

    class HTMLSerializer
    {
    public:

        static DOMString serializeToString(HTMLSerializerNodeSequence sequence);
        /*
            HTMLElement::dataset, CDATASection и ProcessingInstruction пока не сериальзует
        */
    };

}
