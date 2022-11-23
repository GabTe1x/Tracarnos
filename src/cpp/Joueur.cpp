#include "../hpp/Joueur.hpp"
Joueur::Joueur(int id): score{0}, id{id}{}

int Joueur::getScore()
{
    return score;
}

void Joueur::setScore(int n)
{
    score=n;
}