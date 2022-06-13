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
    pageElements.push_back(Element("TITLE FIELD", 0, 5, 0));
    pageElements.push_back(Element("LABEL", 1, 1, 0));
    pageElements.push_back(Element("<ELEMENT", 2, 0, 0));
}

std::vector<Element> Page::getElements()
{
    return pageElements;
}

int Page::getPageId()
{
    return pageID;
}

Data_Index_1::Data_Index_1(int id_)
{
    pageID = id_;


    //Elements for Data index 1
    pageElements.push_back(Element("DATA INDEX    1/2 <>", 0, 5, 0));
    pageElements.push_back(Element("POSITION", 1, 1, 0));
    pageElements.push_back(Link("<MONITOR", 2, 0, 0, 0));
    pageElements.push_back(Element("IRS", 3, 1, 0));
    pageElements.push_back(Link("<MONITOR", 4, 0, 0, 0));
    pageElements.push_back(Element("GPS", 5, 1, 0));
    pageElements.push_back(Link("<A/C STATUS", 7, 0, 0, 0));
    pageElements.push_back(Element("CLOSEST", 8, 1, 0));
    pageElements.push_back(Link("<AIRPORTS", 9, 0, 0, 0));
    pageElements.push_back(Element("PRINT", 8, 18, 0));
    pageElements.push_back(Link("FUNCTION>", 9, 15, 0, 0));
    pageElements.push_back(Element("EQUITIME", 10, 1, 0));
    pageElements.push_back(Link("<POINT", 11, 0, 0, 0));
    pageElements.push_back(Element("AOC", 10, 18, 0));
    pageElements.push_back(Link("FUNCTION>", 11, 15, 0, 0));


}