template <typename T>
Plateau<T>::Plateau(){}

template <typename T>
bool Plateau<T>::existeTuile(int x, int y){
    std::pair<int, int> coord (x, y);
    if ((this->tuiles).count(coord)>=0){
        return true;
    }else return false;
}

template <typename T>
T & Plateau<T>::getTuile(int x, int y){
    std::pair<int, int> coord (x, y);
    return this->tuiles[coord];
}