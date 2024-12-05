#include "JeuDeLaVieController.h"
#include <fstream>
#include <iostream>
#include "Grille.h"

void JeuDeLaVieController::ouvertureFichier(const std::string &chemin){
    std::ifstream fichier(chemin);

    if (!fichier.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier.\n";
    }
   
    int largeur;
    int hauteur;
    fichier >> hauteur >> largeur;
    grille.initialiser(largeur,hauteur);
    
   

    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            int etat;
            fichier >> etat;
            grille.setCellule(i, j, etat);
        }
    }

    fichier.close();

}


void JeuDeLaVieController::setCellule(int x, int y, bool etat){
    grille.setCellule(x,y,etat);
}

void JeuDeLaVieController::afficherGrille(){
    grille.afficher();
}