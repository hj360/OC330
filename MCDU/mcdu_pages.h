#include "mcdu_elements.h"
#include <vector>

#ifndef MCDU_PAGES_H
#define MCDU_PAGES_H

class Page
{
    public:
        Page();
        Page(int id_);
        ~Page(){};

        std::vector<Element> getElements();
        int getPageId();

    protected:
        //Page elements
        std::vector<Element> pageElements;
        int pageID;
};

class Data_Index_1 : public Page
{
    public:
        Data_Index_1(int id_);
        ~Data_Index_1(){};

};

class Ac_Status : public Page
{
    public:
        Ac_Status(int id_);
        ~Ac_Status(){};

};

#endif