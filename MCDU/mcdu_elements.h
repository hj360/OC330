#include <string>

#ifndef MCDU_ELEMENTS_H
#define MCDU_ELEMENTS_H

class Element
{
    public:
        Element();
        Element(std::string text_, int row_, int offset_, int color_, int size_);
        ~Element(){};

        void getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_);

    protected:
        //Current value of text that shows on the MCDU
        std::string text;
        //Row which the element renders on the MCDU
        int row;
        //Beginning offset for the element from the left of the MCDU display in characters
        int offset;
        //Select text color// 0 = white // 1 = green // 2 = blue // 3 = magenta // 4 = yellow // 5 = Amber
        int color;
        //0 is label 1 is large
        int size;
    
};

#endif