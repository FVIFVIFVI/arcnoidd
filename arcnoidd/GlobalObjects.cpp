

#include "GlobalObjects.hpp"




const float GlobalObjects::windowWidth = 700.f;
const float GlobalObjects::windowHeight = 512.f;
sf::RenderWindow GlobalObjects::window;

void GlobalObjects::initializeWindow(bool condition)
{
    if (condition)
    {
        window.create(sf::VideoMode(windowWidth, windowHeight), "Arkanoid", sf::Style::Close | sf::Style::Titlebar);
    }
    else
    {
        window.create(sf::VideoMode(333.f, 333.f), "Arkanoid", sf::Style::Close | sf::Style::Titlebar);
    }
}









