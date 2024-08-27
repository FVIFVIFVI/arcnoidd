#ifndef BLOCKSFIELD_HPP_
#define BLOCKSFIELD_HPP_

#include <list>
#include <memory> 
#include <unordered_map>
#include "Ball.hpp"

class BlocksField
{
private:
    std::list<std::shared_ptr<Block>> blocks;

    

public:
    BlocksField(const sf::Vector2f & size, const sf::Vector2f & position, const sf::Color & color, int columns, int rows ,int level);

    void Update(Ball & ball);

    void Draw(sf::RenderWindow & window);

    bool is_empty() {return blocks.empty();}
};

#endif // BLOCKSFIELD_HPP_
