#include "../include/ParamDominos.hpp"

ParamDominos::ParamDominos(Contexte *obj) : contexte{obj} {};

ParamDominos::~ParamDominos()
{
}

void ParamDominos::init()
{
    dominos.setFont(*(contexte->font));
    slcJoueurs.setFont(*(contexte->font));
    slcDominos.setFont(*(contexte->font));

    dominos.setFillColor(sf::Color::Red);
    slcDominos.setFillColor(sf::Color(255, 215, 0));
    
    dominos.setString("Dominos");
    slcDominos.setString("Nombre de dominos  < 20 >");
    slcJoueurs.setString("Nombre de joueurs  < 2 >");


    float width = contexte->fenetre->getSize().x;
    float height = contexte->fenetre->getSize().y;


    dominos.setPosition(width * 2 / 5, height * 0.5 / 5);
    slcDominos.setPosition(width/5,height*1/3);
    slcJoueurs.setPosition(width/5,height*2/3);
}

void ParamDominos::traitementInput()
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
                curseur-=1;
                if(curseur<0)
                    curseur=1;
                break;
            case sf::Keyboard::Down:
                curseur=(curseur+1)%2;
                break;

            case sf::Keyboard::Right:
                if(curseur == 0)
                {
                    n_dominos++;
                    if(n_dominos>100)n_dominos=1;
                }
                else
                {
                    n_joueurs++;
                    if(n_joueurs>10)n_joueurs=2;
                }
                break;

            case sf::Keyboard::Left:
                if(curseur == 0)
                {
                    n_dominos--;
                    if(n_dominos<1)n_dominos=100;
                }
                else
                {
                    n_joueurs--;
                    if(n_joueurs<2)n_joueurs=10;
                }
                break;

            case sf::Keyboard::Enter:
                entree=true;
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

void ParamDominos::dessine()
{
    contexte->fenetre->clear();
    contexte->fenetre->draw(dominos);
    contexte->fenetre->draw(slcDominos);
    contexte->fenetre->draw(slcJoueurs);
    contexte->fenetre->display();
}

void ParamDominos::maj()
{
    if(entree)
    {
        GameDominos *d=new GameDominos(contexte,n_joueurs,n_dominos);
        contexte->manageur->ajoute(*d);
        entree=false;
    }
    if(curseur==0){
        std::string s = "Nombre de dominos  < "+std::to_string(n_dominos)+" >";
        slcDominos.setString(s);
        slcDominos.setFillColor(sf::Color(255, 215, 0));
        slcJoueurs.setFillColor(sf::Color::White);
    }
    else
    {
        std::string s = "Nombre de joueurs  < "+std::to_string(n_joueurs)+" >";
        slcJoueurs.setString(s);
        slcJoueurs.setFillColor(sf::Color(255, 215, 0));
        slcDominos.setFillColor(sf::Color::White);
    }
}