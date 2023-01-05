#ifndef _PLATEAU_CA
#define _PLATEAU_CA

#include "Plateau.hpp"
#include "TuileCarca.hpp"

class PlateauCarca:public Plateau <TuileCarca>{
    public:
        //contructeur par défaut
        PlateauCarca();

        // return -1 si tuile pas poser, 0 si fin de parti sinon 1
        bool jouer(TuileCarca &d,int x,int y);

        //paramètre la tuile à tester et ça position x,y à laquelle on veut la poser
        //résultat -1 peut pas, 0 première tuile
        int peutPoser(TuileCarca & tuile, int x, int y);
};
std::ostream & operator <<( std::ostream& out, PlateauCarca& x );
#endif