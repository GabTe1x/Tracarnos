#ifndef _SPRITEDOMINOS
#define _SPRITEDOMINOS

#include <SFML/Graphics.hpp>

class SpriteDominos: public sf::Drawable, public sf::Transformable
{
private:
    sf::Text one;
    sf::Text two;
    sf::Text three;
    sf::Text four;
    sf::Text five;
    sf::RectangleShape border;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  
public:
    SpriteDominos();
    ~SpriteDominos();
    void init(sf::Font &f,std::string haut,std::string cote1
                    ,std::string cote2,std::string cote3,std::string bas);
    void myPosition(float x,float y);
};

#endif // _SPRITEDOMINOS