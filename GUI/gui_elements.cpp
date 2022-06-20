#include "gui_elements.h"

Button::Button(int w_, int h_, std::string text_, sf::Font& font_)
{
    shape.setSize(sf::Vector2f(w_, h_));
    shape.setOutlineThickness(1);
    shape.setOutlineColor(sf::Color::White);
    shape.setFillColor(sf::Color::Transparent);

    text.setFont(font_);
    text.setCharacterSize(12);
    text.setFillColor(sf::Color::White);
    text.setString(text_);
    
    lastPressed = false;

    x = 0;
    y = 0;
}

//Returns true if pressed
bool Button::Draw(int x_, int y_, sf::RenderWindow* sfWindow, sf::Mouse* mouse_)
{
    x = x_;
    y = y_;

    //Set position
    shape.setPosition(sf::Vector2f(x_, y_));
    text.setPosition(x_, y_);

    //Draw box
    sfWindow->draw(shape);
    //Draw label
    sfWindow->draw(text);
    //Reset color if pressed
    shape.setOutlineColor(sf::Color::White);

    //Only check if mouse is clicked
    if(mouse_->isButtonPressed(mouse_->Left))
    {
        if(lastPressed == false && Clicked(*sfWindow, mouse_))
        {
            lastPressed = true;
            shape.setOutlineColor(sf::Color::Cyan);
            return true;
        }

        lastPressed = true;
        return false;
    }

    lastPressed = false;

    return false;

}

Button_Graphic::Button_Graphic(int w_, int h_, std::string img_path_, bool hoverable_)
{
    shape.setSize(sf::Vector2f(w_, h_));
    shape.setOutlineThickness(-1);
    shape.setOutlineColor(sf::Color::White);
    shape.setFillColor(sf::Color::Transparent);

    img_tex.loadFromFile(img_path_);
    img_sprite.setTexture(img_tex);
    
    lastPressed = false;
    hoverable = hoverable_;

    x_offset = (w_ - img_tex.getSize().x)/2;
    y_offset = (h_ - img_tex.getSize().y)/2;

    x = 0;
    y = 0;
}

//Returns true if pressed
bool Button_Graphic::Draw(int x_, int y_, sf::RenderWindow* sfWindow, sf::Mouse* mouse_)
{
    x = x_;
    y = y_;

    //Set position
    shape.setPosition(sf::Vector2f(x_, y_));
    img_sprite.setPosition(sf::Vector2f(x_ + x_offset, y_ + y_offset));

    //Draw box
    sfWindow->draw(shape);
    //Draw image
    sfWindow->draw(img_sprite);

    //Reset color if pressed
    shape.setOutlineColor(sf::Color::White);

    if(hoverable)
    {
        if(Clicked(*sfWindow, mouse_))
        {
            shape.setFillColor(sf::Color::Cyan);
            shape.setOutlineColor(sf::Color::Cyan);
        } else {
            shape.setFillColor(sf::Color::Transparent);
            shape.setOutlineColor(sf::Color(50, 50, 50));
        }
    }

    //Only check if mouse is clicked
    if(mouse_->isButtonPressed(mouse_->Left))
    {
        if(lastPressed == false && Clicked(*sfWindow, mouse_))
        {
            lastPressed = true;
            shape.setOutlineColor(sf::Color::Cyan);
            return true;
        }

        lastPressed = true;
        return false;
    }

    lastPressed = false;

    return false;

}

//check if cursor is inside box
bool Button_Graphic::Clicked(sf::Window& sfWindow, sf::Mouse* mouse_)
{
    sf::Vector2i mousePos = mouse_->getPosition(sfWindow);

    if(shape.getGlobalBounds().contains(sf::Vector2f(mousePos)))
    {
        
        return true;
    } else {
        return false;
    }
}

//check if cursor is inside box
bool Button::Clicked(sf::Window& sfWindow, sf::Mouse* mouse_)
{
    sf::Vector2i mousePos = mouse_->getPosition(sfWindow);

    if(shape.getGlobalBounds().contains(sf::Vector2f(mousePos)))
    {
        
        return true;
    } else {
        return false;
    }
}

Button_Text::Button_Text(int w_, int h_, std::string text_, sf::Font& font_, bool hoverable_)
{
    shape.setSize(sf::Vector2f(w_, h_));
    shape.setOutlineThickness(-1);
    shape.setOutlineColor(sf::Color::White);
    shape.setFillColor(sf::Color::Transparent);

    text.setFont(font_);
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::White);
    text.setString(text_);
    
    lastPressed = false;
    hoverable = hoverable_;

    x_offset = (w_ - text.getLocalBounds().width)/2;
    y_offset = (5);

    x = 0;
    y = 0;
}

//Returns true if pressed
bool Button_Text::Draw(int x_, int y_, sf::RenderWindow* sfWindow, sf::Mouse* mouse_)
{
    x = x_;
    y = y_;

    //Set position
    shape.setPosition(sf::Vector2f(x_, y_));
    text.setPosition(sf::Vector2f(x_ + x_offset, y_ + y_offset));

    //Draw box
    sfWindow->draw(shape);
    //Draw image
    sfWindow->draw(text);

    //Reset color if pressed
    shape.setOutlineColor(sf::Color::White);

    if(hoverable)
    {
        if(Clicked(*sfWindow, mouse_))
        {
            shape.setOutlineColor(sf::Color::Cyan);
            text.setFillColor(sf::Color::Cyan);
        } else {
            shape.setOutlineColor(sf::Color(50, 50, 50));
            text.setFillColor(sf::Color(50, 50, 50));
        }
    }

    //Only check if mouse is clicked
    if(mouse_->isButtonPressed(mouse_->Left))
    {
        if(lastPressed == false && Clicked(*sfWindow, mouse_))
        {
            lastPressed = true;
            shape.setOutlineColor(sf::Color::Cyan);
            return true;
        }

        lastPressed = true;
        return false;
    }

    lastPressed = false;

    return false;

}

//check if cursor is inside box
bool Button_Text::Clicked(sf::Window& sfWindow, sf::Mouse* mouse_)
{
    sf::Vector2i mousePos = mouse_->getPosition(sfWindow);

    if(shape.getGlobalBounds().contains(sf::Vector2f(mousePos)))
    {
        
        return true;
    } else {
        return false;
    }
}

GUI_Window::GUI_Window(int w_, int h_)
{
    shape.setSize(sf::Vector2f(w_, h_));
    shape.setOutlineThickness(1);
    shape.setOutlineColor(sf::Color::White);
    shape.setFillColor(sf::Color::Black);

    x = 0;
    y = 0;
}

//Returns true if pressed
bool GUI_Window::Draw(int x_, int y_, sf::RenderWindow* sfWindow, sf::Mouse* mouse_)
{
    x = x_;
    y = y_;

    //Set position
    shape.setPosition(sf::Vector2f(x_, y_));

    //Draw box
    sfWindow->draw(shape);
    //Reset color if pressed
    shape.setOutlineColor(sf::Color::White);

    //Only check if mouse is clicked
    if(mouse_->isButtonPressed(mouse_->Left))
    {
        if(Clicked(*sfWindow, mouse_))
        {
            shape.setOutlineColor(sf::Color::Cyan);
            return true;
        }
    }

    return false;

}

//check if cursor is inside box
bool GUI_Window::Clicked(sf::Window& sfWindow, sf::Mouse* mouse_)
{
    sf::Vector2i mousePos = mouse_->getPosition(sfWindow);

    if(shape.getGlobalBounds().contains(sf::Vector2f(mousePos)))
    {
        
        return true;
    } else {
        return false;
    }
}