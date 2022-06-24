#include <iostream>

#include "fmgc.h"

FMGC::FMGC(int id_, SensorManager* Sensors_)
{
    //Initialize class vars with constructor vars
    id = id_;
    avail = 1;

    //Init sensors
    Sensors = Sensors_;

    //Create fmgc datasets
    navDB = new NavDB();
    airlineConfigDB = new AirlineConfigDB();
    perfDB = new PerfDB();
    magVarDB = new MagVarDB();

    //Create each FMGC Part
    FM = FMGC_FM(airlineConfigDB, navDB);
    FG = FMGC_FG();
    FE = FMGC_FE();

    //Load datasets
    if(LoadAirlineConfig())
    {
        std::cout << "Airline Database Loaded!" << std::endl;
    } else {
        std::cout << "Airline Database Failed to Load!" << std::endl;
        avail = -1;
    }
    if(LoadPerfConfig())
    {
        std::cout << "Performance Database Loaded!" << std::endl;
    } else {
        std::cout << "Performance Database Failed to Load!" << std::endl;
        avail = -1;
    }

    if(LoadAirports())
    {
        std::cout << "Airport Database Loaded!" << std::endl;
    } else {
        std::cout << "Airport Database Failed to Load!" << std::endl;
        avail = -1;
    }
    //Error checking
    if(avail)
    {
        std::cout << "FMGC " << id << " Available." << std::endl;
    } else {
        std::cerr << "FMGC " << id << " Fail." << std::endl;
    }
}

bool FMGC::LoadPerfConfig()
{
    std::fstream in("./CONFIG/fmgs_perf_config.cfg");
    if(!in.is_open())
    {
        std::cout << "Error! Cannot load FMGS Performance Config file" << std::endl;
        return false;
    }

    std::string param;
    std::string value;

    while(!in.eof())
    {
        in >> param;
        in >> value;

        if(param == "aircraft_desig")
        {
            perfDB->aircraft_desig = value;
        } else if (param == "engine_desig")
        {
            perfDB->engine_desig = value;
        } 
    }

    in.close();

    return true;
}

bool FMGC::LoadAirlineConfig()
{
    std::fstream in("./CONFIG/fmgs_airline_config.cfg");
    if(!in.is_open())
    {
        std::cout << "Error! Cannot load FMGS Airline Config file" << std::endl;
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
            airlineConfigDB->idle = stof(value);
        } else if (param == "perf")
        {
            airlineConfigDB->perf = stof(value);
        } else if (param == "acc_alt")
        {
            airlineConfigDB->acc_alt = stof(value);
        } else if (param == "eoc_alt")
        {
            airlineConfigDB->eoc_alt = stof(value);
        } else if (param == "tropo_default")
        {
            airlineConfigDB->tropo_default = stof(value);
        } else if (param == "taxi_fuel")
        {
            airlineConfigDB->taxi_fuel = stof(value);
        }
    }

    in.close();

    return true;
}

bool FMGC::LoadAirports()
{
    std::fstream in("./DATA/arpt.dat");
    if(!in.is_open())
    {
        std::cout << "Error! Cannot load FMGS Airports file" << std::endl;
        return false;
    }

    std::string arpt;
    std::vector<long double> latLong;
    long double latitude;
    long double longitude;

    while(!in.eof())
    {
        in >> arpt;
        in >> latitude;
        in >> longitude;

        latLong = {latitude, longitude};

        navDB->arpts.insert(std::pair<std::string, std::vector<long double>> (arpt, latLong));
    }

    std::cout << navDB->arpts.find("YPAD")->second[0] << std::endl;

    in.close();

    return true;
}