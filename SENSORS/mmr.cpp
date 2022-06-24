#include "mmr.h"

MMR::MMR(ParamSim* SIM_)
{
    SIM = SIM_;
    power = false;
    gps = false;
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
    if(power == false)
    {
        gps = false;
        return;
    } else if(state == 0 && power == true)
    {
        //Initialize the MMR
        gps = false;
        state = 1;
        return;
    } else if(state == 1 && power == true)
    {
        //Init go to acq
        gps = false;
        state = 2;

        return;

    } else if(state == 2 && power == true)
    {
        //ACQ mode
        if(SIM->getSats() >= 4)
        {
            state = 3;
            return;
        }

        setDefaults();
        gps = false;

        return;

    } else if(state == 3 && power == true) 
    {
        //NAV MODE
        //Check if there are at least 4 satellites available
        if(SIM->getSats() == 3)
        {
            state = 4;
            return;
        } else if(SIM->getSats() < 3)
        {
            state = 2;
            return;
        }

        gps = true;

        GPS_lat = SIM->getLat();
        GPS_long = SIM->getLong();
        GPS_alt = SIM->getAltAsl();
        GPS_hdg = SIM->getHdg();
        GPS_gs = SIM->getSpeedGround();
        return;

    } else if(state == 4 && power == true)
    {
        //Altaid
        if(SIM->getSats() >= 4)
        {
            state = 3;
            return;
        } else if(SIM->getSats() < 3)
        {
            state = 2;
            return;
        }
        //ALTAID MODE
        GPS_lat = SIM->getLat();
        GPS_long = SIM->getLong();
        GPS_alt = -999;
        GPS_hdg = SIM->getHdg();
        GPS_gs = SIM->getSpeedGround();

        return;
    } else if(state == 5)
    {
        gps = false;
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

