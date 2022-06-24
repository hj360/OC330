#ifndef ADIRU_H
#define ADIRU_H

#include "../SENSORS/sensors.h"

class Adiru
{
    public:
        Adiru(){};
        Adiru(SensorManager* Sensors_, int id_);
        ~Adiru(){};

        void Update();

    private:
        int id;
        SensorManager* Sensors;

        MMR* ActiveMMR;
        MMR* AltMMR;

        double long GPS_lat;
        double long GPS_long;
        float GPS_alt;
        float GPS_hdg;
        float GPS_gs;


};




#endif