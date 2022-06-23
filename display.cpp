#include "display.h"

Display::Display()
{
    sfWindow = new sf::RenderWindow(sf::VideoMode(1500, 900), "A330", sf::Style::Default);
}

Display::Display(FMGS* FMGS_)
{
    A330_FMGS = FMGS_;
    sfWindow = new sf::RenderWindow(sf::VideoMode(1600, 800), "A330", sf::Style::None);

    //Set the active MCDU
    ActiveMCDU = A330_FMGS->MCDU1;

    //Create a mouse
    mouse = new sf::Mouse();

    icon.loadFromFile("res/icon.png");

    sfWindow->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //Initialize GUI
    systemGUI = new UI(sfWindow, A330_FMGS, mouse);



    //Get watermark
    if(!watermarkTex.loadFromFile("./res/watermark.png"))
    {
        std::cout << "Watermark texture failed to load!" << std::endl;
    }

    watermarkTex.setSmooth(true);

    watermarkSprite.setTexture(watermarkTex);
}


Display::~Display() {}

void Display::Display_RENDER()
{
    //Draw UI
    systemGUI->DrawTaskbar();

    if(systemGUI->drawMCDU1)
    {
        A330_FMGS->MCDU1->DrawMCDU(sfWindow, mouse);
    }
    if(systemGUI->drawMCDU2)
    {
        A330_FMGS->MCDU2->DrawMCDU(sfWindow, mouse);
    }
    if(systemGUI->drawMCDU3)
    {
        A330_FMGS->MCDU3->DrawMCDU(sfWindow, mouse);
    }


}

void Display::Display_CLEAR()
{
    sfWindow->clear();
}

void Display::Display_DISPLAY()
{
    sfWindow->display();
}

void Display::handleEvents()
{
    sf::Event event;
        while (sfWindow->pollEvent(event))
        {
            switch (event.type)
            {
                // window closed
                case sf::Event::Closed:
                    sfWindow->close();
                    break;
                // key pressed
                case sf::Event::KeyPressed:
                    switch (event.key.code)
                    {
                    case sf::Keyboard::Space:
                        ActiveMCDU->pad->AddToScratchpad(" ");
                        break;
                    case sf::Keyboard::BackSpace:
                        ActiveMCDU->pad->CLRScratchpad();
                        break;
                    case sf::Keyboard::A:
                        ActiveMCDU->pad->AddToScratchpad("A");
                        break;
                    case sf::Keyboard::B:
                        ActiveMCDU->pad->AddToScratchpad("B");
                        break;
                    case sf::Keyboard::C:
                        ActiveMCDU->pad->AddToScratchpad("C");
                        break;
                    case sf::Keyboard::D:
                        ActiveMCDU->pad->AddToScratchpad("D");
                        break;
                    case sf::Keyboard::E:
                        ActiveMCDU->pad->AddToScratchpad("E");
                        break;
                    case sf::Keyboard::F:
                        ActiveMCDU->pad->AddToScratchpad("F");
                        break;
                    case sf::Keyboard::G:
                        ActiveMCDU->pad->AddToScratchpad("G");
                        break;
                    case sf::Keyboard::H:
                        ActiveMCDU->pad->AddToScratchpad("H");
                        break;
                    case sf::Keyboard::I:
                        ActiveMCDU->pad->AddToScratchpad("I");
                        break;
                    case sf::Keyboard::J:
                        ActiveMCDU->pad->AddToScratchpad("J");
                        break;
                    case sf::Keyboard::K:
                        ActiveMCDU->pad->AddToScratchpad("K");
                        break;
                    case sf::Keyboard::L:
                        ActiveMCDU->pad->AddToScratchpad("L");
                        break;
                    case sf::Keyboard::M:
                        ActiveMCDU->pad->AddToScratchpad("M");
                        break;
                    case sf::Keyboard::N:
                        ActiveMCDU->pad->AddToScratchpad("N");
                        break;
                    case sf::Keyboard::O:
                        ActiveMCDU->pad->AddToScratchpad("O");
                        break;
                    case sf::Keyboard::P:
                        ActiveMCDU->pad->AddToScratchpad("P");
                        break;
                    case sf::Keyboard::Q:
                        ActiveMCDU->pad->AddToScratchpad("Q");
                        break;
                    case sf::Keyboard::R:
                        ActiveMCDU->pad->AddToScratchpad("R");
                        break;
                    case sf::Keyboard::S:
                        ActiveMCDU->pad->AddToScratchpad("S");
                        break;
                    case sf::Keyboard::T:
                        ActiveMCDU->pad->AddToScratchpad("T");
                        break;
                    case sf::Keyboard::U:
                        ActiveMCDU->pad->AddToScratchpad("U");
                        break;
                    case sf::Keyboard::V:
                        ActiveMCDU->pad->AddToScratchpad("V");
                        break;
                    case sf::Keyboard::W:
                        ActiveMCDU->pad->AddToScratchpad("W");
                        break;
                    case sf::Keyboard::X:
                        ActiveMCDU->pad->AddToScratchpad("X");
                        break;
                    case sf::Keyboard::Y:
                        ActiveMCDU->pad->AddToScratchpad("Y");
                        break;
                    case sf::Keyboard::Z:
                        ActiveMCDU->pad->AddToScratchpad("Z");
                        break;
                    case sf::Keyboard::Num0:
                        ActiveMCDU->pad->AddToScratchpad("0");
                        break;
                    case sf::Keyboard::Num1:
                        ActiveMCDU->pad->AddToScratchpad("1");
                        break;
                    case sf::Keyboard::Num2:
                        ActiveMCDU->pad->AddToScratchpad("2");
                        break;
                    case sf::Keyboard::Num3:
                        ActiveMCDU->pad->AddToScratchpad("3");
                        break;
                    case sf::Keyboard::Num4:
                        ActiveMCDU->pad->AddToScratchpad("4");
                        break;
                    case sf::Keyboard::Num5:
                        ActiveMCDU->pad->AddToScratchpad("5");
                        break;
                    case sf::Keyboard::Num6:
                        ActiveMCDU->pad->AddToScratchpad("6");
                        break;
                    case sf::Keyboard::Num7:
                        ActiveMCDU->pad->AddToScratchpad("7");
                        break;
                    case sf::Keyboard::Num8:
                        ActiveMCDU->pad->AddToScratchpad("8");
                        break;
                    case sf::Keyboard::Num9:
                        ActiveMCDU->pad->AddToScratchpad("9");
                        break;
                    case sf::Keyboard::Slash:
                        ActiveMCDU->pad->AddToScratchpad("/");
                        break;
                    case sf::Keyboard::Period:
                        ActiveMCDU->pad->AddToScratchpad(".");
                        break;
                    case sf::Keyboard::Dash:
                        ActiveMCDU->pad->AddToScratchpad("-");
                        break;
                    case sf::Keyboard::Left:
                        ActiveMCDU->goLeft();
                        break;
                    case sf::Keyboard::Right:
                        ActiveMCDU->goRight();
                        break;
                    case sf::Keyboard::Up:
                        //Move mcdu page up
                        break;
                    case sf::Keyboard::Down:
                        //Move mcdu page down
                        break;

                    default:
                        break;
                    }
                    

                // we don't process other types of events
                default:
                    break;
            }

        }
}

void Display::drawWatermark()
{
    watermarkSprite.setPosition(sf::Vector2f(sfWindow->getSize().x - 250, sfWindow->getSize().y - 40));
    sfWindow->draw(watermarkSprite);
}