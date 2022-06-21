#include <string>

#ifndef FMGC_FM_H
#define FMGC_FM_H

struct FlightPlan
{
    std::string origin;
    std::string dest;
    std::string coRte;
    std::string altn;
    std::string altnCoRte;

    std::string fltNbr;

    int costIndex;
    int crzFl;
    int crzTemp;
    int tropo;   
    
};

struct InitWeights
{
    int taxi;
    int tripFuel;
    int tripTime;
    int rsv;
    int altnFuel;
    int finalFuel;
    int extraFuel;
    int zfw;
    int zfwCg;
    int blockFuel;
    int tow;
    int lw;
    int minDestFob;
    int tripWind;
};

class FMGC_FM
{
    public:
        FMGC_FM();
        ~FMGC_FM();

        //Setters
        void set_fpln_origin(std::string origin_, int fpln_);
        void set_fpln_dest(std::string dest_, int fpln_);
        void set_fpln_coRte(std::string coRte_, int fpln_);
        void set_fpln_altn(std::string altn_, int fpln_);
        void set_fpln_altnCoRte(std::string altnCoRte_, int fpln_);
        void set_fpln_fltNbr(std::string fltNbr_, int fpln_);

        //Getters
        void get_fpln_origin(std::string &origin_, int fpln_);
        void get_fpln_dest(std::string &dest_, int fpln_);
        void get_fpln_altn(std::string &altn_, int fpln_);
        void get_fpln_coRte(std::string &coRte_, int fpln_);
        void get_fpln_altnCoRte(std::string &altnCoRte_, int fpln_);
        void get_fpln_fltNbr(std::string &fltNbr_, int fpln_);

    private:
        //Navigation
        //Performance
        InitWeights weights;
        //F-PLN Management
        FlightPlan fpln_prim;
        FlightPlan fpln_sec;
        //Managed Guidance computation
        //Information display
        
        
};




#endif