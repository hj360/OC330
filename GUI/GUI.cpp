#include "GUI.h"

//Main custom GUI for the system

UI::UI(sf::RenderWindow* sfWindow_, FMGS* FMGS_, sf::Mouse* mouse_)
{
    sfWindow = sfWindow_;
    A330_FMGS = FMGS_;
    mouse = mouse_;
    font.loadFromFile("./res/fonts/Montserrat-Regular.ttf");

    exit = new Button_Graphic(45, 30, "./res/exit.png", true);
    fmgc_button = new Button_Text(100, 30, "FMGC", font, true);
    window_move = new Button_Text(21, 30, "", font, true);

    exitCondition = false;
}

void UI::DrawTaskbar()
{
    taskBarOutline.setSize(sf::Vector2f(sfWindow->getSize().x, 30));
    taskBarOutline.setOutlineThickness(-1);
    taskBarOutline.setOutlineColor(sf::Color(50, 50, 50));
    taskBarOutline.setFillColor(sf::Color::Transparent);

    sfWindow->draw(taskBarOutline);

    //Draw exit button
    if(exit->Draw(sfWindow->getSize().x - 45, 0, sfWindow, mouse))
    {
        //Exit program
        sfWindow->close();
    }

    if(fmgc_button->Draw(20, 0, sfWindow, mouse))
    {

    }

    if(window_move->Draw(0, 0, sfWindow, mouse))
    {
        while(mouse->isButtonPressed(mouse->Left))
        {
            sfWindow->setPosition(sf::Vector2i(mouse->getPosition().x - 10, mouse->getPosition().y - 10));
        }
        
    }


}

bool UI::getExitCondition()
{
    return exitCondition;
}
