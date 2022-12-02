#include "../hpp/Dominos.hpp"


Dominos::Dominos(std::array<int, 3> &h,std::array<int, 3> &d,std::array<int, 3> &b,std::array<int, 3>&g):Tuile(h,d,b,g){}

Dominos::~Dominos()
{
    std::cout<<"Destruction dominos"<<std::endl;
}

bool Dominos::correspond(std::array<int,3>& cote,int myside)
{
    std::array<int,3>arr{getValeur(myside)};
    if(arr[0]==cote[2] && arr[1]==cote[1] && arr[2]==cote[0])return true;
    return false;
}

int Dominos::getScore(int i){
    if (i==1){
        return haut[0]+haut[1]+haut[2];
    }
    else if (i==2){
        return droite[0]+droite[1]+droite[2];
    }
    else if (i==3){
        return bas[0]+bas[1]+bas[2];
    }
    else {
        return gauche[0]+gauche[1]+gauche[2];
    }
}