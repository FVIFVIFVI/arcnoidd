#include <iostream>
#include <memory> 

#include "BlocksField.hpp"
#include "score.hpp"


ScoreDrawable score;


BlocksField::BlocksField(const sf::Vector2f & size, const sf::Vector2f & position, const sf::Color & color, int columns, int rows,int level)
{
    sf::Vector2f blockSize(size.x / columns, size.y / rows);

    

    for (int i = 2; i < 7; i++)
    {
        for (int j = 2; j < 5; j++)
        {
           if(level == 1)
            {std::shared_ptr<Block> bl2 = std::make_shared<Blocklevel1>(blockSize - sf::Vector2f(4.f, 4.f), position + sf::Vector2f(blockSize.x * i + 2.f, blockSize.y * j + 2.f));
            blocks.push_back(bl2);}
            
            if(level == 2)
            {std::shared_ptr<Block> bl2 = std::make_shared<Blocklevel2>(blockSize - sf::Vector2f(4.f, 4.f), position + sf::Vector2f(blockSize.x * i + 2.f, blockSize.y * j + 2.f));
            blocks.push_back(bl2);}
        }
    }
}



void BlocksField::Update(Ball & ball)
{
   

    blocks.remove_if([&ball, this ](std::shared_ptr<Block> blockPtr) -> bool {
       bool a = ball.checkColission(*blockPtr);
       if(a == true){ score.setScore(score.getScore()+1);}
       return a;
    });
}







void BlocksField::Draw(sf::RenderWindow & window)
{
    score.Draw(window);
    for (auto &block : blocks)
    {
       block->Draw(window);
    }
}
