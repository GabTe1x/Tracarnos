#ifndef _PLATEAU_TR
#define _PLATEAU_TR

#include "Plateau.hpp"
#include "TuileTrax.hpp"

class PlateauTrax:public Plateau <TuileTrax>{
    public:
        //contructeur par défaut
        PlateauTrax();

        bool verifCoupObligatoire(std::pair<int, int> coord);
        bool jouerCoupObligatoire();
        // return -1 si tuile pas poser, 0 si fin de parti sinon 1
        bool jouer(TuileTrax &d,int x,int y);

        //paramètre la tuile à tester et ça position x,y à laquelle on veut la poser
        //résultat -1 peut pas, 0 première tuile
        int peutPoser(TuileTrax & tuile, int x, int y);
};
std::ostream & operator <<( std::ostream& out, PlateauTrax& x );
#endif