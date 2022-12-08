#include "../hpp/ManageurEtat.hpp"

ManageurEtat::ManageurEtat():mettre{false},retirer{false},remplacer{false}
{
    
}

ManageurEtat::~ManageurEtat()
{

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
        if(!etats.empty())
            etats.top()->pause();
        etats.push(courant);
        etats.top()->init();
        etats.top()->reprendre();
        mettre=false;
    }
}

Etat* ManageurEtat::getCourant()
{
    return etats.top();
}