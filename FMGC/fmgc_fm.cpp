#include "fmgc_fm.h"

FMGC_FM::FMGC_FM()
{
    //Initialize class vars with constructor vars


    //Initizlize prim and sec fplns
    //_______________PRIMARY FLIGHT PLAN_________________
    fpln_prim.origin = "";
    fpln_prim.dest = "";
    //_______________SECONDARY FLIGHT PLAN_______________
    fpln_sec.origin = "";
    fpln_sec.dest = "";

    fpln_prim.fltNbr = "";
    fpln_sec.fltNbr = "";



}

FMGC_FM::~FMGC_FM()
{

}

void FMGC_FM::set_fpln_origin(std::string origin_, int fpln_)
{
    //If all checks out enter origin into FM origin
    if(fpln_ == 1)
    {
        fpln_prim.origin = origin_;
    } else {
        fpln_sec.origin = origin_;
    }
}

void FMGC_FM::set_fpln_dest(std::string dest_, int fpln_)
{
    //If all checks out enter origin into FM origin
    if(fpln_ == 1)
    {
        fpln_prim.dest = dest_;
    } else {
        fpln_sec.dest = dest_;
    }
}

void FMGC_FM::get_fpln_origin(std::string &origin_, int fpln_)
{
    //Sets passed reference value to the value of the chosen fpln origin
    if(fpln_ == 1)
    {
        origin_ = fpln_prim.origin;
    } else {
        origin_ = fpln_sec.origin;
    }
}

void FMGC_FM::get_fpln_dest(std::string &dest_, int fpln_)
{
    //Sets passed reference value to the value of the chosen fpln origin
    if(fpln_ == 1)
    {
        dest_ = fpln_prim.dest;
    } else {
        dest_ = fpln_sec.dest;
    }
}

void FMGC_FM::set_fpln_fltNbr(std::string fltNbr_, int fpln_)
{
    //Check if string is valid
    if(fpln_ == 1)
    {
        fpln_prim.fltNbr = fltNbr_;
    } else {
        fpln_sec.fltNbr = fltNbr_;
    }
}

void FMGC_FM::get_fpln_fltNbr(std::string &fltNbr_, int fpln_)
{
    //Sets passed reference value to the value of the chosen fpln origin
    if(fpln_ == 1)
    {
        fltNbr_ = fpln_prim.fltNbr;
    } else {
        fltNbr_ = fpln_sec.fltNbr;
    }
}