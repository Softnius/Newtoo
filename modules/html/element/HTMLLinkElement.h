#pragma once

#include "HTMLElement.h"
#include "../../cssom/style/StyleSheet.h"

namespace Newtoo
{

    class HTMLLinkElement : public HTMLElement
    {
    public:

        HTMLLinkElement();
        HTMLLinkElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix = "");

        Node* cloneNode(bool deep = false) override;

        USVString href()                                    { return getAttribute("href"); }
        void setHref(USVString aHref)                       { setAttribute("href", aHref); }

        DOMString rel()                                     { return getAttribute("rel"); }
        void setRel(DOMString aRel)                         { setAttribute("rel", aRel); }

        DOMString rev()                                     { return getAttribute("rev"); }
        void setRev(DOMString aRev)                         { setAttribute("rev", aRev); }

        DOMString as()                                      { return getAttribute("as"); }
        void setAs(DOMString aAs)                           { setAttribute("as", aAs); }

        DOMTokenList relList()                              { return reflectTo("rel"); }

        DOMString media()                                   { return getAttribute("media"); }
        void setMedia(DOMString aMedia)                     { setAttribute("media", aMedia); }

        DOMString hreflang()                                { return getAttribute("hreflang"); }
        void setHreflang(DOMString aHreflang)               { setAttribute("hreflang", aHreflang); }

        DOMString type()                                    { return getAttribute("type"); }
        void setType(DOMString aType)                       { setAttribute("type", aType); }

        DOMTokenList sizes()                                { return reflectTo("sizes"); }

        DOMString referrerPolicy()                          { return getAttribute("referrerpolicy"); }
        void setReferrerPolicy(DOMString aReferrerPolicy)
        { setAttribute("referrerpolicy", aReferrerPolicy); }

        StyleSheet& sheet()                                 { return mStyleSheet; }

        HTMLLinkElement(HTMLLinkElement& reference, bool deep)
            :HTMLElement(reference, deep),
             mStyleSheet(reference.mStyleSheet)
        {}

    private:

        StyleSheet mStyleSheet;
    };

}
