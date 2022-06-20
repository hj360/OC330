#include "display.h"

Display::Display()
{
    sfWindow = new sf::RenderWindow(sf::VideoMode(1280, 720), "A330", sf::Style::Default);
}

Display::Display(FMGS* FMGS_)
{
    A330_FMGS = FMGS_;
    sfWindow = new sf::RenderWindow(sf::VideoMode(1280, 720), "A330", sf::Style::None);

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

    A330_FMGS->MCDU1->DrawMCDU(sfWindow, mouse);

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
                        A330_FMGS->MCDU1->pad->AddToScratchpad(" ");
                        break;
                    case sf::Keyboard::BackSpace:
                        A330_FMGS->MCDU1->pad->CLRScratchpad();
                        break;
                    case sf::Keyboard::A:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("A");
                        break;
                    case sf::Keyboard::B:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("B");
                        break;
                    case sf::Keyboard::C:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("C");
                        break;
                    case sf::Keyboard::D:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("D");
                        break;
                    case sf::Keyboard::E:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("E");
                        break;
                    case sf::Keyboard::F:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("F");
                        break;
                    case sf::Keyboard::G:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("G");
                        break;
                    case sf::Keyboard::H:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("H");
                        break;
                    case sf::Keyboard::I:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("I");
                        break;
                    case sf::Keyboard::J:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("J");
                        break;
                    case sf::Keyboard::K:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("K");
                        break;
                    case sf::Keyboard::L:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("L");
                        break;
                    case sf::Keyboard::M:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("M");
                        break;
                    case sf::Keyboard::N:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("N");
                        break;
                    case sf::Keyboard::O:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("O");
                        break;
                    case sf::Keyboard::P:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("P");
                        break;
                    case sf::Keyboard::Q:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("Q");
                        break;
                    case sf::Keyboard::R:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("R");
                        break;
                    case sf::Keyboard::S:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("S");
                        break;
                    case sf::Keyboard::T:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("T");
                        break;
                    case sf::Keyboard::U:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("U");
                        break;
                    case sf::Keyboard::V:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("V");
                        break;
                    case sf::Keyboard::W:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("W");
                        break;
                    case sf::Keyboard::X:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("X");
                        break;
                    case sf::Keyboard::Y:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("Y");
                        break;
                    case sf::Keyboard::Z:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("Z");
                        break;
                    case sf::Keyboard::Num0:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("0");
                        break;
                    case sf::Keyboard::Num1:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("1");
                        break;
                    case sf::Keyboard::Num2:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("2");
                        break;
                    case sf::Keyboard::Num3:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("3");
                        break;
                    case sf::Keyboard::Num4:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("4");
                        break;
                    case sf::Keyboard::Num5:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("5");
                        break;
                    case sf::Keyboard::Num6:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("6");
                        break;
                    case sf::Keyboard::Num7:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("7");
                        break;
                    case sf::Keyboard::Num8:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("8");
                        break;
                    case sf::Keyboard::Num9:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("9");
                        break;
                    case sf::Keyboard::Slash:
                        A330_FMGS->MCDU1->pad->AddToScratchpad("/");
                        break;
                    case sf::Keyboard::Period:
                        A330_FMGS->MCDU1->pad->AddToScratchpad(".");
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