#pragma once
#include "../node/DocumentFragment.h"
#include "../exception/RaisesException.h"
#include "../geometry/DOMRectList.h"

namespace Newtoo
{

    class Range
    {
    public:

        Range();
        Range(Range& reference);

        Node* startContainer() const                    { return mStartContainer; }
        unsigned long startOffset() const               { return mStartOffset; }
        Node* endContainer() const                      { return mEndContainer; }
        unsigned long endOffset() const                 { return mEndOffset; }
        bool collapsed();
        Node* commonAncestorContainer() const           { return mCommonAncestorContainer; }

        void setStart(Node* node, unsigned long offset);
        void setEnd(Node* node, unsigned long offset);
        RaisesExceptionVoid setStartBefore(Node* node);
        RaisesExceptionVoid setStartAfter(Node* node);
        RaisesExceptionVoid setEndBefore(Node* node);
        RaisesExceptionVoid setEndAfter(Node* node);
        void collapse(bool toStart = false);
        void selectNode(Node* node);
        void selectNodeContents(Node* node);

        enum CompareHow
        {
            START_TO_START = 0,
            START_TO_END = 1,
            END_TO_END = 2,
            END_TO_START = 3
        };

        signed short compareBoundaryPoints(CompareHow how, Range* sourceRange);

        void deleteContents(); // пока работает только, если начало и конец на одном уровне
        DocumentFragment* extractContents(); // копирует пока только текст
        DocumentFragment* cloneContents(); // копирует пока только текст
        void insertNode(Node* node);
        void surroundContents(Node* newParent);

        Range* cloneRange();
        void detach() {} // эта функция ничего не делает

        bool isPointInRange(Node* node, unsigned long offset);
        signed short comparePoint(Node* node, unsigned long offset);

        bool intersectsNode(Node* node);

        DOMString toString();

        //Из стандарта CSSOM и CSSOM View

        std::vector<DOMRect> getClientRects();
        DOMRect getBoundingClientRect();

    private:

        void setupCommonAncestorContainer();

        void setStartQuickly(Node* node, unsigned long offset);
        void setEndQuickly(Node* node, unsigned long offset);

        Node* mStartContainer;
        unsigned long mStartOffset;
        Node* mEndContainer;
        unsigned long mEndOffset;
        Node* mCommonAncestorContainer;
    };

}
