#pragma once

#include "HTMLElement.h"

namespace Newtoo
{

    const unsigned long ULongLengthAuto = 2147483647;

    class HTMLImageElement : public HTMLElement
    {
    public:

        HTMLImageElement(unsigned long aWidth = ULongLengthAuto, unsigned long aHeight = ULongLengthAuto);

        Node* cloneNode(bool deep = false) override;

        DOMString alt()                                     { return getAttribute("alt"); }
        void setAlt(DOMString aAlt)                         { setAttribute("alt", aAlt); }

        DOMString src()                                     { return getAttribute("src"); }
        void setSrc(DOMString aSrc)                         { setAttribute("src", aSrc); }

        DOMString srcset()                                  { return getAttribute("srcset"); }
        void setSrcset(DOMString aSrcset)                   { setAttribute("srcset", aSrcset); }

        DOMString sizes()                                   { return getAttribute("sizes"); }
        void setSizes(DOMString aSizes)                     { setAttribute("sizes", aSizes); }

        DOMString crossOrigin()                             { return getAttribute("crossorigin"); }
        void setCrossOrigin(DOMString aCrossOrigin)         { setAttribute("crossorigin", aCrossOrigin); }

        DOMString decoding()                                { return getAttribute("decoding"); }
        void setDecoding(DOMString aDecoding)               { setAttribute("decoding", aDecoding); }

        DOMString longDesc()                                { return getAttribute("longdesc"); }
        void setLongDesc(DOMString aLongDesc)               { setAttribute("longdesc", aLongDesc); }

        bool isMap() const                                  { return false; }

        unsigned long width()                               { return getAttributeSignedLong("width"); }
        void setWidth(unsigned long aWidth)                 { setAttributeSignedLong("width", aWidth); }

        unsigned long height()                              { return getAttributeSignedLong("height"); }
        void setHeight(unsigned long aHeight)               { setAttributeSignedLong("height", aHeight); }

        unsigned long naturalWidth() const                  { return mNaturalWidth; }

        unsigned long naturalHeight() const                 { return mNaturalHeight; }

        bool complete() const                               { return mComplete; }

        DOMString currentSrc()                              { return getAttribute("currentsrc"); }
        void setCurrentSrc(DOMString aCurrentSrc)           { setAttribute("currentsrc", aCurrentSrc); }

        DOMString referrerPolicy()                          { return getAttribute("referrerpolicy"); }
        void setReferrerPolicy(DOMString aReferrerPolicy)
        { setAttribute("referrerpolicy", aReferrerPolicy); }

        HTMLImageElement(HTMLImageElement& reference, bool deep)
            :HTMLElement(reference, deep),
             mNaturalWidth(reference.mNaturalWidth),
             mNaturalHeight(reference.mNaturalHeight),
             mComplete(reference.mComplete)
        {}

    private:

        unsigned long mNaturalWidth;
        unsigned long mNaturalHeight;
        bool mComplete;
    };

}
