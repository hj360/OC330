#include <string>
#include "mcdu_scratchpad.h"

#ifndef MCDU_ELEMENTS_H
#define MCDU_ELEMENTS_H

class Element
{
    public:
        Element();
        Element(std::string text_, int row_, int offset_, int color_, int size_);
        ~Element(){};

        void getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_);
        virtual void Select(int &linkedPageId_, Scratchpad &pad_);
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

        virtual void Select(int &linkedPageId_, Scratchpad &pad_);

    private:

};

#endif