#include "../include/Joueur.hpp"
Joueur::Joueur(int id): score{0}, id{id}{}

Joueur::~Joueur()
{
    std::cout<<"Destruction Joueur"<<std::endl;
}

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