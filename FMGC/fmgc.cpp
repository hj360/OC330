#include <iostream>

#include "fmgc.h"

FMGC::FMGC(int id_)
{
    //Initialize class vars with constructor vars
    id = id_;

    //Create fmgc datasets
    navDB = new NavDB();
    airlineConfigDB = new AirlineConfigDB();
    perfDB = new PerfDB();
    magVarDB = new MagVarDB();

    //Create each FMGC Part
    FM = FMGC_FM(airlineConfigDB);
    FG = FMGC_FG();
    FE = FMGC_FE();

    //Load datasets
    if(LoadAirlineConfig())
    {
        std::cout << "Airline Database Loaded!" << std::endl;
    } else {
        std::cout << "Airline Database Failed to Load!" << std::endl;
    }
    //FMGC is online
    avail = 1;
    //Error checking
    if(avail)
    {
        std::cout << "FMGC " << id << " Available." << std::endl;
    } else {
        std::cerr << "FMGC " << id << " Fail." << std::endl;
    }
}

bool FMGC::LoadAirlineConfig()
{
    std::fstream in("./CONFIG/fmgs_airline_config.cfg");
    if(!in.is_open())
    {
        std::cout << "Error! Cannot load FMGS Config file" << std::endl;
        return false;
    }

    std::string param;
    std::string value;

    while(!in.eof())
    {
        in >> param;
        in >> value;

        if(param == "idle")
        {
            airlineConfigDB->idle = stoi(value);
        } else if (param == "perf")
        {
            airlineConfigDB->perf = stoi(value);
        } else if (param == "acc_alt")
        {
            airlineConfigDB->acc_alt = stoi(value);
        } else if (param == "eoc_alt")
        {
            airlineConfigDB->eoc_alt = stoi(value);
        } else if (param == "tropo_default")
        {
            airlineConfigDB->tropo_default = stoi(value);
        } else if (param == "taxi_fuel")
        {
            airlineConfigDB->taxi_fuel = stoi(value);
        }
    }

    return true;
}