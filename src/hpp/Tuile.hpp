#ifndef _TUILE
#define _TUILE

template<typename T>
class Tuile {
    public:
        T haut;
        T droite;
        T bas;
        T gauche;

    public:
        Tuile(T h,T d,T b,T g);
        void tourne();
        T getValeur(int i);
};
#include "Tuile.tpp"

#endif