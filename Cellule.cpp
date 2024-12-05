

#include "Cellule.h"

Cellule::Cellule(int x, int y, bool etat_vie){
    this->x =x;
    this->y = y;
    this->etat_vie = etat_vie;
}


bool Cellule::getEtat(){
    return etat_vie;
}

void Cellule::setEtat(bool etat){
    etat_vie = etat;
}


