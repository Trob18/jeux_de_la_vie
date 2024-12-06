#ifndef GRILLE_H 
#define GRILLE_H 

#include <vector>
#include <iostream> 

class Grille {
private:
    int largeur;
    int hauteur;
    std::vector<std::vector<int>> matrice;

public : 
    Grille(int largeur = 0, int hauteur = 0);
    void initialiser(int largeur, int hauteur);
    int getCellule(int x, int y);
    void setCellule(int x, int y, bool etat);
    void updateGrille();
    void afficher();
    std::vector<std::vector<int>> getMatrice() const { return matrice; }
    std::vector<std::vector<int>> nouvGrille(const std::vector<std::vector<int>>& matrice);
};

#endif