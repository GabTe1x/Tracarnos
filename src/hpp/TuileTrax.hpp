#pragma once

#include "Tuile.hpp"
#include <array>
#include <iostream>

class TuileTrax:public Tuile<bool>
{
public:
    TuileTrax(bool h,bool d,bool b,bool g);
    ~TuileTrax();
    bool correspond(bool cote,int myside);
    void retourner();
};

std::ostream & operator <<( std::ostream& out, TuileTrax& x );
