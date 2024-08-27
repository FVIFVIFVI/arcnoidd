#include "screen.hpp"
#include <iostream>
#include "GlobalObjects.hpp"


GameDrawable::GameDrawable(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, int rows, int columns, int level)
        : blocksField(size, position, color, rows, columns, level) {}


bool GameDrawable::Draw(sf::RenderWindow &window, float deltaTime)
{
        blocksField.Draw(window);
        Game::Draw(window);
        return Game::Update(deltaTime, blocksField);
}




   ImageDrawable::ImageDrawable(const std::string& imagePath)
   :playy{play()}
    {
        if (!texture.loadFromFile(imagePath)) {
            std::cerr << "Failed to load image: " << imagePath << std::endl;
        }

        sprite.setTexture(texture);
         sprite.setPosition(sf::Vector2f(50.f, 50.f));
    }

    bool ImageDrawable::Draw(sf::RenderWindow &window, float deltaTime)
    {
         window.draw(sprite);
         playy.Draw(window , deltaTime);
         return true;
    }

   
play::play() 
    :  fontPath("Pacifico.ttf"), fontColor(sf::Color::White), position(sf::Vector2f(500,20)), fontSize(100) 
    {
    
    if (!font.loadFromFile(fontPath)) {
        std::cerr << "Failed to load font: " << fontPath << std::endl;
    }

    text.setFont(font);
    text.setCharacterSize(fontSize);
    text.setFillColor(fontColor);
    text.setPosition(position);
}

bool play::Draw(sf::RenderWindow &window ,float deltaTime) {
    text.setString("play" );
    window.draw(text);
    return true;
}


