#include "../include/SpriteDominos.hpp"

SpriteDominos::SpriteDominos(){}

SpriteDominos::~SpriteDominos(){}

void SpriteDominos::init(sf::Font &f,std::string haut,std::string cote1,std::string cote2,std::string cote3,std::string bas)
{
    one.setString(haut);
    one.setFont(f);
    one.setCharacterSize(14);

    two.setString(cote1);
    two.setFont(f);
    two.setCharacterSize(14);

    three.setString(cote2);
    three.setFont(f);
    three.setCharacterSize(14);

    four.setString(cote3);
    four.setFont(f);
    four.setCharacterSize(14);

    five.setString(bas);
    five.setFont(f);
    five.setCharacterSize(14);
}


void SpriteDominos::myPosition(float x,float y)
{
    this->setPosition(x,y);
    one.setPosition(x+1,y+1);
    two.setPosition(x+1,y+15);
    three.setPosition(x+1,y+29);
    four.setPosition(x+1,y+43);
    five.setPosition(x+1,y+57);
    border.setPosition(x,y);
}


void SpriteDominos::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(one,states);
    target.draw(two,states);
    target.draw(three,states);
    target.draw(four,states);
    target.draw(five,states);
}