#pragma once

#include "EventHandler.h"

namespace Newtoo
{

    class GlobalEventHandlers
    {
    public:

        EventHandler& onabort()                             { return mOnabort; }
        EventHandler& onauxclick()                          { return mOnauxclick; }
        EventHandler& onblur()                              { return mOnblur; }
        EventHandler& oncancel()                            { return mOncancel; }
        EventHandler& oncanplay()                           { return mOncanplay; }
        EventHandler& oncanplaythrough()                    { return mOncanplaythrough; }
        EventHandler& onchange()                            { return mOnchange; }
        EventHandler& onclick()                             { return mOnclick; }
        EventHandler& onclose()                             { return mOnclose; }
        EventHandler& oncontextmenu()                       { return mOncontextmenu; }
        EventHandler& oncuechange()                         { return mOncuechange; }
        EventHandler& ondblclick()                          { return mOndblclick; }
        EventHandler& ondrag()                              { return mOndrag; }
        EventHandler& ondragend()                           { return mOndragend; }
        EventHandler& ondragenter()                         { return mOndragenter; }
        EventHandler& ondragexit()                          { return mOndragexit; }
        EventHandler& ondragleave()                         { return mOndragleave; }
        EventHandler& ondragover()                          { return mOndragover; }
        EventHandler& ondragstart()                         { return mOndragstart; }
        EventHandler& ondrop()                              { return mOndrop; }
        EventHandler& ondurationchange()                    { return mOndurationchange; }
        EventHandler& onemptied()                           { return mOnemptied; }
        EventHandler& onended()                             { return mOnended; }
        /*OnError*/EventHandler& onerror()                  { return mOnerror; }
        EventHandler& onfocus()                             { return mOnfocus; }
        EventHandler& oninput()                             { return mOninput; }
        EventHandler& oninvalid()                           { return mOninvalid; }
        EventHandler& onkeydown()                           { return mOnkeydown; }
        EventHandler& onkeypress()                          { return mOnkeypress; }
        EventHandler& onkeyup()                             { return mOnkeyup; }
        EventHandler& onload()                              { return mOnload; }
        EventHandler& onloadeddata()                        { return mOnloadeddata; }
        EventHandler& onloadedmetadata()                    { return mOnloadedmetadata; }
        EventHandler& onloadend()                           { return mOnloadend; }
        EventHandler& onloadstart()                         { return mOnloadstart; }
        EventHandler& onmousedown()                         { return mOnmousedown; }
        EventHandler& onmouseenter()                        { return mOnmouseenter; }
        EventHandler& onmouseleave()                        { return mOnmouseleave; }
        EventHandler& onmousemove()                         { return mOnmousemove; }
        EventHandler& onmouseout()                          { return mOnmouseout; }
        EventHandler& onmouseover()                         { return mOnmouseover; }
        EventHandler& onmouseup()                           { return mOnmouseup; }
        EventHandler& onwheel()                             { return mOnwheel; }
        EventHandler& onpause()                             { return mOnpause; }
        EventHandler& onplay()                              { return mOnplay; }
        EventHandler& onplaying()                           { return mOnplaying; }
        EventHandler& onprogress()                          { return mOnprogress; }
        EventHandler& onratechange()                        { return mOnratechange; }
        EventHandler& onreset()                             { return mOnreset; }
        EventHandler& onresize()                            { return mOnresize; }
        EventHandler& onscroll()                            { return mOnscroll; }
        EventHandler& onsecuritypolicyviolation()           { return mOnsecuritypolicyviolation; }
        EventHandler& onseeked()                            { return mOnseeked; }
        EventHandler& onseeking()                           { return mOnseeking; }
        EventHandler& onselect()                            { return mOnselect; }
        EventHandler& onstalled()                           { return mOnstalled; }
        EventHandler& onsubmit()                            { return mOnsubmit; }
        EventHandler& onsuspend()                           { return mOnsuspend; }
        EventHandler& ontimeupdate()                        { return mOntimeupdate; }
        EventHandler& ontoggle()                            { return mOntoggle; }
        EventHandler& onvolumechange()                      { return mOnvolumechange; }
        EventHandler& onwaiting()                           { return mOnwaiting; }

        void setOnabort(EventHandler fn)                    { mOnabort = fn; }
        void setOnauxclick(EventHandler fn)                 { mOnauxclick = fn; }
        void setOnblur(EventHandler fn)                     { mOnblur = fn; }
        void setOncancel(EventHandler fn)                   { mOncancel = fn; }
        void setOncanplay(EventHandler fn)                  { mOncanplay = fn; }
        void setOncanplaythrough(EventHandler fn)           { mOncanplaythrough = fn; }
        void setOnchange(EventHandler fn)                   { mOnchange = fn; }
        void setOnclick(EventHandler fn)                    { mOnclick = fn; }
        void setOnclose(EventHandler fn)                    { mOnclose = fn; }
        void setOncontextmenu(EventHandler fn)              { mOncontextmenu = fn; }
        void setOncuechange(EventHandler fn)                { mOncuechange = fn; }
        void setOndblclick(EventHandler fn)                 { mOndblclick = fn; }
        void setOndrag(EventHandler fn)                     { mOndrag = fn; }
        void setOndragend(EventHandler fn)                  { mOndragend = fn; }
        void setOndragenter(EventHandler fn)                { mOndragenter = fn; }
        void setOndragexit(EventHandler fn)                 { mOndragexit = fn; }
        void setOndragleave(EventHandler fn)                { mOndragleave = fn; }
        void setOndragover(EventHandler fn)                 { mOndragover = fn; }
        void setOndragstart(EventHandler fn)                { mOndragstart = fn; }
        void setOndrop(EventHandler fn)                     { mOndrop = fn; }
        void setOndurationchange(EventHandler fn)           { mOndurationchange = fn; }
        void setOnemptied(EventHandler fn)                  { mOnemptied = fn; }
        void setOnended(EventHandler fn)                    { mOnended = fn; }
        /*OnError*/void setOnerror(EventHandler fn)         { mOnerror = fn; }
        void setOnfocus(EventHandler fn)                    { mOnfocus = fn; }
        void setOninput(EventHandler fn)                    { mOninput = fn; }
        void setOninvalid(EventHandler fn)                  { mOninvalid = fn; }
        void setOnkeydown(EventHandler fn)                  { mOnkeydown = fn; }
        void setOnkeypress(EventHandler fn)                 { mOnkeypress = fn; }
        void setOnkeyup(EventHandler fn)                    { mOnkeyup = fn; }
        void setOnload(EventHandler fn)                     { mOnload = fn; }
        void setOnloadeddata(EventHandler fn)               { mOnloadeddata = fn; }
        void setOnloadedmetadata(EventHandler fn)           { mOnloadedmetadata = fn; }
        void setOnloadend(EventHandler fn)                  { mOnloadend = fn; }
        void setOnloadstart(EventHandler fn)                { mOnloadstart = fn; }
        void setOnmousedown(EventHandler fn)                { mOnmousedown = fn; }
        void setOnmouseenter(EventHandler fn)               { mOnmouseenter = fn; }
        void setOnmouseleave(EventHandler fn)               { mOnmouseleave = fn; }
        void setOnmousemove(EventHandler fn)                { mOnmousemove = fn; }
        void setOnmouseout(EventHandler fn)                 { mOnmouseout = fn; }
        void setOnmouseover(EventHandler fn)                { mOnmouseover = fn; }
        void setOnmouseup(EventHandler fn)                  { mOnmouseup = fn; }
        void setOnwheel(EventHandler fn)                    { mOnwheel = fn; }
        void setOnpause(EventHandler fn)                    { mOnpause = fn; }
        void setOnplay(EventHandler fn)                     { mOnplay = fn; }
        void setOnplaying(EventHandler fn)                  { mOnplaying = fn; }
        void setOnprogress(EventHandler fn)                 { mOnprogress = fn; }
        void setOnratechange(EventHandler fn)               { mOnratechange = fn; }
        void setOnreset(EventHandler fn)                    { mOnreset = fn; }
        void setOnresize(EventHandler fn)                   { mOnresize = fn; }
        void setOnscroll(EventHandler fn)                   { mOnscroll = fn; }
        void setOnsecuritypolicyviolation(EventHandler fn)  { mOnsecuritypolicyviolation = fn; }
        void setOnseeked(EventHandler fn)                   { mOnseeked = fn; }
        void setOnseeking(EventHandler fn)                  { mOnseeking = fn; }
        void setOnselect(EventHandler fn)                   { mOnselect = fn; }
        void setOnstalled(EventHandler fn)                  { mOnstalled = fn; }
        void setOnsubmit(EventHandler fn)                   { mOnsubmit = fn; }
        void setOnsuspend(EventHandler fn)                  { mOnsuspend = fn; }
        void setOntimeupdate(EventHandler fn)               { mOntimeupdate = fn; }
        void setOntoggle(EventHandler fn)                   { mOntoggle = fn; }
        void setOnvolumechange(EventHandler fn)             { mOnvolumechange = fn; }
        void setOnwaiting(EventHandler fn)                  { mOnwaiting = fn; }

    private:

        EventHandler mOnabort;
        EventHandler mOnauxclick;
        EventHandler mOnblur;
        EventHandler mOncancel;
        EventHandler mOncanplay;
        EventHandler mOncanplaythrough;
        EventHandler mOnchange;
        EventHandler mOnclick;
        EventHandler mOnclose;
        EventHandler mOncontextmenu;
        EventHandler mOncuechange;
        EventHandler mOndblclick;
        EventHandler mOndrag;
        EventHandler mOndragend;
        EventHandler mOndragenter;
        EventHandler mOndragexit;
        EventHandler mOndragleave;
        EventHandler mOndragover;
        EventHandler mOndragstart;
        EventHandler mOndrop;
        EventHandler mOndurationchange;
        EventHandler mOnemptied;
        EventHandler mOnended;
        /*OnError*/EventHandler mOnerror;
        EventHandler mOnfocus;
        EventHandler mOninput;
        EventHandler mOninvalid;
        EventHandler mOnkeydown;
        EventHandler mOnkeypress;
        EventHandler mOnkeyup;
        EventHandler mOnload;
        EventHandler mOnloadeddata;
        EventHandler mOnloadedmetadata;
        EventHandler mOnloadend;
        EventHandler mOnloadstart;
        EventHandler mOnmousedown;
        EventHandler mOnmouseenter;
        EventHandler mOnmouseleave;
        EventHandler mOnmousemove;
        EventHandler mOnmouseout;
        EventHandler mOnmouseover;
        EventHandler mOnmouseup;
        EventHandler mOnwheel;
        EventHandler mOnpause;
        EventHandler mOnplay;
        EventHandler mOnplaying;
        EventHandler mOnprogress;
        EventHandler mOnratechange;
        EventHandler mOnreset;
        EventHandler mOnresize;
        EventHandler mOnscroll;
        EventHandler mOnsecuritypolicyviolation;
        EventHandler mOnseeked;
        EventHandler mOnseeking;
        EventHandler mOnselect;
        EventHandler mOnstalled;
        EventHandler mOnsubmit;
        EventHandler mOnsuspend;
        EventHandler mOntimeupdate;
        EventHandler mOntoggle;
        EventHandler mOnvolumechange;
        EventHandler mOnwaiting;
    };

}
