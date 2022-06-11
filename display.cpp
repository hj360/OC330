#include <iostream>
#include <windows.h>
#include "display.h"

Char_Display::Char_Display(const char *title, int x, int y, int w, int h, int flags, int charW, int charH)
{
    dimX = charW;
    dimY = charH;

    defaultChar = '0';

    //Initialize vector matrix with default values with speciied dimensions
    displayMatrix.resize(dimX, std::vector<char>(dimY, defaultChar));

    if(displayMatrix.size() != 0)
    {
        std::cout << "Char Matrix creation Success!" << std::endl;
    } else {
        std::cerr << "Failed to create char matrix!" << std::endl;
    }
    
    //Initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL has been initialized!" << std::endl;
        //Create an SDL window
        window = SDL_CreateWindow(title, x, y, w, h, flags);
        if(window)
        {
            std::cout << "SDL Window created!" << std::endl;
        } else {
            std::cerr << "SDL Window creation failed! Error: " << SDL_GetError() << std::endl;
        }
        //Create an SDL renderer
        renderer = SDL_CreateRenderer(window, -1, 0);
        
        if(renderer)
        {
            std::cout << "SDL Renderer created!" << std::endl;
        } else {
            std::cerr << "SDL Renderer creation failed! Error: " << SDL_GetError() << std::endl;
        }

        isRunning = true;

    } else {
        std::cerr << "SDL initilization has failed! Error: " << SDL_GetError() << std::endl;
        isRunning = false;
    }
}

Char_Display::~Char_Display()
{

}

void Char_Display::RenderConsole()
{
    //Refresh console
    system("cls");

    //Iterate through each character in matrix and print it to screen
    for(int i = 0; i < dimY; ++i)
    {
        for(int j = 0; j < dimX; ++j)
        {
            std::cout << displayMatrix[i][j];
        }

        std::cout << '\n';
    }
}

void Char_Display::HandleEvents()
{
    //Continuous keys
    const Uint8* keystate = SDL_GetKeyboardState(NULL);

    SDL_Event event;
    while(SDL_PollEvent(&event) != 0)
        {
            switch(event.type) {
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            isRunning = false;
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
        }
}

void Char_Display::Render()
{
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);

        
}

void Char_Display::Clean()
{
    SDL_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    std::cout << "Quitting SDL..." << std::endl;
}