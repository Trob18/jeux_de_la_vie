class Grille;
class Vue;
#include "Grille.h"
#include <iostream>

#ifndef JEUDELAVIECONTROLLER_H 
#define JEUDELAVIECONTROLLER_H

class JeuDeLaVieController{
    private :
        Grille grille;
    
    public: 
        void startSimulation();
        void ouvertureFichier(const std::string &chemin);
        void setCellule(int x, int y, bool etat);
        void afficherGrille();

};

#endif