#include "../include/TuileTrax.hpp"
#include <type_traits>


TuileTrax::TuileTrax(bool h,bool d,bool b,bool g):Tuile(h,d,b,g){}

TuileTrax::~TuileTrax()
{
    std::cout<<"Destruction TuileTrax"<<std::endl;
}

bool TuileTrax::correspond(bool cote,int myside)
{
    bool arr{getValeur(myside)};
    std::cout<< arr << "=?=" << cote << std::endl;
    if(arr==cote){
        std::cout<<"Comparaison reussie"<<std::endl;
        return true;
    } else return false;
}

void TuileTrax::retourner(){
    //Donne l'illusion que la tuile est retournée. C'est un mensonge sans honte
    if (haut==gauche){
        bool tmp= haut;
        haut=bas;
        bas=tmp;
    } else{
        bool tmp= haut;
        haut=gauche;
        gauche=tmp;
    }
}

std::ostream & operator <<( std::ostream& out, TuileTrax& x ) {
    std::cout << 
        "'" << x.getValeur(1) << "'\n"
        << x.getValeur(4) << "0" << x.getValeur(2)<< "\n"
        << "'" << x.getValeur(3)<< "'\n"
    << std::endl;
    return out ;
}