#pragma once

#include "PlateauTrax.hpp"
#include "Joueur.hpp"
#include <random>

    
class ControleurTrax {
    private:
        PlateauTrax *plateau;
        int tour =0; //Indique le joueur auquel c'est le tour de jouer
        int nombreDeJoueurs;
    
    public:
        ControleurTrax();
        /* initialise le modèle Trax
        @param j = nombre de joueurs
        @param pioche = nombre de Trax*/
        void commencer(int j,int pioche);

        // vérifie si la partie est terminé
        bool finDePartie() const;

        // récupère le vainqueur
        Joueur& getVainqueur();
        
        // @param x,y coordonnées ou poser la tuile courante
        // return -1 si tuile pas poser, 0 plus de tuile sinon 1
        bool jouer(int x,int y, TuileTrax* d);

        // récupère la tuile la plus haute de la pioche
        TuileTrax& piocher();

        // permet de defausser la premiere tuile de la pioche
        bool defausser();

        PlateauTrax* getPlateau();
        Joueur* getJoueurActuel();
};
std::ostream& operator<<(std::ostream&, ControleurTrax&);