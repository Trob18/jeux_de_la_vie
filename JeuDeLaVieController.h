#ifndef JEUDELAVIECONTROLLER_H
#define JEUDELAVIECONTROLLER_H

#include "Grille.h"
#include "Vue.h"

class JeuDeLaVieController {
private:
    Grille grille;
    Vue* vue;

public:
    JeuDeLaVieController(int largeur, int hauteur, Vue* vue);

    void startSimulation();
    void temps_iteration(int temps);
};

#endif
