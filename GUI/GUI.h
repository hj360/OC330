#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "gui_elements.h"

#include "../fmgs.h"



#ifndef GUI_H
#define GUI_H

class UI
{
    public:
        UI(sf::RenderWindow* sfWindow_, FMGS* FMGS_);
        ~UI(){};

        void DrawTaskbar();

    private:
        sf::RenderWindow* sfWindow;
        FMGS* A330_FMGS;

        sf::RectangleShape taskBarOutline;
};


#endif