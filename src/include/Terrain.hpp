#ifndef _TERRAIN
#define _TERRAIN


#include "Joueur.hpp"
#include <iostream>
#include <string>

class Terrain {
private:
    std::string type;
    bool isMeeple=false;
    Joueur* meeple;

public:
    Terrain();
    Terrain(std::string type);

//Le joueur j pose un meeple
    void poserMeeple(Joueur* j);
    bool getIsMeeple();
    std::string getType();
    Joueur* getJoueurMeeple();

};

std::ostream & operator <<( std::ostream& out, Terrain& x );

#endif //_TUILECarca