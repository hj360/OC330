#include "fmgs.h"

FMGS::FMGS(SensorManager* Sensors_)
{
    Sensors = Sensors_;

    //Inidialize guidance computers
    FMGC1 = new FMGC(1, Sensors);
    FMGC2 = new FMGC(2, Sensors);
    
    //Initialize display units
    //Because the font is .8em width the display resolution needs to be a multiple of 192 8*24 characters
    MCDU1 = new MCDU(1, 384, 400, FMGC1, Sensors);
    MCDU2 = new MCDU(2, 384, 400, FMGC2, Sensors);
    MCDU3 = new MCDU(3, 384, 400, FMGC1, Sensors);
    
}

FMGS::~FMGS()
{

}