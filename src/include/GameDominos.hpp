#ifndef _GAMEDOMINOS
#define _GAMEDOMINOS

#include "Etat.hpp"
#include "Contexte.hpp"
#include "Controleur.hpp"
#include <SFML/Window/Event.hpp>
#include "SpriteDominos.hpp"
#include <vector>

class GameDominos:public Etat
{
private:
    const float size_tuile = 100;
    Contexte *contexte;
    Controleur *ctlr;
    std::vector <SpriteDominos> tuiles;
public:
    GameDominos(Contexte *obj,int j,int d);
    ~GameDominos();

    void init() override;
    void traitementInput() override;
    void dessine() override;
    void maj() override;
};

#endif // _GAMEDOMINOS