#ifndef _TUILECARCA
#define _TUILECARCA

#include "Tuile.hpp"
#include "Terrain.hpp"
#include <array>
#include <iostream>

class TuileCarca:public Tuile<Terrain>
{
public:
    TuileCarca(Terrain h,Terrain d,Terrain b,Terrain g);
    ~TuileCarca();
    bool correspond(Terrain cote,int myside);
};

std::ostream & operator <<( std::ostream& out, TuileCarca& x );

#endif //_TUILECarca