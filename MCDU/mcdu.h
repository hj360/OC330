#include <vector>

#ifndef MCDU_H
#define MCDU_H


class MCDU
{
    public:
        MCDU(int id_);
        ~MCDU();

    private:
        //1 is MCDU1, 2 is MCDU2, 3 is MCDU3
        int id;
        //Is MCDU functional?
        bool avail;
        //MCDU Display Matrix 24 characters long, 14 characters high
        std::vector<std::vector<char>> display_matrix;

        //PAGE ActivePage;

        int dimX;
        int dimY;

        int refreshRate;

        char defaultChar;

};




#endif