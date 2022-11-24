#include <iostream>
#include "../hpp/Dominos.hpp"

int main(){
    std::array<int,3> one{1,2,3};
    std::array<int,3> two{3,2,1};
    Dominos d{one,one,one,one};
    std::cout<<d.getValeur(1)[0]<<":"<<d.getValeur(1)[1]<<":"<<d.getValeur(1)[2]<<std::endl;
    std::cout<<d.correspond(two,1)<<std::endl;
    std::cout<<"Hello"<<std::endl;
}