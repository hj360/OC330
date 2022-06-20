#include <string>

#ifndef FMGC_FM_H
#define FMGC_FM_H

struct FlightPlan
{
    std::string origin;
    std::string dest;

    std::string fltNbr;
    
};

class FMGC_FM
{
    public:
        FMGC_FM();
        ~FMGC_FM();

        //Setters
        void set_fpln_origin(std::string origin_, int fpln_);
        void set_fpln_dest(std::string dest_, int fpln_);
        void set_fpln_fltNbr(std::string fltNbr_, int fpln_);

        //Getters
        void get_fpln_origin(std::string &origin_, int fpln_);
        void get_fpln_dest(std::string &dest_, int fpln_);
        void get_fpln_fltNbr(std::string &fltNbr_, int fpln_);

    private:
        //Navigation
        //Performance
        //F-PLN Management
        //Managed Guidance computation
        //Information display

        //Primary and secondary flight plans
        FlightPlan fpln_prim;
        FlightPlan fpln_sec;
};




#endif