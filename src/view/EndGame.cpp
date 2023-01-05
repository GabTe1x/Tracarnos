#include "../include/EndGame.hpp"

EndGame::EndGame(Contexte *obj,std::string s) : contexte{obj},joueur{s} {};

EndGame::~EndGame()
{
}

void EndGame::init()
{
    vainqueur.setFont(*(contexte->font));
    retour.setFont(*(contexte->font));
    msg.setFont(*(contexte->font));

    vainqueur.setFillColor(sf::Color::White);
    retour.setFillColor(sf::Color(255, 215, 0));
    msg.setFillColor(sf::Color::White);
    
    vainqueur.setString(joueur);
    retour.setString("RETOUR MENU");
    msg.setString("vainqueur :");

    retour.setCharacterSize(40);
    vainqueur.setCharacterSize(40);
    msg.setCharacterSize(40);

    retour.setPosition(400,400);
    msg.setPosition(400,100);
    vainqueur.setPosition(300,200);

}

void EndGame::traitementInput()
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

void EndGame::dessine()
{
    contexte->fenetre->clear();
    contexte->fenetre->draw(retour);
    contexte->fenetre->draw(vainqueur);
    contexte->fenetre->draw(msg);
    contexte->fenetre->display();
}

void EndGame::maj()
{
    if(entree)
    {
        Menu *m=new Menu(contexte);
        contexte->manageur->ajoute(*m,true);
    }
}