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
        UI(sf::RenderWindow* sfWindow_, FMGS* FMGS_, sf::Mouse* mouse_);
        ~UI(){};

        void DrawTaskbar();
        bool getExitCondition();

    private:
        sf::RenderWindow* sfWindow;
        FMGS* A330_FMGS;

        sf::Mouse* mouse;

        //Main ui font
        sf::Font font;
        sf::RectangleShape taskBarOutline;

        Button_Graphic* exit;
        Button_Text* fmgc_button;

        bool exitCondition;
};


#endif