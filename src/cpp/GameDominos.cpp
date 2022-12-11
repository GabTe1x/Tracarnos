#include "../hpp/GameDominos.hpp"

GameDominos::GameDominos(Contexte *obj,Controleur *ctrl,int j,int d) : contexte{obj}, ctlr{ctrl}
{
    ctlr->commencer(j,d);
}

GameDominos::~GameDominos()
{
}

void GameDominos::init()
{

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
    contexte->fenetre->display();
}

void GameDominos::maj()
{
}