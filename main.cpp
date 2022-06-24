#include <iostream>
#include "display.h"

//Sim systems
#include "sim_params.h"

//Aircraft systems
#include "SENSORS/sensors.h"
#include "fmgs.h"

int main(int argc, char* argv[])
{
    //Begin initializing core systems
    std::cout << "Initializing core systems..." << std::endl;

    //Initialize simulator for dummy vars
    ParamSim *SIM = new ParamSim();

    //Initialize all sensors
    SensorManager* Sensors = new SensorManager(SIM);

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