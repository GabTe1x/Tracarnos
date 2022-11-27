#ifndef _PLATEAU_DOM
#define _PLATEAU_DOM

#include "Plateau.hpp"
#include "Dominos.hpp"

class PlateauDominos:public Plateau <Dominos>{
    public:
        //contructeur par défaut
        PlateauDominos();
        //paramètre la tuile à tester et ça position x,y à laquelle on veut la poser
        //résultat -1 peut pas, 0 première tuile sinon nombre de pts
        int peutPoser(Dominos & tuile, int x, int y);
};
#endif