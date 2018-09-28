#pragma once

#include "../dom/node/Element.h"

namespace Newtoo
{

    const char HTMLAddressElementTagName[] = "address";
    const char HTMLAnchorElementTagName[] = "anchor";
    const char HTMLBaseElementTagName[] = "base";
    const char HTMLHeading1ElementTagName[] = "h1";
    const char HTMLHeading2ElementTagName[] = "h2";
    const char HTMLHeading3ElementTagName[] = "h3";
    const char HTMLHeading4ElementTagName[] = "h4";
    const char HTMLHeading5ElementTagName[] = "h5";
    const char HTMLHeading6ElementTagName[] = "h6";
    const char HTMLHRElementTagName[] = "hr";
    const char HTMLImageElementTagName[] = "img";
    const char HTMLImageElementTagNameAlternative[] = "image";
    const char HTMLLinkElementTagName[] = "link";
    const char HTMLOListElementTagName[] = "olist";
    const char HTMLPictureElementTagName[] = "picture";
    const char HTMLPreElementTagName[] = "pre";
    const char HTMLQuoteElementTagName[] = "qoute";
    const char HTMLSourceElementTagName[] = "source";
    const char HTMLTitleElementTagName[] = "title";
    const char HTMLUListElementTagName[] = "ulist";
    const char HTMLHeadElementTagName[] = "head";
    const char HTMLBodyElementTagName[] = "body";
    const char HTMLArticleElementTagName[] = "article";
    const char HTMLSectionElementTagName[] = "section";
    const char HTMLNavElementTagName[] = "nav";
    const char HTMLAsideElementTagName[] = "aside";
    const char HTMLHeaderElementTagName[] = "header";
    const char HTMLFooterElementTagName[] = "footer";
    const char HTMLDListElementTagName[] = "dlist";
    const char HTMLDDElementTagName[] = "dd";
    const char HTMLDTElementTagName[] = "dt";
    const char HTMLFigureElementTagName[] = "figure";
    const char HTMLFigCaptionElementTagName[] = "figcaption";
    const char HTMLMainElementTagName[] = "main";
    const char HTMLDivElementTagName[] = "div";
    const char HTMLParagraphElementTagName[] = "p";
    const char HTMLStyleElementTagName[] = "style";
    const char HTMLIFrameElementTagName[] = "iframe";

    class ElementBuilder
    {
    public:
        static Element* createElement(DOMString name, DOMString namespaceURI = "");
    };

}
