#pragma once

#include "../media/MediaList.h"
#include "../../dom/node/Node.h"

namespace Newtoo
{

    class StyleSheet
    {
    public:

        StyleSheet();

        virtual StyleSheet* clone();

        DOMString type()                                    { return mType; }
        DOMString href()                                    { return mHref; }
        Node* ownerNode()                                   { return mOwnerNode; }
        StyleSheet* parentStyleSheet()                      { return mParentStyleSheet; }
        DOMString title() const                             { return mTitle; }
        MediaList& media()                                  { return mMedia; }
        bool disabled() const                               { return mDisabled; }
        void setDisabled(bool aDisabled)                    { mDisabled = aDisabled; }

        StyleSheet(StyleSheet& reference)
            :mType(reference.mType),
             mHref(reference.mHref),
             mOwnerNode(reference.mOwnerNode),
             mParentStyleSheet(reference.mParentStyleSheet),
             mTitle(reference.mTitle),
             mMedia(reference.mMedia),
             mDisabled(reference.mDisabled)
        {}

    private:

        DOMString mType;
        DOMString mHref;
        Node* mOwnerNode;
        StyleSheet* mParentStyleSheet;
        DOMString mTitle;
        MediaList mMedia;
        bool mDisabled;
    };

}
