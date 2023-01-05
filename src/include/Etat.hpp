#ifndef _ETAT
#define _ETAT

class Etat
{
public:
    Etat(){};
    virtual ~Etat(){};

    virtual void init() = 0;
    virtual void traitementInput() = 0;
    virtual void dessine() = 0;
    virtual void maj() = 0;
};

#endif