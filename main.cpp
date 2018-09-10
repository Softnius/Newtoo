#include <iostream>

#include "modules/dom/DOMString.h"
#include "modules/dom/node/Element.h"
#include "modules/dom/range/Range.h"
#include "modules/dom/node/Text.h"

using namespace std;

int main()
{
    Newtoo::Element el("div");

    Newtoo::Text text("This is text!");

    el.appendChild(&text);

    Newtoo::Range r;

    r.setStart(&text, 1);
    r.setEnd(&text, 3);

    r.insertNode(new Newtoo::Text("[2a]"));

    r.setStart(&text, 1);
    r.setEnd(&text, 5);

    r.deleteContents();

    r.setStart(&text, 0);
    r.setEnd(&text, 11);

    Newtoo::DOMString s = r.toString();

    el.setClassName("gaff");
    el.setId("ss");

    Newtoo::Element child("p");
    child.setId("tf");

    el.appendChild(&child);
    el.setAttribute("dirt", "a1");

    cout << child.matches(".gaff#ss[dirt='a1'] > #tf, p") << endl;

    return 0;
}
