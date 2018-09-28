#pragma once

#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>

namespace Newtoo
{

    struct USVString // вариант с std::string
    {

    private:

        std::string data_;

    public:

        USVString() {}
        USVString(const char str) : data_(std::to_string(str)) {}
        USVString(const char str[]) : data_(str) {}
        USVString(const USVString& str) : data_(str.data_) {}
        USVString(const std::string str) : data_(str) {}
        ~USVString() {}

        inline char& operator [](const unsigned long index)
        {
            return data_[index];
        }
        inline void operator +=(const USVString str)
        {
            data_ = data_ + str.data_;
        }
        inline void operator +=(const char str[])
        {
            data_ = data_ + std::string(str);
        }
        inline void operator +=(const char str)
        {
            std::string c;
            c = c + str;
            data_ = data_ + c;
        }
        inline void operator =(const USVString str)
        {
            data_ = str.data_;
        }
        inline void operator =(const char str[])
        {
            data_ = std::string(str);
        }
        inline bool operator ==(const char str[])
        {
            return this->equals(str);
        }
        inline bool operator ==(const USVString str)
        {
            return this->equals(str);
        }
        inline bool operator !=(const char str[])
        {
            return this->equals(str) == false;
        }
        inline bool operator !=(const USVString str)
        {
            return this->equals(str) == false;
        }
        inline USVString operator +(USVString str)
        {
            return this->concat(str);
        }
        inline USVString operator +(const char str[])
        {
            return this->concat(str);
        }
        inline char& at(const unsigned long index)
        {
            return data_[index];
        }
        inline char& item(const unsigned long index)
        {
            return data_[index];
        }
        inline bool equals(const USVString str)
        {
            return data_ == str.data_;
        }
        inline bool equals(const char str[])
        {
            return data_ == std::string(str);
        }
        inline USVString& toLower();
        inline USVString& toUpper();
        inline USVString* dublicate()
        {
            return new USVString(std::string(data_));
        }
        inline USVString concat(USVString str)
        {
            return USVString(data_ + str.data_);
        }
        inline USVString concat(const char str[])
        {
            return USVString(data_ + std::string(str));
        }
        inline USVString append_(const USVString str)
        {
            return this->append(str);
        }
        inline USVString append_(const char str[])
        {
            return this->append(str);
        }
        inline USVString append_(const char str)
        {
            return this->append(str);
        }
        inline USVString append(const USVString str)
        {
            return USVString(data_ + str.data_);
        }
        inline USVString append(const char str[])
        {
            return USVString(data_ + std::string(str));
        }
        inline USVString append(const char str)
        {
            std::string c = data_;
            c = c + str;
            return USVString(c);
        }
        inline void prependCharToThis(const char str)
        {
            std::string c;
            c = c + str;
            data_ = c + data_;
        }
        inline USVString substring(const unsigned long index, const unsigned long length)
        {
            return USVString(data_.substr(index, length));
        }
        inline USVString cut(const unsigned long index, const unsigned long length)
        {
            return this->erase(index, length);
        }
        inline USVString erase(const unsigned long index, const unsigned long length)
        {
            std::string ret = data_;
            ret.erase(index, length);
            return USVString(ret);
        }
        inline void eraseThis(const unsigned long index, const unsigned long length)
        {
            data_.erase(index, length);
        }
        inline USVString replace(USVString str1, USVString str2)
        {
            return data_.replace(data_.find(str1.data_), str1.data_.length(), str2.data_);
        }
        inline USVString replace(const char str1[], USVString str2)
        {
            std::string str1s = std::string(str1);
            return data_.replace(data_.find(str1s), str1s.length(), str2.data_);
        }
        inline USVString replace(USVString str1, const char str2[])
        {
            return data_.replace(data_.find(str1.data_), str1.data_.length(), std::string(str2));
        }
        inline USVString replace(const char str1[], const char str2[])
        {
            std::string str1s = std::string(str1);
            return data_.replace(data_.find(str1s), str1s.length(), std::string(str2));
        }
        inline USVString replace(const unsigned long index, const unsigned long length, USVString str)
        {
            return data_.replace(index, length, str.data_);
        }
        inline USVString replace(const unsigned long index, const unsigned long length, const char str[])
        {
            return data_.replace(index, length, std::string(str));
        }
        inline bool startsWith(USVString str)
        {
            unsigned long len = str.data_.length();
            if(len > data_.size())
                return false;
            std::string piece = data_.substr(0, len);
            return piece == str.data_;
        }
        inline bool startsWith(const char str[])
        {
            unsigned long len = strlen(str);
            if(len > data_.size())
                return false;
            std::string piece = data_.substr(0, len);
            return piece == str;
        }
        inline bool endsWith(USVString str)
        {
            unsigned long len = str.data_.length();
            if(len > data_.size())
                return false;
            std::string piece = data_.substr(data_.length() - str.data_.length(), str.data_.length());
            return piece == str.data_;
        }
        inline bool endsWith(const char str[])
        {
            unsigned long len = strlen(str);
            if(len > data_.size())
                return false;
            std::string piece = data_.substr(data_.length() - len, len);
            return piece == str;
        }
        inline bool startsWithChar(const char chr)
        {
            return data_[0] == chr;
        }
        inline bool endsWithChar(const char chr)
        {
            return data_[data_.length() - 1] == chr;
        }
        inline unsigned long indexOf(USVString str)
        {
            return data_.find(str.data_);
        }
        inline unsigned long indexOf(const char str[])
        {
            return data_.find(str);
        }
        inline unsigned long indexOfChar(const char str, unsigned long startsAt = 0)
        {
            return data_.find(str, startsAt);
        }

        inline void* find(USVString str)
        {
            void* ret = strstr(this->data_.c_str(), str.data_.c_str());
            return ret;
        }
        inline void* find(const char str[])
        {
            return strstr(this->data_.c_str(), str);
        }
        inline void* findChar(const char str)
        {
            return strchr(this->data_.c_str(), str);
        }
        inline bool has(USVString str)
        {
            return data_.find(str.data_) != std::string::npos;
        }
        inline bool has(const char str[])
        {
            return find(str) != NULL;
        }
        inline bool contains(USVString str)
        {
            return contains(str);
        }
        inline bool contains(const char str[])
        {
            return contains(str);
        }
        inline bool hasChar(const char str, unsigned long startsAt)
        {
            const char* i = strchr(this->data_.c_str(), str);
            if(i != NULL)
            {
                if(i - this->data_.c_str() >= (int)startsAt)
                    return true;
            }
            return false;
        }
        inline unsigned long size()
        {
            return data_.length();
        }
        inline unsigned long length()
        {
            return data_.length();
        }
        inline unsigned long capacity()
        {
            return data_.capacity();
        }
        inline unsigned long weight()
        {
            return data_.length() * sizeof(char);
        }
        inline bool empty()
        {
            return data_.empty();
        }
        inline void clear()
        {
            data_.clear();
        }
        inline const char * raw()
        {
            return data_.c_str();
        }
        inline USVString toLower_()
        {
            std::string ret = data_;
            std::transform(ret.begin(), ret.end(), ret.begin(), ::tolower);
            return USVString(ret);
        }
        inline short toShort()
        {
            return (short)strtol(data_.c_str(), NULL, 10);
        }
        inline int toInt()
        {
            return (int)strtol(data_.c_str(), NULL, 10);
        }
        inline long toLong()
        {
            return strtol(data_.c_str(), NULL, 10);
        }
        inline float toFloat()
        {
            return strtof(data_.c_str(), NULL);
        }
        inline double toDouble()
        {
            return strtod(data_.c_str(), NULL);
        }

        #define m_from(format)			\
        char buff[128];					\
        sprintf(buff, format, value);	\
        data_ = std::string(buff);

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
            std::cout << data_;
        }

#define UNDERSCORE_SPLIT_CHAR '_'

        inline USVString toUnderscore()
        {
            std::string c = data_;
            unsigned i = 0;
            while(true)
            {
                if(i >= c.size())
                    break;

                if(isupper(c[i]))
                {
                    char lower = tolower(c[i]);
                    std::string next = c.substr(i + 1, c.size() - i - 1);
                    c = c.substr(0, i);
                    c = c + UNDERSCORE_SPLIT_CHAR;
                    c = c + lower;
                    c = c + next;
                }
                i++;
            }
            return USVString(c);
        }
    };

}

#undef m_check_temporary
#undef m_check_temporary_str

