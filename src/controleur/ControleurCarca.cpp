#include "../include/ControleurCarca.hpp"
#include <vector>

ControleurCarca::ControleurCarca():plateau{}{};

std::vector<std::string> typesTerrain {"prés", "église", "ville", "route"};



void ControleurCarca::commencer(int pioche, int nbJoueur)
{
    plateau=new PlateauCarca{};
    
    // init random
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,typesTerrain.size()-1);

    nombreDeJoueurs=nbJoueur; 

    // initialisation des joueurs
    for(int i =0;i< nbJoueur;i++)
    {
        Joueur *player=new Joueur{i};
        plateau->ajouterJoueur(*player);
    }

    // initialisation de la pioche de TuileCarca
    for(int cmpt =0;cmpt <= pioche;cmpt++)
    {
        TuileCarca *d=new TuileCarca{
            Terrain{typesTerrain.at((int)dist6(rng))},
            Terrain{typesTerrain.at((int)dist6(rng))},
            Terrain{typesTerrain.at((int)dist6(rng))},
            Terrain{typesTerrain.at((int)dist6(rng))}
        };
        plateau->ajouteTuileDsPioche(*d);
    }
}

Joueur& ControleurCarca::getVainqueur()
{
    return *plateau->getVainqueur();
}

bool ControleurCarca::finDePartie() const{
    return plateau->finDePartie();
}

TuileCarca& ControleurCarca::piocher()
{
    return *plateau->piocher();
}
 bool ControleurCarca::defausser(){
    return plateau->defausser();
}

bool ControleurCarca::jouer(int x,int y, TuileCarca* d){
    int ret=plateau->peutPoser(*d,x,y);
    if(ret==-1) return false;
    plateau->defausser();
    return true;
}

PlateauCarca* ControleurCarca::getPlateau(){
    return plateau;
}

Joueur* ControleurCarca::getJoueurActuel(){
    return plateau->joueurs.at(tour % this->nombreDeJoueurs);
}

std::ostream & operator <<( std::ostream& out, ControleurCarca& x ) {
    std::cout << "Plateau: \n " << *(x.getPlateau()) << std::endl;
    return out ;
}