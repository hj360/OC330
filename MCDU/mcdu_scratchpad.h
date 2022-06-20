#include <string>
#include <vector>

#ifndef MCDU_SCRATCHPAD_H
#define MCDU_SCRATCHPAD_H

class Scratchpad
{
    public:
        Scratchpad(int size);
        ~Scratchpad();

        void setState(int state_);
        void AddMSG(int msgCode_);
        void AddToScratchpad(std::string str_);
        void CLRScratchpad();
        void GetScratchPad(std::string &pad_);
        void EmptyScratchPad();
        int GetState();

    private:
        //Usually 24 for length of MCDU screen in chars
        int maxLength;
        //Determines what state scratchpad is in. 0 - text, 1 - CLR, 2 - MSG
        int state;
        //The synamic scratchpad
        std::string pad;
        //Scratchpad messages maximum 5
        std::vector<std::string> msg;


};





#endif