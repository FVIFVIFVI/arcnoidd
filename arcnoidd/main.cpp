#include <SFML/Graphics.hpp>
#include <iostream>
#include "GlobalObjects.hpp"
#include "BlocksField.hpp"
#include "Paddle.hpp"
#include "Block.hpp"
#include "screen.hpp"

int main()
{
    sf::Event event;
    sf::Clock clock;
    float deltaTime;

    int level = 1;

    GlobalObjects::initializeWindow(true);

    Game::createBall(Ball(10.f, sf::Vector2f(225.0710f, 400.f), sf::Color::Red, 180.f, 90.f));

    Game::createPaddle(Paddle(sf::Vector2f(100.f, 10.f), sf::Vector2f(256.f, 450.f), sf::Color::Green, 200.f));

    GameDrawable gameDrawable(sf::Vector2f(GlobalObjects::windowWidth, 200.f), sf::Vector2f(0.f, 0.f), sf::Color::Yellow, 9, 7,level );

    ImageDrawable imageDrawable("/home/mefathim-tech-41/Downloads/aaa.jpg");


    sf::IntRect clickableArea(500, 20, 100, 100);

    int userInput = 0;
    while (GlobalObjects::window.isOpen())
    {

        Drawable *drawable;
        if (userInput == 0)
        {
            drawable = &imageDrawable;
        }
        if (userInput == 1)
        {
           
            if (gameDrawable.addlevel()){
                level +=1 ;
                // std::cout << gameDrawable.addlevel() << '/n';

            GameDrawable gameDrawable2(sf::Vector2f(GlobalObjects::windowWidth, 200.f), 
            sf::Vector2f(0.f, 0.f), sf::Color::Yellow, 9, 7,level ); 
            gameDrawable = gameDrawable2;
            }
            drawable = &gameDrawable;
        }

        deltaTime = clock.restart().asSeconds();

        while (GlobalObjects::window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                GlobalObjects::window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Enter)
                { 
                    userInput = 1;
                }
            }

            if (event.type == sf::Event::MouseButtonPressed)
            
            {if (event.mouseButton.button == sf::Mouse::Left)
            
                {sf::Vector2i mousePos = sf::Mouse::getPosition(GlobalObjects::window);
                if (clickableArea.contains(mousePos))
                {
                    userInput = 1;
                }}}
        
        }

        GlobalObjects::window.clear(sf::Color::Black);

        if (!drawable->Draw(GlobalObjects::window, deltaTime))
        {GlobalObjects::window.close();}

        GlobalObjects::window.display();
    }

    return 0;
}
