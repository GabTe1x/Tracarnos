#include <iostream>
#include <vector>
#include <array>
#include "../include/Controleur.hpp"
#include "../include/App.hpp"
#include "../include/ControleurTrax.hpp"

int main(){
    std::cout << "Dominos (1) ou Trax (2)?" << std::endl;
    int num;
    std::cin >> num;
    if (num==1){
        std::cout << "Graphique (1) ou Terminal (2)?" << std::endl;
        std::cin >> num;
        if(num==1){
            App app{};
            app.run();
        }else{
            int joueurs;
            std::cout << "Nombre de joueurs?" << std::endl;
            std::cin >> joueurs;
            int dominos;
            std::cout << "Nombre de dominos?" << std::endl;
            std::cin >> dominos;
            // int joueurs{2};int dominos{5};
            Controleur ctrl;
            ctrl.commencer(joueurs,dominos);

            while (!ctrl.finDePartie()){
                Dominos d = ctrl.piocher();
                bool endTurn{false};
                while(endTurn==false){
                    std::cout << ctrl << std::endl;
                    std::cout << "Joueur n°" << ctrl.getJoueurActuel()->getId() << std::endl;
                    std::cout << ": Nouvelle tuile:\n" <<d << std::endl;
                    int choix;
                    std::cout << "placer (1), défausser (2) ou tourner(3)?" << std::endl;
                    std::cin >> choix;
                    if (choix == 1){
                        int x;
                        std::cout << "ou placer (x)?" << std::endl;
                        std::cin >> x;
                        int y;
                        std::cout << "ou placer (y)?" << std::endl;
                        std::cin >> y;
                        ctrl.jouer(x, y, &d); 
                        endTurn=true; 
                    } else if (choix == 2){
                        ctrl.defausser();
                        endTurn=true; 
                    }
                    else{
                        d.tourne();
                    }          
                }
            }
            std::cout << "fin de partie" << std::endl;        
        }
    }else{
        std::cout << "Graphique (1) ou Terminal (2)?" << std::endl;
        std::cin >> num;
        if(num==1){
            App app{};
            app.run();
        }else{
            std::cout << "Trax ne se joue qu'a deux joueurs." << std::endl;
            int nbTrax;
            std::cout << "Nombre de Tuiles?" << std::endl;
            std::cin >> nbTrax;
            // int joueurs{2};int dominos{5};
            ControleurTrax ctrl;
            ctrl.commencer(nbTrax);

            while (!ctrl.finDePartie()){
                TuileTrax d = ctrl.piocher();
                bool endTurn{false};
                while(endTurn==false){
                    std::cout << ctrl << std::endl;
                    std::cout << "Joueur n°" << ctrl.getJoueurActuel()->getId() << std::endl;
                    std::cout << ": Nouvelle tuile:\n" <<d << std::endl;
                    int choix;
                    std::cout << "placer (1), défausser (2), tourner(3) ou retourner(4)?" << std::endl;
                    std::cin >> choix;
                    if (choix == 1){
                        int x;
                        std::cout << "ou placer (x)?" << std::endl;
                        std::cin >> x;
                        int y;
                        std::cout << "ou placer (y)?" << std::endl;
                        std::cin >> y;
                        ctrl.jouer(x, y, &d); 
                        endTurn=true; 
                    } else if (choix == 2){
                        ctrl.defausser();
                        endTurn=true; 
                    }
                    else if (choix == 3){
                        d.tourne();
                    }
                    else{
                        d.retourner();
                    }     
                }
            }
            std::cout << "fin de partie" << std::endl;        
        }
    }
}

