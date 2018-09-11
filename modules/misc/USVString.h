#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#define USVString_CHAR char
#define USVString_NUMERIC long

//#pragma warning(disable : 4996)

#define m_check_temporary  \
if (str.m_delete)		   \
delete &str

#define m_check_temporary_str(obj)  \
if (obj.m_delete)					\
delete &obj

namespace Newtoo
{

    struct USVString
    {
    private:

        inline void m_realloc()
        {
            data = (USVString_CHAR*)realloc(data, m_length);
        }

        bool m_delete;
        USVString_NUMERIC m_length;
        USVString_CHAR* data;

    public:

        USVString()
        {
            m_length = 0;
            m_delete = false;
            data = (USVString_CHAR*)malloc(1);
            data[0] = '\0';
        }
        USVString(const char str[])
        {
            m_length = strlen(str) + 1;
            m_delete = false;
            data = (USVString_CHAR*)malloc(m_length);
            strcpy(data, str);
        }
        USVString(const char str)
        {
            m_length = 2;
            m_delete = true;
            data = (USVString_CHAR*)malloc(2);
            data[0] = str;
            data[1] = '\0';
        }
        USVString(const USVString& str)
        {
            m_length = str.m_length;
            m_delete = false;
            data = (USVString_CHAR*)malloc(m_length);
            strcpy(data, str.data);
            m_check_temporary;
        }
        USVString(USVString_NUMERIC len, bool del)
        {
            m_length = len;
            m_delete = del;
            data = (USVString_CHAR*)malloc(m_length);
        }
        ~USVString()
        {
            free(data);
        }

        inline USVString_CHAR& operator [](const USVString_NUMERIC index)
        {
            return data[index];
        }
        inline void operator +=(USVString& str)
        {
            *this = this->append_(str);
        }
        inline void operator +=(const char str[])
        {
            *this = this->append_(str);
        }
        inline void operator =(const USVString& str)
        {
            if(str.m_length != 0)
            {
                m_length = str.m_length;
                this->m_realloc();
                strcpy(this->data, str.data);
            } else
            {
                m_length = 1;
                this->m_realloc();
                data[0] = '\0';
            }
            m_check_temporary;
        }
        inline void operator =(const char str[])
        {
            m_length = strlen(str) + 1;
            this->m_realloc();
            strcpy(this->data, str);
            this->data[m_length - 1] = 0;
        }
        inline bool operator ==(const char str[])
        {
            return this->equals(str);
        }
        inline bool operator ==(const USVString& str)
        {
            return this->equals(str);
        }
        inline bool operator !=(const char str[])
        {
            return this->equals(str) == false;
        }
        inline bool operator !=(const USVString& str)
        {
            return this->equals(str) == false;
        }
        inline USVString& operator +(USVString& str)
        {
            return this->concat(str);
        }
        inline USVString& operator +(const char str[])
        {
            return this->concat(str);
        }
        inline USVString_CHAR& at(const USVString_NUMERIC index)
        {
            return data[index];
        }
        inline USVString_CHAR& item(const USVString_NUMERIC index)
        {
            return data[index];
        }
        inline bool equals(const USVString& str)
        {
            bool ret = this->equals(str.data);
            m_check_temporary;
            return ret;
        }
        inline bool equals(const char str[])
        {
            if((int)strlen(str) != (int)m_length - 1)
                return false;

            for (USVString_NUMERIC i = 0; i < m_length - 1; i++)
            {
                if (data[i] != str[i])
                {
                    return false;
                    break;
                }
            }
            return true;
        }
        inline USVString& toLower()
        {
            USVString & a_str = *this->dublicate();
            for (USVString_NUMERIC i = 0; i < m_length - 1; i++)
            {
                a_str[i] = tolower(a_str[i]);
            }
            return a_str;
        }
        inline USVString& toUpper()
        {
            USVString & a_str = *this->dublicate();
            for (USVString_NUMERIC i = 0; i < m_length - 1; i++)
            {
                a_str[i] = toupper(a_str[i]);
            }
            return a_str;
        }
        inline USVString* dublicate()
        {
            USVString * a_str = new USVString(m_length, true);
            strcpy(a_str->data, this->data);
            return a_str;
        }
        inline USVString& concat(USVString& str)
        {
            USVString& a_str = this->concat(str.data);
            m_check_temporary;
            return a_str;
        }
        inline USVString& concat(const char str[])
        {
            unsigned USVString_NUMERIC len = m_length;
            USVString * a_str = new USVString(len + strlen(str), true);
            strcpy(a_str->data, this->data);
            strcpy(&a_str->data[len - 1], str);
            a_str->data[a_str->m_length - 1] = 0;
            return *a_str;
        }
        inline USVString& append_(const USVString& str)
        {
            return this->append(str);
        }
        inline USVString& append_(const char str[])
        {
            return this->append(str);
        }
        inline USVString& append(const USVString& str)
        {
            USVString& ret = this->append(str.data);
            m_check_temporary;
            return ret;
        }
        inline USVString& append(const char str[])
        {
            const USVString_NUMERIC len = strlen(str);
            USVString* s = new USVString(m_length+len, true);
            strcpy(s->data, this->data);
            strcpy(s->data + m_length - 1, str);
            return *s;
        }
        inline void prependCharToThis(const char str)
        {
            if(!empty())
            {
                USVString buff = this->data;
                m_length += 1;
                this->m_realloc();
                strcpy(this->data + 1, buff.raw());
                this->data[m_length - 1] = 0;
                this->data[0] = str;
            } else
            {
                m_length = 2;
                data = (USVString_CHAR*)malloc(m_length);//this->m_realloc();
                this->data[0] = str;
                this->data[1] = '\0';
            }
        }
        inline USVString& substring(const USVString_NUMERIC index, const USVString_NUMERIC length)
        {
            USVString * a_str = new USVString(length + 1, true);
            strncpy(a_str->data, data + index, length);
            a_str->data[length] = '\0';
            return *a_str;
        }
        inline USVString& cut(const USVString_NUMERIC index, const USVString_NUMERIC length)
        {
            return this->erase(index, length);
        }
        inline USVString& erase(const USVString_NUMERIC index, const USVString_NUMERIC length)
        {
            USVString * a_str = new USVString(m_length - length, true);
            strcpy(a_str->data, this->substring(0, index).data);
            strcpy(&a_str->data[index], this->substring(index + length, this->length() - index - length).data);
            a_str->data[a_str->m_length - 1] = '\0';
            return *a_str;
        }
        inline USVString& replace(USVString& str1, USVString& str2)
        {
            USVString& ret = this->replace(this->indexOf(str1), str1.length(), str2);
            m_check_temporary_str(str1);
            m_check_temporary_str(str2);
            return ret;
        }
        inline USVString& replace(const char str1[], USVString& str2)
        {
            USVString& ret = this->replace(this->indexOf(str1), strlen(str1), str2);
            m_check_temporary_str(str2);
            return ret;
        }
        inline USVString& replace(USVString& str1, const char str2[])
        {
            USVString& ret = this->replace(this->indexOf(str1), str1.length(), str2);
            m_check_temporary_str(str1);
            return ret;
        }
        inline USVString& replace(const char str1[], const char str2[])
        {
            return this->replace(this->indexOf(str1), strlen(str1), str2);
        }
        inline USVString& replace(const USVString_NUMERIC index, const USVString_NUMERIC length, USVString& str)
        {
            USVString& ret = this->replace(index, length, str.data);
            m_check_temporary;
            return ret;
        }
        inline USVString& replace(const USVString_NUMERIC index, const USVString_NUMERIC length, const char str[])
        {
            USVString_NUMERIC str_len = strlen(str);
            USVString * a_str = new USVString(m_length - length + str_len, true);
            strcpy(a_str->data, this->substring(0, index).data);
            strcpy(&a_str->data[index], str);
            strcpy(&a_str->data[index + str_len], this->substring(index + length, this->length() - index - length).data);
            a_str->data[a_str->m_length - 1] = '\0';
            return *a_str;
        }
        inline bool startsWith(USVString& str)
        {
            bool ret = str.equals(this->substring(0, str.length()));
            m_check_temporary;
            return ret;
        }
        inline bool startsWith(const char str[])
        {
            return this->substring(0, strlen(str)) == str;
        }
        inline bool endsWith(USVString& str)
        {
            bool ret = str.equals(this->substring(this->length() - str.length(), str.length()));
            m_check_temporary;
            return ret;
        }
        inline bool endsWith(const char str[])
        {
            USVString_NUMERIC str_len = strlen(str);
            return this->substring(this->length() - str_len, str_len) == str;
        }
        inline bool startsWithChar(const char chr)
        {
            return data[0] == chr;
        }
        inline bool endsWithChar(const char chr)
        {
            return data[m_length - 2] == chr;
        }
        inline USVString_NUMERIC indexOf(USVString& str)
        {
            USVString_NUMERIC ret = this->indexOf(str.data);
            m_check_temporary;
            return ret;
        }
        inline USVString_NUMERIC indexOf(const char str[])
        {
            const char * ptr = strstr(this->data, str);
            USVString_NUMERIC index = ptr - data;
            return index;
        }
        inline USVString_NUMERIC indexOfChar(const char str, USVString_NUMERIC startsAt)
        {
            const char * ptr = strchr(this->data+startsAt, str);
            USVString_NUMERIC index = ptr - data;
            return index;
        }

#ifdef n2SearchSubstringResult_H_

        inline SearchsubstringResult resultOfCharSearch(const char str, USVString_NUMERIC startsAt)
        {
            const char * ptr = strchr(this->data+startsAt, str);
            SearchsubstringResult_NUMERIC index = 0;
            bool found = false;
            if(ptr != NULL)
            {
                index = ptr - data;
                found = true;
            }
            return SearchsubstringResult(index, found);
        }

#endif

        inline void* find(USVString& str)
        {
            void* ret = strstr(this->data, str.data);
            m_check_temporary;
            return ret;
        }
        inline void* find(const char str[])
        {
            return strstr(this->data, str);
        }
        inline void* findChar(const char str)
        {
            return strchr(this->data, str);
        }
        inline bool has(USVString& str)
        {
            bool ret = find(str) != NULL;
            m_check_temporary;
            return ret;
        }
        inline bool has(const char str[])
        {
            return find(str) != NULL;
        }
        inline bool contains(USVString& str)
        {
            return contains(str);
        }
        inline bool contains(const char str[])
        {
            return contains(str);
        }
        inline bool hasChar(const char str, USVString_NUMERIC startsAt)
        {
            bool ret = false;
            const char* i = strchr(this->data, str);
            if(i != NULL)
            {
                if(i - this->data >= startsAt)
                    ret = true;
            }
            return ret;
        }
        inline unsigned USVString_NUMERIC size()
        {
            return m_length - 1;
        }
        inline unsigned USVString_NUMERIC length()
        {
            return m_length - 1;
        }
        inline unsigned USVString_NUMERIC capacity()
        {
            return m_length;
        }
        inline unsigned long weight()
        {
            return m_length * sizeof(USVString_CHAR);
        }
        inline bool empty()
        {
            return m_length == 1;
        }
        inline void clear()
        {
            *this = "";
        }
        inline USVString_CHAR * raw()
        {
            return data;
        }
        inline short toShort()
        {
            return (short)strtol(data, NULL, 10);
        }
        inline int toInt()
        {
            return (int)strtol(data, NULL, 10);
        }
        inline long toLong()
        {
            return strtol(data, NULL, 10);
        }
        inline float toFloat()
        {
            return strtof(data, NULL);
        }
        inline double toDouble()
        {
            return strtod(data, NULL);
        }

    #define m_from(format)			\
    char buff[128];					\
    sprintf(buff, format, value);	\
    m_length = strlen(buff) + 1;	\
    this->m_realloc();				\
    strcpy(data, buff);				\
    data[m_length - 1] = 0

        inline void fromShort(short value)
        {
            m_from("%i");
        }
        inline void fromInt(int value)
        {
            m_from("%i");
        }
        inline void fromLong(long value)
        {
            m_from("%li");
        }
        inline void fromFloat(float value)
        {
            m_from("%f");
        }
        inline void fromDouble(double value)
        {
            m_from("%f");
        }

    #undef m_from

        inline void print()
        {
            printf(data);
        }

        unsigned long toHash()
        {
            long ret = 0;
            long multipler = 1;

            for(unsigned i = 0; i < length(); i++)
            {
                ret+= (long)data[i]*multipler;
                multipler*=10;
            }
            return ret;
        }
    };

}

#undef m_check_temporary
#undef m_check_temporary_str

