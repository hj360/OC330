#include "GUI.h"

GUI::GUI(sf::RenderWindow* sfWindow_, FMGS* FMGS_)
{
    sfWindow = sfWindow_;
    A330_FMGS = FMGS_;
}

void GUI::imgui_INIT()
{
    std::cout << "Starting ImGUI..." << std::endl;
    ImGui::SFML::Init(*sfWindow);
}

void GUI::imgui_UPDATE(sf::Clock &deltaClock)
{
    ImGui::SFML::Update(*sfWindow, deltaClock.restart());
}

void GUI::imgui_RENDER()
{
    ImGui::Begin("Hello");
    ImGui::Text("Text");
    if(ImGui::Button("LSK1"))
    {
        A330_FMGS->MCDU1->selectLsk(1);
    }
    ImGui::End();

    ImGui::SFML::Render(*sfWindow);
}

void GUI::imgui_DESTROY()
{
    std::cout << "Shutting down ImGUI..." << std::endl;
    ImGui::SFML::Shutdown();
}

void GUI::imgui_EVENTHANDLER(sf::Event Event_)
{
    ImGui::SFML::ProcessEvent(Event_);
}
