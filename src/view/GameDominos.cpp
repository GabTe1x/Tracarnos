#include "../include/GameDominos.hpp"

GameDominos::GameDominos(Contexte *obj,int j,int d) : contexte{obj},x{500},y{500}
{
    ctlr.commencer(j,d);
}

GameDominos::~GameDominos()
{
    for(SpriteDominos*s:tuiles)
    {
        delete s;
    }
    tuiles.clear();
}

void GameDominos::init()
{
    titre.setString("Dominos");
    titre.setCharacterSize(25);
    titre.setFont(*(contexte->font));
    titre.setPosition(962,50);
    
    border.setSize(sf::Vector2f(296,596));
    border.setPosition(902,2);
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineThickness(2.f);
    border.setOutlineColor(sf::Color::White);

    Dominos *d=ctlr.getPlateau()->getTuile(500,500);
    
    pioche = new SpriteDominos();
    pioche->init(*(contexte->font),d);
    pioche->myPosition(400,200);
    pioche->setGridPosition(x,y);

    tuiles.push_back(pioche);

    current=&ctlr.piocher();
    pioche= new SpriteDominos();
    pioche->init(*(contexte->font),current);
    pioche->myPosition(1000,200);

    Joueur j=*ctlr.getJoueurActuel();
    std::string jou = "Joueur "+std::to_string(j.getId())+" Score:"+std::to_string(j.getScore());
    player.setString(jou);
    player.setCharacterSize(18);
    player.setFont(*(contexte->font));
    player.setPosition(sf::Vector2f(920,120));

    select.setSize(sf::Vector2f(98,98));
    select.setPosition(401,201);
    select.setFillColor(sf::Color::Transparent);
    select.setOutlineColor(sf::Color::Red);
    select.setOutlineThickness(2.f);
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
                for(size_t i=0;i<tuiles.size();i++)
                {
                    int _x=tuiles.at(i)->getPos().x;
                    int _y=tuiles.at(i)->getPos().y;
                    tuiles.at(i)->myPosition(_x,_y-100);
                }
                this->y=this->y-1;
                break;
            case sf::Keyboard::Down:
                for(size_t i=0;i<tuiles.size();i++)
                {
                    int _x=tuiles.at(i)->getPos().x;
                    int _y=tuiles.at(i)->getPos().y;
                    tuiles.at(i)->myPosition(_x,_y+100);
                }
                this->y=this->y+1;
                break; 
            case sf::Keyboard::Right:
                for(size_t i=0;i<tuiles.size();i++)
                {
                    int _x=tuiles.at(i)->getPos().x;
                    int _y=tuiles.at(i)->getPos().y;
                    tuiles.at(i)->myPosition(_x+100,_y);
                }
                this->x=this->x+1;
                break;
            case sf::Keyboard::Left:
                for(size_t i=0;i<tuiles.size();i++)
                {
                    int _x=tuiles.at(i)->getPos().x;
                    int _y=tuiles.at(i)->getPos().y;
                    tuiles.at(i)->myPosition(_x-100,_y);
                }
                this->x=this->x-1;
                break;
            case sf::Keyboard::Enter:
                if(1)
                {
                    int pts=ctlr.getPlateau()->peutPoser(*current,x,y);
                    if(pts!=-1)
                    {
                    pioche->setGridPosition(x,y);
                    tuiles.push_back(pioche);
                    current=&ctlr.piocher();
                    pioche->init(*(contexte->font),current);
                    pioche->myPosition(1000,200);
                    }
                }
                break;
            case sf::Keyboard::D:
                ctlr.defausser();
                delete pioche;
                current=&ctlr.piocher();
                pioche= new SpriteDominos();
                pioche->init(*(contexte->font),current);
                pioche->myPosition(1000,200);
                break;

            case sf::Keyboard::R:
                current->tourne();
                pioche->setString(current);
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
    pioche->draw(*(contexte->fenetre));
    for(size_t i=0;i<tuiles.size();i++)
    {
        // dessine que les tuiles concernées
        if(!(tuiles.at(i)->getX()<x-4 || tuiles.at(i)->getX()>x+4 ||
        tuiles.at(i)->getY()<y-2 || tuiles.at(i)->getY()>y+2 ))
        {
            tuiles.at(i)->draw(*(contexte->fenetre));   
        }
    }
    contexte->fenetre->draw(titre);
    contexte->fenetre->draw(player);
    contexte->fenetre->draw(border);
    contexte->fenetre->draw(select);
    contexte->fenetre->display();
}

void GameDominos::maj()
{
}