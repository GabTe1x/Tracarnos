#pragma once

class Etat
{
public:
    Etat(){};
    virtual ~Etat(){};

    virtual void init() = 0;
    virtual void traitementInput() = 0;
    virtual void dessine() = 0;
    virtual void maj() = 0;

    virtual void pause(){};
    virtual void reprendre(){};
};