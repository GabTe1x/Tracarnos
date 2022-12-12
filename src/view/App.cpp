#include "../include/App.hpp"

App::App():contexte{new Contexte()}
{
    contexte->fenetre->create(sf::VideoMode(1200,660),"Tracarnos",sf::Style::Close | sf::Style::Titlebar);
    contexte->font->loadFromFile("src/ressources/joystix monospace.ttf");
    Menu *menu = new Menu(contexte);
    contexte->manageur->ajoute(*menu);
}

App::~App()
{

}

void App::run()
{
    while (contexte->fenetre->isOpen())
    {
        contexte->manageur->change();
        contexte->manageur->getCourant()->traitementInput();
        contexte->manageur->getCourant()->maj();
        contexte->manageur->getCourant()->dessine();
    }
}