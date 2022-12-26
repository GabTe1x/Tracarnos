#ifndef _SPRITEDOMINOS
#define _SPRITEDOMINOS

#include <SFML/Graphics.hpp>
#include "Dominos.hpp"

class SpriteDominos
{
private:
    sf::Vector2f pos;
    sf::Text one;
    sf::Text two;
    sf::Text three;
    sf::Text four;
    sf::Text five;
    int x,y;
  
public:
    SpriteDominos();
    ~SpriteDominos();
    void init(sf::Font &f,Dominos *d);
    void myPosition(float x,float y);
    void draw(sf::RenderWindow &w);
    void setString(Dominos *d);
    int getY();
    int getX();
    void setGridPosition(int x,int y);
    sf::Vector2f getPos();
};

#endif // _SPRITEDOMINOS