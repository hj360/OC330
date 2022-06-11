#include "fmgs.h"

FMGS::FMGS()
{

    //Inidialize guidance computers
    FMGC1 = new FMGC(1);
    FMGC2 = new FMGC(2);
    
    //Initialize display units
    MCDU1 = new MCDU(1);
    MCDU2 = new MCDU(2);
    MCDU3 = new MCDU(3);
    
}

FMGS::~FMGS()
{

}