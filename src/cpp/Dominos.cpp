#include "../hpp/Dominos.hpp"


Dominos::Dominos(std::array<int, 3> &h,std::array<int, 3> &d,std::array<int, 3> &b,std::array<int, 3>&g):Tuile(h,d,b,g){}

Dominos::~Dominos()
{
    std::cout<<"Destruction dominos"<<std::endl;
}

bool Dominos::correspond(std::array<int,3>& cote,int myside)
{
    std::array<int,3>arr{getValeur(myside)};
    std::cout<< arr[0] << "=?=" << cote[2] 
    << " et "<< arr[1] << "=?=" << cote[1] 
    << " et "<< arr[2] << "=?=" << cote[0]
    <<std::endl;
    if(arr[0]==cote[2] && arr[1]==cote[1] && arr[2]==cote[0]){
        std::cout<<"Comparaison reussie"<<std::endl;
        return true;
    } else return false;
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

std::ostream & operator <<( std::ostream& out, Dominos& x ) {
    std::cout << 
        "'" << x.getValeur(1).at(0) << x.getValeur(1).at(1) << x.getValeur(1).at(2) << "'\n"
        << x.getValeur(4).at(2) << "---" << x.getValeur(2).at(0)<< "\n"
        << x.getValeur(4).at(1) << "---" << x.getValeur(2).at(1)<< "\n"
        << x.getValeur(4).at(0) << "---" << x.getValeur(2).at(2)<< "\n"
        << "'" << x.getValeur(3).at(2) << x.getValeur(3).at(1) << x.getValeur(3).at(0) << "'\n"
    << std::endl;
    return out ;
}