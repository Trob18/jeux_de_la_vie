#ifndef JEUDELAVIECONTROLLER_H 
#define JEUDELAVIECONTROLLER_H

#include <string>  
#include <vector>
#include "Vue.h"
#include "Vue_Console.h"
#include "Grille.h"

class JeuDeLaVieController {
private:
    int largeur;
    int hauteur;
    std::vector<int> matrice;
    Grille grille;
    
public: 
    void startSimulation();
    void ouvertureFichier(const std::string &chemin);
    void setCellule(int x, int y, bool etat);
    void afficherGrille();
};

#endif