#include "HTMLSerializer.h"
#include "../dom/node/DocumentType.h"
#include "../dom/node/Comment.h"
#include "../dom/node/Text.h"

namespace Newtoo
{

#define COMMENT_PREFIX "<!-- "
#define COMMENT_SUFFIX " -->"
#define DOCUMENT_TYPE_PREFIX "<!doctype "
#define TAG_BRACKET_OPEN "<"
#define TAG_BRACKET_CLOSE ">"
#define TAG_CLOSE "</"
#define WHITESPACE " "
#define VALUE_START "=\""
#define VALUE_END "\""

    DOMString HTMLSerializer::serializeToString(HTMLSerializerNodeSequence sequence)
    {
        DOMString html;

        for(unsigned i = 0; i < sequence.size(); i++)
        {
            Node* targetNode = sequence[i];
            switch(targetNode->nodeType())
            {
                case Node::TEXT_NODE:
                {
                    Text* text = (Text*)targetNode;
                    html += text->data();
                    break;
                }
                case Node::COMMENT_NODE:
                {
                    Comment* comment = (Comment*)targetNode;
                    html += COMMENT_PREFIX;
                    html += comment->data();
                    html += COMMENT_SUFFIX;
                    break;
                }
                case Node::CDATA_SECTION_NODE:
                {
                    break; // пока не работает
                }
                case Node::PROCESSING_INSTRUCTION_NODE:
                {
                    break; // пока не работает
                }
                case Node::DOCUMENT_TYPE_NODE:
                {
                    DocumentType* doctype = (DocumentType*)targetNode;
                    html += DOCUMENT_TYPE_PREFIX;
                    html += doctype->name();
                    html += TAG_BRACKET_CLOSE;
                    break;
                }
                case Node::ELEMENT_NODE:
                {
                    Element* element = (Element*)element;

                    html += TAG_BRACKET_OPEN;
                    /* Название тега */
                    html += element->tagName();

                    /* Атрибуты, если есть */
                    for(unsigned i = 0; i < element->attributes().length(); i++)
                    {
                        html += WHITESPACE;
                        html += element->attributes().item(i)->name();
                        html += VALUE_START;
                        html += element->attributes().item(i)->value();
                        html += VALUE_END;
                    }

                    html += TAG_BRACKET_CLOSE;
                    /* Внутренности элемента */

                    html += element->innerHTML();


                    /* Закрывающий тег */
                    html += TAG_CLOSE;
                    html += element->tagName();
                    html += TAG_BRACKET_CLOSE;
                }
                case Node::ATTRIBUTE_NODE:
                {
                    break; // устарел
                }
                case Node::DOCUMENT_NODE:
                {
                    break;
                }
                case Node::DOCUMENT_FRAGMENT_NODE:
                {
                    break;
                }
            } // switch
        }
        return html;
    }

}
