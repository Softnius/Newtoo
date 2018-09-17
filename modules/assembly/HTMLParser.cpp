#include "HTMLParser.h"
#include "../dom/node/Document.h"
#include "../dom/node/Element.h"

namespace Newtoo
{

#define CLOSE_BRACKET_CHAR '>'
#define OPEN_BRACKET_CHAR '<'
#define EQUALS_CHAR '='
#define QUOTE_CHAR '\"'
#define QUOTE_ALTERNATIVE_CHAR '\''
#define CLOSE_TAG_CHAR '/'
#define WHITESPACE_CHAR ' '

    const char CommentPrefix[] = "<!-- ";
    const char CommentSuffix[] = " -->";
    const char DoctypePrefix[] = "<!doctype ";
    const char CloseTagPrefix[] = "</";

    struct Token
    {
        enum TokenType
        {
            TAG_TOKEN,
            CLOSE_TAG_TOKEN,
            TEXT_TOKEN,
            DOCTYPE_TOKEN,
            COMMENT_TOKEN,
            MISC_TOKEN
        };
        TokenType type;

        Token(TokenType tokenType) : type(tokenType)
        {}
    };
    struct Tag : public Token
    {
        enum TagType
        {
            NORMAL,
            SINGLE,
            OPTIONAL_CLOSE_TAG
        };
        enum ParsingPhase
        {
            TagNamePhase,
            AttrNamePhase,
            AttrValuePhase
        };
        struct Pair
        {
            DOMString name, value;
        };
        typedef std::vector<Pair> PairList;

        PairList attributes;
        DOMString tagname;
        TagType tagType;

        Tag() : Token(TAG_TOKEN)
        {}
    };
    struct CloseTag : public Token
    {
        DOMString tagname;

        CloseTag() : Token(CLOSE_TAG_TOKEN)
        {}
    };
    struct Text : public Token
    {
        DOMString text;

        Text() : Token(TEXT_TOKEN)
        {}
    };
    struct Comment : public Token
    {
        DOMString text;

        Comment() : Token(COMMENT_TOKEN)
        {}
    };
    struct Doctype : public Token
    {
        DOMString name;

        Doctype() : Token(DOCTYPE_TOKEN)
        {}
    };
    struct MiscToken : public Token
    {
        DOMString data;

        MiscToken() : Token(MISC_TOKEN)
        {}
    };
    typedef std::vector<Token*> TokenList;
    typedef std::vector<Tag> Hierarchy;

    Tag::TagType tagTypeByTagName(DOMString tagname)
    {
        if(tagname == "p")
        {
            return Tag::OPTIONAL_CLOSE_TAG;
        }
        else if(tagname == "br")
        {
            return Tag::SINGLE;
        }
        else if(tagname == "hr")
        {
            return Tag::SINGLE;
        }
        else if(tagname == "img")
        {
            return Tag::SINGLE;
        }
        else if(tagname == "input")
        {
            return Tag::SINGLE;
        }
        return Tag::NORMAL;
    }
    Token::TokenType define(DOMString& str)
    {
        if(str.startsWithChar(OPEN_BRACKET_CHAR))
        {
            if(str.startsWith(CommentPrefix))
            {
                return Token::COMMENT_TOKEN;
            }
            else if(str.startsWith(DoctypePrefix))
            {
                return Token::DOCTYPE_TOKEN;
            }
            else if(str.startsWith(CloseTagPrefix))
            {
                return Token::CLOSE_TAG_TOKEN;
            }
            else
            {
                return Token::TAG_TOKEN;
            }
        } else
        {
            return Token::TEXT_TOKEN;
        }
    }
    Token* from(DOMString str)
    {
        Token::TokenType type = define(str);

        switch(type)
        {
            case Token::TEXT_TOKEN:
            {
                Text* tk = new Text();
                tk->text = str;
                return (Token*)tk;
                break;
            }
            case Token::TAG_TOKEN:
            {
                Tag* tk = new Tag();
                DOMString tagContents = str.substring(1, str.size() - 2);
                DOMString contents, attrName;
                bool inString = false;
                char quote = 0;
                Tag::ParsingPhase phase = Tag::TagNamePhase;
                for(unsigned long i = 0; i < tagContents.size(); i++)
                {
                    char c = tagContents[i];

                    switch(phase)
                    {
                        case Tag::TagNamePhase:
                        {
                            if(c == WHITESPACE_CHAR)
                            {
                                phase = Tag::AttrNamePhase;
                                tk->tagType = tagTypeByTagName(contents);
                                tk->tagname = contents;
                                contents.clear();
                            } else
                            {
                                contents += c;
                            }
                            break;
                        }
                        case Tag::AttrNamePhase:
                        {
                            if(c == EQUALS_CHAR)
                            {
                                phase = Tag::AttrValuePhase;
                                attrName = contents;
                                contents.clear();
                            }
                            else if(c != WHITESPACE_CHAR)
                            {
                                contents += c;
                            }
                            break;
                        }
                        case Tag::AttrValuePhase:
                        {
                            if(!inString)
                            {
                                if(c == WHITESPACE_CHAR)
                                {
                                    phase = Tag::AttrNamePhase;
                                    Tag::Pair attribute;
                                    attribute.name = attrName;
                                    attribute.value = contents;
                                    tk->attributes.push_back(attribute);
                                    contents.clear();
                                }
                                else if(c == QUOTE_CHAR or c == QUOTE_ALTERNATIVE_CHAR)
                                {
                                    inString = true;
                                    quote = c;
                                }
                                else
                                {
                                    contents += c;
                                }
                            } else
                            {
                                if(c == quote)
                                    inString = false;
                                else
                                {
                                    contents += c;
                                }
                            }
                            break;
                        }
                    }
                }
                if(phase == Tag::TagNamePhase)
                {
                    tk->tagType = tagTypeByTagName(contents);
                    tk->tagname = contents;
                }
                else if(phase == Tag::AttrValuePhase)
                {
                    Tag::Pair attribute;
                    attribute.name = attrName;
                    attribute.value = contents;
                    tk->attributes.push_back(attribute);
                }
                return (Token*)tk;
                break;
            }
            case Token::CLOSE_TAG_TOKEN:
            {
                CloseTag* tk = new CloseTag();
                /*
                    "</" - 2 символа
                */
                tk->tagname = str.substring(2, str.size() - 1);

                return (Token*)tk;
                break;
            }
            case Token::COMMENT_TOKEN:
            {
                Comment* tk = new Comment();
                /*
                    "<!-- " - 5 символов
                    " -->" - 4 символа (индекс length() - 4)
                */
                if(str.endsWith(CommentSuffix))
                {
                    tk->text = str.substring(5, str.size() - 4);
                }
                return (Token*)tk;
                break;
            }
            case Token::DOCTYPE_TOKEN:
            {
                Doctype* tk = new Doctype();
                /*
                    "<!doctype " - 10 символов
                */
                tk->name = str.substring(10, str.size() - 1);

                return (Token*)tk;
                break;
            }
            case Token::MISC_TOKEN:
            {
                break;
            }
        }
        return 0;
    }
    Token* fromMisc(DOMString str)
    {
        MiscToken* misc = new MiscToken();
        misc->data = str;
        return (Token*)misc;
    }
    TokenList tokenListFromString(DOMString str)
    {
        TokenList ret;

        /*
            Эта функция делит строку на токены,
            разбивая строку перед '<' и после '>'.
            Также разрешает использовать специальные
            символы внутри тегов <style>, <script> и кавычек
        */

        DOMString unlockTag;
        bool locked = false;
        DOMString left = str;
        bool inString = false;
        char quote = 0;
        unsigned i = 0;
        while(true)
        {
            unsigned long leftsize = left.size();
            if(i >= leftsize)
                break;

            char c = left[i];

            if(!locked)
            {
                if(c == OPEN_BRACKET_CHAR)
                {
                    if(i == 0)
                    {
                        if(left.startsWith("<style"))
                        {
                            unlockTag = "</style";
                            locked = true;
                        }
                        else if(left.startsWith("<script"))
                        {
                            unlockTag = "</script";
                            locked = true;
                        }
                    }
                    else
                    {
                        ret.push_back(from(left.substring(0, i - 1)));
                        left = left.substring(i, leftsize - i);
                        i = 0;
                        continue;
                    }
                }
                else if(c == CLOSE_BRACKET_CHAR and i != 0)
                {
                    ret.push_back(from(left.substring(0, i)));
                    if(i != str.size() - 1)
                    {
                        left = left.substring(i + 1, leftsize - i - 1);
                        i = 0;
                        continue;
                    }
                    else break;
                }
            }
            else
            {
                if(!inString)
                {
                    if(c == OPEN_BRACKET_CHAR)
                    {
                        bool unlock = true;
                        unsigned unlockTagLength = unlockTag.size();
                        for(unsigned i1 = 0; i1 < unlockTagLength; i1++)
                        {
                            if(left[i + i1] != unlockTag[i1])
                            {
                                unlock = false;
                                break;
                            }
                        }
                        if(unlock)
                        {
                            locked = false;

                            /*
                                ...Lorem impsum</style>_
                                               ^       ^
                                               i      next
                            */

                            unsigned long next = i + unlockTagLength;
                            if(next < str.size())
                            {
                                ret.push_back(fromMisc(left.substring(0, i)));
                                left = left.substring(i + 1, leftsize - i - 1);
                                i = 0;
                                continue;
                            }
                        }
                    }
                    else if(c == QUOTE_CHAR or c == QUOTE_ALTERNATIVE_CHAR)
                    {
                        inString = true;
                        quote = c;
                    }
                } else
                {
                    if(c == quote)
                    {
                        inString = false;
                    }
                }
            }
            i++;
        }

        return ret;
    }
    unsigned long HTMLParser::tokenListSizeFromString(DOMString str)
    {
        return tokenListFromString(str).size();
    }

    void clearList(TokenList& list)
    {
        for(unsigned i = 0; i < list.size(); i++)
            delete list[i];
    }

    HTMLParserOutput HTMLParser::parseHtmlFromString(DOMString str)
    {
        TokenList tokenList = tokenListFromString(str);
        HTMLParserOutput list;
        Hierarchy hierarchy;


        return list;
    }

#ifdef n2DEBUG
    DOMString HTMLParser::tokenInfo(DOMString tag)
    {
        DOMString ret;

        Token* tk = from(tag);

        if(tk->type == Tag::TAG_TOKEN)
        {
            Tag* t = (Tag*)tk;

            ret += "TagName: \"";
            ret += t->tagname;
            ret += "\"; ";

            ret += "TagType: ";
            if(t->tagType == Tag::NORMAL)
            {
                ret += "NORMAL";
            }
            else if(t->tagType == Tag::SINGLE)
            {
                ret += "SINGLE";
            }
            else if(t->tagType == Tag::OPTIONAL_CLOSE_TAG)
            {
                ret += "OPTIONAL_CLOSE_TAG";
            }
            ret += "; ";

            ret += "Attributes: {";
            for(unsigned i = 0; i < t->attributes.size(); i++)
            {
                ret += " ";
                ret += t->attributes[i].name;
                ret += "=\"";
                ret += t->attributes[i].value;
                ret += "\"";
            }
            ret += " };";
        }
        delete tk;

        return ret;
    }
#endif

}
