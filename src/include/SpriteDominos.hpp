#ifndef _SPRITEDOMINOS
#define _SPRITEDOMINOS

#include <SFML/Graphics.hpp>

class SpriteDominos//: public sf::Drawable, public sf::Transformable
{
private:
    //virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  
public:
    SpriteDominos(std::string a,std::string b,std::string c,std::string d,std::string e,sf::Font f);
    ~SpriteDominos();
};

#endif // _SPRITEDOMINOS
