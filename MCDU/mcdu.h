#include <vector>
#include "mcdu_scratchpad.h"
#include "mcdu_pages.h"
#include "gui_elements.h"
#include "fmgc.h"
#include <SFML/Graphics.hpp>
#include "../SENSORS/sensors.h"

#ifndef MCDU_H
#define MCDU_H


class MCDU
{
    public:
        MCDU(int id_, int w_, int h_, FMGC* ActiveFMGC_, SensorManager* Sensors_);
        ~MCDU();

        void selectLsk(int lsk);
        void InitPages();
        void DrawMCDU(sf::RenderWindow* sfWindow, sf::Mouse* mouse_);
        void SetActivePage(Page* page_);
        void UpdateMCDU(sf::RenderWindow* sfWindow, sf::Mouse* mouse_);

        void updateActivePage();

        void updateWarnings();

        void goRight();
        void goLeft();

        void CleanPages();
        //Pointer to MCDU scratchpad
        Scratchpad* pad;

    private:
        //1 is MCDU1, 2 is MCDU2, 3 is MCDU3
        int id;
        //Is MCDU functional?
        bool avail;
        //Dimensions of the display in characters
        int dimX;
        int dimY;
        //Dimensions of display in px
        int w;
        int h;
        int refreshRate;

        //Buffer lsk select
        int lskBuffer;

        //Texture for display
        sf::RenderTexture mcduDisplay;
        sf::Sprite mcduSprite;

        //Clock for checking mcdu refresh rate
        sf::Clock sfClock;

        //Position of the MCDU refs top left of display
        int x;
        int y;

        //Defines the width and height of a character
        int charW;
        int charH;

        //Font size
        int fontSize;
        
        std::string scratchpad_buff;

        //Pointer to the linked FMGC
        FMGC* ActiveFMGC;
        //Pointer to aircraft sensors
        SensorManager* Sensors;
        //Pointer to the active page
        Page* ActivePage;
        int p_Act;
        int p_Buff;
        //MCDU Pages
        Page* P_DATA_INDEX_1;
        Page* P_DATA_INDEX_2;
        Page* P_AC_STATUS;
        Page* P_INIT_A;
        Page* P_INIT_B;
        Page* P_RTE_SEL;
        Page* P_GPS_MONITOR;
        Page* P_POSITION_MONITOR;
        Page* P_MCDU_MENU;
        //Performance
        Page* P_PERF_TAKEOFF;
        

        sf::Font mcduFont_s;
        sf::Font mcduFont_l;

        //Lsk elements for the active page
        std::vector<Element> pageElements;

        //MCDU colors
        sf::Color mcdu_white;
        sf::Color mcdu_green;
        sf::Color mcdu_blue;
        sf::Color mcdu_magenta;
        sf::Color mcdu_yellow;
        sf::Color mcdu_orange;


        bool gps_primary;

        //Mcdu outlines
        GUI_Window* outline;

        //Test buttons
        Button* LSK1L;
        Button* LSK2L;
        Button* LSK3L;
        Button* LSK4L;
        Button* LSK5L;
        Button* LSK6L;
        Button* LSK1R;
        Button* LSK2R;
        Button* LSK3R;
        Button* LSK4R;
        Button* LSK5R;
        Button* LSK6R;

        Button* DIR;
        Button* PROG;
        Button* PERF;
        Button* INIT;
        Button* DATA;
        Button* EMPTY_KEY;
        Button* FPLN;
        Button* RAD_NAV;
        Button* FUEL_PRED;
        Button* SEC_FPLN;
        Button* ATC_COMM;
        Button* MCDU_MENU;  
};




#endif