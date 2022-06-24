#include "mmr.h"

MMR::MMR(ParamSim* SIM_)
{
    SIM = SIM_;
    power = false;
    state = 0;

    setDefaults();
}

void MMR::setDefaults()
{
    GPS_lat = -999;
    GPS_long = -999;
    GPS_alt = -999;
    GPS_hdg = -999;
    GPS_gs = -999;
}

void MMR::Update()
{
    if(state == 0 || power == false)
    {
        return;
    } else if(state == 0 && power == true)
    {
        //Initialize the MMR
        state = 1;
        return;
    } else if(state == 1 && power == true)
    {
        //ACQ mode
        if(SIM->getSats() >= 4)
        {
            state = 2;
            return;
        }

        setDefaults();

        return;

    } else if(state == 2 && power == true) 
    {
        //NAV MODE
        //Check if there are at least 4 satellites available
        if(SIM->getSats() == 3)
        {
            state = 3;
            return;
        } else if(SIM->getSats() < 3)
        {
            state = 1;
            return;
        }

        GPS_lat = SIM->getLat();
        GPS_long = SIM->getLong();
        GPS_alt = SIM->getAltAsl();
        GPS_hdg = SIM->getHdg();
        GPS_gs = SIM->getSpeedGround();
        return;

    } else if(state == 3 && power == true)
    {
        if(SIM->getSats() >= 4)
        {
            state = 2;
            return;
        } else if(SIM->getSats() < 3)
        {
            state = 1;
            return;
        }
        //ALTAID MODE
        GPS_lat = SIM->getLat();
        GPS_long = SIM->getLong();
        GPS_alt = -999;
        GPS_hdg = SIM->getHdg();
        GPS_gs = SIM->getSpeedGround();

        return;
    } else if(state == 4)
    {
        //Fault MODE
        return;
    } else {
        return;
    }
}

void MMR::setPwr(bool pwr)
{
    power = pwr;
}

