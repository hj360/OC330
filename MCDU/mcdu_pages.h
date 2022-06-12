#include "mcdu_elements.h"
#include <vector>

#ifndef MCDU_PAGES_H
#define MCDU_PAGES_H

class Page
{
    public:
        Page();
        ~Page();

        std::vector<Element> getElements();

    private:
        //Page elements
        std::vector<Element> pageElements;
        
    
};

#endif