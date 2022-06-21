#include "fmgc_fm.h"

FMGC_FM::FMGC_FM()
{
    //Initialize class vars with constructor vars


    //Initizlize prim and sec fplns
    //_______________PRIMARY FLIGHT PLAN_________________
    fpln_prim.origin = "";
    fpln_prim.dest = "";
    fpln_prim.coRte = "";
    fpln_prim.altn = "";
    fpln_prim.altnCoRte = "";

    fpln_prim.fltNbr = "";

    fpln_prim.costIndex = -999;
    fpln_prim.crzFl = -999;
    fpln_prim.crzTemp = -999;
    fpln_prim.tropo = -999;   

    //_______________SECONDARY FLIGHT PLAN_______________
    fpln_sec.origin = "";
    fpln_sec.dest = "";
    fpln_sec.coRte = "";
    fpln_sec.altn = "";
    fpln_sec.altnCoRte = "";

    fpln_sec.fltNbr = "";

    fpln_sec.costIndex = -999;
    fpln_sec.crzFl = -999;
    fpln_sec.crzTemp = -999;
    fpln_sec.tropo = -999;   



    //_______________Initial Weights____________________(kg)
    weights.taxi = 400;
    weights.tripFuel = 0;
    weights.tripTime = 0;
    weights.rsv = 0;
    weights.altnFuel = 0;
    weights.finalFuel = 0;
    weights.extraFuel = 0;
    weights.zfw = 0;
    weights.zfwCg = 0;
    weights.blockFuel = 0;
    weights.tow = 0;
    weights.lw = 0;
    weights.minDestFob = 0;
    weights.tripWind = 0;

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

void FMGC_FM::set_fpln_altn(std::string altn_, int fpln_)
{
    //If all checks out enter origin into FM origin
    if(fpln_ == 1)
    {
        fpln_prim.altn = altn_;
    } else {
        fpln_sec.altn = altn_;
    }
}

void FMGC_FM::get_fpln_altn(std::string &altn_, int fpln_)
{
    //Sets passed reference value to the value of the chosen fpln origin
    if(fpln_ == 1)
    {
        altn_ = fpln_prim.altn;
    } else {
        altn_ = fpln_sec.altn;
    }
}

void FMGC_FM::set_fpln_coRte(std::string coRte_, int fpln_)
{
    //If all checks out enter origin into FM origin
    if(fpln_ == 1)
    {
        fpln_prim.coRte = coRte_;
    } else {
        fpln_sec.coRte = coRte_;
    }
}

void FMGC_FM::get_fpln_coRte(std::string &coRte_, int fpln_)
{
    //Sets passed reference value to the value of the chosen fpln origin
    if(fpln_ == 1)
    {
        coRte_ = fpln_prim.coRte;
    } else {
        coRte_ = fpln_sec.coRte;
    }
}

void FMGC_FM::set_fpln_altnCoRte(std::string altnCoRte_, int fpln_)
{
    //If all checks out enter origin into FM origin
    if(fpln_ == 1)
    {
        fpln_prim.altnCoRte = altnCoRte_;
    } else {
        fpln_sec.altnCoRte = altnCoRte_;
    }
}

void FMGC_FM::get_fpln_altnCoRte(std::string &altnCoRte_, int fpln_)
{
    //Sets passed reference value to the value of the chosen fpln origin
    if(fpln_ == 1)
    {
        altnCoRte_ = fpln_prim.altnCoRte;
    } else {
        altnCoRte_ = fpln_sec.altnCoRte;
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