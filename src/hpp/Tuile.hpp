#ifndef _TUILE
#define _TUILE

template< class T> class Tuile {
    private:
        T haut;
        T droite;
        T bas;
        T gauche;

    public:
        Tuile(T h, T d, T b, T g);
        void tourne();
        T getValeur(int i);
};
#endif