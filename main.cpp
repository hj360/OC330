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
    
    debugDisplay->sfWindow->setFramerateLimit(30);


    //GUI loop
    sf::Clock deltaClock;
    while (debugDisplay->sfWindow->isOpen())
    {
        //Update UI
        debugDisplay->handleEvents();
        debugDisplay->Display_CLEAR();
        debugDisplay->drawWatermark();
        debugDisplay->Display_RENDER();
        debugDisplay->Display_DISPLAY();

    }


    std::cout << "Quitting..." << std::endl;
    A330_FMGS->MCDU1->CleanPages();
    delete debugDisplay;
    delete A330_FMGS;

    return 0;
}