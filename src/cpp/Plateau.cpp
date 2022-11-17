#include "../hpp/Plateau.hpp"

bool corespondent (int* vd, int* vt){
    if (vd[0]==vt[2] && vd[1]==vt[1] && vd[2]==vt[0] ){
        return true;
    }
    return false;
}

bool Plateau::existeTuile(int x, int y){
    std::pair<int, int> coord (x, y);
    if ((this->tuiles).count(coord)>=0){
        return true;
    }else return false;
}
Tuile* Plateau::getTuile(int x, int y){
    std::pair<int, int> coord (x, y);
    return this->tuiles[coord];
}

//Retourne x tel que le plateau rentre dans un carrer 2x*2x
int Plateau::getTaille(){
    int x=0;
    for (auto cood : this->tuiles){
        if (cood.first.first > x){
            x = cood.first.first;
        }else if (-cood.first.first < -x){
            x = cood.first.first;
        }
        if (cood.first.second > x){
            x = cood.first.second;
        }else if (-cood.first.second < -x){
            x = cood.first.second;
        }
    }
    return x;
}

bool Plateau::peutPoser(Tuile* t, int x, int y){
    //Si le plateau est vide
    std::pair<int, int> coord (x, y);
    if (this->tuiles.empty()){
        this->tuiles[coord]= t;
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
        estColle = true;
        Tuile* tuileAuDessus = getTuile(x, y+1);
        int* vd = tuileAuDessus->getValeur(3);
        int* vt =t->getValeur(1);
        if (!corespondent (vd, vt)){
            return false;
        }       
    }
    //On verifie que la pièce de gauche correspond bien
    if (existeTuile(x+1, y)){
        estColle = true;
        Tuile* tuileAuDessus = getTuile(x+1, y);
        int* vd = tuileAuDessus->getValeur(4);
        int* vt =t->getValeur(2);
        if (!corespondent (vd, vt)){
            return false;
        }       
    }
    //On verifie que la pièce du bas correspond bien
    if (existeTuile(x+1, y)){
        estColle = true;
        Tuile* tuileAuDessus = getTuile(x+1, y);
        int* vd = tuileAuDessus->getValeur(1);
        int* vt =t->getValeur(3);
        if (!corespondent (vd, vt)){
            return false;
        }       
    }
    //On verifie que la pièce de droite correspond bien
    if (existeTuile(x-1, y)){
        estColle = true;
        Tuile* tuileAuDessus = getTuile(x-1, y);
        int* vd = tuileAuDessus->getValeur(2);
        int* vt =t->getValeur(4);
        if (!corespondent (vd, vt)){
            return false;
        }       
    }
    if (estColle){
        this->tuiles[coord]= t;
        return true;
    }
    else return false;
}