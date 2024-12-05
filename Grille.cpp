#include "Grille.h"
#include <iostream>

Grille::Grille(int largeur, int hauteur) : largeur(largeur), hauteur(hauteur) {
    initialiser(largeur, hauteur);
}


void Grille::initialiser(int largeur, int hauteur){
    this-> largeur = largeur;
    this-> hauteur = hauteur;
    matrice.resize(hauteur, std::vector<int>(largeur, 0));
}


int Grille::getCellule(int x, int y){
    if(x < 0 || y < 0 || x >= largeur || y >= hauteur){
        std::cerr << "Les coordonnées sont inaccesibles" << std::endl;
    }
    return matrice[x][y];
}



void Grille::setCellule(int x, int y, bool etat){
    
    if(x < 0 || y < 0 || x >= largeur || y >= hauteur){
        std::cerr << "Les coordonnées sont inaccesibles";
    }
        matrice[x][y] = etat;
}


void Grille::afficher() {
    for (const auto& ligne : matrice) {
        for (int val : ligne) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}

