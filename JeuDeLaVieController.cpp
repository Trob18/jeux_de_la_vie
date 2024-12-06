#include "JeuDeLaVieController.h"
#include <fstream>
#include <iostream>



void JeuDeLaVieController::ouvertureFichier(const std::string &chemin) {
    std::ifstream fichier(chemin);

    if (!fichier.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier.\n";
        return;
    }
   
    int hauteur, largeur;
    fichier >> hauteur >> largeur;

  
    grille.initialiser(largeur, hauteur);
    
    
    for (int x = 0; x < hauteur; x++) {
        for (int y = 0; y < largeur; y++) {
            int etat;
            fichier >> etat;
            grille.setCellule(x, y, etat);
        }
    }

   
    std::cout << "Matrice initiale :\n";
    grille.afficher();

    fichier.close();
}


void JeuDeLaVieController::setCellule(int x, int y, bool etat){
    grille.setCellule(x,y,etat);
}

void JeuDeLaVieController::afficherGrille(){
    grille.afficher();
}





void JeuDeLaVieController::startSimulation() {
    std::vector<std::vector<int>> matrice = grille.nouvGrille(grille.getMatrice());  // Ajoutez cette méthode getMatrice()

    Vue_Console display;
    
    std::cout << "Etat 1 :\n";
    display.affichage(matrice);
    
    int steps = 30;
    for (int i = 1; i < steps; ++i) {
        std::cout << "Etape " << i + 1 << " :\n";
        matrice = grille.nouvGrille(matrice);
        display.affichage(matrice);
    }    
}