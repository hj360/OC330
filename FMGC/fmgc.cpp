#include <iostream>

#include "fmgc.h"

FMGC::FMGC(int id_)
{
    //Initialize class vars with constructor vars
    id = id_;
    //Create each FMGC Part
    FM = FMGC_FM();
    FG = FMGC_FG();
    FE = FMGC_FE();

    //FMGC is online
    avail = 1;
    

    //Error checking
    if(avail)
    {
        std::cout << "FMGC " << id << " Available." << std::endl;
    } else {
        std::cerr << "FMGC " << id << " Fail." << std::endl;
    }
}

FMGC::~FMGC()
{

}