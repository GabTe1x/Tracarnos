#ifndef _SPRITETRAX
#define _SPRITETRAX

#include <SFML/Graphics.hpp>
#include "TuileTrax.hpp"

class SpriteTrax
{
private:
    sf::Vector2f pos;
    sf::Sprite texture;
    sf::Texture back;
    sf::Texture front;
    int x,y;
    bool side=true;// true front false back
  
public:
    SpriteTrax();
    ~SpriteTrax();
    void init();
    void myPosition(float x,float y);
    void draw(sf::RenderWindow &w);
    void rotate();
    void switchSide(TuileTrax * t);
    int getY();
    int getX();
    void setGridPosition(int x,int y);
    sf::Vector2f getPos();
};

#endif // _SPRITETRAX