#pragma once

#include "../dom/event/EventTarget.h"
#include "../dom/node/Document.h"
#include "../cssom/media/MediaQueryList.h"
#include "../cssom/misc/ScrollBehavior.h"
#include "Location.h"
#include "Console.h"
#include "History.h"

namespace Newtoo
{

    class CSSStyleDeclaration;
    class Screen;

    class Window : public EventTarget
    {
    public:
        Window();

        Console& console() const;

        Document* document();

        bool fullScreen();

        History& history();

        Location& location();

        Window* parent();
        Window* self();
        Window* top();

        void alert(DOMString message);
        void find(DOMString string);

        Range* getSelection();

        // Из стандарта CSSOM и CSSOM View

        CSSStyleDeclaration* getComputedStyle(Element * element);
        CSSStyleDeclaration* getComputedStyle(Element * element, DOMString pseudoElt);

        MediaQueryList& matchMedia(DOMString query);
        Screen& screen();

        void moveTo(long x, long y);
        void moveBy(long x, long y);
        void resizeTo(long x, long y);
        void resizeBy(long x, long y);

        long innerWidth();
        long innerHeight();

        double scrollX();
        double pageXOffset();
        double scrollY();
        double pageYOffset();
        void scroll(ScrollBehavior behavior, double left, double top);
        void scroll(double x, double y);
        void scrollTo(ScrollBehavior behavior, double left, double top);
        void scrollTo(double x, double y);
        void scrollBy(ScrollBehavior behavior, double left, double top);
        void scrollBy(double x, double y);

        long screenX();
        long screenY();
        long outerWidth();
        long outerHeight();
        double devicePixelRatio();
    };

}
