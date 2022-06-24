#include "mcdu_pages.h"

//Returns a DD coordinate in DDM format
std::string getDDM(long double DD)
{
    std::string tempString;

    int degrees = DD;
    long double minutes = (DD - degrees)*60;
    if(minutes < 0)
    {
        minutes = -minutes;
    }

    std::stringstream ss;
    ss << std::fixed << std::setprecision(0) << degrees;
    tempString = ss.str() + "c";
    ss.str(std::string());
    ss << std::fixed << std::setprecision(1) << minutes;
    tempString += ss.str();

    return tempString;
}

Page::Page()
{
    pageID = 0;
}

std::vector<Element> Page::getElements(FMGC* ActiveFMGC_)
{
    pageElements.clear();
    return pageElements;
}

void Page::selectLSK(int lsk_, FMGC* ActiveFMGC_, int &p_act_, Scratchpad &pad_)
{

}

int Page::getPageId()
{
    return pageID;
}

int Page::getLeftPageId()
{
    return leftPageID;
}

int Page::getRightPageId()
{
    return rightPageID;
}

Data_Index_1::Data_Index_1()
{
    pageID = 1;
    leftPageID = 0;
    rightPageID = 0;
}

void Data_Index_1::selectLSK(int lsk_, FMGC* ActiveFMGC_, int &p_act_, Scratchpad &pad_)
{
    p_act_ = this->pageID;

    if(lsk_ == 1)
    {
        p_act_ = 7;
        return;
    } else if(lsk_ == 3)
    {
        p_act_ = 6;
        return;
    } else if(lsk_ == 4)
    {
        p_act_ = 2;
        return;
    } else {
        pad_.AddMSG(0);
        return;
    }


}

std::vector<Element> Data_Index_1::getElements(FMGC* ActiveFMGC_)
{
    pageElements.clear();
    //Elements for Data index 1
    pageElements.push_back(Element("DATA INDEX    1/2 <>", 0, 4, 0, 1));
    pageElements.push_back(Element("POSITION", 1, 1, 0, 0));
    pageElements.push_back(Element("<MONITOR", 2, 0, 0, 1));
    pageElements.push_back(Element("IRS", 3, 1, 0, 0));
    pageElements.push_back(Element("<MONITOR", 4, 0, 0, 1));
    pageElements.push_back(Element("GPS", 5, 1, 0, 0));
    pageElements.push_back(Element("<MONITOR", 6, 0, 0, 1));
    pageElements.push_back(Element("<A/C STATUS", 8, 0, 0, 1));
    pageElements.push_back(Element("CLOSEST", 9, 1, 0, 0));
    pageElements.push_back(Element("<AIRPORTS", 10, 0, 0, 1));
    pageElements.push_back(Element("PRINT", 9, 18, 0, 0));
    pageElements.push_back(Element("FUNCTION>", 10, 15, 0, 1));
    pageElements.push_back(Element("EQUITIME", 11, 1, 0, 0));
    pageElements.push_back(Element("<POINT", 12, 0, 0, 1));
    pageElements.push_back(Element("AOC", 11, 18, 0, 0));
    pageElements.push_back(Element("FUNCTION>", 12, 15, 0, 1));

    return pageElements;
}




Ac_Status::Ac_Status()
{
    pageID = 2;
    leftPageID = 0;
    rightPageID = 0;
}

void Ac_Status::selectLSK(int lsk_, FMGC* ActiveFMGC_, int &p_act_, Scratchpad &pad_)
{
    p_act_ = this->pageID;

    switch(lsk_)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        default:
            break;

    }

}


std::vector<Element> Ac_Status::getElements(FMGC* ActiveFMGC_)
{
    pageElements.clear();

    pageElements.push_back(Element("ENG", 1, 1, 0, 0));
    pageElements.push_back(Element("ACTIVE NAV DATA BASE", 3, 1, 0, 0));
    pageElements.push_back(Element("28MAY-24JUN", 4, 1, 2 ,1));
    pageElements.push_back(Element("AB2388371", 4, 14, 1, 1));
    pageElements.push_back(Element("SECOND NAV DATA BASE", 5, 1, 0, 0));
    pageElements.push_back(Element("<28MAY-24JUN", 6, 0, 2, 0));
    pageElements.push_back(Element("CHG CODE", 9, 0, 0, 0));
    pageElements.push_back(Element("[ ]", 10, 0, 2, 1));
    pageElements.push_back(Element("IDLE/PERF", 11, 0, 0, 0));
    pageElements.push_back(Element("SOFTWARE", 11, 15, 0, 0));
    pageElements.push_back(Element("+0.0/+4.4", 12, 0, 1, 1));
    pageElements.push_back(Element("STATUS/XLOAD>", 12, 11, 0, 1));

    //Dynamic values
    std::string tempString;
    int tempRow, tempOffset, tempColor, tempSize;

    //Aircraft type
    tempString = ActiveFMGC_->getAircraftType();
    if(tempString == "")
    {
        tempString = "#######";
    }
    tempRow = 0;
    tempOffset = 6;
    tempColor = 0;
    tempSize = 1;
    
    pageElements.push_back(Element(tempString, tempRow, tempOffset, tempColor, tempSize));

    //Engine type
    tempString = ActiveFMGC_->getEngineType();
    if(tempString == "")
    {
        tempString = "#######";
    }
    tempRow = 2;
    tempOffset = 0;
    tempColor = 1;
    tempSize = 1;
    
    pageElements.push_back(Element(tempString, tempRow, tempOffset, tempColor, tempSize));

    return pageElements;
}

Init_A::Init_A()
{
    pageID = 3;
    leftPageID = 4;
    rightPageID = 4;
}

void Init_A::selectLSK(int lsk_, FMGC* ActiveFMGC_, int &p_act_, Scratchpad &pad_)
{
    p_act_ = this->pageID;

    if(lsk_ == 1)
    {
        if(pad_.GetState() == 1)
        {
            ActiveFMGC_->FM.set_fpln_coRte("", 1);
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
            pad_.EmptyScratchPad();
            return;
    
        } else
        {
            pad_.AddMSG(1);
            return;
        }    

        return;

    }else if(lsk_ == 2)
    {
        if(pad_.GetState() == 1)
        {
            ActiveFMGC_->FM.set_fpln_altn("", 1);
            ActiveFMGC_->FM.set_fpln_altnCoRte("", 1);
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
                pad_.EmptyScratchPad();
                p_act_ = 5;
                return;
            } else if (tempAltnCoRte[0] == '/')
            {
                tempAltnCoRte.erase(0, 1); //remove the '/'
                ActiveFMGC_->FM.set_fpln_altnCoRte(tempAltnCoRte, 1);
                pad_.EmptyScratchPad();
                p_act_ = 5;
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

        return;

    } else if(lsk_ == 3)
    {
        //Check if pad is clearing the field
        if(pad_.GetState() == 1)
        {
            ActiveFMGC_->FM.set_fpln_fltNbr("", 1);
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
        return;

    } else if(lsk_ == 5)
    {
        if(pad_.GetState() == 1 && ActiveFMGC_->FM.get_cost_index(1) != -999)
        {
            ActiveFMGC_->FM.set_cost_index(-999, 1);
            pad_.EmptyScratchPad();
            pad_.setState(0);
            return;
        } else if (pad_.GetState() == 1 )
        {
            pad_.AddMSG(0);
            return;
        }

        std::string tempScratchPad;
        pad_.GetScratchPad(tempScratchPad);
        int tempCostIndex;
        try
        {
            tempCostIndex = stoi(tempScratchPad);
        } catch (...)
        {
            pad_.AddMSG(1);
            return;
        }

        if(tempCostIndex >= 0 && tempCostIndex <= 999 )
        {
            ActiveFMGC_->FM.set_cost_index(tempCostIndex, 1);
            pad_.EmptyScratchPad();
            return;
    
        } else
        {
            pad_.AddMSG(2);
            return;
        }    
        return;
    } else if(lsk_ == 6)
    {
        if(pad_.GetState() == 1 && ActiveFMGC_->FM.get_crz_fl(1) != -999)
        {
            ActiveFMGC_->FM.set_crz_fl(-999, 1);
            ActiveFMGC_->FM.set_crz_temp(-999, 1);
            pad_.EmptyScratchPad();
            pad_.setState(0);
            return;
        } else if (pad_.GetState() == 1 )
        {
            pad_.AddMSG(0);
            return;
        }

        std::string tempScratchPad;
        
        pad_.GetScratchPad(tempScratchPad);
        std::string tempCrzFlStr = tempScratchPad;
        std::string tempCrzTempStr = tempScratchPad;
        int tempCrzFl = ActiveFMGC_->FM.get_crz_fl(1);
        int tempCrzTemp = ActiveFMGC_->FM.get_crz_temp(1);
        //Check input format
        if(tempScratchPad.length() > 3 && tempScratchPad[3] == '/')
        {
            tempCrzFlStr = tempCrzFlStr.substr(0, 3);
            tempCrzTempStr = tempCrzTempStr.substr(4, tempScratchPad.length()-4);

            try
            {
                tempCrzFl = stoi(tempCrzFlStr);
                tempCrzTemp = stoi(tempCrzTempStr);
            } catch (...)
            {
                pad_.AddMSG(1);
                return;
            }

        } else if (tempScratchPad.length() > 2 && tempScratchPad[2] == '/' )
        {
            tempCrzFlStr = tempCrzFlStr.substr(0, 2);
            tempCrzTempStr = tempCrzTempStr.substr(3, tempScratchPad.length()-3);

            try
            {
                tempCrzFl = stoi(tempCrzFlStr);
                tempCrzTemp = stoi(tempCrzTempStr);
            } catch (...)
            {
                pad_.AddMSG(1);
                return;
            }

        }else if (tempScratchPad.length() > 1 && tempScratchPad[1] == '/' )
        {
            tempCrzFlStr = tempCrzFlStr.substr(0, 1);
            tempCrzTempStr = tempCrzTempStr.substr(2, tempScratchPad.length()-2);

            try
            {
                tempCrzFl = stoi(tempCrzFlStr);
                tempCrzTemp = stoi(tempCrzTempStr);
            } catch (...)
            {
                pad_.AddMSG(1);
                return;
            }

        } else if (tempScratchPad.length() > 0 && tempScratchPad[0] == '/')
        {
            try
            {
                tempCrzTemp = stoi(tempCrzTempStr.substr(1, tempScratchPad.length()-1));
                
            } catch (...)
            {
                pad_.AddMSG(1);
                return;
            }

        } else if (tempScratchPad.length() == 3 || tempScratchPad.length() == 2 || tempScratchPad.length() == 1)
        {
            try
            {
                tempCrzFl = stoi(tempScratchPad);
                tempCrzTemp = -999;
            } catch (...)
            {
                pad_.AddMSG(1);
                return;
            }

        } else {
            pad_.AddMSG(1);
            return;
        }

        //Check if input is correct format
        if(tempCrzFl > 0 && tempCrzFl <= 410 && ActiveFMGC_->FM.is_fpln_init(1))
        {
            ActiveFMGC_->FM.set_crz_fl(tempCrzFl, 1);
            if(tempCrzTemp > 0 && tempCrzTemp <= 99)
            {
                tempCrzTemp = -tempCrzTemp;
            }

            ActiveFMGC_->FM.set_crz_temp(tempCrzTemp, 1);
            pad_.EmptyScratchPad();
            return;
    
        } else
        {
            pad_.AddMSG(2);
            return;
        }    
        return;
    } else if(lsk_ == 7)
    {
        if(pad_.GetState() == 1)
        {
            ActiveFMGC_->FM.set_fpln_origin("", 1);
            ActiveFMGC_->FM.set_fpln_dest("", 1);
            ActiveFMGC_->FM.set_fpln_altn("", 1);
            ActiveFMGC_->FM.set_fpln_altnCoRte("", 1);
            ActiveFMGC_->FM.set_fpln_coRte("", 1);
            ActiveFMGC_->FM.set_crz_fl(-999, 1);
            ActiveFMGC_->FM.set_crz_temp(-999, 1);
            ActiveFMGC_->FM.set_cost_index(-999, 1);
            ActiveFMGC_->FM.set_fpln_fltNbr("", 1);

            pad_.EmptyScratchPad();
            pad_.setState(0);

            return;
        }

        std::string tempOrigin;
        std::string tempDest;
        std::string scratchpad;

        pad_.GetScratchPad(scratchpad);
        //Check if input is correct format
        //Check if airports exist in the database
        if(scratchpad.length() != 9)
        {
            pad_.AddMSG(1);
            return;
        } else if(scratchpad[4] != '/')
        {
            pad_.AddMSG(1);
            return;
        } else if(!ActiveFMGC_->FM.arpt_in_database(scratchpad.substr(0, 4)))
        {
            pad_.AddMSG(3);
            return;
        } else if(!ActiveFMGC_->FM.arpt_in_database(scratchpad.substr(5, 4)))
        {
            pad_.AddMSG(3);
            return;
        }

        tempOrigin = scratchpad.substr(0, 4);
        tempDest = scratchpad.substr(5, 4);

        //Check if there already exists a flightplan
        if(ActiveFMGC_->FM.is_fpln_init(1))
        {
            ActiveFMGC_->FM.set_fpln_origin("", 1);
            ActiveFMGC_->FM.set_fpln_dest("", 1);
            ActiveFMGC_->FM.set_fpln_altn("", 1);
            ActiveFMGC_->FM.set_fpln_altnCoRte("", 1);
            ActiveFMGC_->FM.set_fpln_coRte("", 1);
            ActiveFMGC_->FM.set_crz_fl(-999, 1);
            ActiveFMGC_->FM.set_crz_temp(-999, 1);
            ActiveFMGC_->FM.set_cost_index(-999, 1);
            ActiveFMGC_->FM.set_fpln_fltNbr("", 1);
        }
        //If input is correct and valid - input into fmgc
        ActiveFMGC_->FM.set_fpln_origin(tempOrigin, 1);
        ActiveFMGC_->FM.set_fpln_dest(tempDest, 1);
        ActiveFMGC_->FM.set_fpln_altn("NONE", 1);
        ActiveFMGC_->FM.set_fpln_coRte("NONE", 1);

        pad_.EmptyScratchPad();

        p_act_ = 5; //Go to route selection page
        return;
        
    } else if(lsk_ == 8)
    {
        return;
    } else if(lsk_ == 9)
    {
        return;
    } else if(lsk_ == 11)
    {
        return;
    } else if(lsk_ == 12)
    {
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
        if(tempTropo >= 0 && tempTropo <= 60000 )
        {
            ActiveFMGC_->FM.set_tropo(tempTropo, 1);
            pad_.EmptyScratchPad();
            return;
    
        } else
        {
            pad_.AddMSG(1);
            return;
        }
        return;

    } else {
        pad_.AddMSG(0);
        return;
    }
}

std::vector<Element> Init_A::getElements(FMGC* ActiveFMGC_)
{
    pageElements.clear();

    pageElements.push_back(Element("INIT", 0, 10, 0, 1));
    pageElements.push_back(Element("<>", 0, 22, 0, 1));
    pageElements.push_back(Element("CO RTE", 1, 1, 0, 0));
    pageElements.push_back(Element("FROM/TO", 1, 15, 0, 0));
    pageElements.push_back(Element("ALTN/CO RTE", 3, 0, 0, 0));
    pageElements.push_back(Element("FLT NBR", 5, 0, 0, 0));
    pageElements.push_back(Element("COST INDEX", 9, 0, 0, 0));
    pageElements.push_back(Element("CRZ FL/TEMP", 11, 0, 0, 0));
    pageElements.push_back(Element("TROPO", 11, 19, 0, 0));
    
    //Dynamic values
    std::string tempString;
    int tempRow, tempOffset, tempColor, tempSize, tempNum;

    //CoRoute
    tempString = ActiveFMGC_->FM.get_fpln_coRte(1);
    if(tempString == "")
    {
        tempString = "##########";
        tempRow = 2;
        tempOffset = 0;
        tempColor = 5;
        tempSize = 1;
    } else {
        tempString = ActiveFMGC_->FM.get_fpln_coRte(1);
        tempRow = 2;
        tempOffset = 0;
        tempColor = 2;
        tempSize = 1;
    }

    pageElements.push_back(Element(tempString, tempRow, tempOffset, tempColor, tempSize));

    //AltnCorte
    tempString = ActiveFMGC_->FM.get_fpln_altn(1);
    if(tempString != "")
    {
        tempString = ActiveFMGC_->FM.get_fpln_altn(1);
        if(ActiveFMGC_->FM.get_fpln_altnCoRte(1) != "")
        {
            tempString += "/" + ActiveFMGC_->FM.get_fpln_altnCoRte(1);
        }
        tempColor = 2;
    } else if(ActiveFMGC_->FM.get_fpln_altn(1) != "") {
        tempString = ActiveFMGC_->FM.get_fpln_altn(1);
        tempColor = 2;
    } else {
        tempString = "----/----------";
        tempColor = 0;
    }

    tempRow = 4;
    tempOffset = 0;
    tempSize = 1;

    pageElements.push_back(Element(tempString, tempRow, tempOffset, tempColor, tempSize));

    //Flight number
    tempString = ActiveFMGC_->FM.get_fpln_fltNbr(1);
    if(tempString != "")
    {
        tempColor = 2;
    } else {
        tempString = "##########";
        tempColor = 5;
    }

    tempRow = 6;
    tempOffset = 0;
    tempSize = 1;

    pageElements.push_back(Element(tempString, tempRow, tempOffset, tempColor, tempSize));

    //CostIndex
    tempNum = ActiveFMGC_->FM.get_cost_index(1);
    if(tempNum != -999)
    {
        tempString = std::to_string(ActiveFMGC_->FM.get_cost_index(1));
        tempColor = 2;
    } else {
        if(ActiveFMGC_->FM.is_fpln_init(1))
        {
            tempString = "###";
            tempColor = 5;
        } else {
            tempString = "---";
            tempColor = 0;
        }
    }

    tempRow = 10;
    tempOffset = 0;
    tempSize = 1;

    pageElements.push_back(Element(tempString, tempRow, tempOffset, tempColor, tempSize));

    //CrzFLTemp
    if(ActiveFMGC_->FM.get_crz_fl(1) != -999)
    {
        int tempFL = ActiveFMGC_->FM.get_crz_fl(1);

        if(tempFL < 10)
        {
            tempString = "FL00" + std::to_string(tempFL) + " /";
        } else if(tempFL < 100)
        {
            tempString = "FL0" + std::to_string(tempFL) + " /";
        } else {
            tempString = "FL" + std::to_string(tempFL) + " /";
        }

         //" /" + std::to_string(ActiveFMGC_->FM.get_crz_temp(1));
        tempColor = 2;
        tempRow = 12;
        tempOffset = 0;
        tempSize = 1;

        pageElements.push_back(Element(tempString, tempRow, tempOffset, tempColor, tempSize));

        if(ActiveFMGC_->FM.get_crz_temp(1) == -999)
        {
            tempString = std::to_string(ActiveFMGC_->FM.get_isa(tempFL)) + "c";
            tempSize = 0;
        } else {
            tempString = std::to_string(ActiveFMGC_->FM.get_crz_temp(1)) + "c";
            tempSize = 1;
        }

        tempOffset = 7;
        pageElements.push_back(Element(tempString, tempRow, tempOffset, tempColor, tempSize));

    } else {
        if(ActiveFMGC_->FM.is_fpln_init(1))
        {
            tempString = "##### /###c";
            tempColor = 5;
        } else {
            tempString = "----- /---c";
            tempColor = 0;
        }

        tempRow = 12;
        tempOffset = 0;
        tempSize = 1;

        pageElements.push_back(Element(tempString, tempRow, tempOffset, tempColor, tempSize));
    }

    //FromTo
    if(ActiveFMGC_->FM.get_fpln_origin(1) != "" && ActiveFMGC_->FM.get_fpln_dest(1) != "")
    {
        tempString = ActiveFMGC_->FM.get_fpln_origin(1) + "/" + ActiveFMGC_->FM.get_fpln_dest(1);
        tempColor = 2;
    } else {
        tempString = "####/####";
        tempColor = 5;
    }

    tempRow = 2;
    tempOffset = 15;
    tempSize = 1;

    pageElements.push_back(Element(tempString, tempRow, tempOffset, tempColor, tempSize));

    //Tropo
    if(ActiveFMGC_->FM.get_tropo(1) != -999)
    {
        tempString = std::to_string(ActiveFMGC_->FM.get_tropo(1));
        tempSize = 1;
    } else {
        tempString = std::to_string(ActiveFMGC_->FM.get_db_tropo());
        tempSize = 0;
    }

    tempRow = 12;
    tempOffset = 19;
    tempColor = 2;

    pageElements.push_back(Element(tempString, tempRow, tempOffset, tempColor, tempSize));

    return pageElements;
}


Init_B::Init_B()
{
    pageID = 4;
    leftPageID = 3;
    rightPageID = 3;
}

void Init_B::selectLSK(int lsk_, FMGC* ActiveFMGC_, int &p_act_, Scratchpad &pad_)
{
    p_act_ = this->pageID;

    if(lsk_ == 1)
    {
        if(pad_.GetState() == 1)
        {
            if(ActiveFMGC_->FM.get_taxi_fuel() != -999)
            {
                ActiveFMGC_->FM.set_taxi_fuel(-999);
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

        std::string tempString;
        float tempFloat;
        pad_.GetScratchPad(tempString);

        try
        {
            tempFloat = stof(tempString)*1000;
        } catch (...)
        {
            pad_.AddMSG(1);
            return;
        }

        if(tempFloat < 10000 && tempFloat >= 0)
        {
            ActiveFMGC_->FM.set_taxi_fuel(tempFloat);
            pad_.EmptyScratchPad();
        } else {
            pad_.AddMSG(2);
        }        
        return;
    } else {
        pad_.AddMSG(0);
        return;
    }
    
}

std::vector<Element> Init_B::getElements(FMGC* ActiveFMGC_)
{
    pageElements.clear();

    pageElements.push_back(Element("INIT", 0, 10, 0, 1));
    pageElements.push_back(Element("<>", 0, 22, 0, 1));
    pageElements.push_back(Element("TAXI", 1, 0, 0, 0));
    pageElements.push_back(Element("ZFW/ZFWCG", 1, 15, 0, 0));
    pageElements.push_back(Element("TRIP/TIME", 3, 0, 0, 0));
    pageElements.push_back(Element("BLOCK", 3, 19, 0, 0));
    pageElements.push_back(Element("RTE RSV//", 5, 0, 0, 0));
    pageElements.push_back(Element("ALTN/TIME", 7, 0, 0, 0));
    pageElements.push_back(Element("FINAL/TIME", 9, 0, 0, 0));
    pageElements.push_back(Element("EXTRA/TIME", 11, 0, 0, 0));

    pageElements.push_back(Element("TOW/   LW", 7, 15, 0, 0));
    pageElements.push_back(Element("MIN DEST FOB", 9, 12, 0, 0));
    pageElements.push_back(Element("TRIP WIND", 11, 15, 0, 0));

    //Dynamic values
    std::string tempString;
    int tempRow, tempOffset, tempColor, tempSize, tempNum;

    if(ActiveFMGC_->FM.get_taxi_fuel() != -999)
    {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(1) << ActiveFMGC_->FM.get_taxi_fuel()/1000;
        tempString = ss.str();
        tempSize = 1;
    } else {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(1) << ActiveFMGC_->FM.get_db_taxi()/1000;
        tempString = ss.str();
        tempSize = 0;
    }

    tempColor = 2;
    tempRow = 2;
    tempOffset = 0;

    pageElements.push_back(Element(tempString, tempRow, tempOffset, tempColor, tempSize));

    return pageElements;
}

Route_Sel::Route_Sel()
{
    pageID = 5;
    leftPageID = 0;
    rightPageID = 0;
}

void Route_Sel::selectLSK(int lsk_, FMGC* ActiveFMGC_, int &p_act_, Scratchpad &pad_)
{
    p_act_ = this->pageID;

    if(lsk_ == 6)
    {
        p_act_ = 3;
        return;
    }
    return;
}

std::vector<Element> Route_Sel::getElements(FMGC* ActiveFMGC_)
{
    pageElements.clear();

    pageElements.push_back(Element("<>", 0, 22, 0, 1));
    pageElements.push_back(Element("<RETURN", 12, 0, 0, 1));

    //Dynamic values
    std::string tempString;
    int tempRow, tempOffset, tempColor, tempSize, tempNum;

    if(ActiveFMGC_->FM.get_fpln_origin(1) != "" && ActiveFMGC_->FM.get_fpln_dest(1) != "")
    {
        tempString = ActiveFMGC_->FM.get_fpln_origin(1) + "/" + ActiveFMGC_->FM.get_fpln_dest(1);
    } else {
        tempString = "----/----";
    }

    tempRow = 0;
    tempOffset = 6;
    tempColor = 0;
    tempSize = 1;

    pageElements.push_back(Element(tempString, tempRow, tempOffset, tempColor, tempSize));

    return pageElements;
}

Gps_Monitor::Gps_Monitor()
{
    pageID = 6;
    leftPageID = 0;
    rightPageID = 0;
}

void Gps_Monitor::selectLSK(int lsk_, FMGC* ActiveFMGC_, int &p_act_, Scratchpad &pad_)
{
    p_act_ = this->pageID;

    switch(lsk_)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        default:
            break;

    }

}


std::vector<Element> Gps_Monitor::getElements(FMGC* ActiveFMGC_)
{
    pageElements.clear();

    pageElements.push_back(Element("GPS MONITOR", 0, 7, 0, 1));
    pageElements.push_back(Element("GPS1 POSITION", 1, 0, 0, 0));
    pageElements.push_back(Element("TTRK    GPS ALT       GS", 3, 0, 0 ,0));
    pageElements.push_back(Element("MERIT           MODE/SAT", 5, 0, 0, 0));
    pageElements.push_back(Element("GPS2 POSITION", 7, 0, 0, 0));
    pageElements.push_back(Element("TTRK    GPS ALT       GS", 9, 0, 0 ,0));
    pageElements.push_back(Element("MERIT           MODE/SAT", 11, 0, 0, 0));

    //Dynamic values
    std::string tempString;
    int tempRow, tempOffset, tempColor, tempSize;

    //GPS1 Position

    if(ActiveFMGC_->Sensors->MMR1->getGPSStatus())
    {

        long double tempLat = ActiveFMGC_->Sensors->MMR1->getGPSLat();
        long double tempLong = ActiveFMGC_->Sensors->MMR1->getGPSLong();

        if(tempLat > 0)
        {
            tempString = getDDM(tempLat) + "N/";
        } else {
            tempString = getDDM(-tempLat) + "S/";
        }

        if(tempLong > 0)
        {
            tempString += getDDM(tempLong) + "E";
        } else {
            tempString += getDDM(-tempLong) + "W";
        }

        tempSize = 0;
        tempColor = 1;

    } else {
        tempString = "--c--.--/---c--.--";
        tempColor = 0;
    }

    tempRow = 2;
    tempOffset = 0;
    tempSize = 1;

    pageElements.push_back(Element(tempString, tempRow, tempOffset, tempColor, tempSize));

    //GPS1 Mode
    int status = ActiveFMGC_->Sensors->MMR1->getMMRStatus();
    if(status == 0)
    {
        tempString = "---/--";
        tempOffset = 17;
        tempColor = 0;
    } else if (status == 1)
    {
        tempString = "INIT/" + std::to_string(ActiveFMGC_->Sensors->MMR1->getSats());
        tempColor = 1;
        tempOffset = 16;
    } else if (status == 2)
    {
        tempString = "ACQ/" + std::to_string(ActiveFMGC_->Sensors->MMR1->getSats());
        tempColor = 1;
        tempOffset = 17;
    } else if (status == 3)
    {
        tempString = "NAV/" + std::to_string(ActiveFMGC_->Sensors->MMR1->getSats());
        tempColor = 1;
        tempOffset = 17;
    } else if (status == 4)
    {
        tempString = "ALTAID/" + std::to_string(ActiveFMGC_->Sensors->MMR1->getSats());
        tempColor = 1;
        tempOffset = 14;
    } else {
        tempString = "---/--";
        tempOffset = 17;
        tempColor = 0;
    }

    tempRow = 6;

    pageElements.push_back(Element(tempString, tempRow, tempOffset, tempColor, tempSize));

    //GPS2 Position

    if(ActiveFMGC_->Sensors->MMR2->getGPSStatus())
    {

        long double tempLat = ActiveFMGC_->Sensors->MMR2->getGPSLat();
        long double tempLong = ActiveFMGC_->Sensors->MMR2->getGPSLong();

        if(tempLat > 0)
        {
            tempString = getDDM(tempLat) + "N/";
        } else {
            tempString = getDDM(-tempLat) + "S/";
        }

        if(tempLong > 0)
        {
            tempString += getDDM(tempLong) + "E";
        } else {
            tempString += getDDM(-tempLong) + "W";
        }

        tempSize = 0;
        tempColor = 1;

    } else {
        tempString = "--c--.--/---c--.--";
        tempColor = 0;
    }

    tempRow = 8;
    tempOffset = 0;
    tempSize = 1;

    pageElements.push_back(Element(tempString, tempRow, tempOffset, tempColor, tempSize));

    //GPS2 Mode
    status = ActiveFMGC_->Sensors->MMR2->getMMRStatus();
    if(status == 0)
    {
        tempString = "---/--";
        tempOffset = 17;
        tempColor = 0;
    } else if (status == 1)
    {
        tempString = "INIT/" + std::to_string(ActiveFMGC_->Sensors->MMR2->getSats());
        tempColor = 1;
        tempOffset = 16;
    } else if (status == 2)
    {
        tempString = "ACQ/" + std::to_string(ActiveFMGC_->Sensors->MMR2->getSats());
        tempColor = 1;
        tempOffset = 17;
    } else if (status == 3)
    {
        tempString = "NAV/" + std::to_string(ActiveFMGC_->Sensors->MMR2->getSats());
        tempColor = 1;
        tempOffset = 17;
    } else if (status == 4)
    {
        tempString = "ALTAID/" + std::to_string(ActiveFMGC_->Sensors->MMR2->getSats());
        tempColor = 1;
        tempOffset = 14;
    } else {
        tempString = "---/--";
        tempOffset = 17;
        tempColor = 0;
    }

    tempRow = 12;

    pageElements.push_back(Element(tempString, tempRow, tempOffset, tempColor, tempSize));


    return pageElements;
}

Position_Monitor::Position_Monitor()
{
    pageID = 7;
    leftPageID = 0;
    rightPageID = 0;
}

void Position_Monitor::selectLSK(int lsk_, FMGC* ActiveFMGC_, int &p_act_, Scratchpad &pad_)
{
    p_act_ = this->pageID;

    switch(lsk_)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        default:
            break;

    }

}


std::vector<Element> Position_Monitor::getElements(FMGC* ActiveFMGC_)
{
    pageElements.clear();

    pageElements.push_back(Element("POSITION MONITOR", 0, 4, 0, 1));
    pageElements.push_back(Element("FMS1", 2, 0, 0, 0));
    pageElements.push_back(Element("3IRS/GPS", 3, 6, 0 ,0));
    pageElements.push_back(Element("FMS1", 4, 0, 0, 0));
    pageElements.push_back(Element("3IRS/GPS", 5, 6, 0 ,0));
    pageElements.push_back(Element("GPIRS", 6, 0, 0, 0));
    pageElements.push_back(Element("MIX IRS", 8, 0, 0 ,0));
    pageElements.push_back(Element("IRS1    IRS2    IRS3", 9, 2, 0 ,0));

    //Dynamic values
    std::string tempString;
    int tempRow, tempOffset, tempColor, tempSize;


    return pageElements;
}

