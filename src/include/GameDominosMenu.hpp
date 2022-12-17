#ifndef _DOMINOSMENU
#define _DOMINOSMENU

#include <SFML/Graphics.hpp>

class GameDominosMenu: public sf::Drawable, public sf::Transformable
{
private:
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  
public:
    GameDominosMenu();
    ~GameDominosMenu();
    void init();
    void setJoueur();
    void myPosition(float x,float y);
};

#endif // _DOMINOSMENU