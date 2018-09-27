#include "HTMLHeadingElement.h"

namespace Newtoo
{

    HTMLHeadingElement::HTMLHeadingElement(Rank aRank)
        :mRank(aRank)
    {}
    HTMLHeadingElement::HTMLHeadingElement(DOMString aNamespace, DOMString qualifiedName,
                                           DOMString aPrefix, Rank aRank)
        :HTMLElement(aNamespace, qualifiedName, aPrefix), mRank(aRank)
    {}

    CSSStyleDeclaration HTMLHeadingElement::userAgentStyle()
    {
        CSSStyleDeclaration st;
        st.setProperty("display", "block", UAPropertyPriority);
        st.setProperty("font-weight", "bold", UAPropertyPriority);
        st.setProperty("margin-bottom", "0.5em", UAPropertyPriority);
        st.setProperty("margin-top", "0.5em", UAPropertyPriority);
        switch(rank())
        {
            case H1:
            {
                st.setProperty("font-size", "38px", UAPropertyPriority);
                break;
            }
            case H2:
            {
                st.setProperty("font-size", "32px", UAPropertyPriority);
                break;
            }
            case H3:
            {
                st.setProperty("font-size", "26px", UAPropertyPriority);
                break;
            }
            case H4:
            {
                st.setProperty("font-size", "22px", UAPropertyPriority);
                break;
            }
            case H5:
            {
                st.setProperty("font-size", "18px", UAPropertyPriority);
                break;
            }
            case H6:
            {
                st.setProperty("font-size", "14px", UAPropertyPriority);
                break;
            }
        }
        return st;
    }

    Node* HTMLHeadingElement::cloneNode(bool deep)
    {
        return new HTMLHeadingElement(*this, deep);
    }

}
