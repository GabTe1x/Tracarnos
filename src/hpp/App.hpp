#pragma once

#include "Contexte.hpp"
#include "Controleur.hpp"
#include "Menu.hpp"

class App
{
private:
    Contexte *contexte;
public:
    App();
    ~App();

    void run();
};