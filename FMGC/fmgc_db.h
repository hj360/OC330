#ifndef FMGC_DB_H
#define FMGC_DB_H

#include <string>

struct NavDB
{

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