#include "../hpp/Controleur.hpp"

Controleur::Controleur(){};

void Controleur::commencer(int j,int pioche)
{
    // init random
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,4);

    // initialisation des joueurs
    for(int i =0;i< j;i++)
    {
        Joueur player{i};
        plateau.ajouterJoueur(player);
    }

    // initialisation de la pioche de dominos
    for(int i =0;i <= pioche;i++)
    {
        Dominos d{{(int)dist6(rng),(int)dist6(rng),(int)dist6(rng)},
                  {(int)dist6(rng),(int)dist6(rng),(int)dist6(rng)},
                  {(int)dist6(rng),(int)dist6(rng),(int)dist6(rng)},
                  {(int)dist6(rng),(int)dist6(rng),(int)dist6(rng)}};
        plateau.ajouteDominos(d);
    }
    plateau.peutPoser(plateau.getPioche(),0,0);
}

Joueur& Controleur::getVainqueur()
{
    return plateau.getVainqueur();
}

Dominos& Controleur::getPioche()
{
    return plateau.getPioche();
}


bool Controleur::jouer(int x,int y){
    int ret=plateau.peutPoser(plateau.getPioche(),x,y);
    if(ret==-1)
        return false;
    //joueurs.at(tour%nbrJoueurs).addScore(ret);
    plateau.deffauser();
    return true;
}

PlateauDominos* Controleur::getPlateau(){
    return &plateau;
}

std::ostream & operator <<( std::ostream& out, Controleur& x ) {
    std::cout << "Plateau: \n " << *(x.getPlateau()) << std::endl;
    return out ;
}