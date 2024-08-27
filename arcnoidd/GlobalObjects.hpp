

#ifndef GLOBALOBJECTS_HPP_
#define GLOBALOBJECTS_HPP_

#include <SFML/Graphics.hpp>



class GlobalObjects
{
private:
    GlobalObjects() = delete;

public:
    static const float windowWidth, windowHeight;
    static sf::RenderWindow window;


    static void initializeWindow(bool condition);
};




#endif // GLOBALOBJECTS_HPP_