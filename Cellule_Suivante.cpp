#include "Cellule_Suivante.h"

int Cellule_suiv::etat_voisin(const std::vector<std::vector<int>>& matrice, int x, int y) {
    int etat_voisin = 0;
    int largeur = matrice[0].size();
    int hauteur = matrice.size();  

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;

            int nx = x + i;
            int ny = y + j;

            if (nx >= 0 && nx < largeur && ny >= 0 && ny < hauteur) {
                etat_voisin += matrice[nx][ny];
            }
        }
    }
    return etat_voisin;
}