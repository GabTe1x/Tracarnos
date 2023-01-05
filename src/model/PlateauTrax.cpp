#include "../include/PlateauTrax.hpp"
#include <set>
#include <utility>

PlateauTrax::PlateauTrax() {}

int getEntrant(TuileTrax *t, int n) {
  if (t->getValeur(4) == n)
    return 4;
  if (t->getValeur(3) == n)
    return 3;
  if (t->getValeur(2) == n)
    return 2;
  if (t->getValeur(1) == n)
    return 1;
  return 0;
}

int getSortant(TuileTrax *t, int n, int entrant) {
  if (t->getValeur(1) == n && entrant != 1)
    return 1;
  if (t->getValeur(2) == n && entrant != 2)
    return 2;
  if (t->getValeur(3) == n && entrant != 3)
    return 3;
  if (t->getValeur(4) == n && entrant != 4)
    return 4;
  return 0;
}

void PlateauTrax::addPoint(bool n) {
  if (n) {
    joueurs.at(0)->addScore(1);
  } else {
    joueurs.at(1)->addScore(1);
  }
}

bool PlateauTrax::gagne(bool n) {
  // Trouver une boucle ou un chemin de taille 8
  std::set<std::pair<int, int>> dejaVerif;

  for (std::pair<std::pair<int, int>, TuileTrax *> it : tuiles) {
    std::cout << it.first.first << " " << it.first.second << " dans le FOR"
              << std::endl;
    std::set<std::pair<int, int>> boucle;
    if ((dejaVerif).count(it.first) != 1) {
      int coteEntrant = getEntrant(it.second, n);
      int x = it.first.first;
      int y = it.first.second;
      int taillex = 0;
      int tailley = 0;
      bool isNext = true;


      while (isNext) {

        
      TuileTrax *t = getTuile(x, y);
      int coteSortant = getSortant(t, n, coteEntrant);

 /*     std::cout << "Entrée dans le WHILE. Case de départ :" << it.first.first
                << " " << it.first.second << " || Case actuelle: " << x << " "
                << y << " || Entrant = " << coteEntrant
                << " Sortant = " << coteSortant << std::endl;
*/
        // Il y a une boucle
        if (boucle.count(std::pair<int, int> {x, y}) == 1) {
          addPoint(n);
          std::cout << "BOUCLE" << std::endl;
          return true;
        }

        boucle.insert(std::pair<int, int>{x, y});
        dejaVerif.insert(std::pair<int, int>{x, y});


        if (coteSortant == 1) {
          x++;
          if (existeTuile(x, y)) {
            taillex++;
            coteEntrant = 3;
          } else {
            isNext = false;
          }
        } else if (coteSortant == 2) {
          y++;
          if (existeTuile(x, y)) {
            tailley++;
            coteEntrant = 4;
          } else {
            isNext = false;
          }
        } else if (coteSortant == 3) {
          x--;
          if (existeTuile(x, y)) {
            taillex--;
            coteEntrant = 1;
          } else {
            isNext = false;
          }
        } else if (coteSortant == 4) {
          y--;
          if (existeTuile(x, y)) {
            tailley--;
            coteEntrant = 3;
          } else {
            isNext = false;
          }
        }
        // chemin de taille 8
        if (taillex >= 8 || taillex <= -8 || tailley >= 8 || tailley <= -8) {
          std::cout << "CHEMIN 8" << std::endl;
          addPoint(n);
          return true;
        }
        std::cout << "Sortie du WHILE. lx = " << taillex
                  << " ly =" << tailley << std::endl;
      }

    std::cout << "Sortie du FOR lx = " << taillex
                  << " ly =" << tailley << std::endl;
    }
  }

  // Trouver la pièce suivante en verifiant toutes les pièces sauf celle du
  // coté Cotéentrant
  std::cout << "return False pour n= " << n << std::endl;
  return false;
}

bool PlateauTrax::finDePartie() {
  std::cout << "Verif fin de partie" << std::endl;
  if (pioche.empty())
    return true;
  else {
    // On verifie si un chemin ou une boucle existe pour le joueur n
    if (gagne(0) || gagne(1)) {
      return true;
    }
  }
  return false;
}

// Pose une tuile sur l'emplacement coord si c'est obligatoire
bool PlateauTrax::verifCoupObligatoire(std::pair<int, int> coord) {
  int haut, droite, bas, gauche;

  if (existeTuile(coord.first, coord.second + 1)) {
    haut =
        tuiles[std::pair<int, int>(coord.first, coord.second + 1)]->getValeur(
            3);
  } else
    haut = 2;

  if (existeTuile(coord.first + 1, coord.second)) {
    droite =
        tuiles[std::pair<int, int>(coord.first + 1, coord.second)]->getValeur(
            4);
  } else
    droite = 2;

  if (existeTuile(coord.first, coord.second - 1)) {
    bas = tuiles[std::pair<int, int>(coord.first, coord.second - 1)]->getValeur(
        1);
  } else
    bas = 2;

  if (existeTuile(coord.first - 1, coord.second)) {
    gauche =
        tuiles[std::pair<int, int>(coord.first - 1, coord.second)]->getValeur(
            2);
  } else
    gauche = 2;

  if (haut != 2) {
    if (droite == haut) {
      TuileTrax *tuile = new TuileTrax(haut, haut, !haut, !haut);
      this->tuiles[coord] = tuile;
      return true;
    } else if (bas == haut) {
      TuileTrax *tuile = new TuileTrax(haut, !haut, haut, !haut);
      this->tuiles[coord] = tuile;
      return true;

    } else if (gauche == haut) {
      TuileTrax *tuile = new TuileTrax(haut, !haut, !haut, haut);
      this->tuiles[coord] = tuile;
      return true;
    }
  }

  if (droite != 2) {
    if (bas == droite) {
      TuileTrax *tuile = new TuileTrax(!droite, droite, droite, !droite);
      this->tuiles[coord] = tuile;
      return true;

    } else if (gauche == droite) {
      TuileTrax *tuile = new TuileTrax(!droite, droite, !droite, droite);
      this->tuiles[coord] = tuile;
      return true;
    }
  }

  if (bas != 2) {
    if (gauche == bas) {
      TuileTrax *tuile = new TuileTrax(!bas, !bas, bas, bas);
      this->tuiles[coord] = tuile;
      return true;
    }
  }
  return false;
}

// S'il existe un coup obligatoire, le joue et renvoie true
bool PlateauTrax::jouerCoupObligatoire() {
  // Repertorie les coordonnées déja vérifiées
  std::set<std::pair<int, int>> dejaVerif;
  for (std::pair<std::pair<int, int>, TuileTrax *> it : tuiles) {
    std::pair<int, int> paire = it.first;
    if (!existeTuile(paire.first + 1, paire.second)) {
      std::pair<int, int> coord{paire.first + 1, paire.second};
      if ((dejaVerif).count(coord) != 1) {
        if (verifCoupObligatoire(coord)) {
          return true;
        }
        dejaVerif.insert(coord);
      }
    }
    if (!existeTuile(paire.first - 1, paire.second)) {
      std::pair<int, int> coord{paire.first - 1, paire.second};
      if ((dejaVerif).count(coord) != 1) {
        if (verifCoupObligatoire(coord)) {
          return true;
        }
        dejaVerif.insert(coord);
      }
    }
    if (!existeTuile(paire.first, paire.second + 1)) {
      std::pair<int, int> coord{paire.first, paire.second + 1};
      if ((dejaVerif).count(coord) != 1) {
        if (verifCoupObligatoire(coord)) {
          return true;
        }
        dejaVerif.insert(coord);
      }
    }
    if (!existeTuile(paire.first, paire.second - 1)) {
      std::pair<int, int> coord{paire.first, paire.second - 1};
      if ((dejaVerif).count(coord) != 1) {
        if (verifCoupObligatoire(coord)) {
          return true;
        }
        dejaVerif.insert(coord);
      }
    }
  }
  return false;
}

int PlateauTrax::peutPoser(TuileTrax &tuile, int x, int y) {
  // Si le plateau est vide
  std::pair<int, int> coord(x, y);
  if (tuiles.empty()) {
    this->tuiles[coord] = &tuile;
    defausser();
    return 1;
    std::cout << "tuile placée sur plateau vide" << std::endl;
  }

  // Si le plateau n'est pas vide
  // S'il y a deja une tuile sur la case (x, y)
  if (existeTuile(x, y)) {
    std::cout << "Il existe déjà une tuile sur cet emplacement" << std::endl;
    return -1;
  }

  bool estColle = false;

  // On verifie que la pièce au dessus correspond bien
  if (existeTuile(x, y + 1)) {
    estColle = true;
    if (tuile.correspond(tuiles[std::pair<int, int>(x, y + 1)]->getValeur(3),
                         1)) {
      std::cout << "dessus correspond" << std::endl;
    } else {
      std::cout << "dessus say no" << std::endl;
      return -1;
    }
  }

  // On verifie que la pièce à droite correspond bien
  if (existeTuile(x + 1, y)) {
    estColle = true;
    if (tuile.correspond(tuiles[std::pair<int, int>(x + 1, y)]->getValeur(4),
                         2)) {
      std::cout << "droite correspond" << std::endl;
    } else {
      std::cout << "droite say no" << std::endl;
      return -1;
    }
  }

  // On verifie que la pièce en dessous correspond bien
  if (existeTuile(x, y - 1)) {
    estColle = true;
    if (tuile.correspond(tuiles[std::pair<int, int>(x, y - 1)]->getValeur(1),
                         3)) {
      std::cout << "dessous correspond" << std::endl;
    } else {
      std::cout << "dessous say no" << std::endl;
      return -1;
    }
  }

  // On verifie que la pièce à gauche correspond bien
  if (existeTuile(x - 1, y)) {
    estColle = true;
    if (tuile.correspond(tuiles[std::pair<int, int>(x - 1, y)]->getValeur(2),
                         4)) {
      std::cout << "gauche correspond" << std::endl;
    } else {
      std::cout << "gauche say no" << std::endl;
      return -1;
    }
  }

  if (estColle) {
    this->tuiles[coord] = &tuile;
    defausser();
    return 1;
    std::cout << "tuile placée" << std::endl;
  }
  std::cout << "estColle say no" << std::endl;
  return -1;
}

std::ostream &operator<<(std::ostream &out, PlateauTrax &x) {
  for (std::pair<std::pair<int, int>, TuileTrax *> it : x.tuiles) {
    // Accessing KEY from element pointed by it.
    std::pair<int, int> paire = it.first;
    TuileTrax *dom = it.second;
    std::cout << "Trax. (x=: " << paire.first << "; y=" << paire.second << ")\n"
              << *dom << std::endl;
  }
  std::cout << "fin du plateau" << std::endl;
  return out;
}
