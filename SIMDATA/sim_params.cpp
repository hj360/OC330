#include "sim_params.h"

ParamSim::ParamSim()
{
    //Initial values

    latitude = -37.673302;
    longitude = 144.843002;
    alt_asl = 0;

    hdg = 0;

    speed_ground = 0;

    sats = 6;

    count = 0;
}


void ParamSim::Update()
{
    if(count > 100 && sats > 0)
    {
        sats = sats - 1;
        count = 0;
    }

    count++;
    
}