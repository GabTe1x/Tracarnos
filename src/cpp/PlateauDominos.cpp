#include "../hpp/PlateauDominos.hpp"

PlateauDominos::PlateauDominos(){}

bool PlateauDominos::peutPoser(Dominos & tuile, int x, int y)
{
    //Si le plateau est vide
    std::pair<int, int> coord (x, y);
    if (tuiles.empty()){
        tuiles[coord]=&tuile;
    }
    
    //Si le plateau n'est pas vide
    //S'il y a deja une tuile sur la case (x, y)
    if (existeTuile(x, y)){
        return false;
    }
    bool estColle= false; //Verifier que la pièce est bien adjacente a une autre pièce
    
    //TODO: Il y a surement un moyen de factoriser ça, mais j'ai pas trouvé a 
    //cause du Boolean estColle (et de ma flemme)

    //On verifie que la pièce du dessus correspond bien
    if (existeTuile(x, y+1)){
     
    }
    //On verifie que la pièce de gauche correspond bien
    if (existeTuile(x+1, y)){
     
    }
    //On verifie que la pièce du bas correspond bien
    if (existeTuile(x+1, y)){
      
    }
    //On verifie que la pièce de droite correspond bien
    if (existeTuile(x-1, y)){
    
    }
    return estColle;
}