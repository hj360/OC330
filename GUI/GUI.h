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
        void draw_debug_fmgc();

        bool drawMCDU1;
        bool drawMCDU2;
        bool drawMCDU3;


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
        Button_Text* elec_button;
        Button_Text* window_move;


        //FMGC Debug window
        CheckBox* chbx_MCDU1;
        CheckBox* chbx_MCDU2;
        CheckBox* chbx_MCDU3;

        bool exitCondition;

        bool show_debug_fmgc;
};


#endif