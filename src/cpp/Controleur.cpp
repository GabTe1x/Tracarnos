#include "../hpp/Controleur.hpp"

Controleur::Controleur():plateau{}{};

void Controleur::commencer(int nbrJ,int pioche)
{
    plateau=new PlateauDominos{};
    // init random
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,4);

    nombreDeJoueurs=j; 

    // initialisation des joueurs
    for(int i =0;i< nbrJ;i++)
    {
        Joueur *player=new Joueur{i};
        plateau->ajouterJoueur(*player);
    }

    // initialisation de la pioche de dominos
    for(int cmpt =0;cmpt <= pioche;cmpt++)
    {
        std::array<int,3>c1{(int)dist6(rng),(int)dist6(rng),(int)dist6(rng)};
        std::array<int,3>c2{(int)dist6(rng),(int)dist6(rng),(int)dist6(rng)};
        std::array<int,3>c3{(int)dist6(rng),(int)dist6(rng),(int)dist6(rng)};
        std::array<int,3>c4{(int)dist6(rng),(int)dist6(rng),(int)dist6(rng)};
        Dominos *d=new Dominos{c1,c2,c3,c4};
        plateau->ajouteTuile(*d);
    }
    plateau->peutPoser(*plateau->getPioche(),5,5);
}

Joueur& Controleur::getVainqueur()
{
    return *plateau->getVainqueur();
}

bool Controleur::finDePartie() const{
    return plateau.finDePartie();
}

Dominos& Controleur::getPioche()
{
    return *plateau->getPioche();
}


bool Controleur::jouer(int x,int y){
    int ret=plateau->peutPoser(*plateau->getPioche(),x,y);
    if(ret==-1)
        return false;
    plateau->getJoueur(tour%plateau->getNbrJoueurs())->addScore(ret);
    plateau->deffauser();
    return true;
}

PlateauDominos* Controleur::getPlateau(){
    return &plateau;
}

Joueur* Controleur::getJoueurActuel(){
    return &(plateau.joueurs.at(tour % this->nombreDeJoueurs));
}

std::ostream & operator <<( std::ostream& out, Controleur& x ) {
    std::cout << "Plateau: \n " << *(x.getPlateau()) << std::endl;
    return out ;
}