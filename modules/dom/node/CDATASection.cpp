#include "CDATASection.h"

namespace Newtoo
{

    CDATASection::CDATASection(DOMString text)
        :Text(text)
    {
        mNodeType = CDATA_SECTION_NODE;
    }

}
