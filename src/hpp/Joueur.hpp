#ifndef _JOUEUR
#define _JOUEUR

class Joueur {
    private:
        int score;
        int id;
    
    public:
        Joueur(int id);
        int getScore();
        void setScore(int n);      
};
#endif