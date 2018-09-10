#pragma once

#include "../style/CSSStyleSheet.h"

namespace Newtoo
{

    class CSSRule
    {
    public:

        enum RuleType
        {
            STYLE_RULE = 1,
            IMPORT_RULE = 3,
            MEDIA_RULE = 4,
            FONT_FACE_RULE = 5,
            PAGE_RULE = 6,
            KEYFRAMES_RULE = 7,
            KEYFRAME_RULE = 8,
            MARGIN_RULE = 9,
            NAMESPACE_RULE = 10
        };

        CSSRule(RuleType aType, CSSRule* parent = 0);

        RuleType type() const                                   { return mType; }

        virtual CSSRule* clone();

        virtual DOMString cssText()                             { return DOMString(""); }
        virtual void setCssText(DOMString aCssText)             { aCssText.clear(); }

        CSSRule* parentRule() const                             { return mParentRule; }
        CSSStyleSheet* parentStyleSheet();

        CSSRule(CSSRule& reference)
            :mType(reference.mType),
             mParentRule(reference.mParentRule)
        {}

    protected:

        RuleType mType;
        CSSRule* mParentRule;
    };

}
