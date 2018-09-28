#include "CSSRule.h"
#include "CSSImportRule.h"

namespace Newtoo
{

    CSSRule::CSSRule(RuleType aType, CSSRule* parent)
        :mType(aType), mParentRule(parent)
    {}

#define OPEN_COMMENT_STR "/*"
#define CLOSE_COMMENT_STR "*/"
#define OPEN_SINGLE_COMMENT_STR "//"
#define CLOSE_SINGLE_COMMENT_STR "\n"

#define NEW_LINE "\n"

    CSSRule* CSSRule::clone()
    {
        return new CSSRule(*this);
    }

    DOMString CSSRule::cssText()
    {
        return cssComment();
    }
    void CSSRule::setCssText(DOMString aCssText)
    {
        checkForComments(aCssText);
    }

    DOMString CSSRule::cssComment()
    {
        if(hasComment())
        {
            DOMString ret = OPEN_COMMENT_STR;
            ret += mComment;
            ret += CLOSE_COMMENT_STR;
            return ret;
        } else
        {
             return DOMString("");
        }
    }
    bool CSSRule::hasComment()
    {
        return !mComment.empty();
    }

    CSSRule::CommentCheckOutput CSSRule::checkForComments(DOMString str)
    {
        CommentCheckOutput ret;

        /*
            Работает довольно медленно. Расчитываю на то,
            что комментариев в коде вообще не будет
        */

        if(str.has(OPEN_COMMENT_STR) or str.has(OPEN_SINGLE_COMMENT_STR))
        {
            ret.hasComments = true;
            while(str.has(OPEN_COMMENT_STR) and str.has(CLOSE_COMMENT_STR))
            {
                unsigned long start = str.indexOf(OPEN_COMMENT_STR);
                unsigned long end = str.indexOf(CLOSE_COMMENT_STR);

                mComment += str.substring(start + 2, end - start - 2) + NEW_LINE;
                str.eraseThis(start, end - start + 2);
            };
            while(str.has(OPEN_SINGLE_COMMENT_STR) and str.has(CLOSE_SINGLE_COMMENT_STR))
            {
                unsigned long start = str.indexOf(OPEN_SINGLE_COMMENT_STR);
                unsigned long end = str.indexOf(CLOSE_SINGLE_COMMENT_STR);

                mComment += str.substring(start + 2, end - start - 2);
                str.eraseThis(start, end - start);
            };
            ret.processed = str;
        } else
        {
            ret.hasComments = false;
        }
        return ret;
    }

    CSSStyleSheet* CSSRule::parentStyleSheet()
    {
        if(mParentRule->type() == RuleType::IMPORT_RULE)
        {
            CSSImportRule* i = (CSSImportRule*)mParentRule;
            return &i->styleSheet();
        }

        return 0;
    }

}
