#include "JeuDeLaVieController.h"
#include <iostream>

int main() {
    JeuDeLaVieController test;
    std::string nom_fichier;
    std::cout << "Entrer le nom de votre fichier consommable (sans extension) : ";
    std::cin >> nom_fichier;
    test.setNomFichier(nom_fichier);
    test.ouvertureFichier(nom_fichier + ".txt");
    test.startSimulation();

    return 0;
}