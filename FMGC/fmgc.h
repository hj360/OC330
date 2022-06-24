//FMGC Components
#include "fmgc_fm.h"
#include "fmgc_fg.h"
#include "fmgc_fe.h"
#include "fmgc_db.h"

#include "../SENSORS/sensors.h"

#ifndef FMGC_H
#define FMGC_H

class FMGC
{
    public:
        FMGC(int id_, SensorManager* Sensors_);
        ~FMGC();

        bool LoadAirlineConfig();
        bool LoadPerfConfig();
        bool LoadAirports();
        //Separate FMGC components
        FMGC_FM FM;
        FMGC_FG FG;
        FMGC_FE FE;

        //Aircraft sensors
        SensorManager* Sensors;


        std::string getAircraftType(){return perfDB->aircraft_desig;};
        std::string getEngineType(){return perfDB->engine_desig;};

    private:
        //1 is FMGC1, 2 is FMGC2
        int id;
        //Is FMGC available?
        bool avail;
        //FMGC Datasets
        NavDB* navDB;
        AirlineConfigDB* airlineConfigDB;
        PerfDB* perfDB;
        MagVarDB* magVarDB;

        

};




#endif