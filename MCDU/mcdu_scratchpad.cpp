#include "mcdu_scratchpad.h"

Scratchpad::Scratchpad(int size)
{
    maxLength = size;
    state = 0;
}

Scratchpad::~Scratchpad()
{

}

void Scratchpad::AddToScratchpad(std::string str_)
{
    //Check if scratchpad has room and if mode is correct
    if(pad.length() < maxLength)
    {
        pad += str_;
    }
}

void Scratchpad::CLRScratchpad()
{
    if(pad.length() > 0 && state == 0)
    {
        pad.pop_back();
    } else if(pad.length() == 0 && state == 0)
    {
        pad = "CLR";
        state = 1;
    } else if(state == 1)
    {
        pad = "";
        state = 0;
    } else if(state == 2)
    {
        state = 0;
    }
}

void Scratchpad::GetScratchPad(std::string &pad_)
{
    //Check state of Scratchpad
    if(state == 0)
    {
        pad_ = pad;
    } else if(state == 1)
    {
        pad_ = "CLR";
    } else if(state == 2)
    {
        //Set scratchpad to the first message
        pad_ = msg[0];
    }
}