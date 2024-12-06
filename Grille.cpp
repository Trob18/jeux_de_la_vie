#include "Grille.h"
#include "Cellule_Suivante.h"
#include <iostream> 

Grille::Grille(int largeur, int hauteur) : largeur(largeur), hauteur(hauteur) {
    initialiser(largeur, hauteur);
}

void Grille::initialiser(int largeur, int hauteur) {
    this->largeur = largeur;
    this->hauteur = hauteur;
    matrice.resize(hauteur, std::vector<int>(largeur, 0));
}

int Grille::getCellule(int x, int y) {
    if(x < 0 || y < 0 || y >= largeur || x >= hauteur) {
        std::cerr << "Les coordonnées sont inaccesibles" << std::endl;
        return -1; 
    }
    return matrice[x][y];
}

void Grille::setCellule(int x, int y, bool etat) {
    if(x < 0 || y < 0 || x >= largeur || y >= hauteur) {
        std::cerr << "Les coordonnées sont inaccesibles" << std::endl;
        return;
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

void Grille::updateGrille() {
    matrice = nouvGrille(matrice);
}

std::vector<std::vector<int>> Grille::nouvGrille(const std::vector<std::vector<int>>& matrice) {
    std::vector<std::vector<int>> newMatrice = matrice;
    Cellule_suiv compteur;
    
    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            int voisin = compteur.etat_voisin(matrice, x, y);
            if (matrice[x][y] == 1) {
                if (voisin < 2 || voisin > 3) {
                    newMatrice[x][y] = 0;
                }
            } else {
                if (voisin == 3) {
                    newMatrice[x][y] = 1;
                }
            }
        }
    }

    return newMatrice;
}