#ifndef _PLATEAU
#define _PLATEAU

#include <iostream>
#include <map>
#include <vector>
#include "Joueur.hpp"

template<typename T>
class Plateau{
    protected:
        //joueurs participant au jeu
        std::vector<Joueur*> joueurs;

        //Un dictionnaire. Les clées sont des paires représentants les
        //coordonnées de chaque Tuile. Les int peuvent être négatifs
        std::map<std::pair<int, int> , T* > tuiles;

        //Pioche de  Tuile T a poser sur notre plateau
        std::vector<T*> pioche;
    public:

        // contructeur par défaut initialisation par controleur
        Plateau();

        // vérifie si la tuile existe à la position x,y
        bool existeTuile(int x, int y)const;

        // retourne la tuile posé sur le plateau a la case X,Y
        T * getTuile(int x, int y)const;

        // retourne la dernière carte de la pioche
        T * getPioche();

        // retourne nbr joueurs
        int getNbrJoueurs()const;

        // retourne joueur i
        Joueur * getJoueur(int i);

        // vérifie s'il reste une tuile à jouer
        bool finDePartie()const;

        //utiliser pour retirer dernière carte joué de la pioche
        void deffauser();

        //retourne le joueur avec le plus de points
        Joueur* getVainqueur();
        
        // ajouter joueur à la liste de joueur (initialisation)
        void ajouterJoueur(Joueur & j);
        // ajouter dominos à la pioche (initialisation)
        void ajouteTuile(T &t);
};
#include "Plateau.tpp"

#endif