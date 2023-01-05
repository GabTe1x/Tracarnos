#include "../include/GameTrax.hpp"

GameTrax::GameTrax(Contexte *obj) : contexte{obj}, x{500}, y{500}
{
    ctlr.commencer(2, 64);
}

GameTrax::~GameTrax()
{
    for (SpriteTrax *s : tuiles)
    {
        delete s;
    }
    tuiles.clear();
}

void GameTrax::init()
{
    titre.setString("Trax");
    titre.setCharacterSize(25);
    titre.setFont(*(contexte->font));
    titre.setPosition(962, 50);

    border.setSize(sf::Vector2f(296, 596));
    border.setPosition(902, 2);
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineThickness(2.f);
    border.setOutlineColor(sf::Color::White);

    current = &ctlr.piocher();
    pioche = new SpriteTrax();
    pioche->init();
    pioche->myPosition(1000, 200);

    player.setString("Joueur noir");
    player.setCharacterSize(18);
    player.setFont(*(contexte->font));
    player.setPosition(sf::Vector2f(920, 120));

    select.setSize(sf::Vector2f(98, 98));
    select.setPosition(401, 201);
    select.setFillColor(sf::Color::Transparent);
    select.setOutlineColor(sf::Color::Red);
    select.setOutlineThickness(2.f);

    aide1.setString("ENTREE = POSER");
    aide1.setCharacterSize(18);
    aide1.setFont(*(contexte->font));
    aide1.setPosition(sf::Vector2f(920, 350));

    aide2.setString("R = TOURNER");
    aide2.setCharacterSize(18);
    aide2.setFont(*(contexte->font));
    aide2.setPosition(sf::Vector2f(920, 380));

    aide3.setString("S = RETOURNER");
    aide3.setCharacterSize(18);
    aide3.setFont(*(contexte->font));
    aide3.setPosition(sf::Vector2f(920, 410));
}

void GameTrax::traitementInput()
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
                for (size_t i = 0; i < tuiles.size(); i++)
                {
                    int _x = tuiles.at(i)->getPos().x;
                    int _y = tuiles.at(i)->getPos().y;
                    tuiles.at(i)->myPosition(_x, _y + 100);
                }
                this->y = this->y + 1;
                break;
            case sf::Keyboard::Down:
                for (size_t i = 0; i < tuiles.size(); i++)
                {
                    int _x = tuiles.at(i)->getPos().x;
                    int _y = tuiles.at(i)->getPos().y;
                    tuiles.at(i)->myPosition(_x, _y - 100);
                }
                this->y = this->y - 1;
                break;
            case sf::Keyboard::Right:
                for (size_t i = 0; i < tuiles.size(); i++)
                {
                    int _x = tuiles.at(i)->getPos().x;
                    int _y = tuiles.at(i)->getPos().y;
                    tuiles.at(i)->myPosition(_x - 100, _y);
                }
                this->x = this->x + 1;
                break;
            case sf::Keyboard::Left:
                for (size_t i = 0; i < tuiles.size(); i++)
                {
                    int _x = tuiles.at(i)->getPos().x;
                    int _y = tuiles.at(i)->getPos().y;
                    tuiles.at(i)->myPosition(_x + 100, _y);
                }
                this->x = this->x - 1;
                break;
            case sf::Keyboard::Enter:
                std::cout << std::to_string(x) << "," << std::to_string(y) << std::endl;
                std::cout<<*current;
                if (ctlr.jouer(x, y, current))
                {
                    pioche->setGridPosition(x, y);
                    tuiles.push_back(pioche);
                    pioche->myPosition(400, 200);
                    current = &ctlr.piocher();
                    pioche = new SpriteTrax();
                    pioche->init();
                    pioche->myPosition(1000, 200);
                    Joueur *j = ctlr.getJoueurActuel();
                    if(j->getId()==0)
                        player.setString("Joueur noir");
                    else
                        player.setString("Joueur blanc");
                }
                break;
            case sf::Keyboard::S:
                current->retourner();
                pioche->switchSide(current);
                std::cout<<*current;
                break;
            case sf::Keyboard::R:
                current->tourne();
                pioche->rotate();
                std::cout<<*current;
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

void GameTrax::dessine()
{
    contexte->fenetre->clear();
    if(pioche!=nullptr)pioche->draw(*(contexte->fenetre));
    for (size_t i = 0; i < tuiles.size(); i++)
    {
        tuiles.at(i)->draw(*(contexte->fenetre));
    }
    contexte->fenetre->draw(titre);
    contexte->fenetre->draw(player);
    contexte->fenetre->draw(border);
    contexte->fenetre->draw(select);
    contexte->fenetre->draw(aide1);
    contexte->fenetre->draw(aide2);
    contexte->fenetre->draw(aide3);
    contexte->fenetre->display();
}

void GameTrax::maj()
{
    if(ctlr.finDePartie())
    {
        std::string s = "Joueur " + std::to_string(ctlr.getVainqueur().getId()) + " Score:" + std::to_string(ctlr.getVainqueur().getScore());
        EndGame *m=new EndGame(contexte,s);
        contexte->manageur->ajoute(*m,true);
    }
}