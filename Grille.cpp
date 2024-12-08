#include "Grille.h"
#include "Cellule_Suivante.h"
#include <iostream> 
#include <random>

Grille::Grille(int largeur, int hauteur) : largeur(largeur), hauteur(hauteur) {
    initialiser(largeur, hauteur);
}

void Grille::initialiser(int largeur, int hauteur) {
    this->largeur = largeur;
    this->hauteur = hauteur;
    matrice.resize(hauteur, std::vector<int>(largeur, 0));
    matriceObstacle.resize(hauteur, std::vector<int>(largeur, 0));
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

    if (!etat) { 
        static std::random_device rd;  
        static std::mt19937 gen(rd()); 
        static std::uniform_int_distribution<> dist(1, 20);

        int randomValue = dist(gen);
        if (randomValue == 8) {
            matriceObstacle[x][y] = 2; 
        }
        else{
            matriceObstacle[x][y] = 0;
            matrice[x][y] = 0; 
        }
    } else {
        matriceObstacle[x][y] = 1;
        matrice[x][y] = 1; 
    }
}

void Grille::afficher() {
    for (size_t i = 0; i < matrice.size(); ++i) {           
        const auto& ligne = matrice[i];                    
        const auto& ligneObstacle = matriceObstacle[i];    

        for (size_t j = 0; j < ligne.size(); ++j) {        
            if (ligneObstacle[j] == 2) {                  
                std::cout << ligneObstacle[j] << " ";     
            } else {
                std::cout << ligne[j] << " ";            
            }
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



std::vector<std::vector<int>> Grille::nouvGrilleObstacle(const std::vector<std::vector<int>>& matriceObstacle) {
    std::vector<std::vector<int>> newMatriceObstacle = matriceObstacle;
    
    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            if (matriceObstacle[x][y]==2){
                newMatriceObstacle[x][y] = 2;
            } else if (matriceObstacle[x][y] == 1) {
                    newMatriceObstacle[x][y] = 1;
            } else {
                    newMatriceObstacle[x][y] = 0;
            }
        }
    }

    return newMatriceObstacle;
}