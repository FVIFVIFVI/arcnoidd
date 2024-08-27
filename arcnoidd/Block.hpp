#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include <cmath>
#define M_PI 3.14159265358979323846

#include <SFML/Graphics.hpp>

class Block
{
  

protected:
    Block() {};

public:

    virtual void Draw(sf::RenderWindow & window) = 0;
    
    virtual void updatelifeBlok() = 0;

    virtual bool getlifblok() = 0;


    virtual float left() const = 0;
    virtual float rigth() const = 0;
    virtual float top() const = 0;  
    virtual float bottom() const = 0;
  
};


class Blocklevel1 : public Block
{
    public:

     Blocklevel1(const sf::Vector2f & size, const sf::Vector2f & position);


     bool getlifblok()  override;

     void Draw(sf::RenderWindow & window);
         
     void updatelifeBlok() override; 

    float left()   const override { return rect.getPosition().x; }
    float rigth()  const override { return rect.getPosition().x + rect.getSize().x; }
    float top()    const override { return rect.getPosition().y; }
    float bottom() const override { return rect.getPosition().y + rect.getSize().y; }
  

    private:
   
    sf::RectangleShape rect;
    int lifeblok;
    std::vector<sf::Color> listColor = {sf::Color::Red};

};



class Blocklevel2 : public Block
{
    public:

     Blocklevel2(const sf::Vector2f & size, const sf::Vector2f & position);


     bool getlifblok()  override;

     void Draw(sf::RenderWindow & window);
         
     void updatelifeBlok() override; 

    float left()   const override { return rect.getPosition().x; }
    float rigth()  const override { return rect.getPosition().x + rect.getSize().x; }
    float top()    const override { return rect.getPosition().y; }
    float bottom() const override { return rect.getPosition().y + rect.getSize().y; }
 

    private:
  
    sf::RectangleShape rect;
    int lifeblok;
    std::vector<sf::Color> listColor = {sf::Color::Red,sf::Color::Green,sf::Color::White,sf::Color::Yellow};

};

#endif // BLOCK_HPP
