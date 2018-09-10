#pragma once

#include "EventSequence.h"
#include "EventTarget.h"
#include "../DOMString.h"

/*
     Описание методов интерфейса взято с MDN

     Смотрите подробную документацию к интерфейсу Event на MDN
     https://developer.mozilla.org/ru/docs/Web/API/Event

     О MDN (https://developer.mozilla.org/ru/docs/MDN/About),
     создано помощниками Mozilla и лицензируется под CC-BY-SA 2.5
     (https://creativecommons.org/licenses/by-sa/2.5/).
*/

namespace Newtoo
{

    class Event
    {
    public:

        Event(DOMString aType, bool aBubbles = false, bool aCancelable = false);
        Event();

        DOMString type()                    { return mType; }

        /*
            Название события (без учета регистра символов).
            Только для чтения.
            Подробнее: https://developer.mozilla.org/ru/docs/Web/API/Event/type
        */

        EventTarget* target() const         { return mTarget; }

        /*
            Ссылка на целевой объект, на котором произошло событие.
            Только для чтения.
            Подробнее: https://developer.mozilla.org/ru/docs/Web/API/Event/target
        */

        EventTarget* currentTarget() const  { return mCurrentTarget; }

        /*
            Ссылка на текущий зарегистрированный объект, на котором обрабатывается событие.
            Это объект, которому планируется отправка события; поведение можно изменить с
            использованием перенаправления (retargeting).
            Только для чтения.
            Подробнее: https://developer.mozilla.org/ru/docs/Web/API/Event/currentTarget
        */

        EventSequence& composedPath()       { return mEventSequence; }

        /*
            Предположительно deepPath.
            Массив DOM-узлов, через которые всплывало событие.
            Только для чтения.
            Подробнее: https://developer.mozilla.org/ru/docs/Web/API/Event/deepPath
        */

        enum Phase
        {
            NONE = 0,               // Фаза.. спокойствия?
            CAPTURING_PHASE = 1,    // Фаза перехвата
            AT_TARGET = 2,          // Событие достигло цели
            BUBBLING_PHASE = 3      // Фаза всплытия
        };

        unsigned short eventPhase();

        /*
            Указывает фазу процесса обработки события.
            Только для чтения.
            Подробнее: https://developer.mozilla.org/ru/docs/Web/API/Event/eventPhase
        */

        void stopPropagation();

        /*
            Для конкретного события не будет больше вызвано обработчиков.
            Ни тех, которые привязаны к этому же элементу (на котором
            работает обработчик, который вызывает этот
            Event.stopImmediatePropagation()), ни других, которые могли
            бы вызваться при распространении события позже (например, в
            фазе перехвата - capture).
            Подробнее: https://developer.mozilla.org/ru/docs/Web/API/Event/stopImmediatePropagation
        */

        bool cancelBubble() const { return mCancelBubble; }
        void setCancelBubble(bool aCancelBubble)  { mCancelBubble = aCancelBubble; }

        /*
            Историческое название синонима Event.stopPropagation().
            Если установить знаение в true до возврата из
            обработчика события (Event Handler), то событие не
            будет распространяться дальше (например, на обрабочики
            для родительских узлов).
            Подробнее: https://developer.mozilla.org/ru/docs/Web/API/Event/cancelBubble
        */

        void stopImmediatePropagation();

        /*
            Для конкретного события не будет больше вызвано обработчиков.
            Ни тех, которые привязаны к этому же элементу (на котором
            работает обработчик, который вызывает этот
            Event.stopImmediatePropagation()), ни других, которые могли
            бы вызваться при распространении события позже (например, в
            фазе перехвата - capture).
            Подробнее: https://developer.mozilla.org/ru/docs/Web/API/Event/stopImmediatePropagation
        */

        bool bubbles()                      { return mBubbles; }

        /*
            Логическое значение, указывающее, вспыло ли событие вверх по DOM или нет.
            Только для чтения.
            Подробнее: https://developer.mozilla.org/ru/docs/Web/API/Event/bubbles
        */

        bool cancelable()                   { return mCancelable; }

        /*
            Логическое значение, показывающее возможность отмены события.
            Только для чтения.
            Подробнее: https://developer.mozilla.org/ru/docs/Web/API/Event/cancelable
        */

        void preventDefault();

        /*
            Отменяет событие (если его возможно отменить).
            Подробнее: https://developer.mozilla.org/ru/docs/Web/API/Event/preventDefault
        */

        bool defaultPrevented()            { return mDefaultPrevented; }

        /*
            Показывает, была ли для события вызвана функция event.preventDefault().
            Подробнее: https://developer.mozilla.org/ru/docs/Web/API/Event/defaultPrevented
        */

        //bool composed();

        /*
            Не используется.
            Логическое значение, показывающее может или нет событие
            всплывать через границы между shadow DOM (внутренний DOM
            конкретного элемента) и обычного DOM документа.
            Только для чтения.
            Подробнее: https://developer.mozilla.org/ru/docs/Web/API/Event/composed
        */

        bool isTrusted()                   { return mIsTrusted; }


        //DOMHighResTimeStamp timeStamp();

        /*
            Не используется.
            Время, когда событие было создано (в миллисекундах).
            По спецификации это время от начала Эпохи (Unix Epoch),
            но в действительности в разных браузерах определяется по-разному;
            кроме того, ведётся работа по изменению его на
            DOMHighResTimeStamp тип.
            Только для чтения.
            Подробнее: https://developer.mozilla.org/ru/docs/Web/API/Event/timeStamp
        */

        void initEvent(DOMString aType, bool aBubbles, bool aCancelable);

        /*
            Устарело.
            Инициализация значений созданного с помощью Document.createEvent()
            события. Если событие уже отправлено, то эта функция ничего не делает.
            Подробнее: https://developer.mozilla.org/ru/docs/Web/API/Event/initEvent
        */

    private:

        DOMString mType;

    protected:

        EventTarget* mTarget;
        EventTarget* mCurrentTarget;

        EventSequence mEventSequence;

    private:

        unsigned short mEventPhase;

        bool mCancelBubble;

        bool mBubbles;
        bool mCancelable;
        bool mDefaultPrevented;

        bool mComposed;

        bool mIsTrusted;

    };

}
