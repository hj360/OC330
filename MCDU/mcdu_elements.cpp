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


//_______________________________________________Engine type_________________________________________//
EngineType::EngineType(int row_, int offset_)
{
    text = "#######";
    row = row_;
    offset = offset_;
    color = 5;
    size = 1;
    linkedPageId = 0;
}

void EngineType::Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_)
{
    //Return error if user tries to select engine type
    linkedPageId_ = linkedPageId;
    pad_.AddMSG(1);
    return;
}

void EngineType::getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_, FMGC* ActiveFMGC_)
{    
    text = ActiveFMGC_->getEngineType();
    color = 1;

    text_ = text;
    row_ = row;
    offset_ = offset;
    color_ = color;
    size_ = size;
}

//_______________________________________________AIRCRAFT TYPE__________________________________________//
AircraftType::AircraftType(int row_, int offset_)
{
    text = "#######";
    row = row_;
    offset = offset_;
    color = 0;
    size = 1;
    linkedPageId = 0;
}

void AircraftType::Select(int &linkedPageId_, Scratchpad &pad_, FMGC* ActiveFMGC_)
{
    //Return error if user tries to select engine type
    linkedPageId_ = linkedPageId;
    pad_.AddMSG(1);
    return;
}

void AircraftType::getElement(std::string &text_, int &row_, int &offset_, int &color_, int &size_, FMGC* ActiveFMGC_)
{    
    text = ActiveFMGC_->getAircraftType();
    color = 0;

    text_ = text;
    row_ = row;
    offset_ = offset;
    color_ = color;
    size_ = size;
}


//_______________________________________________FROM TO FIELD________________________________________//

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
    if(ActiveFMGC_->FM.get_fpln_origin(1) != "" && ActiveFMGC_->FM.get_fpln_dest(1) != "")
    {
        text = ActiveFMGC_->FM.get_fpln_origin(1) + "/" + ActiveFMGC_->FM.get_fpln_dest(1);
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


//_______________________________________________FLIGHT NUMBER________________________________________//

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
  
    if(ActiveFMGC_->FM.get_fpln_fltNbr(1) != "")
    {
        text = ActiveFMGC_->FM.get_fpln_fltNbr(1);;
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


//_______________________________________________ALTN CO ROUTE________________________________________//

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
   
    if(ActiveFMGC_->FM.get_fpln_altnCoRte(1) != "")
    {
        text = ActiveFMGC_->FM.get_fpln_altn(1) + "/" + ActiveFMGC_->FM.get_fpln_altnCoRte(1);
        color = 2;
    } else if(ActiveFMGC_->FM.get_fpln_altn(1) != "") {
        text = ActiveFMGC_->FM.get_fpln_altn(1);
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

//_______________________________________________CO ROUTE________________________________________//

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
    
    if(ActiveFMGC_->FM.get_fpln_coRte(1) != "")
    {
        text = ActiveFMGC_->FM.get_fpln_coRte(1);
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

//_______________________________________________TROPO________________________________________//

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
    //Check if pad is clearing the field
    if(pad_.GetState() == 1)
    {
        if(ActiveFMGC_->FM.get_tropo(1) != -999)
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
    int tempTropo;

    pad_.GetScratchPad(tempTropoStr);

    try
    {
        tempTropo = stoi(tempTropoStr);
    } catch (...)
    {
        pad_.AddMSG(1);
        return;
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
    if(ActiveFMGC_->FM.get_tropo(1) != -999)
    {
        text = std::to_string(ActiveFMGC_->FM.get_tropo(1));
        color = 2;
        size = 1;
    } else {
        text = std::to_string(ActiveFMGC_->FM.get_db_tropo());
        color = 2;
        size = 0;
    }

    text_ = text;
    row_ = row;
    offset_ = offset;
    color_ = color;
    size_ = size;
}