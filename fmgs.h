#include "FMGC/fmgc.h"
#include "MCDU/mcdu.h"

#ifndef FMGS_H
#define FMGS_H

class FMGS
{
    public:
        FMGS();
        ~FMGS();

        //Flight management guidance computers
        FMGC* FMGC1;
        FMGC* FMGC2;
        //Display units
        MCDU* MCDU1;
        MCDU* MCDU2;
        MCDU* MCDU3;


    
    private:

};

#endif