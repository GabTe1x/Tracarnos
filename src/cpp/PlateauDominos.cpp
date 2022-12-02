#include "../hpp/PlateauDominos.hpp"

PlateauDominos::PlateauDominos(){}

int PlateauDominos::peutPoser(Dominos & tuile, int x, int y)
{
    int pts=0;
    //Si le plateau est vide
    std::pair<int, int> coord (x, y);
    if (tuiles.empty()){
        tuiles[coord]=&tuile;
        return 0;
    }
    
    //Si le plateau n'est pas vide
    //S'il y a deja une tuile sur la case (x, y)
    if (existeTuile(x, y)){
        return -1;
    }

    bool estColle= false;
    //On verifie que la pièce du dessus correspond bien
    if (existeTuile(x, y+1)){
        estColle = true;
        if(!tuile.correspond(tuiles[std::pair<int,int>(x,y+1)]->getValeur(2),0))
            return -1;
        else{ 
            pts+=tuile.getScore(0);
        }
    }
    //On verifie que la pièce de gauche correspond bien
    if (existeTuile(x-1, y)){
        estColle = true;
        if(!tuile.correspond(tuiles[std::pair<int,int>(x-1,y)]->getValeur(1),3))
            return -1;
        else{ 
            pts+=tuile.getScore(3);
        }
    }
    //On verifie que la pièce du bas correspond bien
    if (existeTuile(x, y-1)){
        estColle = true;
        if(!tuile.correspond(tuiles[std::pair<int,int>(x,y-1)]->getValeur(0),2))
            return -1;
        else{ 
            pts+=tuile.getScore(2);
        }
    }
    //On verifie que la pièce de droite correspond bien
    if (existeTuile(x+1, y)){
        estColle = true;
        if(!tuile.correspond(tuiles[std::pair<int,int>(x+1,y)]->getValeur(3),1))
            return -1;
        else{ 
            pts+=tuile.getScore(1);
        }
    }
    if (estColle){
        this->tuiles[coord]=&tuile;
        deffauser();
        return pts;
    }
    return -1;
}

std::ostream & operator <<( std::ostream& out, PlateauDominos& x ) {
    for(std::pair<std::pair<int, int>,Dominos*> it : x.tuiles){
        // Accessing KEY from element pointed by it.
        std::pair<int, int> paire = it.first;
        Dominos* dom= it.second;
        std::cout << "Domino. (x=: " << paire.first << "; y="<< paire.second << ")\n" << *dom << std::endl;
    }
    std::cout << "fin du plateau" << std::endl;
    return out ;
}

