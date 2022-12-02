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
T * Plateau<T>::getTuile(int x, int y)const
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
T* Plateau<T>::getPioche()
{
    return pioche.at(pioche.size()-1);
}

template <typename T>
std::array<int, 4>* Plateau<T>::getTaille(){
    int maxx {0}; int maxy {0};int minx {0}; int miny {0};
    for(std::pair<std::pair<int, int>,T*> it : tuiles){
        // Accessing KEY from element pointed by it.
        std::pair<int, int> paire = it.first;
        if (minx>paire.first){
            minx=paire.first;
        }
        if(miny>paire.second){
            miny=paire.second;
        }
        if(maxx<paire.first){
            maxx=paire.first;
        }
        if(maxy<paire.second){
            maxy=paire.second;
        }    
    }
    std::array<int, 4> v{ {maxx, minx, maxy, miny}};
    return &v;
}
    

template <typename T>
void Plateau<T>::ajouterJoueur(Joueur & j)
{
    joueurs.push_back(&j);
}

template <typename T>
void Plateau<T>::deffauser()
{
    joueurs.pop_back();
}

template <typename T>
void Plateau<T>::ajouteTuile(T &t)
{
    pioche.push_back(&t);
}

template <typename T>
Joueur* Plateau<T>::getVainqueur()
{
    int score=0;
    int id=0;
    for(Joueur *j:joueurs)
    {
        if(j->getScore()>score)
        {
            score=j->getScore();
            id=j->getId();
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
Joueur * Plateau<T>::getJoueur(int i)
{
    return joueurs.at(i);
}