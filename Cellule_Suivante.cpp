#include "Cellule_Suivante.h"





int Cellule_suiv::etat_voisin(const vector<vector<int>>& grid, int x, int y){
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;

            int nx = x + i;
            int ny = y + j;

            if (nx >= 0 && nx <  && ny >= 0 && ny < hauteur) {
                count += grid[nx][ny];
            }
        }
    }
    return count;
}