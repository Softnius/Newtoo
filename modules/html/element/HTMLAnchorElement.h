#pragma once

#include "HTMLElement.h"
#include "../../cssom/style/StyleSheet.h"

namespace Newtoo
{

    class HTMLAnchorElement : public HTMLElement
    {
    public:

        HTMLAnchorElement();
        HTMLAnchorElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix = "");

        Node* cloneNode(bool deep = false) override;

        DOMString target()                                  { return getAttribute("target"); }
        void setTarget(DOMString aTarget)                   { setAttribute("target", aTarget); }

        DOMString download()                                { return getAttribute("download"); }
        void setDownload(DOMString aDownload)               { setAttribute("download", aDownload); }

        DOMString rel()                                     { return getAttribute("rel"); }
        void setRel(DOMString aRel)                         { setAttribute("rel", aRel); }

        DOMString rev()                                     { return getAttribute("rev"); }
        void setRev(DOMString aRev)                         { setAttribute("rev", aRev); }

        DOMTokenList relList()                              { return reflectTo("rel"); }

        DOMString hreflang()                                { return getAttribute("hreflang"); }
        void setHreflang(DOMString aHreflang)               { setAttribute("hreflang", aHreflang); }

        DOMString type()                                    { return getAttribute("type"); }
        void setType(DOMString aType)                       { setAttribute("type", aType); }

        DOMString text()                                    { return getAttribute("text"); }
        void setText(DOMString aText)                       { setAttribute("text", aText); }

        DOMString referrerPolicy()                          { return getAttribute("referrerpolicy"); }
        void setReferrerPolicy(DOMString aReferrerPolicy)
        { setAttribute("referrerpolicy", aReferrerPolicy); }

        HTMLAnchorElement(HTMLAnchorElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}

    private:

    };

}
