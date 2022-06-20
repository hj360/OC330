#include "mcdu_elements.h"

#include <iostream>

Element::Element()
{
    text = "DEFAULT ELEMENT";
    row = 0;
    offset = 0;
    color = 0;

    type = 0;
}

Element::Element(std::string text_, int row_, int offset_, int color_, int size_)
{
    text = text_;
    row = row_;
    offset = offset_;
    color = color_;
    size = size_;
}

void Element::Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_)
{
    //Element is not allowed to be selected
    pad_.AddMSG(0);
    std::cout << "Element element select" << std::endl;
}

int Element::getType()
{
    return type;
}

//For rendering to a display. Sets reference vars to those of the specific element
void Element::getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_, FMGC* ActiveFMGC_)
{
    text_ = text;
    row_ = row;
    offset_ = offset;
    color_ = color;
    size_ = size;
}

Link::Link(std::string text_, int row_, int offset_, int color_, int size_, int linkedPageId_)
{
    text = text_;
    row = row_;
    offset = offset_;
    color = color_;
    size = size_;
    linkedPageId = linkedPageId_;

    type = 1;
}

void Link::Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_)
{
    linkedPageId_ = linkedPageId;
}

FromTo::FromTo(std::string text_, int row_, int offset_, int color_, int size_)
{
    text = text_;
    row = row_;
    offset = offset_;
    color = color_;
    size = size_;
    linkedPageId = 0;

    type = 1;
}

void FromTo::Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_)
{
    //Check if pad is clearing the field
    if(pad_.GetState() == 1)
    {
        ActiveFMGC_->FM.set_fpln_origin("", 1);
        ActiveFMGC_->FM.set_fpln_dest("", 1);
        text = "####/####";
        color = 5;

        pad_.EmptyScratchPad();
        pad_.setState(0);

        return;
    }


    std::string tempOrigin;
    std::string tempDest;
    std::string scratchpad;

    pad_.GetScratchPad(scratchpad);
    //Check if input is correct format
    if(scratchpad.length() != 9)
    {
        pad_.AddMSG(1);
        return;
    } else if(scratchpad[4] != '/')
    {
        pad_.AddMSG(1);
        return;
    }
     /*else if(scratchpad.substr(0, 4))
    {

    } else if(scratchpad.substr(5, 4))
    {

    }*/

    tempOrigin = scratchpad.substr(0, 4);
    tempDest = scratchpad.substr(5, 4);

    //If input is correct and valid - input into fmgc
    ActiveFMGC_->FM.set_fpln_origin(tempOrigin, 1);
    ActiveFMGC_->FM.set_fpln_dest(tempDest, 1);
    ActiveFMGC_->FM.get_fpln_origin(tempOrigin, 1);
    ActiveFMGC_->FM.get_fpln_dest(tempDest, 1);

    if(tempDest != "" && tempOrigin != "")
    {
        text = tempOrigin + "/" + tempDest;
        color = 2;
    } else {
        text = "####/####";
        color = 5;
    }

    pad_.EmptyScratchPad();
}

void FromTo::getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_, FMGC* ActiveFMGC_)
{
    std::string tempOrigin;
    std::string tempDest;
    ActiveFMGC_->FM.get_fpln_origin(tempOrigin, 1);
    ActiveFMGC_->FM.get_fpln_dest(tempDest, 1);
    
    if(tempDest != "" && tempOrigin != "")
    {
        text = tempOrigin + "/" + tempDest;
        color = 2;
    } else {
        text = "####/####";
        color = 5;
    }

    text_ = text;
    row_ = row;
    offset_ = offset;
    color_ = color;
    size_ = size;
}

FlightNumber::FlightNumber(std::string text_, int row_, int offset_, int color_, int size_)
{
    text = text_;
    row = row_;
    offset = offset_;
    color = color_;
    size = size_;
    linkedPageId = 0;

    type = 1;
}

void FlightNumber::Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_)
{
    //Check if pad is clearing the field
    if(pad_.GetState() == 1)
    {
        ActiveFMGC_->FM.set_fpln_fltNbr("", 1);
        text = "##########";
        color = 5;

        pad_.EmptyScratchPad();
        pad_.setState(0);

        return;
    }

    std::string tempFltNbr;

    pad_.GetScratchPad(tempFltNbr);
    //Check if input is correct format
    if(tempFltNbr.length() > 8)
    {
        pad_.AddMSG(1);
        return;
    }
    //If input is correct and valid - input into fmgc
    ActiveFMGC_->FM.set_fpln_fltNbr(tempFltNbr, 1);
    ActiveFMGC_->FM.get_fpln_fltNbr(tempFltNbr, 1);

    if(tempFltNbr != "")
    {
        text = tempFltNbr;
        color = 2;
    } else {
        text = "##########";
        color = 5;
    }

    pad_.EmptyScratchPad();
}

void FlightNumber::getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_, FMGC* ActiveFMGC_)
{
    std::string tempFltNbr;
    ActiveFMGC_->FM.get_fpln_fltNbr(tempFltNbr, 1);

    if(tempFltNbr != "")
    {
        text = tempFltNbr;
        color = 2;
    } else {
        text = "##########";
        color = 5;
    }

    text_ = text;
    row_ = row;
    offset_ = offset;
    color_ = color;
    size_ = size;
}