#pragma once

#include "../DOMString.h"

#include <vector>

namespace Newtoo
{

    class DOMTokenList
    {
    public:

        DOMTokenList(DOMString* reference);

        unsigned long length();
        DOMString* item(unsigned long index); // память утекает
        bool contains(DOMString token);
        void remove(DOMString token);
        void add(DOMString token);
        void replace(DOMString oldToken, DOMString newToken);
        void toggle(DOMString token);
        DOMString value();

        void fromString(DOMString string);

    private:

        DOMString trimWhitespaces(DOMString raw); // Удаляет все пробелы

        DOMString* mRaw;
    };

}
