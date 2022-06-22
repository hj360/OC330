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

std::string FMGC_FM::get_fpln_origin(int fpln_)
{
    //Sets passed reference value to the value of the chosen fpln origin
    if(fpln_ == 1)
    {
        return fpln_prim.origin;
    } else {
        return fpln_sec.origin;
    }
}

std::string FMGC_FM::get_fpln_dest(int fpln_)
{
    //Sets passed reference value to the value of the chosen fpln origin
    if(fpln_ == 1)
    {
        return fpln_prim.dest;
    } else {
        return fpln_sec.dest;
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

std::string FMGC_FM::get_fpln_altn(int fpln_)
{
    //Sets passed reference value to the value of the chosen fpln origin
    if(fpln_ == 1)
    {
        return fpln_prim.altn;
    } else {
        return fpln_sec.altn;
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

std::string FMGC_FM::get_fpln_coRte(int fpln_)
{
    //Sets passed reference value to the value of the chosen fpln origin
    if(fpln_ == 1)
    {
        return fpln_prim.coRte;
    } else {
        return fpln_sec.coRte;
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

std::string FMGC_FM::get_fpln_altnCoRte(int fpln_)
{
    //Sets passed reference value to the value of the chosen fpln origin
    if(fpln_ == 1)
    {
        return fpln_prim.altnCoRte;
    } else {
        return fpln_sec.altnCoRte;
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

std::string FMGC_FM::get_fpln_fltNbr(int fpln_)
{
    //Sets passed reference value to the value of the chosen fpln origin
    if(fpln_ == 1)
    {
        return fpln_prim.fltNbr;
    } else {
        return fpln_sec.fltNbr;
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

int FMGC_FM::get_tropo(int fpln_)
{
    //Sets passed reference value to the value of the chosen fpln origin
    if(fpln_ == 1)
    {
        return fpln_prim.tropo;
    } else {

        return fpln_sec.tropo;
    }
}

void FMGC_FM::set_cost_index(int costIndex_, int fpln_)
{
    //Check if string is valid
    if(fpln_ == 1)
    {
        fpln_prim.costIndex = costIndex_;
    } else {
        fpln_sec.costIndex = costIndex_;
    }
}

int FMGC_FM::get_cost_index(int fpln_)
{
    //Sets passed reference value to the value of the chosen fpln origin
    if(fpln_ == 1)
    {
        return fpln_prim.costIndex;
    } else {

        return fpln_sec.costIndex;
    }
}

void FMGC_FM::set_crz_fl(int crzFl_, int fpln_)
{
    //Check if string is valid
    if(fpln_ == 1)
    {
        fpln_prim.crzFl = crzFl_;
    } else {
        fpln_sec.crzFl = crzFl_;
    }
}

int FMGC_FM::get_crz_fl(int fpln_)
{
    //Sets passed reference value to the value of the chosen fpln origin
    if(fpln_ == 1)
    {
        return fpln_prim.crzFl;
    } else {

        return fpln_sec.crzFl;
    }
}

void FMGC_FM::set_crz_temp(int crzTemp_, int fpln_)
{
    //Check if string is valid
    if(fpln_ == 1)
    {
        fpln_prim.crzTemp = crzTemp_;
    } else {
        fpln_sec.crzTemp = crzTemp_;
    }
}

int FMGC_FM::get_crz_temp(int fpln_)
{
    //Sets passed reference value to the value of the chosen fpln origin
    if(fpln_ == 1)
    {
        return fpln_prim.crzTemp;
    } else {

        return fpln_sec.crzTemp;
    }
}












int FMGC_FM::get_db_tropo()
{
    return airlineConfigDB->tropo_default;
}