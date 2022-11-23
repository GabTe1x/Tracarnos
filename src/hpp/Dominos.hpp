#ifndef _DOMINOS
#define _DOMINOS

#include "Tuile.hpp"
#include <array>

class Dominos:public Tuile<std::array<int, 3>>
{
public:
    Dominos(std::array<int, 3> h,std::array<int, 3> d,std::array<int, 3> b,std::array<int, 3>g);
    bool correspond(std::array<int,3> cote,int myside);
};


#endif