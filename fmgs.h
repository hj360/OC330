#include "FMGC/fmgc.h"
#include "MCDU/mcdu.h"
#include "SENSORS/sensors.h"

#ifndef FMGS_H
#define FMGS_H

class FMGS
{
    public:
        FMGS(SensorManager* Sensors_);
        FMGS(){};
        ~FMGS();

        //Flight management guidance computers
        FMGC* FMGC1;
        FMGC* FMGC2;
        //Display units
        MCDU* MCDU1;
        MCDU* MCDU2;
        MCDU* MCDU3;

    private:
        SensorManager* Sensors;


};

#endif