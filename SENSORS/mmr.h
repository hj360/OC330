#ifndef MMR_H
#define MMR_H

#include "../SIMDATA/sim_params.h"

//Multi Mode reciever - A330 has two
class MMR
{
    public:
        MMR(ParamSim *SIM_);
        MMR(){};
        ~MMR(){};

        void Update();
        void setPwr(bool pwr);

    private:
        void setDefaults();
        //Does the MMR have power?
        bool power;
        //What state is the MMR in?
        //0 - OFF, 1 - INIT, 2 = ACQ, 3 - NAV, 4 - ALTAID, 5 - FAULT
        int state;
        //Values for the MMR to read
        ParamSim* SIM;
        //GPS Values GPS1 is MMR1, GPS2 is MMR2
        double long GPS_lat;
        double long GPS_long;
        float GPS_alt;
        float GPS_hdg;
        float GPS_gs;

        //ILS Values
};

#endif