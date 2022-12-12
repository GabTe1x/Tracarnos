#ifndef _GAMEDOMINOS
#define _GAMEDOMINOS

#include "Etat.hpp"
#include "Contexte.hpp"
#include "Controleur.hpp"
#include <SFML/Window/Event.hpp>

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

#endif // _GAMEDOMINOS