#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Graphics.hpp>
#include "BlocksField.hpp"

class Game
{
private:
    static Ball * ball;
    static Paddle * paddle;
    static bool exsistball;
    Game() = delete;

public:
    static void createBall(const Ball & bll) { ball = new Ball(bll); }
    static void createPaddle(const Paddle & padd) { paddle = new Paddle(padd); }
    static bool Update(float deltaTime, BlocksField & blocksField);
    static void Draw(sf::RenderWindow & window);
    static bool exsistbal() {return exsistball;}
};

#endif // GAME_HPP_
