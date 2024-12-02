#include "CelluleVoisine.h"
#include <iostream>

CelluleVoisine::CelluleVoisine(Cellule* cellule) : celluleObservee(cellule) {
    celluleObservee->ajouterObservateur(this);
}

void CelluleVoisine::update(Cellule* observable) {
    if (observable->getEtat()) {
        std::cout << "Cellule (" << observable->getX() << ", " << observable->getY() << ") est vivante.\n";
    } else {
        std::cout << "Cellule (" << observable->getX() << ", " << observable->getY() << ") est morte.\n";
    }
}
