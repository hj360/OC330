#include "SDL2/SDL.h"

#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "display.h"

#define TICK_INTERVAL 5

static Uint32 next_time;

Uint32 time_left()
{
    Uint32 now;
    now = SDL_GetTicks();
    if(next_time <= now)
    {
        return 0;
    } else {
        return next_time - now;
    }
}


int main(int argc, char* argv[])
{

    //Create an instance of display
    Char_Display* MCDU_L = new Char_Display("MCDU LEFT", 50, 50, 400, 350, 0, 24, 14);

    //Main refresh loop
    while(MCDU_L->running())
    {
        MCDU_L->HandleEvents();
        MCDU_L->Render();

        //MCDU_L->RenderConsole();

        SDL_Delay(time_left());
        next_time += TICK_INTERVAL;

    }

    MCDU_L->Clean();

    return 0;
}
