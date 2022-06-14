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
    mcduFont_s.loadFromFile("res/fonts/MCDU_S.ttf");
    mcduFont_l.loadFromFile("res/fonts/MCDU_M.ttf");

    //Set colors
    mcdu_white = sf::Color(255, 255, 255);
    mcdu_green = sf::Color(0, 255, 17);
    mcdu_blue = sf::Color(0, 98, 255);
    mcdu_magenta = sf::Color(255, 0, 255);
    mcdu_yellow = sf::Color(255, 255, 0);
    mcdu_orange = sf::Color(255, 100, 0);

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

    SetActivePage(P_DATA_INDEX_1);
}

MCDU::~MCDU()
{

}

void MCDU::InitPages()
{
    P_DATA_INDEX_1 = new Data_Index_1(0);
    P_AC_STATUS = new Ac_Status(1);
    P_INIT_A = new Init_A(2);
}

void MCDU::SetActivePage(Page* page_)
{
    ActivePage = page_;

    //Get all lsk elements from the page
    lskElements = ActivePage->getLSKElements();
    pageElements = ActivePage->getElements();

    inTransition = true;
}

void MCDU::DrawPageTransitions(sf::RenderWindow* sfWindow)
{
    if(inTransition)
    {
        sfWindow->clear();
        sfWindow->display();
        sf::sleep(sf::milliseconds(250));
    }

    inTransition = false;
}

void MCDU::selectLsk(int lsk)
{
    //Check lsk has valid element
    if(lskElements[lsk] == nullptr)
    {
        pad->AddMSG(0); //Not allowed msg
        return;
    }

    lskElements[lsk]->Select(p_Act, *pad);

    //Update any page changes
    if(p_Act == 2)
    {
        SetActivePage(P_AC_STATUS);
    }

    if(p_Act == 1)
    {
        SetActivePage(P_INIT_A);
    }

}


void MCDU::DrawMCDU(sf::RenderWindow* sfWindow)
{
    //Render scratchpad
    pad->GetScratchPad(scratchpad_buff);

    sf::Text text;

    text.setFont(mcduFont_l);
    text.setCharacterSize(fontSize);
    text.setFillColor(sf::Color::White);
    text.setString(scratchpad_buff);
    text.setPosition(0, (charH * 13));

    //Draw scratchpad
    sfWindow->draw(text);

    std::string tempString;
    int tempRow;
    int tempOffset;
    int tempColor;
    int tempSize;
    sf::Color elementColor;

    //Render all page elements on current page
    for(int i = 0; i < pageElements.size(); ++i)
    {
        pageElements[i]->getElement(tempString, tempRow, tempOffset, tempColor, tempSize);

        //Select text color// 0 = white // 1 = green // 2 = blue // 3 = magenta // 4 = yellow // 5 = orange
        switch(tempColor)
        {
            case 0:
                elementColor = mcdu_white;
                break;
            case 1:
                elementColor = mcdu_green;
                break;
            case 2:
                elementColor = mcdu_blue;
                break;
            case 3:
                elementColor = mcdu_magenta;
                break;
            case 4:
                elementColor = mcdu_yellow;
                break;
            case 5:
                elementColor = mcdu_orange;
                break;

            default:
                break;
        }

        if(tempSize == 0)
        {
            text.setFont(mcduFont_s);
        } else {
            text.setFont(mcduFont_l);
        }

        text.setFillColor(elementColor);
        text.setString(tempString);
        text.setPosition(charW * tempOffset, charH * tempRow);

        sfWindow->draw(text);
    }

    //render all LSK elements
    for(int i = 0; i < lskElements.size(); ++i)
    {
        //Check if lsk element is null
        if(lskElements[i] == nullptr)
        {
            continue;
        }

        lskElements[i]->getElement(tempString, tempRow, tempOffset, tempColor, tempSize);

        //Select text color// 0 = white // 1 = green // 2 = blue // 3 = magenta // 4 = yellow // 5 = orange
        switch(tempColor)
        {
            case 0:
                elementColor = mcdu_white;
                break;
            case 1:
                elementColor = mcdu_green;
                break;
            case 2:
                elementColor = mcdu_blue;
                break;
            case 3:
                elementColor = mcdu_magenta;
                break;
            case 4:
                elementColor = mcdu_yellow;
                break;
            case 5:
                elementColor = mcdu_orange;
                break;

            default:
                break;
        }

        if(tempSize == 0)
        {
            text.setFont(mcduFont_s);
        } else {
            text.setFont(mcduFont_l);
        }

        text.setFillColor(elementColor);
        text.setString(tempString);
        text.setPosition(charW * tempOffset, charH * tempRow);

        sfWindow->draw(text);
    }
}

void MCDU::CleanPages()
{
    P_DATA_INDEX_1->Clean();
    P_AC_STATUS->Clean();

    delete P_DATA_INDEX_1;
    delete P_AC_STATUS;
}