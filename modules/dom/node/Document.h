#pragma once

#include "../../html/element/collection/HTMLCollection.h"
#include "../../window/Location.h"
#include "../../cssom/style/StyleSheetList.h"
#include "../../cssom/misc/CaretPosition.h"
#include "../../html/DocumentAndElementEventHandlers.h"
#include "../event/GlobalEventHandlers.h"
#include "../DOMImplementation.h"
#include "DocumentFragment.h"
#include "DocumentType.h"
#include "../range/Range.h"
#include "Node.h"

namespace Newtoo
{

    class ProcessingInstruction;
    class Element;
    class Comment;
    class Window;
    class Attr;
    class Text;

    class HTMLElement;
    class HTMLOrSVGScriptElement;

    class Document : public Node, public GlobalEventHandlers, public DocumentAndElementEventHandlers
    {
    public:
        Document();

        DOMImplementation implementation()         { return DOMImplementation(); }

        Node* cloneNode(bool deep = false);

        DOMString nodeName() override;

        USVString URL() const                       { return mURL; }
        USVString documentURI() const               { return mDocumentURI; }
        USVString origin() const                    { return mOrigin; }
        DOMString compatMode() const                { return mCompatMode; }
        DOMString characterSet() const              { return mCharacterSet; }
        DOMString charset() const /* alias */       { return characterSet(); }
        DOMString inputEncoding() const /* alias */ { return characterSet(); }
        DOMString contentType() const               { return mContentType; }

        DocumentType* doctype();
        Element* documentElement();

        HTMLCollection getElementsByTagName(DOMString localName);
        HTMLCollection getElementsByTagNameNS(DOMString aNamespace, DOMString localName);
        HTMLCollection getElementsByClassName(DOMString classNames);

        Element* getElementById(DOMString aId);

        static Element* createElement(DOMString localName/*, ElementCreationOptions options*/);
        static Element* createElementNS(DOMString aNamespace, DOMString qualifiedName/*, ElementCreationOptions options*/);

        static DocumentFragment* createDocumentFragment();
        static Text* createTextNode(DOMString data);
        static Comment* createComment(DOMString data);
        static ProcessingInstruction* createProcessingInstruction(DOMString target/*, DOMString data*/);

        Node* importNode(Node* node, bool deep = false);
        Node* adoptNode(Node* node); // оно работает не по стандартам

        static Attr* createAttribute(DOMString localName);
        static Attr* createAttributeNS(DOMString aNamespace, DOMString qualifiedName);

        static Event* createEvent(DOMString interface);

        static Range* createRange();

        // NodeFilter.SHOW_ALL = 0xFFFFFFFF
        //NodeIterator createNodeIterator(Node* root, unsigned long whatToShow = 0xFFFFFFFF,
        //                                NodeFilter* filter = 0);
        //TreeWalker createTreeWalker(Node* root, unsigned long whatToShow = 0xFFFFFFFF,
        //                            NodeFilter* filter = 0);

        Location& location()                        { return mLocation; }

        USVString domain()                          { return mDomain; }
        void setDomain(USVString aDomain)           { mDomain = aDomain; }

        USVString referrer()                        { return mReferrer; }

        USVString cookie()                          { return mCookie; }
        void setCookie(USVString aCookie)           { mCookie = aCookie; }

        DOMString lastModified()                    { return mLastModified; }

        enum DocumentReadyState
        {
            loading, interactive, complete
        };

        DocumentReadyState readyState()            { return mReadyState; }

        //getter object (DOMString name);

        DOMString title()                           { return mTitle; }
        void setTitle(DOMString aTitle);

        DOMString dir()                             { return mDir; }
        void setDir(DOMString aDir);

        HTMLElement* body();
        HTMLElement* head();

        HTMLCollection images();
        HTMLCollection embeds();
        //HTMLCollection plugins();
        HTMLCollection links();
        HTMLCollection forms();
        HTMLCollection scripts();

        HTMLCollection getElementsByName(DOMString elementName);
        HTMLOrSVGScriptElement* currentScript();

        // динамические вставки html кода
        Document* open(DOMString type = "text/html", DOMString replace = "");
        Window* open(DOMString url, DOMString name, DOMString features, bool replace = false);

        void close() {}

        void write(DOMString text);
        void writeln(DOMString text);

        // взаимодействие пользователя
        Window* defaultView()                       { return mDefaultView; }
        Element* activeElement();
        bool hasFocus() { return true; }

        DOMString designMode()                      { return mDesignMode; }
        void setDesignMode(DOMString aDesignMode)   { mDesignMode = aDesignMode; }

        bool execCommand(DOMString commandId, bool showUI = false, DOMString value = "");

        bool queryCommandEnabled(DOMString commandId);
        bool queryCommandIndeterm(DOMString commandId);
        bool queryCommandState(DOMString commandId);
        bool queryCommandSupported(DOMString commandId);
        DOMString queryCommandValue(DOMString commandId);

        EventHandler& onreadystatechange()          { return mOnreadystatechange; }
        void setOnreadystatechange(EventHandler fn) { mOnreadystatechange = fn; }

        //из стандарта CSSOM и CSSOM View

        StyleSheetList& styleSheets()               { return mStyleSheets; }

        Element* elementFromPoint(double x, double y);
        std::vector<Element> elementsFromPoint(double x, double y);
        CaretPosition* caretPositionFromPoint(double x, double y);
        Element* scrollingElement();

        Document(Document& reference, bool deep)
            :Node(reference, deep),
             mURL(reference.mURL),
             mDocumentURI(reference.mDocumentURI),
             mOrigin(reference.mOrigin),
             mCompatMode(reference.mCompatMode),
             mCharacterSet(reference.mCharacterSet),
             mContentType(reference.mContentType),
             mLocation(reference.mLocation),
             mDomain(reference.mDomain),
             mReferrer(reference.mReferrer),
             mCookie(reference.mCookie),
             mLastModified(reference.mLastModified),
             mReadyState(reference.mReadyState),
             mTitle(reference.mTitle),
             mDir(reference.mDir),
             mDefaultView(reference.mDefaultView),
             mDesignMode(reference.mDesignMode),
             mStyleSheets(reference.mStyleSheets)
        {}

    protected:

        USVString mURL;
        USVString mDocumentURI;
        USVString mOrigin;
        DOMString mCompatMode;
        DOMString mCharacterSet;
        DOMString mContentType;

        Location mLocation;
        USVString mDomain;
        USVString mReferrer;
        USVString mCookie;
        DOMString mLastModified;
        DocumentReadyState mReadyState;

        DOMString mTitle;
        DOMString mDir;

        Window* mDefaultView;

        DOMString mDesignMode;

        EventHandler mOnreadystatechange;

        StyleSheetList mStyleSheets;
    };

}
