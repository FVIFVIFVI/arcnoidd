
#ifndef SCREEN_HPP_
#define SCREEN_HPP_

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "score.hpp"

class Drawable {
public:
    virtual bool Draw(sf::RenderWindow &window ,float deltaTime ) = 0; 
};


class GameDrawable : public Drawable {
public:
    GameDrawable(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color, int rows, int columns, int level);

    bool Draw(sf::RenderWindow &window, float deltaTime) override ;

    bool addlevel() { return blocksField.is_empty();}

private:
    BlocksField blocksField;
};


class GameStart : public Drawable{
    public:
    GameStart();
    bool Draw(sf::RenderWindow &window, float deltaTime) override ;

};



class play: public Drawable{
    public:
    play();
    bool Draw(sf::RenderWindow &window ,float deltaTime) override ;
 

private:
    sf::Font font;
    sf::Text text;
    

    std::string fontPath;
    sf::Color fontColor;
    sf::Vector2f position;
    unsigned int fontSize;
};



class ImageDrawable : public Drawable {
public:
    ImageDrawable(const std::string& imagePath);
    bool Draw(sf::RenderWindow &window, float deltaTime) override ;

private:
    sf::Texture texture;
    sf::Sprite sprite;
    play playy;
};



#endif