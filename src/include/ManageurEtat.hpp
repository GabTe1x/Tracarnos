#ifndef _STATEMANAGER
#define _STATEMANAGER

#include <stack>
#include "Etat.hpp"

class ManageurEtat
{
private:
    std::stack<Etat*>etats;
    Etat* courant;

    bool mettre,retirer,remplacer;
public:
    ManageurEtat(/* args */);
    ~ManageurEtat();

    void ajoute(Etat& etat,bool remplace=false);
    void retire();
    void change();
    Etat* getCourant();
};

#endif