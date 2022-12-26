#ifndef _GAMEDOMINOS
#define _GAMEDOMINOS

#include "Etat.hpp"
#include "Contexte.hpp"
#include "Controleur.hpp"
#include <SFML/Window/Event.hpp>
#include "SpriteDominos.hpp"
#include <vector>
#include "EndGame.hpp"

class GameDominos:public Etat
{
private:
    // contexte
    Contexte *contexte;
    // controleur
    Controleur ctlr;

    // Texte + bordure menu 
    sf::Text titre;
    sf::RectangleShape border;
    SpriteDominos *pioche;
    sf::Text player;
    sf::Text aide1;
    sf::Text aide2;
    sf::Text aide3;
    // Dominos
    std::vector<SpriteDominos*>tuiles;
    Dominos *current;   
    sf::RectangleShape select;
    int x,y;
public:
    GameDominos(Contexte *obj,int j,int d);
    ~GameDominos();

    void init() override;
    void traitementInput() override;
    void dessine() override;
    void maj() override;
};

#endif // _GAMEDOMINOS