#ifndef GUI_ELEMENTS_H
#define GUI_ELEMENTS_H

#include <SFML/Graphics.hpp>
#include <string>

class Button
{
    public:
        Button(int w_, int h_, std::string text_, sf::Font& font_);
        ~Button(){};

        bool Draw(int x_, int y_, sf::RenderWindow* sfWindow, sf::Mouse* mouse_);
        bool Clicked(sf::Window& sfWindow, sf::Mouse* mouse_);
    private:
        //Position of the button on screen
        int x;
        int y;
        //shape
        sf::RectangleShape shape;
        sf::Text text;

        bool lastPressed;

};

class GUI_Window
{
    public:
        GUI_Window(int w_, int h_);
        ~GUI_Window(){};

        bool Draw(int x_, int y_, sf::RenderWindow* sfWindow, sf::Mouse* mouse_);
        bool Clicked(sf::Window& sfWindow, sf::Mouse* mouse_);
    private:
        //Position of the button on screen
        int x;
        int y;
        //shape
        sf::RectangleShape shape;
};



#endif