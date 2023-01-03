#include "../include/Terrain.hpp"

Terrain::Terrain(std::string type): type {type} {}

void Terrain::poserMeeple(Joueur *j){
    this->isMeeple=true;
    this->meeple=j;

}

Terrain::Terrain(){}

bool Terrain::getIsMeeple(){
    return isMeeple;
}

std::string Terrain::getType(){
    return type;
}

Joueur * Terrain::getJoueurMeeple(){
    if (isMeeple){
        return meeple;
    }else return nullptr;

}

std::ostream &operator<<(std::ostream &out, Terrain &x){
    if (x.getIsMeeple()){
        std::cout << x.getType() << "avec meeple du joueur " << x.getJoueurMeeple() << std::endl;
   
    }else{
        std::cout << x.getType() << std::endl;
    }
    return out;
}
