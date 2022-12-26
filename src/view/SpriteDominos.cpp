#include "../include/SpriteDominos.hpp"

SpriteDominos::SpriteDominos(){}

SpriteDominos::~SpriteDominos(){}

void SpriteDominos::init(sf::Font &f,Dominos *d)
{
    std::string haut = " "+std::to_string(d->getValeur(0)[0])+std::to_string(d->getValeur(0)[1])+std::to_string(d->getValeur(0)[2])+" ";
    std::string cote1 = std::to_string(d->getValeur(3)[2])+"   "+std::to_string(d->getValeur(1)[0]);
    std::string cote2 = std::to_string(d->getValeur(3)[1])+"   "+std::to_string(d->getValeur(1)[1]);
    std::string cote3 = std::to_string(d->getValeur(3)[0])+"   "+std::to_string(d->getValeur(1)[2]);
    std::string bas = " "+std::to_string(d->getValeur(2)[2])+std::to_string(d->getValeur(2)[1])+std::to_string(d->getValeur(2)[0])+" ";
    
    one.setString(haut);
    one.setFont(f);
    one.setCharacterSize(19);

    two.setString(cote1);
    two.setFont(f);
    two.setCharacterSize(19);

    three.setString(cote2);
    three.setFont(f);
    three.setCharacterSize(19);

    four.setString(cote3);
    four.setFont(f);
    four.setCharacterSize(19);

    five.setString(bas);
    five.setFont(f);
    five.setCharacterSize(19);
}

void SpriteDominos::setString(Dominos *d)
{
    std::string haut = " "+std::to_string(d->getValeur(0)[0])+std::to_string(d->getValeur(0)[1])+std::to_string(d->getValeur(0)[2])+" ";
    std::string cote1 = std::to_string(d->getValeur(3)[2])+"   "+std::to_string(d->getValeur(1)[0]);
    std::string cote2 = std::to_string(d->getValeur(3)[1])+"   "+std::to_string(d->getValeur(1)[1]);
    std::string cote3 = std::to_string(d->getValeur(3)[0])+"   "+std::to_string(d->getValeur(1)[2]);
    std::string bas = " "+std::to_string(d->getValeur(2)[2])+std::to_string(d->getValeur(2)[1])+std::to_string(d->getValeur(2)[0])+" ";
    
    one.setString(haut);
    two.setString(cote1);
    three.setString(cote2);
    four.setString(cote3);
    five.setString(bas);
}

void SpriteDominos::myPosition(float x,float y)
{
    pos.x=x;
    pos.y=y;
    one.setPosition(x+10,y);
    two.setPosition(x+10,y+19);
    three.setPosition(x+10,y+39);
    four.setPosition(x+10,y+59);
    five.setPosition(x+10,y+76);
}

void SpriteDominos::setGridPosition(int x,int y)
{
    this->x=x;
    this->y=y;
}

int SpriteDominos::getX()
{
    return x;
}

int SpriteDominos::getY()
{
    return y;
}

void SpriteDominos::draw(sf::RenderWindow &w)
{
    w.draw(one);
    w.draw(two);
    w.draw(three);
    w.draw(four);
    w.draw(five);
}

sf::Vector2f SpriteDominos::getPos()
{
    return pos;
}