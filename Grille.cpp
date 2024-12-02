#include "Grille.h"

Grille::Grille(int largeur, int hauteur) : largeur(largeur), hauteur(hauteur) {
    cellules.resize(hauteur, std::vector<Cellule>(largeur));
    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            cellules[y][x] = Cellule(x, y, false);
        }
    }
}

Cellule* Grille::getCellule(int x, int y) {
    if (x >= 0 && x < largeur && y >= 0 && y < hauteur) {
        return &cellules[y][x];
    }
    return nullptr;
}

void Grille::setCellule(int x, int y, bool etat) {
    if (auto* cellule = getCellule(x, y)) {
        cellule->setEtat(etat);
    }
}

void Grille::updateGrille() {
    // Logique de mise à jour des cellules (jeu de la vie).
}
