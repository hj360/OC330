#include <vector>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "mcdu_scratchpad.h"
#include "mcdu_pages.h"

#ifndef MCDU_H
#define MCDU_H


class MCDU
{
    public:
        MCDU(int id_, int w_, int h_);
        ~MCDU();

        void selectLsk(int lsk);

        void RenderSDLMCDU(SDL_Renderer* renderer, TTF_Font* DisplayFont);

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

        //Defines the width and height of a character
        int charW;
        int charH;
        
        std::string scratchpad_buff;
        //Pointer to the active page
        Page* ActivePage;
        //MCDU Pages
        Page* P_MCDU_MENU;

        //Line select keys
        std::vector<bool> lsk[6];




        //_________SDL____________
        SDL_Rect textRect;
        int length;
        

};




#endif