#include "DOMTokenList.h"

#define WHITESPACE_CHAR " "
#define SPLIT_C ' '

namespace Newtoo
{

    DOMTokenList::DOMTokenList(DOMString* reference)
        :mRaw(reference)
    {}

    unsigned long DOMTokenList::length()
    {
        if(mRaw == 0)
            return 0;

        if(mRaw->empty())
            return 0;

        unsigned long ret = 1;
        for(unsigned i = 0; i < mRaw->size(); i++)
        {
            if(mRaw->item(i) == SPLIT_C)
                ret++;
        }
        return ret;
    }

    DOMString* DOMTokenList::item(unsigned long index)
    {
        if(mRaw == 0)
            return 0;

        unsigned long len = length();

        if(index >= len)
            return 0;

        if(len > 1)
        {
            unsigned long cindex = 0;
            unsigned long start = 0;
            unsigned long lng = 0;

            bool found = false;

            if(cindex == index)
                found = true;

            for(unsigned i = 0; i < mRaw->size(); i++)
            {
                char c = mRaw->item(i);

                if(c == SPLIT_C)
                {
                    if(!found)
                    {
                        cindex++;
                        if(cindex == index)
                            found = true;
                    } else
                    {
                        break;
                    }
                }
                if(!found)
                    start++;
                else
                    lng++;
            }

            return new DOMString(mRaw->substring(start, lng));
        }
        else
        {
            return new DOMString(*mRaw);
        }
    }

    bool DOMTokenList::contains(DOMString token)
    {
        if(mRaw == 0)
            return false;

        if(mRaw->startsWith(token))
            return true;

        DOMString noFirst = SPLIT_C;
        noFirst = noFirst.append_(token);

        if(mRaw->endsWith(noFirst))
            return true;

        if(mRaw->has(noFirst))
            return true;

        return false;
    }

    void DOMTokenList::remove(DOMString token)
    {
        if(mRaw == 0)
            return;

        if(mRaw->startsWith(token))
        {
            *mRaw = mRaw->replace(token, "");
            return;
        }

        DOMString noFirst = SPLIT_C;
        noFirst = noFirst.append_(token);

        if(mRaw->has(noFirst))
        {
            *mRaw = mRaw->replace(noFirst, "");
            return;
        }
    }
    void DOMTokenList::add(DOMString token)
    {
        if(mRaw == 0)
            return;

        DOMString tk = trimWhitespaces(token);

        if(!contains(tk)) // чтобы не было дубликатов
        {
            if(!mRaw->empty())
            {
                DOMString noFirst = SPLIT_C;
                noFirst = noFirst.append_(tk);

                *mRaw = mRaw->append_(noFirst);
            }
            else
            {
                *mRaw = mRaw->append_(tk);
            }
        }
    }
    void DOMTokenList::replace(DOMString oldToken, DOMString newToken)
    {
        if(mRaw == 0)
            return;

        if(contains(oldToken))
        {
            remove(oldToken);
            add(newToken);
        }
    }
    void DOMTokenList::toggle(DOMString token)
    {
        if(mRaw == 0)
            return;

        if(contains(token))
            remove(token);

        else add(token);
    }

    DOMString DOMTokenList::value()
    {
        if(mRaw == 0)
            return DOMString("");

        return *mRaw;
    }

    DOMString DOMTokenList::trimWhitespaces(DOMString raw)
    {
        DOMString processed = raw;

        while(processed.has(WHITESPACE_CHAR))
        {
            processed.erase(processed.indexOf(WHITESPACE_CHAR), 1);
        }

        return processed;
    }

    void DOMTokenList::fromString(DOMString string)
    {
        if(mRaw == 0)
            return;

        *mRaw = string;
    }

}
