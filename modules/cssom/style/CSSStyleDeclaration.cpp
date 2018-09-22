#include "CSSStyleDeclaration.h"

namespace Newtoo
{

    CSSStyleDeclaration::CSSStyleDeclaration()
    {

    }

    DOMString CSSStyleDeclaration::cssText()
    {
        DOMString text;

        for(unsigned i = 0; i < length(); i++)
        {
            StyleProperty prop = mStylePropertyList[i];
            text += prop.id;
            text += ":";
            text += prop.value;
            if(prop.priority == ImportantPriority)
            {
                text += " ";
                text += ImportantPriority;
            }
            text += ";";
        }

        return text;
    }

#define idx startAt

    struct IndexOfChar
    {
        unsigned long index;
        bool found;

        IndexOfChar() : index(0), found(false) {}

        inline void find(unsigned long startAt, const char target, DOMString& str)
        {
            found = false;
            while(idx < str.size())
            {
                if(str[idx] == target)
                {
                    index = idx;
                    found = true;
                    return;
                }

                idx++;
            }
        }
    };

#undef idx

#define CSS_SEPERATOR ';'
#define CSS_SPLIT ':'

    void CSSStyleDeclaration::setCssText(DOMString css, DOMString priority)
    {
        unsigned long before = 0;
        IndexOfChar splitter;
        splitter.find(0, CSS_SPLIT, css);

        while(splitter.found)
        {

            StyleProperty prop;
            prop.priority = priority;
            prop.id = css.substring(before, splitter.index - before);

            while(prop.id.has("\n"))
                prop.id = prop.id.erase(prop.id.indexOf("\n"), 1);
            while(prop.id.has(" "))
                prop.id = prop.id.erase(prop.id.indexOf(" "), 1);

            IndexOfChar seperator;
            seperator.find(splitter.index, CSS_SEPERATOR, css);

            if(seperator.found)
            {
                before = seperator.index + 1;
                splitter.find(before, CSS_SPLIT, css);

                prop.value = css.substring(splitter.index + 1, seperator.index - splitter.index - 1);

                if(prop.value.endsWith(ImportantPriority))
                {
                    prop.value = prop.value.substring(0, prop.value.length()
                                                      - sizeof(ImportantPriority));
                    prop.priority = ImportantPriority;
                }

                mStylePropertyList.push_back(prop);
            }
            else
            {
                prop.value = css.substring(splitter.index + 1, css.length() - splitter.index - 1);

                mStylePropertyList.push_back(prop);
                break;
            }
        }
    }

    unsigned long CSSStyleDeclaration::length()
    {
        return mStylePropertyList.size();
    }

    DOMString CSSStyleDeclaration::item(unsigned long index)
    {
        if(index >= length())
            return DOMString("");

        return mStylePropertyList[index].value;
    }

    DOMString CSSStyleDeclaration::getPropertyValue(DOMString property)
    {
        for(unsigned i = 0; i < length(); i++)
        {
            if(mStylePropertyList[i].id == property)
                return mStylePropertyList[i].value;
        }
        return DOMString("");
    }
    DOMString CSSStyleDeclaration::getPropertyPriority(DOMString property)
    {
        for(unsigned i = 0; i < length(); i++)
        {
            if(mStylePropertyList[i].id == property)
                return mStylePropertyList[i].priority;
        }
        return DOMString("");
    }

    void CSSStyleDeclaration::setProperty(DOMString property, DOMString value, DOMString priority)
    {
        for(unsigned i = 0; i < length(); i++)
        {
            if(mStylePropertyList[i].id == property)
            {
                mStylePropertyList[i].value = value;
                mStylePropertyList[i].priority = priority;
                return;
            }
        }
        StyleProperty prop = { property, value, priority };
        mStylePropertyList.push_back(prop);
    }
    void CSSStyleDeclaration::setPropertyValue(DOMString property, DOMString value)
    {
        for(unsigned i = 0; i < length(); i++)
        {
            if(mStylePropertyList[i].id == property)
            {
                mStylePropertyList[i].value = value;
                break;
            }
        }
    }
    void CSSStyleDeclaration::setPropertyPriority(DOMString property, DOMString priority)
    {
        for(unsigned i = 0; i < length(); i++)
        {
            if(mStylePropertyList[i].id == property)
            {
                mStylePropertyList[i].priority = priority;
                break;
            }
        }
    }
    DOMString CSSStyleDeclaration::removeProperty(DOMString property)
    {
        for(unsigned i = 0; i < length(); i++)
        {
            if(mStylePropertyList[i].id == property)
            {
                DOMString prop = mStylePropertyList[i].value;
                mStylePropertyList.erase(mStylePropertyList.begin() + i);
                return prop;
            }
        }
        return DOMString("");
    }

    DOMString CSSStyleDeclaration::cssFloat()
    {
        return getPropertyValue("float");
    }

    DOMString CSSStyleDeclaration::get(DOMString aProperty)
    {
        return getPropertyValue(aProperty.toUnderscore());
    }
    void CSSStyleDeclaration::set(DOMString aProperty, DOMString value)
    {
        setProperty(aProperty.toUnderscore(), value);
    }

}
