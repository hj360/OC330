#include "mcdu_scratchpad.h"

Scratchpad::Scratchpad(int size)
{
    maxLength = size;
    state = 0;
}

Scratchpad::~Scratchpad()
{

}

void Scratchpad::setState(int state_)
{
    state = state_;
}

void Scratchpad::AddToScratchpad(std::string str_)
{
    //Check if scratchpad has room and if mode is correct
    if(pad.length() < maxLength && state == 0)
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
        msg.erase(msg.begin());
        state = 0;
    }
}

void Scratchpad::AddMSG(int msgCode_)
{
    switch(msgCode_)
    {
        case 0:
            msg.push_back("NOT ALLOWED");
            break;
        case 1:
            msg.push_back("FORMAT ERROR");
            break;
        case 2:
            msg.push_back("ENTRY OUT OF RANGE");
            break;
        case 3:
            msg.push_back("NOT IN DATABASE");
            break;
        case 4:
            msg.push_back("GPS PRIMARY LOST");
            break;
        case 5:
            msg.push_back("GPS PRIMARY");
            break;

        default:
            break;
    }

    //Remove last element if there are more than 5 messages
    //Last in first out structure
    if(msg.size() > 5)
    {
        msg.pop_back();
    }
}

void Scratchpad::GetScratchPad(std::string &pad_)
{
    //Check for scratchpad messages
    if(msg.size() > 0 && state != -1)
    {
        state = 2;
    }
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
    } else if(state == 3)
    {
        pad_ = pad;
    }
}

void Scratchpad::SetScratchPad(std::string pad_)
{
    pad = pad_;
}

void Scratchpad::EmptyScratchPad()
{
    pad = "";
}

int Scratchpad::GetState()
{
    return state;
}