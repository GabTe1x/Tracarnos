#ifndef _DOMINOS
#define _DOMINOS

#include "Tuile.hpp"

class Dominos
{
private:
    Tuile<int[3]> &t;
public:
    Dominos(int h[3],int d[3],int b[3],int g[3]);
    bool correspond(int cote[3],int myside);
};


#endif