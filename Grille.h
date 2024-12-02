#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include "Cellule.h"

class Grille {
private:
    int largeur, hauteur;
    std::vector<std::vector<Cellule>> cellules;

public:
    Grille(int largeur, int hauteur);

    Cellule* getCellule(int x, int y);
    void setCellule(int x, int y, bool etat);
    void updateGrille();
};

#endif
