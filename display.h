#include <vector>
#include "SDL2/SDL.h"

#ifndef DISPLAY_H
#define DISPLAY_H

class Char_Display
{
    public:
        Char_Display(const char *title, int x, int y, int w, int h, int flags, int charW, int charH);
        ~Char_Display();

        void HandleEvents();
        void Update();
        void Render();
        void Clean();

        bool running()
        {
            return isRunning;
        }

        void RenderConsole();

    private:
        int dimX;
        int dimY;

        int refreshRate;

        char defaultChar;

        std::vector<std::vector<char>> displayMatrix;


        bool isRunning;
        SDL_Window* window;
        SDL_Renderer* renderer;
        int mouse_x;
        int mouse_y;
};




#endif