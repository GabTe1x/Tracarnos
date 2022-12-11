#ifndef _PLATEAU
#define _PLATEAU

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include "Joueur.hpp"

template<typename T>
class Plateau{
    public:
        //joueurs participant au jeu
        std::vector<Joueur*> joueurs;

        //Un dictionnaire. Les clées sont des paires représentants les
        //coordonnées de chaque Tuile. Les int peuvent être négatifs
        std::map<std::pair<int, int> , T* > tuiles;

        //Pioche de  Tuile T a poser sur notre plateau
        std::stack<T*> pioche;
    public:

        // contructeur par défaut initialisation par controleur
        Plateau();
        
        // destructeur
        virtual ~Plateau();

        // vérifie si la tuile existe à la position x,y
        bool existeTuile(int x, int y)const;

        // retourne la tuile posé sur le plateau a la case X,Y
        T * getTuile(int x, int y)const;

        // retourne la dernière carte de la pioche
        T * piocher();

        // retourne nbr joueurs
        int getNbrJoueurs()const;

        // retourne joueur i
        Joueur * getJoueur(int i);

        //renvois un tableau contenannt 4 valeurs: {maxx, minx, maxy, miny}
        std::array<int, 4>* getTaille();

        // vérifie s'il reste une tuile à jouer
        bool finDePartie()const;

        //Supprime la tuile en haut de la pioche (après l'avoir poser ou defaussé)
        bool defausser();

        //retourne le joueur avec le plus de points
        Joueur* getVainqueur();
        
        // ajouter joueur à la liste de joueur (initialisation)
        void ajouterJoueur(Joueur & j);
        // ajouter dominos à la pioche (initialisation)
        void ajouteTuileDsPioche(T &t);
};
#include "Plateau.tpp"

#endif