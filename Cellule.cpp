#include "Cellule.h"

Cellule::Cellule() : x(0), y(0), etat_vie(false) {}

Cellule::Cellule(int x, int y, bool etat_vie) : x(x), y(y), etat_vie(etat_vie) {}

int Cellule::getX() const { return x; }
int Cellule::getY() const { return y; }
bool Cellule::getEtat() const { return etat_vie; }

void Cellule::setEtat(bool etat) {
    etat_vie = etat;
    notifierObservateurs();
}

void Cellule::ajouterObservateur(CelluleVoisine* observateur) {
    observateurs.push_back(observateur);
}

void Cellule::notifierObservateurs() {
    for (auto* observateur : observateurs) {
        observateur->update(this);
    }
}
