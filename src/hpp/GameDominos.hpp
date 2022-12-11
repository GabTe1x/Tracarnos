#pragma once

#include "Etat.hpp"
#include "Contexte.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include "Controleur.hpp"

class GameDominos:public Etat
{
private:
    Contexte *contexte;
    Controleur *ctlr;
public:
    GameDominos(Contexte *obj,Controleur *ctrl,int j,int d);
    ~GameDominos();

    void init() override;
    void traitementInput() override;
    void dessine() override;
    void maj() override;
};
