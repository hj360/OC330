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
        //For a linked page if it exists, 0 for no linked page
        int linkedPageId;
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

//AC Status page
class EngineType : public Element
{
    public:
        EngineType(int row_, int offset_);
        ~EngineType(){};

        virtual void Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_);
        virtual void getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_, FMGC* ActiveFMGC_);
};

class AircraftType : public Element
{
    public:
        AircraftType(int row_, int offset_);
        ~AircraftType(){};

        virtual void Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_);
        virtual void getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_, FMGC* ActiveFMGC_);
};

class FromTo : public Element
{
    public:
        FromTo(int row_, int offset_);
        ~FromTo(){};

        virtual void getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_, FMGC* ActiveFMGC_);
        virtual void Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_);

    private:

};

class CoRte : public Element
{
    public:
        CoRte(int row_, int offset_);
        ~CoRte(){};

        virtual void getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_, FMGC* ActiveFMGC_);
        virtual void Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_);

    private:

};

class AltnCoRte : public Element
{
    public:
        AltnCoRte(int row_, int offset_);
        ~AltnCoRte(){};

        virtual void getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_, FMGC* ActiveFMGC_);
        virtual void Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_);

    private:

};

class FlightNumber : public Element
{
    public:
        FlightNumber(int row_, int offset_);
        ~FlightNumber(){};

        virtual void Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_);
        virtual void getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_, FMGC* ActiveFMGC_);

};

class CostIndex : public Element
{
    public:
        CostIndex(int row_, int offset_);
        ~CostIndex(){};

        virtual void Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_);
        virtual void getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_, FMGC* ActiveFMGC_);

    private:

};

class CrzFlTemp : public Element
{
    public:
        CrzFlTemp(int row_, int offset_);
        ~CrzFlTemp(){};

        virtual void Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_);
        virtual void getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_, FMGC* ActiveFMGC_);

    private:

};

class Tropo : public Element
{
    public:
        Tropo(int row_, int offset_);
        ~Tropo(){};

        virtual void Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_);
        virtual void getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_, FMGC* ActiveFMGC_);

};

#endif