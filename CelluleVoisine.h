#ifndef CELLULEVOISINE_H
#define CELLULEVOISINE_H

#include "Cellule.h"

class CelluleVoisine {
private:
    Cellule* celluleObservee;

public:
    CelluleVoisine(Cellule* cellule);
    void update(Cellule* observable);
};

#endif
