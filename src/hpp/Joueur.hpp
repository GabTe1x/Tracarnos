#ifndef _JOUEUR
#define _JOUEUR

class Joueur {
    private:
        int score;
        int id;
    
    public:
        Joueur(int id);
        int getScore()const;
        void addScore(int n);  
        int getId()const;    
};
#endif