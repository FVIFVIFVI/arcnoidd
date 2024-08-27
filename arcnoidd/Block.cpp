#include "Block.hpp"
#include <random>


 Blocklevel1::Blocklevel1(const sf::Vector2f & size, const sf::Vector2f & position)

: Block{},
lifeblok {(rand() % 1)}

{
    rect.setSize(size);
    rect.setPosition(position);
    rect.setFillColor(listColor[lifeblok]);

}

bool Blocklevel1::getlifblok()
{
     return lifeblok == -1;
}

void Blocklevel1::updatelifeBlok()
{lifeblok -= 1; rect.setFillColor(listColor[lifeblok]);}


void Blocklevel1::Draw(sf::RenderWindow & window)
{
    window.draw(rect);
    
}


Blocklevel2::Blocklevel2(const sf::Vector2f & size, const sf::Vector2f & position)

: Block{},
lifeblok {(rand() % 4)}

{
    rect.setSize(size);
    rect.setPosition(position);
    rect.setFillColor(listColor[lifeblok]);

}

bool Blocklevel2::getlifblok()
{
     return lifeblok == -1;
}

void Blocklevel2::updatelifeBlok()
{lifeblok -= 1; rect.setFillColor(listColor[lifeblok]);}


void Blocklevel2::Draw(sf::RenderWindow & window)
{
    window.draw(rect);
    
}

