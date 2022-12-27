#ifndef _CONTEXTE
#define _CONTEXTE

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "ManageurEtat.hpp"

struct Contexte
{
    sf::RenderWindow *fenetre;
    sf::Font *font;
    ManageurEtat *manageur;

    Contexte()
    {
        fenetre=new sf::RenderWindow();
        font=new  sf::Font();
        manageur = new ManageurEtat();
    }
};


#endif // _CONTEXTE