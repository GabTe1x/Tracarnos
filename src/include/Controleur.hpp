#ifndef _CONTROLEURDOMINOS
#define _CONTROLEURDOMINOS

#include "PlateauDominos.hpp"
#include "Joueur.hpp"
#include <random>

    
class Controleur {
    private:
        PlateauDominos *plateau;
        int tour =0; //Indique le joueur auquel c'est le tour de jouer
        int nombreDeJoueurs;
        int x=5;
        int y=5;
    
    public:
        Controleur();
        ~Controleur();
        /* initialise le modèle Dominos
        @param j = nombre de joueurs
        @param pioche = nombre de dominos*/
        void commencer(int j,int pioche);

        // vérifie si la partie est terminé
        bool finDePartie() const;

        // récupère le vainqueur
        Joueur& getVainqueur();
        
        // @param x,y coordonnées ou poser la tuile courante
        // return -1 si tuile pas poser, 0 plus de tuile sinon 1
        bool jouer(int x,int y, Dominos* d);

        // récupère la tuile la plus haute de la pioche
        Dominos& piocher();

        // permet de defausser la premiere tuile de la pioche
        bool defausser();

        PlateauDominos* getPlateau();
        Joueur* getJoueurActuel();
        
};
std::ostream& operator<<(std::ostream&, Controleur&);

#endif  // _CONTROLEURDOMINOS