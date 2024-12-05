#include "Cellule.h"
#include "Grille.h"
#include "JeuDeLaVieController.h"

int main(){

    JeuDeLaVieController test;
    test.ouvertureFichier("fichier.txt");
    test.afficherGrille();

    test.setCellule(0,0,true);

    test.afficherGrille();
    

    return 0;
}