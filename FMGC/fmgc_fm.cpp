#include "fmgc_fm.h"

FMGC_FM::FMGC_FM(AirlineConfigDB* airlineConfigDB_)
{
    airlineConfigDB = airlineConfigDB_;
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

void FMGC_FM::set_tropo(int tropo_, int fpln_)
{
    //Check if string is valid
    if(fpln_ == 1)
    {
        fpln_prim.tropo = tropo_;
    } else {
        fpln_sec.tropo = tropo_;
    }
}

void FMGC_FM::get_tropo(int &tropo_, int fpln_)
{
    //Sets passed reference value to the value of the chosen fpln origin
    if(fpln_ == 1)
    {
        tropo_ = fpln_prim.tropo;
    } else {

        tropo_ = fpln_sec.tropo;
    }
}










void FMGC_FM::get_db_tropo(int &tropo_)
{
    tropo_ = airlineConfigDB->tropo_default;
}