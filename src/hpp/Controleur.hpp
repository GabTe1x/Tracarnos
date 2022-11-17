#ifndef _CONTROLEUR
#define _CONTROLEUR

#include "Plateau.hpp"
#include "Joueur.hpp"
#include <vector>

class Controleur {
    private:
        Plateau plateau;
        std::vector<Joueur> joueurs;
        std::vector<Tuile> pioche; 

        int tour =0; //Indique le joueur auquel c'est le tour de jouer
    
    public:
        bool jouer();
    
        
};
#endif