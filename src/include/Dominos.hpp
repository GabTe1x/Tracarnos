#ifndef _TUILEDOMINOS
#define _TUILEDOMINOS

#include "Tuile.hpp"
#include <array>
#include <iostream>

class Dominos:public Tuile<std::array<int, 3>>
{
public:
    Dominos(std::array<int, 3> &h,std::array<int, 3> &d,std::array<int, 3> &b,std::array<int, 3>&g);
    ~Dominos();
    bool correspond(std::array<int,3>& cote,int myside);
    int getScore(int i);
};

std::ostream & operator <<( std::ostream& out, Dominos& x );

#endif // _TUILEDOMINOS