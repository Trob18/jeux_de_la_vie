#ifndef CELLULE_H
#define CELLULE_H

#include <vector>
#include "CelluleVoisine.h"

class CelluleVoisine;

class Cellule {
private:
    int x, y;
    bool etat_vie;
    std::vector<CelluleVoisine*> observateurs; // Observers

public:
    Cellule();
    Cellule(int x, int y, bool etat_vie);

    int getX() const;
    int getY() const;
    bool getEtat() const;

    void setEtat(bool etat_vie);

    void ajouterObservateur(CelluleVoisine* observateur);
    void notifierObservateurs();
};

#endif
