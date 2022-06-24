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
        bool getGPSStatus(){return gps;};

        double long getGPSLat(){return GPS_lat;};
        double long getGPSLong(){return GPS_long;};
        float getGPSAlt(){return GPS_alt;};
        float getGPSHdg(){return GPS_hdg;};
        float getGPSGs(){return GPS_gs;};
        int getMMRStatus(){return state;};
        int getSats(){return SIM->getSats();};


    private:
        void setDefaults();
        //Does the MMR have power?
        bool power;
        //What state is the MMR in?
        //0 - OFF, 1 - INIT, 2 = ACQ, 3 - NAV, 4 - ALTAID, 5 - FAULT
        int state;
        //Values for the MMR to read
        ParamSim* SIM;

        //Is GPS functional?
        bool gps;
        //GPS Values GPS1 is MMR1, GPS2 is MMR2
        double long GPS_lat;
        double long GPS_long;
        float GPS_alt;
        float GPS_hdg;
        float GPS_gs;

        //ILS Values
};

#endif