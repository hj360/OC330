#ifndef SENSORS_H
#define SENSORS_H

#include "mmr.h"
#include "../SIMDATA/sim_params.h"

class SensorManager
{
    public:
        SensorManager(){};
        SensorManager(ParamSim* SIM_);
        ~SensorManager(){};

        void Update();

        MMR* MMR1;
        MMR* MMR2;

    private:
        //Sim parameters
        ParamSim* SIM;

        


};

#endif