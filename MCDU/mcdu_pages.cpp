#include "mcdu_pages.h"

Page::Page()
{
    //Sample page
    //Set ID
    pageID = 0;
    leftPageID = 0;
    rightPageID = 0;
}

void Page::Clean()
{
    for(int i = 0; i < pageElements.size(); ++i)
    {
        delete pageElements[i];
    }

    for(int i = 0; i < lskElements.size(); ++i)
    {
        delete lskElements[i];
    }
}

std::vector<Element*>& Page::getElements()
{
    return pageElements;
}

std::vector<Element*>& Page::getLSKElements()
{
    return lskElements;
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

Element*& Page::getLSKElement(int lsk)
{
    return lskElements[lsk];
}

Data_Index_1::Data_Index_1()
{
    pageID = 1;
    leftPageID = 0;
    rightPageID = 0;

    //Elements for Data index 1
    pageElements.push_back(new Element("DATA INDEX    1/2 <>", 0, 4, 0, 1));
    pageElements.push_back(new Element("POSITION", 1, 1, 0, 0));
    pageElements.push_back(new Link("<MONITOR", 2, 0, 0, 1, 0));
    pageElements.push_back(new Element("IRS", 3, 1, 0, 0));
    pageElements.push_back(new Link("<MONITOR", 4, 0, 0, 1, 0));
    pageElements.push_back(new Element("GPS", 5, 1, 0, 0));
    pageElements.push_back(new Link("<MONITOR", 6, 0, 0, 1, 0));

    pageElements.push_back(new Element("CLOSEST", 9, 1, 0, 0));
    pageElements.push_back(new Link("<AIRPORTS", 10, 0, 0, 1, 0));
    pageElements.push_back(new Element("PRINT", 9, 18, 0, 0));
    pageElements.push_back(new Link("FUNCTION>", 10, 15, 0, 1, 0));
    pageElements.push_back(new Element("EQUITIME", 11, 1, 0, 0));
    pageElements.push_back(new Link("<POINT", 12, 0, 0, 1, 0));
    pageElements.push_back(new Element("AOC", 11, 18, 0, 0));
    pageElements.push_back(new Link("FUNCTION>", 12, 15, 0, 1, 0));

    //Set any lsks
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(new Link("<A/C STATUS", 8, 0, 0, 1, 2));
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
}

Ac_Status::Ac_Status()
{
    pageID = 2;
    leftPageID = 0;
    rightPageID = 0;

    //Select text color// 0 = white // 1 = green // 2 = blue // 3 = magenta // 4 = yellow // 5 = orange
    //Elements for Data index 1
    pageElements.push_back(new Element("A330-300B", 0, 6, 0, 1));
    pageElements.push_back(new Element("ENG", 1, 1, 0, 0));
    pageElements.push_back(new Link("PW4168A", 2, 0, 1, 1, 0));
    pageElements.push_back(new Element("ACTIVE NAV DATA BASE", 3, 1, 0, 0));
    pageElements.push_back(new Element("28MAY-24JUN", 4, 1, 2 ,1));
    pageElements.push_back(new Element("AB2388371", 4, 14, 1, 1));
    pageElements.push_back(new Element("SECOND NAV DATA BASE", 5, 1, 0, 0));
    pageElements.push_back(new Link("<28MAY-24JUN", 6, 0, 2, 0, 0));
    pageElements.push_back(new Element("CHG CODE", 9, 0, 0, 0));
    pageElements.push_back(new Link("[ ]", 10, 0, 2, 1, 0));
    pageElements.push_back(new Element("IDLE/PERF", 11, 0, 0, 0));
    pageElements.push_back(new Element("SOFTWARE", 11, 15, 0, 0));
    pageElements.push_back(new Link("+0.0/+4.4", 12, 0, 1, 1, 0));
    pageElements.push_back(new Link("STATUS/XLOAD>", 12, 11, 0, 1, 0));

    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);

}

Init_A::Init_A()
{
    pageID = 3;
    leftPageID = 0;
    rightPageID = 4;


    pageElements.push_back(new Element("INIT", 0, 10, 0, 1));
    pageElements.push_back(new Element("<>", 0, 22, 0, 1));
    pageElements.push_back(new Element("CO RTE", 1, 1, 0, 0));
    pageElements.push_back(new Element("FROM/TO", 1, 15, 0, 0));
    pageElements.push_back(new Element("ALTN/CO RTE", 3, 0, 0, 0));
    pageElements.push_back(new Element("FLT NBR", 5, 0, 0, 0));
    pageElements.push_back(new Element("COST INDEX", 9, 0, 0, 0));
    pageElements.push_back(new Element("CRZ FL/TEMP", 11, 0, 0, 0));
    pageElements.push_back(new Element("TROPO", 11, 19, 0, 0));
    

    lskElements.push_back(new CoRte(2, 0));
    lskElements.push_back(new AltnCoRte(4, 0));
    lskElements.push_back(new FlightNumber(6, 0));
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(new FromTo(2, 15));
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(new Tropo(12, 19));
}

Init_B::Init_B()
{
    pageID = 4;
    leftPageID = 3;
    rightPageID = 0;

    pageElements.push_back(new Element("INIT", 0, 10, 0, 1));
    pageElements.push_back(new Element("<>", 0, 22, 0, 1));
    pageElements.push_back(new Element("TAXI", 1, 0, 0, 0));
    pageElements.push_back(new Element("ZFW/ZFWCG", 1, 15, 0, 0));
    pageElements.push_back(new Element("#.#", 2, 0, 5, 1));
    pageElements.push_back(new Element("###.#/##.#", 2, 13, 5, 1));
    

    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
}

Route_Sel::Route_Sel()
{
    pageID = 5;
    leftPageID = 0;
    rightPageID = 0;

    pageElements.push_back(new FromTo(0, 6));
    pageElements.push_back(new Element("<>", 0, 22, 0, 1));

    

    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(new Link("<RETURN", 12, 0, 0, 1, 3));
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
}