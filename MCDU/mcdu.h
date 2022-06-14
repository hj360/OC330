#include <vector>
#include "mcdu_scratchpad.h"
#include "mcdu_pages.h"
#include <SFML/Graphics.hpp>

#ifndef MCDU_H
#define MCDU_H


class MCDU
{
    public:
        MCDU(int id_, int w_, int h_);
        ~MCDU();

        void selectLsk(int lsk);
        void InitPages();
        void DrawMCDU(sf::RenderWindow* sfWindow);
        void SetActivePage(Page* page_);

        void CleanPages();
        //Pointer to MCDU scratchpad
        Scratchpad* pad;

        void DrawPageTransitions(sf::RenderWindow* sfWindow);

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

        //Defines the width and height of a character
        int charW;
        int charH;

        //Font size
        int fontSize;
        
        std::string scratchpad_buff;
        //Pointer to the active page
        Page* ActivePage;
        int p_Act;;
        //MCDU Pages
        Page* P_DATA_INDEX_1;
        Page* P_AC_STATUS;
        Page* P_INIT_A;

        //Line select keys
        std::vector<bool> lsk;

        sf::Font mcduFont_s;
        sf::Font mcduFont_l;

        //Lsk elements for the active page
        std::vector<Element*> lskElements;
        std::vector<Element*> pageElements;

        bool inTransition;

        //MCDU colors
        sf::Color mcdu_white;
        sf::Color mcdu_green;
        sf::Color mcdu_blue;
        sf::Color mcdu_magenta;
        sf::Color mcdu_yellow;
        sf::Color mcdu_orange;

};




#endif