#include "mcdu_pages.h"

Page::Page()
{
    pageID = 0;
}

Page::Page(int id_)
{
    //Sample page
    //Set ID
    pageID = id_;
    //Add an element
    pageElements.push_back(new Element("TITLE FIELD", 0, 5, 0, 1));
    pageElements.push_back(new Element("LABEL", 1, 1, 0, 0));
    pageElements.push_back(new Element("<ELEMENT", 2, 0, 0, 0));

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

Element*& Page::getLSKElement(int lsk)
{
    return lskElements[lsk];
}

Data_Index_1::Data_Index_1(int id_)
{
    pageID = id_;


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
    lskElements.push_back(new Link("<A/C STATUS", 8, 0, 0, 1, 1));
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
}

Ac_Status::Ac_Status(int id_)
{
    pageID = id_;

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
    pageElements.push_back(new Link("[]", 10, 0, 2, 1, 0));
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

Init_A::Init_A(int id_)
{
    pageID = id_;


    pageElements.push_back(new Element("INIT", 0, 10, 0, 1));
    pageElements.push_back(new Element("<>", 0, 22, 0, 1));
    pageElements.push_back(new Element("CO RTE", 1, 1, 0, 0));
    pageElements.push_back(new Element("FROM/TO", 1, 15, 0, 0));
    pageElements.push_back(new Element("#########", 2, 0, 5, 1));
    pageElements.push_back(new Element("ALTN/CO RTE", 3, 0, 0, 0));
    pageElements.push_back(new Element("FLT NBR", 5, 0, 0, 0));
    pageElements.push_back(new Element("COST INDEX", 9, 0, 0, 0));
    pageElements.push_back(new Element("CRZ FL/TEMP", 11, 0, 0, 0));
    pageElements.push_back(new Element("TROPO", 11, 18, 0, 0));
    

    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(new FlightNumber("##########", 6, 0, 5, 1));
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(new FromTo("####/####", 2, 15, 5, 1));
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
    lskElements.push_back(nullptr);
}