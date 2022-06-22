#include "mcdu_elements.h"

#include <iostream>

Element::Element()
{
    text = "DEFAULT ELEMENT";
    row = 0;
    offset = 0;
    color = 0;
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
}

void Link::Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_)
{
    linkedPageId_ = linkedPageId;
}

FromTo::FromTo(int row_, int offset_)
{
    text = "####/####";
    row = row_;
    offset = offset_;
    color = 5;
    size = 1;
    linkedPageId = 0;
}

void FromTo::Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_)
{
    linkedPageId_ = linkedPageId;
    //Check if pad is clearing the field
    if(pad_.GetState() == 1)
    {
        ActiveFMGC_->FM.set_fpln_origin("", 1);
        ActiveFMGC_->FM.set_fpln_dest("", 1);

        ActiveFMGC_->FM.set_fpln_altn("", 1);
        ActiveFMGC_->FM.set_fpln_altnCoRte("", 1);

        ActiveFMGC_->FM.set_fpln_coRte("", 1);

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

    ActiveFMGC_->FM.set_fpln_altn("NONE", 1);
    ActiveFMGC_->FM.set_fpln_coRte("NONE", 1);

    //If input is correct and valid - input into fmgc
    ActiveFMGC_->FM.set_fpln_origin(tempOrigin, 1);
    ActiveFMGC_->FM.set_fpln_dest(tempDest, 1);

    pad_.EmptyScratchPad();

    linkedPageId_ = 5; //Go to route selection page
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

FlightNumber::FlightNumber(int row_, int offset_)
{
    text = "##########";
    row = row_;
    offset = offset_;
    color = 5;
    size = 1;
    linkedPageId = 0;
}

void FlightNumber::Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_)
{
    linkedPageId_ = linkedPageId;
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

AltnCoRte::AltnCoRte(int row_, int offset_)
{
    text = "----/----------";
    row = row_;
    offset = offset_;
    color = 0;
    size = 1;
    linkedPageId = 0;
}

void AltnCoRte::Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_)
{
    linkedPageId_ = linkedPageId;
    //Check if pad is clearing the field
    if(pad_.GetState() == 1)
    {
        ActiveFMGC_->FM.set_fpln_altn("", 1);
        ActiveFMGC_->FM.set_fpln_altnCoRte("", 1);
        text = "----/----------";
        color = 0;

        pad_.EmptyScratchPad();
        pad_.setState(0);

        return;
    }

    std::string tempAltnCoRte;

    pad_.GetScratchPad(tempAltnCoRte);
    //Check if input is correct format
    if(tempAltnCoRte.length() > 3 && tempAltnCoRte.length() < 11 )
    {
        if(tempAltnCoRte.length() == 4)
        {
            ActiveFMGC_->FM.set_fpln_altn(tempAltnCoRte, 1);
            ActiveFMGC_->FM.set_fpln_altnCoRte("", 1);
            color = 2;
            pad_.EmptyScratchPad();
            return;
        } else if (tempAltnCoRte[0] == '/')
        {
            tempAltnCoRte.erase(0, 1); //remove the '/'
            ActiveFMGC_->FM.set_fpln_altnCoRte(tempAltnCoRte, 1);
            color = 2;
            pad_.EmptyScratchPad();
            return;
        } else {
            pad_.AddMSG(1);
            return;
        }     
    } else
    {
        pad_.AddMSG(1);
        return;
    }    
}

void AltnCoRte::getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_, FMGC* ActiveFMGC_)
{
    std::string tempAltn;
    std::string tempAltnCoRte;
    ActiveFMGC_->FM.get_fpln_altn(tempAltn, 1);
    ActiveFMGC_->FM.get_fpln_altnCoRte(tempAltnCoRte, 1);
    
    if(tempAltnCoRte != "")
    {
        text = tempAltn + "/" + tempAltnCoRte;
        color = 2;
    } else if(tempAltn != "") {
        text = tempAltn;
        color = 2;
    } else {
        text = "----/----------";
        color = 0;
    }

    text_ = text;
    row_ = row;
    offset_ = offset;
    color_ = color;
    size_ = size;
}

CoRte::CoRte(int row_, int offset_)
{
    text = "##########";
    row = row_;
    offset = offset_;
    color = 5;
    size = 1;
    linkedPageId = 0;
}

void CoRte::Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_)
{
    linkedPageId_ = linkedPageId;
    //Check if pad is clearing the field
    if(pad_.GetState() == 1)
    {
        ActiveFMGC_->FM.set_fpln_coRte("", 1);
        text = "##########";
        color = 0;

        pad_.EmptyScratchPad();
        pad_.setState(0);

        return;
    }

    std::string tempCoRte;

    pad_.GetScratchPad(tempCoRte);
    //Check if input is correct format
    if(tempCoRte.length() > 3 && tempCoRte.length() < 11 )
    {
        ActiveFMGC_->FM.set_fpln_coRte(tempCoRte, 1);
        color = 2;
        pad_.EmptyScratchPad();
        return;
  
    } else
    {
        pad_.AddMSG(1);
        return;
    }    
}

void CoRte::getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_, FMGC* ActiveFMGC_)
{
    std::string tempCoRte;
    ActiveFMGC_->FM.get_fpln_coRte(tempCoRte, 1);
    
    if(tempCoRte != "")
    {
        text = tempCoRte;
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

Tropo::Tropo(int row_, int offset_)
{
    text = "#####";
    row = row_;
    offset = offset_;
    color = 5;
    size = 0;
    linkedPageId = 0;
}

void Tropo::Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_)
{
    linkedPageId_ = linkedPageId;
    int tempTropo;
    ActiveFMGC_->FM.get_tropo(tempTropo, 1);
    //Check if pad is clearing the field
    if(pad_.GetState() == 1)
    {
        if(tempTropo != -999)
        {
            ActiveFMGC_->FM.set_tropo(-999, 1);
            pad_.setState(0);
            pad_.EmptyScratchPad();
            return;
        } else {
            pad_.setState(0);
            pad_.EmptyScratchPad();
            pad_.AddMSG(0);
            return;
        }
        return;
    }

    std::string tempTropoStr;

    pad_.GetScratchPad(tempTropoStr);

    try
    {
        tempTropo = stoi(tempTropoStr);
    } catch (...)
    {
        pad_.AddMSG(1);
    }
    
    //Check if input is correct format
    if(tempTropo >= 0 && tempTropo <= 99999 )
    {
        ActiveFMGC_->FM.set_tropo(tempTropo, 1);
        color = 2;
        size = 1;
        pad_.EmptyScratchPad();
        return;
  
    } else
    {
        pad_.AddMSG(1);
        return;
    }    
}

void Tropo::getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_, FMGC* ActiveFMGC_)
{
    int tempTropo;
    ActiveFMGC_->FM.get_tropo(tempTropo, 1);
    
    if(tempTropo != -999)
    {
        text = std::to_string(tempTropo);
        color = 2;
        size = 1;
    } else {
        ActiveFMGC_->FM.get_db_tropo(tempTropo);
        text = std::to_string(tempTropo);
        color = 2;
        size = 0;
    }

    text_ = text;
    row_ = row;
    offset_ = offset;
    color_ = color;
    size_ = size;
}