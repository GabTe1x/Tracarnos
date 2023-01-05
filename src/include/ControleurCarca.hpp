#ifndef _CONTROLEURCARCA
#define _CONTROLEURCARCA

#include "PlateauCarca.hpp"
#include "Joueur.hpp"
#include <random>

    
class ControleurCarca {
    private:
        PlateauCarca *plateau;
        int tour =0; //Indique le joueur auquel c'est le tour de jouer
        int nombreDeJoueurs;
    
    public:
        ControleurCarca();
        /* initialise le modèle Carca
        @param j = nombre de joueurs
        @param pioche = nombre de Carca*/
        void commencer(int pioche, int j);

        // vérifie si la partie est terminé
        bool finDePartie() const;

        // récupère le vainqueur
        Joueur& getVainqueur();
        
        // @param x,y coordonnées ou poser la tuile courante
        // return -1 si tuile pas poser, 0 plus de tuile sinon 1
        bool jouer(int x,int y, TuileCarca* d);

        // récupère la tuile la plus haute de la pioche
        TuileCarca& piocher();

        // permet de defausser la premiere tuile de la pioche
        bool defausser();

        PlateauCarca* getPlateau();
        Joueur* getJoueurActuel();
};
std::ostream& operator<<(std::ostream&, ControleurCarca&);

#endif //_CONTROLEURCarca