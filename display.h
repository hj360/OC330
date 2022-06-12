#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>

#include <imgui.h>
#include <imgui-SFML.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "fmgs.h"

class Display
{
    public:
        Display();
        Display(FMGS* FMGS_);
        ~Display();

        sf::RenderWindow* sfWindow;

        void Display_Render();
        void imgui_INIT();
        void imgui_DESTROY();

        void handleEvents();

    private:

        FMGS* A330_FMGS;
        

};


#endif