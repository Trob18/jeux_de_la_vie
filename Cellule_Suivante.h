#include "JeuDeLaVieController.h"




class Cellule_suiv :public Cellule{
    public : 
        int etat_voisin(const vector<vector<int>>& grid, int x, int y);
};