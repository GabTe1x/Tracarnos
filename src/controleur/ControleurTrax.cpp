#include "../include/ControleurTrax.hpp"

ControleurTrax::ControleurTrax():plateau{}{};

void ControleurTrax::commencer(int j, int pioche){
    commencer(pioche);
    //Le jeux ne se joue qu'a deux
}

void ControleurTrax::commencer(int pioche)
{
    plateau=new PlateauTrax{};

    nombreDeJoueurs=2; 

    // initialisation des joueurs
    for(int i =0;i< 2;i++)
    {
        Joueur *player=new Joueur{i};
        plateau->ajouterJoueur(*player);
    }

    // initialisation de la pioche de TuileTrax
    for(int cmpt =0;cmpt <= pioche;cmpt++)
    {
        TuileTrax *d = new TuileTrax{true,false,true,false};
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

bool ControleurTrax::jouerCoupObligatoire(){
    if (plateau->jouerCoupObligatoire()){
        return true;
    }else return false;

}

bool ControleurTrax::jouer(int x,int y, TuileTrax* d){
    if (jouerCoupObligatoire()){
        std::cout << "Un coup obligatoire a été jouer automatiquement" << std::endl;
        plateau->defausser();
        tour++;
        return true;
    }else{
        std::cout << "Pas de cout obligatoire" << std::endl;
        int ret=plateau->peutPoser(*d,x,y);
        if(ret==-1) return false;
        plateau->defausser();
        tour++;
        return true;
    }
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