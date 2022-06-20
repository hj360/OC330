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

class Button_Graphic
{
    public:
        Button_Graphic(int w_, int h_, std::string img_path_, bool hoverable_);
        ~Button_Graphic(){};

        bool Draw(int x_, int y_, sf::RenderWindow* sfWindow, sf::Mouse* mouse_);
        bool Clicked(sf::Window& sfWindow, sf::Mouse* mouse_);
        void hoverUpdate();
    private:
        //Position of the button on screen
        int x;
        int y;

        //For placing image sprite in center of box
        int x_offset;
        int y_offset;
        //shape
        sf::RectangleShape shape;
        sf::Texture img_tex;
        sf::Sprite img_sprite;

        bool lastPressed;
        bool hoverable;

};

class Button_Text
{
    public:
        Button_Text(int w_, int h_, std::string text_, sf::Font& font_, bool hoverable_);
        ~Button_Text(){};

        bool Draw(int x_, int y_, sf::RenderWindow* sfWindow, sf::Mouse* mouse_);
        bool Clicked(sf::Window& sfWindow, sf::Mouse* mouse_);
        void hoverUpdate();
    private:
        //Position of the button on screen
        int x;
        int y;

        //For placing text in center of box
        int x_offset;
        int y_offset;
        //shape
        sf::RectangleShape shape;
        sf::Text text;

        bool lastPressed;
        bool hoverable;

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