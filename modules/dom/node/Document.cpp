#include "Document.h"
#include "DocumentFragment.h"
#include "DocumentType.h"
#include "ProcessingInstruction.h"
#include "Element.h"
#include "Comment.h"
#include "Text.h"
#include "Attr.h"
#include "../../assembly/ElementBuilder.h"
#include "../../html/element/HTMLElement.h"

namespace Newtoo
{

    Document::Document()
    {}

    Node* Document::cloneNode(bool deep)
    {
        return new Document(*this, deep);
    }

    DOMString Document::nodeName()
    {
        return DOMString("#document");
    }

    DocumentType* Document::doctype()
    {
        HTMLElement* b = body();
        if(b != 0)
        {
            for(unsigned i = 0; i < b->childNodes().length(); i++)
            {
                if(b->childNodes().item(i)->nodeType() == DOCUMENT_TYPE_NODE)
                    return (DocumentType*)b->childNodes().item(i);
            }
        }
        return 0;
    }

    Element* Document::documentElement()
    {
        return getElementByTagName("html");
    }
    SVGSVGElement* Document::rootElement()
    {
        return (SVGSVGElement*)getElementByTagName("svg");
    }

    HTMLElement* Document::body()
    {
        return (HTMLElement*)getElementByTagName("body");
    }
    HTMLElement *Document::head()
    {
        return (HTMLElement*)getElementByTagName("head");
    }
    HTMLCollection Document::images()
    {
        return HTMLCollection(&childNodes(), HTMLCollection::IMAGES);
    }
    HTMLCollection Document::embeds()
    {
        return HTMLCollection(&childNodes(), HTMLCollection::EMBEDS);
    }
    HTMLCollection Document::links()
    {
        return HTMLCollection(&childNodes(), HTMLCollection::LINKS);
    }
    HTMLCollection Document::forms()
    {
        return HTMLCollection(&childNodes(), HTMLCollection::FORMS);
    }
    HTMLCollection Document::scripts()
    {
        return HTMLCollection(&childNodes(), HTMLCollection::SCRIPTS);
    }

    HTMLCollection Document::getElementsByName(DOMString elementName)
    {
        return HTMLCollection(&childNodes(), HTMLCollection::BY_NAME, elementName);
    }

    HTMLCollection Document::getElementsByTagName(DOMString localName)
    {
        return HTMLCollection(&childNodes(), HTMLCollection::BY_TAG_NAME, localName);
    }
    HTMLCollection Document::getElementsByTagNameNS(DOMString aNamespace, DOMString localName)
    {
        return HTMLCollection(&childNodes(), HTMLCollection::BY_TAG_NAME_NS, aNamespace, localName);
    }
    HTMLCollection Document::getElementsByClassName(DOMString classNames)
    {
        return HTMLCollection(&childNodes(), HTMLCollection::BY_CLASS_NAME, classNames);
    }

    Text* Document::createTextNode(DOMString data)
    {
        return new Text(data);
    }

    Attr* Document::createAttribute(DOMString localName)
    {
        return new Attr(localName);
    }
    Attr* Document::createAttributeNS(DOMString aNamespace, DOMString qualifiedName)
    {
        return new Attr(aNamespace, qualifiedName, "");
    }

    Range* Document::createRange()
    {
        return new Range();
    }

    DocumentFragment* Document::createDocumentFragment()
    {
        return new DocumentFragment();
    }

    Comment* Document::createComment(DOMString data)
    {
        return new Comment(data);
    }

    ProcessingInstruction* Document::createProcessingInstruction(DOMString target)
    {
        return new ProcessingInstruction(target);
    }

    Element* Document::createElement(DOMString localName)
    {
        return ElementBuilder::createElement(localName);
    }
    Element* Document::createElementNS(DOMString aNamespace, DOMString qualifiedName)
    {
        return ElementBuilder::createElement(qualifiedName, aNamespace);
    }

    Node* Document::importNode(Node* node, bool deep)
    {
        return node->cloneNode(deep);
    }
    Node* Document::adoptNode(Node* node)
    {
        return node->appendChild(node);
    }

    void Document::forceRestyle()
    {
        restyle();
    }

}
