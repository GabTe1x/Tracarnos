#include "../include/SpriteDominos.hpp"

SpriteDominos::SpriteDominos(std::string a,std::string b,std::string c,std::string d,std::string e,sf::Font f)
{

}

SpriteDominos::~SpriteDominos(){}

void SpriteDominos::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    states.transform *= getTransform();
    target.draw(states);
}