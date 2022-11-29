template <typename T>
Plateau<T>::Plateau(){}

template <typename T>
bool Plateau<T>::existeTuile(int x, int y)const
{
    std::pair<int, int> coord (x, y);
    if ((this->tuiles).count(coord)>=0){
        return true;
    }else return false;
}

template <typename T>
T & Plateau<T>::getTuile(int x, int y)const
{
    std::pair<int, int> coord (x, y);
    return this->tuiles[coord];
}

template <typename T>
bool Plateau<T>::finDePartie()const
{
    return pioche.empty();
}

template <typename T>
T & Plateau<T>::getPioche()
{
    return pioche.at(pioche.size()-1);
}

template <typename T>
void Plateau<T>::ajouterJoueur(Joueur & j)
{
    joueurs.push_back(j);
}

template <typename T>
void Plateau<T>::deffauser()
{
    joueurs.pop_back();
}

template <typename T>
void Plateau<T>::ajouteDominos(T &d)
{
    pioche.push_back(d);
}

template <typename T>
Joueur& Plateau<T>::getVainqueur()
{
    int score=0;
    int id=0;
    for(Joueur &j:joueurs)
    {
        if(j.getScore()>score)
        {
            score=j.getScore();
            id=j.getId();
        }
    }
    return joueurs.at(id);
}

template <typename T>
int Plateau<T>::getNbrJoueurs()const
{
    return joueurs.size();
}

template <typename T>
Joueur & Plateau<T>::getJoueur(int i)
{
    return joueurs.at(i);
}