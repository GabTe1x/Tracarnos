#ifndef _GAMETRAX
#define _GAMETRAX

#include "Etat.hpp"
#include "Contexte.hpp"
#include "ControleurTrax.hpp"
#include <SFML/Window/Event.hpp>
#include "SpriteTrax.hpp"
#include <vector>
#include "EndGame.hpp"

class GameTrax:public Etat
{
private:
    // contexte
    Contexte *contexte;
    // controleur
    ControleurTrax ctlr;

    // Texte + bordure menu 
    sf::Text titre;
    sf::RectangleShape border;
    SpriteTrax *pioche;
    sf::Text player;
    sf::Text aide1;
    sf::Text aide2;
    sf::Text aide3;
    // Dominos
    std::vector<SpriteTrax*>tuiles;
    TuileTrax *current;   
    sf::RectangleShape select;
    int x,y;
    bool check=false;
public:
    GameTrax(Contexte *obj);
    ~GameTrax();

    void init() override;
    void traitementInput() override;
    void dessine() override;
    void maj() override;
};

#endif // _GAMETRAX