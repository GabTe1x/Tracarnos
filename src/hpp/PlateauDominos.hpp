#ifndef _PLATEAU_DOM
#define _PLATEAU_DOM

#include "Plateau.hpp"
#include "Dominos.hpp"

class PlateauDominos:public Plateau <Dominos>{
    public:
        PlateauDominos();
        bool peutPoser(Dominos & tuile, int x, int y);
};
#endif