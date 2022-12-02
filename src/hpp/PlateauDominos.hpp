#ifndef _PLATEAU_DOM
#define _PLATEAU_DOM

#include "Plateau.hpp"
#include "Dominos.hpp"

class PlateauDominos:public Plateau <Dominos>{
    public:
        //contructeur par défaut
        PlateauDominos();

        // return -1 si tuile pas poser, 0 si fin de parti sinon 1
        bool jouer(Dominos &d,int x,int y);

        //paramètre la tuile à tester et ça position x,y à laquelle on veut la poser
        //résultat -1 peut pas, 0 première tuile sinon nombre de pts
        int peutPoser(Dominos & tuile, int x, int y);
};
std::ostream & operator <<( std::ostream& out, PlateauDominos& x );
#endif