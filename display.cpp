#include <iostream>
#include <windows.h>
#include "display.h"

Display::Display(const char *title, int x, int y, int w, int h, int flags)
{
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

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1" );

    //Initialize SDL TTF for font rendering
    if(TTF_Init() == -1)
    {
        std::cerr << "Error! TTF Failed to init!" << std::endl;
        exit(-1);
    } else {
        std::cout << "TTF Initialized!" << std::endl;
    }

    //Loads fonts for display
    DisplayFont = TTF_OpenFont("res/fonts/B612Mono-Regular.ttf", 25);

    //Check display font is loaded
    if(DisplayFont != nullptr)
    {
        std::cout << "Fonts loaded!" << std::endl;
    } else {
        std::cerr << "Fonts failed to load!" << std::endl;
    }   

}

Display::~Display()
{

}

void Display::HandleEvents()
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

void Display::HandleMcduEvents(MCDU* mcdu_)
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
                        case SDLK_BACKSPACE:
                            mcdu_->pad->CLRScratchpad();
                            break;
                        case SDLK_SPACE:
                            mcdu_->pad->AddToScratchpad(" ");
                            break;
                        case SDLK_a:
                            mcdu_->pad->AddToScratchpad("A");
                            break;
                        case SDLK_b:
                            mcdu_->pad->AddToScratchpad("B");
                            break;
                        case SDLK_c:
                            mcdu_->pad->AddToScratchpad("C");
                            break;
                        case SDLK_d:
                            mcdu_->pad->AddToScratchpad("D");
                            break;
                        case SDLK_e:
                            mcdu_->pad->AddToScratchpad("E");
                            break;
                        case SDLK_f:
                            mcdu_->pad->AddToScratchpad("F");
                            break;
                        case SDLK_g:
                            mcdu_->pad->AddToScratchpad("G");
                            break;
                        case SDLK_h:
                            mcdu_->pad->AddToScratchpad("H");
                            break;
                        case SDLK_i:
                            mcdu_->pad->AddToScratchpad("I");
                            break;
                        case SDLK_j:
                            mcdu_->pad->AddToScratchpad("J");
                            break;
                        case SDLK_k:
                            mcdu_->pad->AddToScratchpad("K");
                            break;
                        case SDLK_l:
                            mcdu_->pad->AddToScratchpad("L");
                            break;
                        case SDLK_m:
                            mcdu_->pad->AddToScratchpad("M");
                            break;
                        case SDLK_n:
                            mcdu_->pad->AddToScratchpad("N");
                            break;
                        case SDLK_o:
                            mcdu_->pad->AddToScratchpad("O");
                            break;
                        case SDLK_p:
                            mcdu_->pad->AddToScratchpad("P");
                            break;
                        case SDLK_q:
                            mcdu_->pad->AddToScratchpad("Q");
                            break;
                        case SDLK_r:
                            mcdu_->pad->AddToScratchpad("R");
                            break;
                        case SDLK_s:
                            mcdu_->pad->AddToScratchpad("S");
                            break;
                        case SDLK_t:
                            mcdu_->pad->AddToScratchpad("T");
                            break;
                        case SDLK_u:
                            mcdu_->pad->AddToScratchpad("U");
                            break;
                        case SDLK_v:
                            mcdu_->pad->AddToScratchpad("V");
                            break;
                        case SDLK_w:
                            mcdu_->pad->AddToScratchpad("W");
                            break;
                        case SDLK_x:
                            mcdu_->pad->AddToScratchpad("X");
                            break;
                        case SDLK_y:
                            mcdu_->pad->AddToScratchpad("Y");
                            break;
                        case SDLK_z:
                            mcdu_->pad->AddToScratchpad("Z");
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
        }
}

void Display::Render()
{
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        SDL_RenderClear(renderer);


        SDL_RenderPresent(renderer);

        
}

void Display::Clean()
{
    TTF_CloseFont(DisplayFont);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    std::cout << "Quitting SDL..." << std::endl;
    TTF_Quit();
    SDL_Quit();
}