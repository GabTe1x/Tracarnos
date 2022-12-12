#include "../hpp/PlateauTrax.hpp"

PlateauTrax::PlateauTrax(){}

int PlateauTrax::peutPoser(TuileTrax & tuile, int x, int y)
{
    //Si le plateau est vide
    std::pair<int, int> coord (x, y);
    if (tuiles.empty()){
        defausser();
        tuiles[coord]=&tuile;
        std::cout << "Tuile placée sur plateau vide" << std::endl;
        return 0;
    }
    
    //Si le plateau n'est pas vide
    //S'il y a deja une tuile sur la case (x, y)
    if (existeTuile(x, y)){
        std::cout << "Il existe déjà une tuile sur cet emplacement" << std::endl;
        return -1;
    }

    bool estColle= false;

    //On verifie que la pièce au dessus correspond bien
    if (existeTuile(x, y+1)){
        estColle = true;
        if(tuile.correspond(tuiles[std::pair<int,int>(x,y+1)]->getValeur(3),1)){
            std::cout << "dessus correspond" << std::endl;
        }else{ 
            std::cout << "dessus say no" << std::endl;
            return -1;
        }
    }
 
    //On verifie que la pièce à droite correspond bien
    if (existeTuile(x+1, y)){
        estColle = true;
        if(tuile.correspond(tuiles[std::pair<int,int>(x+1,y)]->getValeur(4),2)){
            std::cout << "droite correspond" << std::endl;
        }else{ 
            std::cout << "droite say no" << std::endl;
            return -1;
        }
    }

    //On verifie que la pièce en dessous correspond bien
    if (existeTuile(x, y-1)){
        estColle = true;
        if(tuile.correspond(tuiles[std::pair<int,int>(x,y-1)]->getValeur(1),3)){
            std::cout << "dessous correspond" << std::endl;
        }else{ 
            std::cout << "dessous say no" << std::endl;
            return -1;
        }
    }

    //On verifie que la pièce à gauche correspond bien
    if (existeTuile(x-1, y)){
        estColle = true;
        if(tuile.correspond(tuiles[std::pair<int,int>(x-1,y)]->getValeur(2),4)){
            std::cout << "gauche correspond" << std::endl;
        }else{ 
            std::cout << "gauche say no" << std::endl;
            return -1;

        }
    }


    if (estColle){
        this->tuiles[coord]=&tuile;
        defausser();
        return 1;
        std::cout << "tuile placée" << std::endl;
    }
    std::cout << "estColle say no" << std::endl;
    return -1;
}

std::ostream & operator <<( std::ostream& out, PlateauTrax& x ) {
    for(std::pair<std::pair<int, int>,TuileTrax*> it : x.tuiles){
        // Accessing KEY from element pointed by it.
        std::pair<int, int> paire = it.first;
        TuileTrax* dom= it.second;
        std::cout << "Trax. (x=: " << paire.first << "; y="<< paire.second << ")\n" << *dom << std::endl;
    }
    std::cout << "fin du plateau" << std::endl;
    return out ;
}

