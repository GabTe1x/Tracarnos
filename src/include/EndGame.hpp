#ifndef _ENDGAME
#define _ENDGAME

#include "Etat.hpp"
#include "Contexte.hpp"
#include <SFML/Graphics/Text.hpp>
#include "Menu.hpp"

class EndGame:public Etat
{
private:
    Contexte *contexte;

    std::string joueur;

    sf::Text vainqueur;
    sf::Text retour;
    sf::Text msg;

    bool entree=false;

public:
    EndGame(Contexte *obj,std::string s);
    ~EndGame();

    void init() override;
    void traitementInput() override;
    void dessine() override;
    void maj() override;
};

#endif