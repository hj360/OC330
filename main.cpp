#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <string>

//For use of SDL
#include "display.h"

//Aircraft systems
#include "fmgs.h"


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
    //Initialize FMGS
    FMGS* A330_FMGS = new FMGS();

    //Create an instance of display
    Display* Display_System = new Display("A330 SYSTEM", 50, 50, 700, 600, 0);


    std::string origin = "";

    A330_FMGS->FMGC1->FM.set_fpln_origin("YPAD", 1);
    A330_FMGS->FMGC1->FM.get_fpln_origin(origin, 1);


    std::cout << origin << std::endl;

    //Main refresh loop
    while(Display_System->running())
    {
        Display_System->HandleEvents();
        Display_System->Render();

        //MCDU_L->RenderConsole();

        SDL_Delay(time_left());
        next_time += TICK_INTERVAL;

    }

    Display_System->Clean();

    return 0;
}
