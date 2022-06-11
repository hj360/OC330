//FMGC Components
#include "fmgc_fm.h"
#include "fmgc_fg.h"
#include "fmgc_fe.h"

#ifndef FMGC_H
#define FMGC_H

class FMGC
{
    public:
        FMGC(int id_);
        ~FMGC();

        //Separate FMGC components
        FMGC_FM FM;
        FMGC_FG FG;
        FMGC_FE FE;

    private:
        //1 is FMGC1, 2 is FMGC2
        int id;
        //Is FMGC available?
        bool avail;

};




#endif