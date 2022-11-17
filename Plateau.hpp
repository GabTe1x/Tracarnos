#ifndef _PLATEAU
#define _PLATEAU

#include "Tuile.hpp"
#include <iostream>
#include <map>

class Plateau {
    private:
        std::map<std::pair<int, int> , Tuile*> tuiles;
        //Un dictionnaire. Les clées sont des paires représentants les
        //coordonnées de chaque Tuile. Les int peuvent être négatifs

    public:
        bool peutPoser(Tuile* t, int x, int y);
        int getTaille();
        bool existeTuile(int x, int y);
        Tuile* getTuile(int x, int y);
        
    
};
#endif