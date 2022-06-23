#ifndef FMGC_DB_H
#define FMGC_DB_H

#include <string>
#include <vector>
#include <map>

struct NavDB
{
    //Holds all airports and their coords
    std::map<std::string, std::vector<long double>> arpts;

};

struct AirlineConfigDB
{
    int idle;
    int perf;
    int acc_alt;
    int eoc_alt;
    int tropo_default;
    int taxi_fuel;

};

struct PerfDB
{
    std::string aircraft_desig;
    std::string engine_desig;
};

struct MagVarDB
{

};




#endif 