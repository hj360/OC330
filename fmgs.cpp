#include "fmgs.h"

FMGS::FMGS()
{

    //Inidialize guidance computers
    FMGC1 = new FMGC(1);
    FMGC2 = new FMGC(2);
    
    //Initialize display units
    //Because the font is .8em width the display resolution needs to be a multiple of 192 8*24 characters
    MCDU1 = new MCDU(1, 384, 400, FMGC1);
    MCDU2 = new MCDU(2, 384, 400, FMGC2);
    MCDU3 = new MCDU(3, 384, 400, FMGC1);
    
}

FMGS::~FMGS()
{

}