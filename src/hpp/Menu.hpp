#pragma once

#include "Etat.hpp"
#include "Contexte.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>

class Menu:public Etat
{
private:
    Contexte *contexte;
    sf::Text nom_app;
    sf::Text option_dom;
    sf::Text option_tra;
    sf::Text option_car;

    int curseur= 0;

public:
    Menu(Contexte *obj);
    ~Menu();

    void init() override;
    void traitementInput() override;
    void dessine() override;
    void maj() override;
};
