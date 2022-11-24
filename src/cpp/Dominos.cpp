#include "../hpp/Dominos.hpp"


Dominos::Dominos(std::array<int, 3> h,std::array<int, 3> d,std::array<int, 3> b,std::array<int, 3>g):Tuile(h,d,b,g)
{
    std::cout<<h[1]<<""<<b[1]<<""<<d[1]<<""<<g[1]<<std::endl;
}

Dominos::~Dominos()
{
    std::cout<<"Destruction dominos"<<std::endl;
}

bool Dominos::correspond(std::array<int,3>cote,int myside)
{
    std::array<int,3>arr{getValeur(myside)};
    if(arr[0]==cote[2] && arr[1]==cote[1] && arr[2]==cote[0])return true;
    return false;
}