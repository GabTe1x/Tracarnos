#ifndef _PLATEAU
#define _PLATEAU

#include "Tuile.hpp"
#include <iostream>
#include <map>

template <typename T >
class Plateau{
    private:
        std::map<std::pair<int, int> , T > tuiles;
        //Un dictionnaire. Les clées sont des paires représentants les
        //coordonnées de chaque Tuile. Les int peuvent être négatifs

    public:
        bool peutPoser(T & tuile, int x, int y);
        int getTaille();
        bool existeTuile(int x, int y);
        T & getTuile(int x, int y);
        
    
};
#endif