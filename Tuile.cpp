#include "Tuile.hpp"

Tuile::Tuile(int tab[4][3] ): v1{tab[0]}, v2{tab[1]}, v3{tab[2]}, v4{tab[3]}{}

void Tuile::tourne(){
    int* tmp;
    tmp = this->v1;
    this->v1 = this->v2;
    this->v2 = this->v3;
    this->v4 = tmp;    
}

int* Tuile::getValeur(int i){
    if (i==1){
        return this->v1;  //Haut
    }
    else if (i==2){
        return this->v2;  //Gauche
    }
    else if (i==3){
        return this->v3;  //Bas
    }
    else {
        return this->v4;  //Droite
    }
}


