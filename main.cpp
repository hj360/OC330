#include <iostream>
#include "display.h"

//Aircraft systems
#include "fmgs.h"

int main(int argc, char* argv[])
{
    //Begin initializing core systems
    std::cout << "Initializing core systems..." << std::endl;

    //Initialize FMGS
    FMGS* A330_FMGS = new FMGS();

    //Create a display
    Display* debugDisplay = new Display(A330_FMGS);
    
    debugDisplay->debugGUI->imgui_INIT();
    debugDisplay->sfWindow->setFramerateLimit(10);


    //GUI loop
    sf::Clock deltaClock;
    while (debugDisplay->sfWindow->isOpen())
    {
        //Update UI
        debugDisplay->handleEvents();
        debugDisplay->debugGUI->imgui_UPDATE(deltaClock);
        debugDisplay->Display_CLEAR();
        debugDisplay->Display_RENDER();
        debugDisplay->debugGUI->imgui_RENDER();
        debugDisplay->Display_DISPLAY();

    }


    //debugDisplay->imgui_DESTROY();
    A330_FMGS->MCDU1->CleanPages();
    debugDisplay->debugGUI->imgui_DESTROY();
    delete debugDisplay;
    delete A330_FMGS;

    return 0;
}