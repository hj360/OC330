#include "mcdu_elements.h"
#include <vector>
#include "mcdu_scratchpad.h"
#include "fmgc.h"
#include <sstream>
#include <iomanip>

#ifndef MCDU_PAGES_H
#define MCDU_PAGES_H

class Page
{
    public:
        Page();
        ~Page(){};

        virtual std::vector<Element> getElements(FMGC* ActiveFMGC_, Scratchpad &pad_);
        int getPageId();
        int getLeftPageId();
        int getRightPageId();

        virtual void selectLSK(int lsk_, FMGC* ActiveFMGC_, int &p_act_, Scratchpad &pad_);
        


    protected:
        int pageID;
        int leftPageID;
        int rightPageID;

        std::vector<Element> pageElements;
};

class Data_Index_1 : public Page
{
    public:
        Data_Index_1();
        ~Data_Index_1(){};

        virtual std::vector<Element> getElements(FMGC* ActiveFMGC_, Scratchpad &pad_);
        virtual void selectLSK(int lsk_, FMGC* ActiveFMGC_, int &p_act_, Scratchpad &pad_);

};

class Ac_Status : public Page
{
    public:
        Ac_Status();
        ~Ac_Status(){};

        virtual std::vector<Element> getElements(FMGC* ActiveFMGC_, Scratchpad &pad_);
        virtual void selectLSK(int lsk_, FMGC* ActiveFMGC_, int &p_act_, Scratchpad &pad_);

};

class Init_A : public Page
{
    public:
        Init_A();
        ~Init_A(){};

        virtual std::vector<Element> getElements(FMGC* ActiveFMGC_, Scratchpad &pad_);
        virtual void selectLSK(int lsk_, FMGC* ActiveFMGC_, int &p_act_, Scratchpad &pad_);
};

class Init_B : public Page
{
    public:
        Init_B();
        ~Init_B(){};

        virtual std::vector<Element> getElements(FMGC* ActiveFMGC_, Scratchpad &pad_);
        virtual void selectLSK(int lsk_, FMGC* ActiveFMGC_, int &p_act_, Scratchpad &pad_);
};

class Route_Sel : public Page
{
    public:
        Route_Sel();
        ~Route_Sel(){};

        virtual std::vector<Element> getElements(FMGC* ActiveFMGC_, Scratchpad &pad_);
        virtual void selectLSK(int lsk_, FMGC* ActiveFMGC_, int &p_act_, Scratchpad &pad_);
};

class Gps_Monitor : public Page
{
    public:
        Gps_Monitor();
        ~Gps_Monitor(){};

        virtual std::vector<Element> getElements(FMGC* ActiveFMGC_, Scratchpad &pad_);
        virtual void selectLSK(int lsk_, FMGC* ActiveFMGC_, int &p_act_, Scratchpad &pad_);
};

class Position_Monitor : public Page
{
    public:
        Position_Monitor();
        ~Position_Monitor(){};

        virtual std::vector<Element> getElements(FMGC* ActiveFMGC_, Scratchpad &pad_);
        virtual void selectLSK(int lsk_, FMGC* ActiveFMGC_, int &p_act_, Scratchpad &pad_);
};

class Mcdu_Menu : public Page
{
    public:
        Mcdu_Menu();
        ~Mcdu_Menu(){};

        virtual std::vector<Element> getElements(FMGC* ActiveFMGC_, Scratchpad &pad_);
        virtual void selectLSK(int lsk_, FMGC* ActiveFMGC_, int &p_act_, Scratchpad &pad_);

    private:
        int fmState = 2; //fm is selected by default
        int acarsState = 0;//Acars is not selected by default

        bool selected = false;//Is a system being selected
};


#endif