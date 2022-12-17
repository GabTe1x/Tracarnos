#include "../include/GameDominos.hpp"

GameDominos::GameDominos(Contexte *obj,int j,int d) : contexte{obj}
{
    ctlr= new Controleur();
    ctlr->commencer(j,d);
}

GameDominos::~GameDominos()
{
}

void GameDominos::init()
{
    Dominos *d=ctlr->getPlateau()->getTuile(5,5);
    std::string v_haut = " "+std::to_string(d->getValeur(0)[0])+std::to_string(d->getValeur(0)[1])+std::to_string(d->getValeur(0)[2])+" ";
    std::string un_cote = std::to_string(d->getValeur(3)[2])+"   "+std::to_string(d->getValeur(1)[0]);
    std::string deux_cote = std::to_string(d->getValeur(3)[1])+"   "+std::to_string(d->getValeur(1)[1]);
    std::string trois_cote = std::to_string(d->getValeur(3)[2])+"   "+std::to_string(d->getValeur(1)[2]);
    std::string v_bas = " "+std::to_string(d->getValeur(2)[2])+std::to_string(d->getValeur(2)[1])+std::to_string(d->getValeur(2)[0])+" ";
    
    SpriteDominos first{};
    first.init(*(contexte->font),v_haut,un_cote,deux_cote,trois_cote,v_bas);
    first.myPosition(size_tuile*4,size_tuile*2);
    tuiles.push_back(first);
}

void GameDominos::traitementInput()
{
    sf::Event event;
    while (contexte->fenetre->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            contexte->fenetre->close();
            break;
        case sf::Event::KeyPressed:

            switch (event.key.code)
            {
            case sf::Keyboard::Up:
                break;
            case sf::Keyboard::Down:
                break;

            case sf::Keyboard::Right:
                break;

            case sf::Keyboard::Left:
                break;

            case sf::Keyboard::Enter:
                break;
            default:
                break;
            }
            break;

        default:
            break;
        }
    }
}

void GameDominos::dessine()
{
    contexte->fenetre->clear();
    contexte->fenetre->draw(tuiles.at(0));
    contexte->fenetre->display();
}

void GameDominos::maj()
{
}