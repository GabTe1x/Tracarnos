#ifndef _CONTROLEUR
#define _CONTROLEUR

#include "Plateau.hpp"
#include "Dominos.hpp"
#include "Joueur.hpp"
#include <vector>

class Controleur {
    private:
        Plateau <Dominos>plateau;
        std::vector<Joueur> joueurs;
        std::vector<Dominos> pioche; 

        int tour =0; //Indique le joueur auquel c'est le tour de jouer
    
    public:
        bool jouer();
    
        
};
#endif