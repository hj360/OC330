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

    //Initialize line select keys
    lsk = { false, false, false, false, false, false };

    charW = w/dimX;
    charH = h/dimY;
    //Dynamically calculate font size
    //This is because of the 0.8em width of each character
    //MCDU Display window size cannot be resized dynamically with vanilla smfl text class
    fontSize = w/19.2;
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

    p_Act = 0;

    ActivePage = P_DATA_INDEX_1;
}

MCDU::~MCDU()
{

}

void MCDU::InitPages()
{
    P_DATA_INDEX_1 = new Data_Index_1(0);
    P_AC_STATUS = new Ac_Status(1);
}

void MCDU::selectLsk(int lsk)
{
    //Determine the type of element
    Element lskElement = ActivePage->getLSKElement(0);

    if(lskElement.getType() == 1)
    {
        lskElement.Select(p_Act);

        std::cout << p_Act << std::endl;

        //To be turned into an update function
        if(p_Act == 1)
        {
            ActivePage = P_AC_STATUS;
        }

    } else {
        std::cout << "Element type is not 1" << std::endl;
    }

}


void MCDU::DrawMCDU(sf::RenderWindow* sfWindow)
{
    //Render scratchpad
    pad->GetScratchPad(scratchpad_buff);

    sf::Text text;

    text.setFont(mcduFont);
    text.setCharacterSize(fontSize);
    text.setFillColor(sf::Color::White);
    text.setString(scratchpad_buff);
    text.setPosition(0, (charH * 13));

    //Draw scratchpad
    sfWindow->draw(text);

    std::vector<Element> pageElements = ActivePage->getElements();
    std::vector<Element> lskElements = ActivePage->getLSKElements();

    std::string tempString;
    int tempRow;
    int tempOffset;
    int tempColor;
    sf::Color elementColor;

    //Render all page elements on current page
    for(int i = 0; i < pageElements.size(); ++i)
    {
        pageElements[i].getElement(tempString, tempRow, tempOffset, tempColor);

        //Select text color// 0 = white // 1 = green // 2 = blue // 3 = magenta // 4 = yellow // 5 = orange
        if(tempColor == 0)
        {
            elementColor = sf::Color::White;
        } else if(tempColor == 1)
        {
            elementColor = sf::Color::Green;
        } else if(tempColor == 2)
        {
            elementColor = sf::Color::Cyan;
        } else if(tempColor == 3)
        {
            elementColor = sf::Color::Magenta;
        } else if(tempColor == 4)
        {
            elementColor = sf::Color::Yellow;
        } else if(tempColor == 5)
        {
            elementColor == sf::Color::Red;
        } else {
            elementColor == sf::Color::Blue;
        }

        text.setFillColor(elementColor);
        text.setString(tempString);
        text.setPosition(charW * tempOffset, charH * tempRow);

        sfWindow->draw(text);
    }

    //render all LSK elements
    for(int i = 0; i < lskElements.size(); ++i)
    {
        lskElements[i].getElement(tempString, tempRow, tempOffset, tempColor);

        //Select text color// 0 = white // 1 = green // 2 = blue // 3 = magenta // 4 = yellow // 5 = orange
        if(tempColor == 0)
        {
            elementColor = sf::Color::White;
        } else if(tempColor == 1)
        {
            elementColor = sf::Color::Green;
        } else if(tempColor == 2)
        {
            elementColor = sf::Color::Cyan;
        } else if(tempColor == 3)
        {
            elementColor = sf::Color::Magenta;
        } else if(tempColor == 4)
        {
            elementColor = sf::Color::Yellow;
        } else if(tempColor == 5)
        {
            elementColor == sf::Color::Red;
        } else {
            elementColor == sf::Color::Blue;
        }

        text.setFillColor(elementColor);
        text.setString(tempString);
        text.setPosition(charW * tempOffset, charH * tempRow);

        sfWindow->draw(text);
    }
}