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
        */int joueurs{2};int dominos{10};
        Controleur* contr= new Controleur( );
        contr->commencer(joueurs, dominos);
        std::cout << *contr << std::endl;
        
        
    //}
}

