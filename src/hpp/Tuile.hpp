#ifndef _TUILE
#define _TUILE

template<typename T>
class Tuile {
    protected:
        T haut;
        T droite;
        T bas;
        T gauche;
    public:
        Tuile(T & h,T & d,T & b,T & g);
        void tourne();
        T getValeur(int i)const;
};
#include "Tuile.tpp"

#endif