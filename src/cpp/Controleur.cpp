#include "../hpp/Controleur.hpp"

Controleur::Controleur(int nbrJ,int nbrD):nbrDominos{nbrD},nbrJoueurs{nbrJ},plateau{}{};

void Controleur::commencer()
{
    // init random
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,4);

    // initialisation des joueurs
    for(int i =0;i< nbrJoueurs;i++)
    {
        Joueur j{i};
        joueurs.push_back(j);
    }

    // initialisation de la pioche de dominos
    for(int i =0;i < nbrDominos;i++)
    {
        Dominos d{{(int)dist6(rng),(int)dist6(rng),(int)dist6(rng)},
                  {(int)dist6(rng),(int)dist6(rng),(int)dist6(rng)},
                  {(int)dist6(rng),(int)dist6(rng),(int)dist6(rng)},
                  {(int)dist6(rng),(int)dist6(rng),(int)dist6(rng)}};
        pioche.push_back(d);
    }

    Dominos d{{(int)dist6(rng),(int)dist6(rng),(int)dist6(rng)},
                  {(int)dist6(rng),(int)dist6(rng),(int)dist6(rng)},
                  {(int)dist6(rng),(int)dist6(rng),(int)dist6(rng)},
                  {(int)dist6(rng),(int)dist6(rng),(int)dist6(rng)}};
    pioche.push_back(d);
    plateau.peutPoser(d,5,5);
}

bool Controleur::jouer(Dominos &d,int x,int y){
    int ret=plateau.peutPoser(d,x,y);
    if(ret==-1)
        return false;
    joueurs.at(tour%nbrJoueurs).addScore(ret);
    pioche.pop_back();
    return true;
}

bool Controleur::finDePartie()const
{
    return pioche.empty();
}

Joueur& Controleur::getVainqueur()
{
    int score=0;
    int id=0;
    for(Joueur &j:joueurs)
    {
        if(j.getScore()>score)
        {
            score=j.getScore();
            id=j.getId();
        }
    }
    return joueurs.at(id);
}

Dominos& Controleur::getCurrent()
{
    return pioche.at(pioche.size()-1);
}