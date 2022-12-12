#ifndef _PARAMDOMINOS
#define _PARAMDOMINOS

#include "Etat.hpp"
#include "Contexte.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>

class ParamDominos:public Etat
{
private:
    Contexte *contexte;
    int n_joueurs=2;
    int n_dominos=20;
    sf::Text slcDominos;
    sf::Text slcJoueurs;
    sf::Text dominos;
    bool entree=false;
    bool escape=false;
    int curseur=0;
public:
    ParamDominos(Contexte *obj);
    ~ParamDominos();

    void init() override;
    void traitementInput() override;
    void dessine() override;
    void maj() override;
};

#endif