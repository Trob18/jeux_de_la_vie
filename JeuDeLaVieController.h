class Grille;
class Vue;
#include "Grille.h"
#include <iostream>

#ifndef JEUDELAVIECONTROLLER_H 
#define JEUDELAVIECONTROLLER_H

class JeuDeLaVieController:public Grille {
    private :
        Grille grille;
        Vue *vue;
        int temps_iteration;
    public: 
        void startSimulation();
        void ouvertureFichier(const std::string &chemin);

};

#endif