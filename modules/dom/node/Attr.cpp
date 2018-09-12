#include "Attr.h"
#include "../../html/element/HTMLElement.h"
#include "../../cssom/style/CSSStyleDeclaration.h"

namespace Newtoo
{

    // Некоторые методы перенес в Attr.h

    DOMString Attr::value()
    {
        if(mName != "style")
            return mValue;
        else
            return ownerElement()->style().cssText();
    }
    void Attr::setValue(DOMString aValue)
    {
        if(mName != "style")
            mValue = aValue;
        else
            ownerElement()->style().setCssText(aValue);
    }

    Attr::~Attr()
    {
        if(mName == "style")
            ownerElement()->style().setCssText("");
    }

}
