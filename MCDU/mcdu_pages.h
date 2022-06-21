#include "mcdu_elements.h"
#include <vector>

#ifndef MCDU_PAGES_H
#define MCDU_PAGES_H

class Page
{
    public:
        Page();
        ~Page(){};

        void Clean();

        std::vector<Element*>& getElements();
        std::vector<Element*>& getLSKElements();
        int getPageId();
        int getLeftPageId();
        int getRightPageId();
        Element*& getLSKElement(int lsk);
        


    protected:
        //Page elements
        std::vector<Element*> pageElements;
        std::vector<Element*> lskElements;
        int pageID;
        int leftPageID;
        int rightPageID;
};

class Data_Index_1 : public Page
{
    public:
        Data_Index_1();
        ~Data_Index_1(){};

};

class Ac_Status : public Page
{
    public:
        Ac_Status();
        ~Ac_Status(){};

};

class Init_A : public Page
{
    public:
        Init_A();
        ~Init_A(){};

};

class Init_B : public Page
{
    public:
        Init_B();
        ~Init_B(){};
};

class Route_Sel : public Page
{
    public:
        Route_Sel();
        ~Route_Sel(){};
};


#endif