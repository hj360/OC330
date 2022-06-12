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

    //MCDU is online
    avail = 1;
    
    //Error checking
    if(avail)
    {
        std::cout << "MCDU " << id << " Available." << std::endl;
    } else {
        std::cerr << "MCDU " << id << " Fail." << std::endl;
    }
}

MCDU::~MCDU()
{

}

void MCDU::RenderSDLMCDU(SDL_Renderer* renderer, TTF_Font* DisplayFont)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    //Render scratchpad
    pad->GetScratchPad(scratchpad_buff);
    length = scratchpad_buff.length();
    const char* c = scratchpad_buff.c_str();
    
    SDL_Surface* textSurf = TTF_RenderText_Solid(DisplayFont, c, {255, 255, 255});
    delete c;
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurf);
    //Add scratchpad rect to bottom of display
    textRect = {0, (charH * 13), (charW * length), (charH)};
    SDL_FreeSurface(textSurf);
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

    SDL_DestroyTexture(textTexture);
    

    

    SDL_RenderPresent(renderer);


}