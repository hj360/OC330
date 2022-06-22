#include <string>
#include <fstream>
#include <iostream>
#include "fmgc_db.h"

#ifndef FMGC_FM_H
#define FMGC_FM_H

struct FlightPlan
{
    std::string origin = "";
    std::string dest = "";
    std::string coRte = "";
    std::string altn = "";
    std::string altnCoRte = "";

    std::string fltNbr = "";

    int costIndex = -999;
    int crzFl = -999;
    int crzTemp = -999;
    int tropo = -999;   
};

struct InitWeights
{
    int taxi = -999;
    int tripFuel = -999;
    int tripTime = -999;
    int rsv = -999;
    int altnFuel = -999;
    int finalFuel = -999;
    int extraFuel = -999;
    int zfw = -999;
    int zfwCg = -999;
    int blockFuel = -999;
    int tow = -999;
    int lw = -999;
    int minDestFob = -999;
    int tripWind = -999;
};

class FMGC_FM
{
    public:
        FMGC_FM(){};
        FMGC_FM(AirlineConfigDB* airlineConfigDB_);
        ~FMGC_FM(){};

        //Setters
        void set_fpln_origin(std::string origin_, int fpln_);
        void set_fpln_dest(std::string dest_, int fpln_);
        void set_fpln_coRte(std::string coRte_, int fpln_);
        void set_fpln_altn(std::string altn_, int fpln_);
        void set_fpln_altnCoRte(std::string altnCoRte_, int fpln_);
        void set_fpln_fltNbr(std::string fltNbr_, int fpln_);
        void set_tropo(int tropo_, int fpln_);

        //Getters
        std::string get_fpln_origin(int fpln_);
        std::string get_fpln_dest(int fpln_);
        std::string get_fpln_altn(int fpln_);
        std::string get_fpln_coRte(int fpln_);
        std::string get_fpln_altnCoRte(int fpln_);
        std::string get_fpln_fltNbr(int fpln_);
        int get_tropo(int fpln_);



        int get_db_tropo();

    private:
        //Navigation
        //Performance
        AirlineConfigDB* airlineConfigDB;
        InitWeights weights;
        //F-PLN Management
        FlightPlan fpln_prim;
        FlightPlan fpln_sec;
        //Managed Guidance computation
        //Information display
        
        
};




#endif