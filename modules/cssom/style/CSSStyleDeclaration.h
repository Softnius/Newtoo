#pragma once

#include "../../dom/DOMString.h"
#include "../CSSOMString.h"

#include <vector>

namespace Newtoo
{

    class CSSRule;

    const char ImportantPriority[] = "!important";
    const char InlinePriority[] = "1000";

    class CSSStyleDeclaration
    {
    public:

        CSSStyleDeclaration();

        struct StyleProperty
        {
            CSSOMString id, value, priority;
        };

        DOMString cssText();
        void setCssText(DOMString css, DOMString priority = InlinePriority);
        unsigned long length();
        DOMString item(unsigned long index);
        DOMString getPropertyValue(DOMString property);
        DOMString getPropertyPriority(DOMString property);
        void setProperty(DOMString property, DOMString value, DOMString priority = "");
        void setPropertyValue(DOMString property, DOMString value);
        void setPropertyPriority(DOMString property, DOMString priority);
        DOMString removeProperty(DOMString property);
        CSSRule* parentRule() const                         { return mParentRule; }
        DOMString cssFloat();

        /* эти функции кстати превращают aProperty из CamelCase в snake_case (или underscore) */
        DOMString get(DOMString aProperty);
        void set(DOMString aProperty, DOMString value);

        CSSStyleDeclaration(CSSStyleDeclaration& reference, CSSRule* newParent)
            :mParentRule(newParent)
        {
            for(unsigned i = 0; i < reference.length(); i++)
                mStylePropertyList.push_back(reference.mStylePropertyList[i]);
        }

    private:

        std::vector<StyleProperty> mStylePropertyList;

        CSSRule* mParentRule;
    };

}
