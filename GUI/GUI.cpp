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
    elec_button = new Button_Text(100, 30, "ELEC", font, true);

    chbx_MCDU1 = new CheckBox("Show MCDU 1", font);
    chbx_MCDU2 = new CheckBox("Show MCDU 2", font);
    chbx_MCDU3 = new CheckBox("Show MCDU 3", font);

    drawMCDU1 = true;
    drawMCDU2 = false;
    drawMCDU3 = false;

    show_debug_fmgc = false;

    window_move = new Button_Text(20, 30, "", font, true);

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
        show_debug_fmgc = !show_debug_fmgc;
    }

    if(elec_button->Draw(120, 0, sfWindow, mouse))
    {

    }

    if(window_move->Draw(0, 0, sfWindow, mouse))
    {
        while(mouse->isButtonPressed(mouse->Left))
        {
            sfWindow->setPosition(sf::Vector2i(mouse->getPosition().x - 10, mouse->getPosition().y - 10));
        }
        
    }

    if(show_debug_fmgc)
    {
        draw_debug_fmgc();
    }


}

bool UI::getExitCondition()
{
    return exitCondition;
}

void UI::draw_debug_fmgc()
{
    int debugWindowX = sfWindow->getSize().x - 200;
    int debugWindowY = 200;
    if(chbx_MCDU1->Draw(debugWindowX, debugWindowY, sfWindow, mouse))
    {
        drawMCDU1 = !drawMCDU1;
    }
    if(chbx_MCDU2->Draw(debugWindowX, debugWindowY + 50, sfWindow, mouse))
    {
        drawMCDU2 = !drawMCDU2;
    }
    if(chbx_MCDU3->Draw(debugWindowX, debugWindowY + 100, sfWindow, mouse))
    {
        drawMCDU3 = !drawMCDU3;
    }
}
