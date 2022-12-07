#include "../hpp/Joueur.hpp"
Joueur::Joueur(int id): score{0}, id{id}{}

int Joueur::getScore()const
{
    return score;
}

void Joueur::addScore(int n)
{
    score+=n;
}

int Joueur::getId()const
{
    return id;
}