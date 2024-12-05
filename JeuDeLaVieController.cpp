#include "JeuDeLaVieController.h"
#include <fstream>
#include <iostream>
#include "Grille.h"

void JeuDeLaVieController::ouvertureFichier(const std::string &chemin){
    std::ifstream fichier(chemin);

    if (!fichier.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier.\n";
    }
   

    fichier >> hauteur >> largeur;
    matrice.resize(hauteur, std::vector<int>(largeur));
   

    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            fichier >> matrice[i][j];
        }
    }

    //  for (const auto& ligne : matrice) {
    //     for (const auto& valeur : ligne) {
    //         std::cout << valeur << " ";
    //     }
    //     std::cout << "\n";
    // }

    fichier.close();


}