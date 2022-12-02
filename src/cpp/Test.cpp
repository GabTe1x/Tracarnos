#include <iostream>
#include <vector>
#include <array>
#include "../hpp/Dominos.hpp"
#include "../hpp/PlateauDominos.hpp"
#include "../hpp/Controleur.hpp"

int main(){
    /*std::cout << "Graphique (1) ou Terminal (2)?" << std::endl;
    int num;
    std::cin >> num;
    if(num==2){
        int joueurs;
        std::cout << "Nombre de joueurs?" << std::endl;
        std::cin >> joueurs;
        int dominos;
        std::cout << "Nombre de dominos?" << std::endl;
        std::cin >> dominos;
        */ int joueurs{2};int dominos{5};
        Controleur ctrl;
        ctrl.commencer(joueurs,dominos);

        std::cout << ctrl << std::endl;
        while (!ctrl.finDePartie()){
            Dominos d = ctrl.getPioche();
            std::cout << "Joueur n°" << ctrl.getJoueurActuel()->getId() << ": Nouvelle tuile:\n" <<d << std::endl;
            int x;
            std::cout << "ou placer (x)?" << std::endl;
            std::cin >> x;
            int y;
            std::cout << "ou placer (y)?" << std::endl;
            std::cin >> y;
            ctrl.jouer(x, y);            
        }
        std::cout << "fin de partie" << std::endl;

        
        
        
    //}
}

