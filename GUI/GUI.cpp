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
    ImGui::Begin("MCDU LSK");
    if(ImGui::Button("LSK1L"))
    {
        A330_FMGS->MCDU1->selectLsk(0);
    }else if(ImGui::Button("LSK2L"))
    {
        A330_FMGS->MCDU1->selectLsk(1);
    }else if(ImGui::Button("LSK3L"))
    {
        A330_FMGS->MCDU1->selectLsk(2);        
    }else if(ImGui::Button("LSK4L"))
    {
        A330_FMGS->MCDU1->selectLsk(3);       
    }else if(ImGui::Button("LSK5L"))
    {
        A330_FMGS->MCDU1->selectLsk(4);       
    }else if(ImGui::Button("LSK6L"))
    {
        A330_FMGS->MCDU1->selectLsk(5);  
    }else if(ImGui::Button("LSK1R"))
    {
        A330_FMGS->MCDU1->selectLsk(6); 
    }else if(ImGui::Button("LSK2R"))
    {
        A330_FMGS->MCDU1->selectLsk(7);
    }else if(ImGui::Button("LSK3R"))
    {
        A330_FMGS->MCDU1->selectLsk(8); 
    }else if(ImGui::Button("LSK4R"))
    {
        A330_FMGS->MCDU1->selectLsk(9);
    }else if(ImGui::Button("LSK5R"))
    {
        A330_FMGS->MCDU1->selectLsk(10); 
    }else if(ImGui::Button("LSK6R"))
    {
        A330_FMGS->MCDU1->selectLsk(11);  
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
