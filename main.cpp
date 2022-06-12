#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <string>

//For use of SDL
#include "display.h"

//Aircraft systems
#include "fmgs.h"


#define TICK_INTERVAL 100

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
    //Initialize FMGS
    FMGS* A330_FMGS = new FMGS();

    //Create an instance of display
    Display* Display_System = new Display("A330 SYSTEM", 50, 50, 400, 440, SDL_RENDERER_ACCELERATED);


    A330_FMGS->MCDU1->pad->AddToScratchpad("YPAD");

    //Main refresh loop
    while(Display_System->running())
    {
        //Display_System->HandleEvents();
        Display_System->HandleMcduEvents(A330_FMGS->MCDU1);
        //Display_System->Render();
        //MCDU_L->RenderConsole();
        A330_FMGS->MCDU1->RenderSDLMCDU(Display_System->renderer, Display_System->DisplayFont);
        SDL_Delay(time_left());
        next_time += TICK_INTERVAL;

    }

    Display_System->Clean();

    return 0;
}
