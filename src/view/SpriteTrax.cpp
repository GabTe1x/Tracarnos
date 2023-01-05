#include "../include/SpriteTrax.hpp"

SpriteTrax::SpriteTrax() {}

SpriteTrax::~SpriteTrax(){}

void SpriteTrax::init()
{
    if (!front.loadFromFile("src/ressources/trax_front.png"))
    {
        std::cout << "Error couldn't load texture" << std::endl;
    }
    if (!back.loadFromFile("src/ressources/trax_back.png"))
    {
        std::cout << "Error couldn't load texture" << std::endl;
    }
    side = true;
    texture.setTexture(front);
    texture.setScale(0.0488, 0.0488);
}

void SpriteTrax::rotate()
{
    texture.rotate(90);
    myPosition(pos.x,pos.y);
}

void SpriteTrax::switchSide(TuileTrax *t)
{
    if (side)
    {
        side = false;
        texture.setTexture(back);
        texture.setScale(0.083,0.083);
        texture.setRotation(0);
        if(!t->getValeur(3))
        {
            texture.rotate(90);
            myPosition(pos.x,pos.y);
        }else
        {
            texture.rotate(270);
            myPosition(pos.x,pos.y);
        }
    }
    else
    {
        side = true;
        texture.setTexture(front);
        texture.setScale(0.0488, 0.0488);
        texture.setRotation(0);
        myPosition(pos.x,pos.y);
    }
}

void SpriteTrax::myPosition(float x, float y)
{
    pos.x = x;
    pos.y = y;
    if(texture.getRotation()==0.f)
    {
        texture.setPosition(x, y);
    }
    else if(texture.getRotation()==90.f)
    {
        texture.setPosition(x+100,y);
    }
    else if(texture.getRotation()==180.f)
    {
        texture.setPosition(x+100,y+100);
    }
    else
    {
        texture.setPosition(x,y+100);
    }
}

void SpriteTrax::setGridPosition(int x, int y)
{
    this->x = x;
    this->y = y;
    std::cout<<std::to_string(this->x)<<" : "<<std::to_string(this->y)<<std::endl;
}

int SpriteTrax::getX()
{
    return x;
}

int SpriteTrax::getY()
{
    return y;
}

void SpriteTrax::draw(sf::RenderWindow &w)
{
    w.draw(texture);
}

sf::Vector2f SpriteTrax::getPos()
{
    return pos;
}