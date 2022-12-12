#include "../hpp/ControleurTrax.hpp"

ControleurTrax::ControleurTrax():plateau{}{};

void ControleurTrax::commencer(int nbrJ,int pioche)
{
    plateau=new PlateauTrax{};

    nombreDeJoueurs=nbrJ; 

    // initialisation des joueurs
    for(int i =0;i< nbrJ;i++)
    {
        Joueur *player=new Joueur{i};
        plateau->ajouterJoueur(*player);
    }

    // initialisation de la pioche de TuileTrax
    for(int cmpt =0;cmpt <= pioche;cmpt++)
    {
        TuileTrax *d=new TuileTrax{true,false,true,false};
        plateau->ajouteTuileDsPioche(*d);
    }
}

Joueur& ControleurTrax::getVainqueur()
{
    return *plateau->getVainqueur();
}

bool ControleurTrax::finDePartie() const{
    return plateau->finDePartie();
}

TuileTrax& ControleurTrax::piocher()
{
    return *plateau->piocher();
}
 bool ControleurTrax::defausser(){
    return plateau->defausser();
 }

bool ControleurTrax::jouer(int x,int y, TuileTrax* d){
    int ret=plateau->peutPoser(*d,x,y);
    if(ret==-1)
        return false;
    plateau->getJoueur(tour%plateau->getNbrJoueurs())->addScore(ret);
    plateau->defausser();
    return true;
}

PlateauTrax* ControleurTrax::getPlateau(){
    return plateau;
}

Joueur* ControleurTrax::getJoueurActuel(){
    return plateau->joueurs.at(tour % this->nombreDeJoueurs);
}

std::ostream & operator <<( std::ostream& out, ControleurTrax& x ) {
    std::cout << "Plateau: \n " << *(x.getPlateau()) << std::endl;
    return out ;
}