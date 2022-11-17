#ifndef _TUILE
#define _TUILE

class Tuile {
    private:
        int* v1; //Valeur qui se trouve en haut de la pièce
        int* v2; //Seconde valeurs dans le sens des aiguille d'une montre
                    //donc valeur de Droite
        int* v3; //Bas
        int* v4; //Gauche
        
    public:
        Tuile(int[4][3]);
        void tourne();
        int* getValeur(int i); //Retourne un pointeur vers un int[4]
};
#endif