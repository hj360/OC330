#include <string>
#include "mcdu_scratchpad.h"
#include "fmgc.h"

#ifndef MCDU_ELEMENTS_H
#define MCDU_ELEMENTS_H

class Element
{
    public:
        Element();
        Element(std::string text_, int row_, int offset_, int color_, int size_);
        ~Element(){};

        virtual void getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_, FMGC* ActiveFMGC_);
        virtual void Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_);
        int getType();

    protected:
        //Current value of text that shows on the MCDU
        std::string text;
        //Row which the element renders on the MCDU
        int row;
        //Beginning offset for the element from the left of the MCDU display in characters
        int offset;
        //Select text color// 0 = white // 1 = green // 2 = blue // 3 = magenta // 4 = yellow // 5 = orange
        int color;

        int linkedPageId;

        //Type of element//
        //0 - plain text
        //1 - link
        int type;

        //0 is label 1 is large
        int size;
    
};

class Link : public Element
{
    public:
        Link(std::string text_, int row_, int offset_, int color_, int size_, int linkedPageId_);
        ~Link(){};

        virtual void Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_);

    private:

};

class FromTo : public Element
{
    public:
        FromTo(std::string text_, int row_, int offset_, int color_, int size_);
        ~FromTo(){};

        virtual void getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_, FMGC* ActiveFMGC_);
        virtual void Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_);

    private:

};

class AltnCoRte : public Element
{
    public:
        AltnCoRte(std::string text_, int row_, int offset_, int color_, int size_);
        ~AltnCoRte(){};

        virtual void getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_, FMGC* ActiveFMGC_);
        virtual void Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_);

    private:

};

class FlightNumber : public Element
{
    public:
        FlightNumber(std::string text_, int row_, int offset_, int color_, int size_);
        ~FlightNumber(){};

        virtual void Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_);
        virtual void getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_, FMGC* ActiveFMGC_);

    private:

};

#endif