#include <iostream>

#include "mcdu.h"

MCDU::MCDU(int id_)
{
    //Initialize class vars with constructor vars
    id = id_;

    dimX = 24;
    dimY = 14;

    defaultChar = '0';

    //Initialize vector matrix with default values with speciied dimensions
    display_matrix.resize(dimX, std::vector<char>(dimY, defaultChar));



    //MCDU is online
    avail = 1;
    
    //Error checking
    if(avail)
    {
        std::cout << "MCDU " << id << " Available." << std::endl;
    } else {
        std::cerr << "MCDU " << id << " Fail." << std::endl;
    }
}

MCDU::~MCDU()
{

}