#include "../include/TuileCarca.hpp"
#include <type_traits>


TuileCarca::TuileCarca(Terrain h,Terrain d,Terrain b,Terrain g):Tuile(h,d,b,g){}

TuileCarca::~TuileCarca()
{
    std::cout<<"Destruction TuileCarca"<<std::endl;
}

bool TuileCarca::correspond(Terrain cote,int myside)
{
    Terrain arr{getValeur(myside)};
    std::cout<< arr << "=?=" << cote << std::endl;
    if(arr.getType()==cote.getType()){
        std::cout<<"Comparaison reussie"<<std::endl;
        return true;
    } else return false;
}

std::ostream & operator <<( std::ostream& out, TuileCarca& x ) {
    std::cout << 
        "haut: " << x.getValeur(1) << "'\n"
        << "gauche: " << x.getValeur(2)<< "\n"
        << "bas: " << x.getValeur(3)<< "'\n"
        << "droite: "<< x.getValeur(4)
    << std::endl;
    return out ;
}