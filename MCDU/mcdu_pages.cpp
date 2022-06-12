#include "mcdu_pages.h"

Page::Page()
{
    //Sample page
    //Add an element
    pageElements.push_back(Element("DATA INDEX", 0, 5, 0));
    pageElements.push_back(Element("1/2 <>", 0, 17, 0));
    pageElements.push_back(Element("POSITION", 1, 1, 0));
    pageElements.push_back(Element("<MONITOR", 2, 0, 0));
}

Page::~Page()
{

}

std::vector<Element> Page::getElements()
{
    return pageElements;
}