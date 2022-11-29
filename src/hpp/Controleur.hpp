#ifndef _CONTROLEUR
#define _CONTROLEUR

#include "PlateauDominos.hpp"
#include "Joueur.hpp"
#include <random>


/*  
    TODO faire une class template qui prend un plateau T mettre 
    pioche dans tableauDominos car unique a dominos et rédefinir 
    les fonctions starts et jouer pour chaque type pour n'avoir 
    qu'une classe controleur et 3 plateaux au lieu de 3 controleurs
    et 3 plateaux 
*/
    
class Controleur {
    private:
        PlateauDominos plateau;
        int tour =0; //Indique le joueur auquel c'est le tour de jouer
    
    public:
        Controleur();
        /* initialise le modèle Dominos
        @param j = nombre de joueurs
        @param pioche = nombre de dominos*/
        void commencer(int j,int pioche);

        // vérifie si la partie est terminé
        bool finDePartie()const;

        // récupère le vainqueur
        Joueur& getVainqueur();
        
        // @param x,y coordonnées ou poser la tuile courante
        // return -1 si tuile pas poser, 0 plus de tuile sinon 1
        bool jouer(int x,int y);

        // récupère la tuile la plus haute de la pioche
        Dominos& getPioche();

        PlateauDominos* getPlateau();
};

#endif