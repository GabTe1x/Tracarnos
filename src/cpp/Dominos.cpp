#include "../hpp/Dominos.hpp"


Dominos::Dominos(std::array<int, 3> h,std::array<int, 3> d,std::array<int, 3> b,std::array<int, 3>g):Tuile(h,d,b,g){}

Dominos::~Dominos()
{
    //std::cout<<"Destruction dominos"<<std::endl;
}

bool Dominos::correspond(std::array<int,3>cote,int myside)
{
    std::array<int,3>arr{getValeur(myside)};
    if(arr[0]==cote[2] && arr[1]==cote[1] && arr[2]==cote[0])return true;
    return false;
}

std::ostream & operator <<( std::ostream& out, Dominos& x ) {
    std::cout << 
        "'" << x.getValeur(1).at(0) << x.getValeur(1).at(1) << x.getValeur(1).at(2) << "'\n"
        << x.getValeur(4).at(2) << "---" << x.getValeur(2).at(0)<< "\n"
        << x.getValeur(4).at(1) << "---" << x.getValeur(2).at(1)<< "\n"
        << x.getValeur(4).at(0) << "---" << x.getValeur(2).at(2)<< "\n"
        << "'" << x.getValeur(3).at(2) << x.getValeur(3).at(1) << x.getValeur(3).at(1) << "'\n"
    << std::endl;
    return out ;
}