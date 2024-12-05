#include"Cellule.h" 
#include <vector>

#ifndef GRILLE_H 
#define GRILLE_H 

class Grille{
    protected:

        int largeur;
        int hauteur;
        std::vector<std::vector<int>> matrice;
        int  getCellule(int x,int y);
        void setCellule(int x, int y, bool etat);
        void updateGrille();
};

#endif