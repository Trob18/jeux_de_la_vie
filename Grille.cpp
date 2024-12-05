#include "Grille.h"
#include <iostream>


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
    if (matrice[x][y] == etat){
        std::cerr << "La cellule était déja dans cet état" << std::endl;
    }
        matrice[x][y] = etat;
}




