#include "GUI.h"

//Main custom GUI for the system

UI::UI(sf::RenderWindow* sfWindow_, FMGS* FMGS_)
{
    sfWindow = sfWindow_;
    A330_FMGS = FMGS_;
}

void UI::DrawTaskbar()
{
    taskBarOutline.setSize(sf::Vector2f(sfWindow->getSize().x, 30));
    taskBarOutline.setOutlineThickness(-1);
    taskBarOutline.setOutlineColor(sf::Color::White);
    taskBarOutline.setFillColor(sf::Color::Transparent);

    sfWindow->draw(taskBarOutline);


}
