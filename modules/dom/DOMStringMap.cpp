#include "DOMStringMap.h"

namespace Newtoo
{

    DOMStringMap::DOMStringMap()
    {}

    struct PairName
    {
        PairName(DOMString name)
            :mFullname(DatasetPrefix)
        {
            mFullname = mFullname.append_(name);
        }

        DOMString& str() { return mFullname; }

    protected:
        DOMString mFullname;
    };

    DOMString DOMStringMap::get(DOMString name)
    {
        for(unsigned i = 0; i < pairs().size(); i++)
        {
            PairName fullname(name);

            if(fullname.str() == pairs()[i].name)
                return pairs().at(i).value;
        }
        return DOMString("");
    }
    void DOMStringMap::set(DOMString name, DOMString value)
    {
        for(unsigned i = 0; i < pairs().size(); i++)
        {
            PairName fullname(name);

            if(fullname.str() == pairs()[i].name)
            {
                pairs()[i].value = value;
                return;
            }
        }
        Pair p = { name, value };
        pairs().push_back(p);
    }
    void DOMStringMap::remove(DOMString name)
    {
        for(unsigned i = 0; i < pairs().size(); i++)
        {
            PairName fullname(name);

            if(fullname.str() == pairs()[i].name)
            {
                pairs().erase(pairs().begin() + i);
                break;
            }
        }
    }

}
