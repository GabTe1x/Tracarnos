template <typename T>
Tuile<T>::Tuile(T & h,T & d,T & b,T & g):haut{h},droite{d},bas{b},gauche{g}{}

template <typename T>
void Tuile<T>::tourne(){
    T tmp;
    tmp = haut;
    haut = gauche;
    gauche = bas;
    bas = droite;
    haut = tmp;
}

template <typename T>
T& Tuile<T>::getValeur(int i){
    if (i==1){
        return haut;
    }
    else if (i==2){
        return droite;
    }
    else if (i==3){
        return bas;
    }
    else {
        return gauche;
    }
}
