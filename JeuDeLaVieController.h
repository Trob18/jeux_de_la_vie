#ifndef JEUDELAVIECONTROLLER_H 
#define JEUDELAVIECONTROLLER_H

#include <string>  
#include <vector>
#include "Vue.h"
#include "Vue_Console.h"
#include "Vue_Graphique.h"
#include "Grille.h"

class JeuDeLaVieController {
private:
    int largeur;
    int hauteur;
    std::vector<int> matrice;
    std::vector<int> matriceObstacle;
    Grille grille;
    std::string nom_fichier_base;

    
public: 
    void startSimulation();
    void ouvertureFichier(const std::string &chemin);
    void setCellule(int x, int y, bool etat);
    void afficherGrille();
    void setNomFichier(std::string &nom);
};

#endif