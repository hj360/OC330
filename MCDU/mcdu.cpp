#include <iostream>

#include "mcdu.h"

MCDU::MCDU(int id_, int w_, int h_)
{
    //Initialize class vars with constructor vars
    id = id_;

    dimX = 24;
    dimY = 14;

    w = w_;
    h = h_;

    charW = w/dimX;
    charH = h/dimY;

    //Create a scratchpad
    pad = new Scratchpad(dimX);

    //Load font
    //mcduFont.loadFromFile("res/fonts/B612Mono-Regular.ttf");
    mcduFont.loadFromFile("res/fonts/MCDU_M.ttf");

    //MCDU is online
    avail = 1;
    
    //Error checking
    if(avail)
    {
        std::cout << "MCDU " << id << " Available." << std::endl;
    } else {
        std::cerr << "MCDU " << id << " Fail." << std::endl;
    }

    InitPages();

    ActivePage = P_AC_STATUS;
}

MCDU::~MCDU()
{

}

void MCDU::InitPages()
{
    P_DATA_INDEX_1 = new Data_Index_1(1);
    P_AC_STATUS = new Ac_Status(2);
}

void MCDU::DrawMCDU(sf::RenderWindow* sfWindow)
{
    //Render scratchpad
    pad->GetScratchPad(scratchpad_buff);

    sf::Text text;

    text.setFont(mcduFont);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setString(scratchpad_buff);
    text.setPosition(0, (charH * 13));

    sfWindow->draw(text);

    std::vector<Element> pageElements = ActivePage->getElements();

    std::string tempString;
    int tempRow;
    int tempOffset;
    int tempColor;

    //Render all page elements on current page
    for(int i = 0; i < pageElements.size(); ++i)
    {
        pageElements[i].getElement(tempString, tempRow, tempOffset, tempColor);

        text.setString(tempString);
        text.setPosition(charW * tempOffset, charH * tempRow);

        sfWindow->draw(text);
    }
}