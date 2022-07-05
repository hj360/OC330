#include <iostream>

#include "mcdu.h"

MCDU::MCDU(int id_, int w_, int h_, FMGC* ActiveFMGC_, SensorManager* Sensors_)
{
    //Initialize class vars with constructor vars
    id = id_;

    dimX = 24;
    dimY = 14;

    w = w_;
    h = h_;

    mcduDisplay.create(w, h);
    mcduDisplay.clear(sf::Color::Black);

    x = 100;
    y = 70;

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

    //Initialize clock
    sfClock.restart();

    //Set colors
    mcdu_white = sf::Color(255, 255, 255);
    mcdu_green = sf::Color(0, 210, 45);
    mcdu_blue = sf::Color(0, 150, 255);
    mcdu_magenta = sf::Color(255, 0, 255);
    mcdu_yellow = sf::Color(255, 255, 0);
    mcdu_orange = sf::Color(255, 100, 0);

    //MCDU is online
    avail = 1;

    lskBuffer = 0;//No lsk has been selected yet
    
    //Error checking
    if(avail)
    {
        std::cout << "MCDU " << id << " Available." << std::endl;
    } else {
        std::cerr << "MCDU " << id << " Fail." << std::endl;
    }

    //Set active FMGC
    ActiveFMGC = ActiveFMGC_;
    //Set sensors
    Sensors = Sensors_;

    InitPages();

    p_Act = 8;
    p_Buff = 8;

    SetActivePage(P_MCDU_MENU);

    outline = new GUI_Window(w, h);

    //Testing buttons
    LSK1L = new Button(w/8, h/15, "LSK1L", mcduFont_s);
    LSK2L = new Button(w/8, h/15, "LSK2L", mcduFont_s);
    LSK3L = new Button(w/8, h/15, "LSK3L", mcduFont_s);
    LSK4L = new Button(w/8, h/15, "LSK4L", mcduFont_s);
    LSK5L = new Button(w/8, h/15, "LSK5L", mcduFont_s);
    LSK6L = new Button(w/8, h/15, "LSK6L", mcduFont_s);
    LSK1R = new Button(w/8, h/15, "LSK1R", mcduFont_s);
    LSK2R = new Button(w/8, h/15, "LSK2R", mcduFont_s);
    LSK3R = new Button(w/8, h/15, "LSK3R", mcduFont_s);
    LSK4R = new Button(w/8, h/15, "LSK4R", mcduFont_s);
    LSK5R = new Button(w/8, h/15, "LSK5R", mcduFont_s);
    LSK6R = new Button(w/8, h/15, "LSK6R", mcduFont_s);


    DIR = new Button(w/8, h/12, "DIR", mcduFont_s);
    PROG = new Button(w/8, h/12, "PROG", mcduFont_s);
    PERF = new Button(w/8, h/12, "PERF", mcduFont_s);
    INIT = new Button(w/8, h/12, "INIT", mcduFont_s);
    DATA = new Button(w/8, h/12, "DATA", mcduFont_s);
    EMPTY_KEY = new Button(w/8, h/12, "", mcduFont_s);
    FPLN = new Button(w/8, h/12, "F-PLN", mcduFont_s);
    RAD_NAV = new Button(w/8, h/12, "RAD\nNAV", mcduFont_s);
    FUEL_PRED = new Button(w/8, h/12, "FUEL\nPRED", mcduFont_s);
    SEC_FPLN = new Button(w/8, h/12, "SEC\nF-PLN", mcduFont_s);
    ATC_COMM = new Button(w/8, h/12, "ATC\nCOMM", mcduFont_s);
    MCDU_MENU = new Button(w/8, h/12, "MCDU\nMENU", mcduFont_s);

    //Start the clock
    sfClock.restart();
    
}

MCDU::~MCDU()
{

}

void MCDU::InitPages()
{
    P_DATA_INDEX_1 = new Data_Index_1();
    P_AC_STATUS = new Ac_Status();
    P_INIT_A = new Init_A();
    P_INIT_B = new Init_B();
    P_RTE_SEL = new Route_Sel();
    P_GPS_MONITOR = new Gps_Monitor();
    P_POSITION_MONITOR = new Position_Monitor();
    P_MCDU_MENU = new Mcdu_Menu();
}

void MCDU::SetActivePage(Page* page_)
{
    if(page_ == nullptr)
    {
        return;
    }

    ActivePage = page_;

    //Get all lsk elements from the page
    pageElements = ActivePage->getElements(ActiveFMGC, *pad);

    sfClock.restart();
    mcduDisplay.clear();
}

void MCDU::selectLsk(int lsk)
{
    //Check lsk has valid element
    ActivePage->selectLSK(lsk, ActiveFMGC, p_Act, *pad); 
}

void MCDU::goLeft()
{
    int tempID = ActivePage->getLeftPageId();
    if(tempID != 0)
    {
        p_Act = tempID;
        updateActivePage();
    }

    return;
    
}

void MCDU::goRight()
{
    int tempID = ActivePage->getRightPageId();
    if(tempID != 0)
    {
        p_Act = tempID;
        updateActivePage();
    }

    return;
}

void MCDU::updateActivePage()
{
        //Update any page changes
    switch(p_Act)
    {
        case 0:
            break;
        case 1:
            SetActivePage(P_DATA_INDEX_1);
            break;
        case 2:
            SetActivePage(P_AC_STATUS);
            break;
        case 3:
            SetActivePage(P_INIT_A);
            break;
        case 4:
            SetActivePage(P_INIT_B);
            break;
        case 5:
            SetActivePage(P_RTE_SEL);
            break;
        case 6:
            SetActivePage(P_GPS_MONITOR);
            break;
        case 7:
            SetActivePage(P_POSITION_MONITOR);
            break;
        case 8:
            SetActivePage(P_MCDU_MENU);
            break;
        default:
            break;
    }
}

void MCDU::DrawMCDU(sf::RenderWindow* sfWindow, sf::Mouse* mouse_)
{
    //Only render every 500ms
    if(sfClock.getElapsedTime() > sf::milliseconds(300))
    {
        //Clear mcdu texture
        mcduDisplay.clear();
        //Render scratchpad
        pad->GetScratchPad(scratchpad_buff);

        sf::Text text;

        text.setFont(mcduFont_l);
        text.setCharacterSize(fontSize);
        text.setFillColor(sf::Color::White);
        text.setString(scratchpad_buff);
        text.setPosition(0, (charH * 13));
        //draw to texture
        mcduDisplay.draw(text);

        std::string tempString;
        int tempRow;
        int tempOffset;
        int tempColor;
        int tempSize;
        sf::Color elementColor;

        pageElements = ActivePage->getElements(ActiveFMGC, *pad);

        //Render all page elements on current page
        for(int i = 0; i < pageElements.size(); ++i)
        {
            pageElements[i].getElement(tempString, tempRow, tempOffset, tempColor, tempSize);

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
            //text.setPosition(charW * tempOffset + x, charH * tempRow + y);
            text.setPosition(charW * tempOffset, charH * tempRow);
            mcduDisplay.draw(text);
        }
        //Draw MCDU Display
        mcduDisplay.display();

        //Testing saving to a texture
        //mcduDisplay.getTexture().copyToImage().saveToFile("mcdu.tga");

        sfClock.restart();

        //Only update active page after screen draw
        if(p_Act != ActivePage->getPageId())
        {
            //Skip once
            //Means that any changes that need to be seen before page changes can be seen for a frame
            if(p_Act != p_Buff && p_Buff == 8)
            {
                p_Buff = p_Act;

            } else {
                updateActivePage();
                p_Buff = p_Act;
            }
        }

        std::cout << "P_BUFF: " << p_Buff << " P_ACT: " << p_Act << std::endl;
    }

    //Draw bounding box
    if(outline->Draw(x, y, sfWindow, mouse_))
    {
        x = mouse_->getPosition(*sfWindow).x - w/2;
        y = mouse_->getPosition(*sfWindow).y - h/2;

        mcduDisplay.clear();

        return;
    }

    mcduSprite.setTexture(mcduDisplay.getTexture());
    mcduSprite.setPosition(sf::Vector2f(x, y));
    sfWindow->draw(mcduSprite);

    


    //test buttons
    if(LSK1L->Draw(x-charW*4, y + 2*charH, sfWindow, mouse_))
    {
        selectLsk(1);
    }
    if(LSK2L->Draw(x-charW*4, y + 4*charH, sfWindow, mouse_))
    {
        selectLsk(2);
    }
    if(LSK3L->Draw(x-charW*4, y + 6*charH, sfWindow, mouse_))
    {
        selectLsk(3);
    }
    if(LSK4L->Draw(x-charW*4, y + 8*charH, sfWindow, mouse_))
    {
        selectLsk(4);
    }
    if(LSK5L->Draw(x-charW*4, y + 10*charH, sfWindow, mouse_))
    {
        selectLsk(5);
    }
    if(LSK6L->Draw(x-charW*4, y + 12*charH, sfWindow, mouse_))
    {
        selectLsk(6);
    }
    if(LSK1R->Draw(x+charW*25, y + 2*charH, sfWindow, mouse_))
    {
        selectLsk(7);
    }
    if(LSK2R->Draw(x+charW*25, y + 4*charH, sfWindow, mouse_))
    {
        selectLsk(8);
    }
    if(LSK3R->Draw(x+charW*25, y + 6*charH, sfWindow, mouse_))
    {
        selectLsk(9);
    }
    if(LSK4R->Draw(x+charW*25, y + 8*charH, sfWindow, mouse_))
    {
        selectLsk(10);
    }
    if(LSK5R->Draw(x+charW*25, y + 10*charH, sfWindow, mouse_))
    {
        selectLsk(11);
    }
    if(LSK6R->Draw(x+charW*25, y + 12*charH, sfWindow, mouse_))
    {
        selectLsk(12);
    }


    if(DIR->Draw(x+charW*0, y + 15*charH, sfWindow, mouse_))
    {
        
    }
    if(PROG->Draw(x+charW*4, y + 15*charH, sfWindow, mouse_))
    {
        
    }
    if(PERF->Draw(x+charW*8, y + 15*charH, sfWindow, mouse_))
    {
        
    }
    if(INIT->Draw(x+charW*12, y + 15*charH, sfWindow, mouse_))
    {
        p_Act = 3;
    }
    if(DATA->Draw(x+charW*16, y + 15*charH, sfWindow, mouse_))
    {
        p_Act = 1;
    }
 

    if(FPLN->Draw(x+charW*0, y + 17*charH, sfWindow, mouse_))
    {
        
    }
    if(RAD_NAV->Draw(x+charW*4, y + 17*charH, sfWindow, mouse_))
    {
        
    }
    if(FUEL_PRED->Draw(x+charW*8, y + 17*charH, sfWindow, mouse_))
    {
        
    }
    if(SEC_FPLN->Draw(x+charW*12, y + 17*charH, sfWindow, mouse_))
    {
        
    }
    if(ATC_COMM->Draw(x+charW*16, y + 17*charH, sfWindow, mouse_))
    {
        
    }
    if(MCDU_MENU->Draw(x+charW*20, y + 17*charH, sfWindow, mouse_))
    {
        p_Act = 8;
    }
}

void MCDU::CleanPages()
{
    //P_DATA_INDEX_1->Clean();
    //P_AC_STATUS->Clean();

    delete P_DATA_INDEX_1;
    //delete P_AC_STATUS;
}