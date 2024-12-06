#ifndef CELLULE_SUIVANTE_H
#define CELLULE_SUIVANTE_H

#include <vector>

class Cellule_suiv {
public: 
    int etat_voisin(const std::vector<std::vector<int>>& matrice, int x, int y);
};

#endif