#include "../include/ManageurEtat.hpp"

ManageurEtat::ManageurEtat():mettre{false},retirer{false},remplacer{false}
{
    
}

ManageurEtat::~ManageurEtat()
{
    while (!etats.empty())
    {
        etats.pop();
    }
}

void ManageurEtat::ajoute(Etat &etat,bool remplace)
{
    mettre=true;
    courant=&etat;
    remplacer=remplace;
}

void ManageurEtat::retire()
{
    retirer=true;
}

void ManageurEtat::change()
{
    if(retirer)
    {
        etats.pop();
        if(!etats.empty())
            etats.top()->init();
        retirer=false;
    }
    if(mettre)
    {
        if(remplacer && !etats.empty())
        {
            etats.pop();
            remplacer=false;
        }
        etats.push(courant);
        etats.top()->init();
        mettre=false;
    }
}

Etat* ManageurEtat::getCourant()
{
    return etats.top();
}