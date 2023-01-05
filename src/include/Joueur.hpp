#ifndef _JOUEUR
#define _JOUEUR

#include <iostream>

class Joueur {
    private:
        int score;
        int id;
    
    public:
        Joueur(int id);
        ~Joueur();
        int getScore()const;
        void addScore(int n);  
        int getId()const;    
};
#endif