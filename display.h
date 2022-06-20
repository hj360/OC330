#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "GUI/GUI.h"

#include "fmgs.h"

class Display
{
    public:
        Display();
        Display(FMGS* FMGS_);
        ~Display();

        sf::RenderWindow* sfWindow;

        void Display_RENDER();
        void Display_CLEAR();
        void Display_DISPLAY();        

        UI* systemGUI;

        void handleEvents();
        void drawWatermark();

    private:

        FMGS* A330_FMGS;
        sf::Image icon;
        sf::Mouse* mouse;

        sf::Texture watermarkTex;
        sf::Sprite watermarkSprite;
        

};


#endif