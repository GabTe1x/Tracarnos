#include "../hpp/Dominos.hpp"



bool Dominos::correspond(int cote[3],int myside)
{
    int arr[3]{t.getValeur(myside)};
    if(arr[0]==cote[2] && arr[1]==cote[1] && arr[2]==cote[0])return true;
    return false;
}