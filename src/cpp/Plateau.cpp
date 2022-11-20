#include "../hpp/Plateau.hpp"


template <typename T>
bool Plateau<T>::existeTuile(int x, int y){
    std::pair<int, int> coord (x, y);
    if ((this->tuiles).count(coord)>=0){
        return true;
    }else return false;
}

template <typename T>
T & Plateau<T>::getTuile(int x, int y){
    std::pair<int, int> coord (x, y);
    return this->tuiles[coord];
}

//Retourne x tel que le plateau rentre dans un carrer 2x*2x
template <typename T>
int Plateau<T>::getTaille(){
    int x=0;
    for (T cood : this->tuiles){
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

template <typename T>
bool Plateau<T>::peutPoser(T & t, int x, int y){
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

    if (estColle){
        this->tuiles[coord]= t;
        return true;
    }
    else return false;
}