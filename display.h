#include <vector>
#include "SDL2/SDL.h"
#include <SDL2/SDL_ttf.h>
#include "MCDU/mcdu.h"

#ifndef DISPLAY_H
#define DISPLAY_H

class Display
{
    public:
        Display(const char *title, int x, int y, int w, int h, int flags);
        ~Display();

        void HandleEvents();
        void Update();
        void Render();
        void Clean();

        bool running()
        {
            return isRunning;
        }

        //MCDU
        void HandleMcduEvents(MCDU* mcdu_);

        //Font
        TTF_Font* DisplayFont = nullptr;
        SDL_Renderer* renderer;

    private:
        bool isRunning;
        SDL_Window* window;
        int mouse_x;
        int mouse_y;

        

};




#endif