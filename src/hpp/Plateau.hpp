#ifndef _PLATEAU
#define _PLATEAU

#include <iostream>
#include <map>

template<typename T>
class Plateau{
    protected:
        std::map<std::pair<int, int> , T* > tuiles;
        //Un dictionnaire. Les clées sont des paires représentants les
        //coordonnées de chaque Tuile. Les int peuvent être négatifs

        Plateau();
        bool existeTuile(int x, int y);
        T & getTuile(int x, int y);       
};
#include "Plateau.tpp"

#endif