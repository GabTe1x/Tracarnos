#include <iostream>
#include <vector>
#include <array>
#include "../hpp/Dominos.hpp"
#include "../hpp/PlateauDominos.hpp"
#include "../hpp/Controleur.hpp"
void afficherPlateauDominos(Controleur* contr){
    PlateauDominos* p = contr->getPlateau();
    //renvois un tableau contenannt 4 valeurs: {maxx, minx, maxy, miny}
    std::array<int, 4>* bornes = p->getTaille();
    int x=bornes->at(0) - bornes->at(1);
    int y=bornes->at(2) - bornes->at(3);
    std::array<std::array<char, x>, y> tab;
}

int main(){
    std::cout << "Graphique (1) ou Terminal (2)?" << std::endl;
    int num;
    std::cin >> num;
    if(num==2){
        int joueurs;
        std::cout << "Nombre de joueurs?" << std::endl;
        std::cin >> joueurs;
        int dominos;
        std::cout << "Nombre de dominos?" << std::endl;
        std::cin >> dominos;
        Controleur* contr= new Controleur( );
        contr->commencer(joueurs, dominos);
        afficherPlateauDominos(contr);
        
        
    }
}

