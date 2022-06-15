#include <iostream>

#include <imgui.h>
#include <imgui-SFML.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "../fmgs.h"


#ifndef GUI_H
#define GUI_H

class GUI
{
    public:
        GUI(sf::RenderWindow* sfWindow_, FMGS* FMGS_);
        ~GUI();

        void imgui_INIT();
        void imgui_UPDATE(sf::Clock &deltaClock);
        void imgui_RENDER();
        void imgui_DESTROY();
        void imgui_EVENTHANDLER(sf::Event Event_);


    private:

        sf::RenderWindow* sfWindow;
        ImGuiStyle GUIStyle;
        FMGS* A330_FMGS;

};


#endif