template <typename T>
Tuile<T>::Tuile(T & h,T & d,T & b,T & g):haut{h},droite{d},bas{b},gauche{g}{}

template <typename T>
void Tuile<T>::tourne(){
    T tmp;
    tmp = this->haut;
    this->haut = this->gauche;
    this->gauche = this->bas;
    this->bas = this->droite;
    this->haut = tmp;    
}

template <typename T>
T & Tuile<T>::getValeur(int i)const {
    if (i==1){
        return this->haut;
    }
    else if (i==2){
        return this->droite;
    }
    else if (i==3){
        return this->bas;
    }
    else {
        return this->gauche;
    }
}
