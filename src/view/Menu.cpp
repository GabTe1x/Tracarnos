#include "../include/Menu.hpp"

Menu::Menu(Contexte *obj) : contexte{obj} {};
Menu::~Menu()
{
}

void Menu::init()
{
    nom_app.setFont(*(contexte->font));
    option_dom.setFont(*(contexte->font));
    option_car.setFont(*(contexte->font));
    option_tra.setFont(*(contexte->font));

    nom_app.setString("Tracarnos");
    option_dom.setString(">Dominos");
    option_tra.setString("Trax");
    option_car.setString("Carcassonne");

    float width = contexte->fenetre->getSize().x;
    float height = contexte->fenetre->getSize().y;

    nom_app.setPosition(width * 2 / 5, height * 0.5 / 5);
    option_dom.setPosition(width / 4, height * 2 / 5);
    option_tra.setPosition(width / 4, height * 3 / 5);
    option_car.setPosition(width / 4, height * 4 / 5);

    nom_app.setFillColor(sf::Color::Red);
    option_dom.setFillColor(sf::Color(255, 215, 0));
}

void Menu::traitementInput()
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
                    curseur=2;
                break;
            case sf::Keyboard::Down:
                curseur=(curseur+1)%3;
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

void Menu::dessine()
{
    contexte->fenetre->clear();
    contexte->fenetre->draw(nom_app);
    contexte->fenetre->draw(option_dom);
    contexte->fenetre->draw(option_tra);
    contexte->fenetre->draw(option_car);
    contexte->fenetre->display();
}

void Menu::maj()
{
    if(entree)
    {
        if(curseur==0)
        {
            ParamDominos *d=new ParamDominos(contexte);
            contexte->manageur->ajoute(*d);
        }
        if(curseur==1)
        {
            GameTrax *g=new GameTrax{contexte};
            contexte->manageur->ajoute(*g);
        }
        // TODO carcassonne
    }
    switch (curseur)
    {
    case 0:
        option_dom.setString(">Dominos");
        option_tra.setString("Trax");
        option_car.setString("Carcassonne");

        option_dom.setFillColor(sf::Color(255, 215, 0));
        option_tra.setFillColor(sf::Color::White);
        option_car.setFillColor(sf::Color::White);
        break;
    case 1:
        option_dom.setString("Dominos");
        option_tra.setString(">Trax");
        option_car.setString("Carcassonne");

        option_dom.setFillColor(sf::Color::White);
        option_tra.setFillColor(sf::Color(255, 215, 0));
        option_car.setFillColor(sf::Color::White);
        break;
    case 2:
        option_dom.setString("Dominos");
        option_tra.setString("Trax");
        option_car.setString(">Carcassonne");

        option_dom.setFillColor(sf::Color::White);
        option_car.setFillColor(sf::Color(255, 215, 0));
        option_tra.setFillColor(sf::Color::White);
        break;
    default:
        break;
    }
}