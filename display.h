#include <vector>
#include "SDL2/SDL.h"

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

    private:
        bool isRunning;
        SDL_Window* window;
        SDL_Renderer* renderer;
        int mouse_x;
        int mouse_y;
};




#endif