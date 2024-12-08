#include "JeuDeLaVieController.h"
#include <iostream>

int main() {

    JeuDeLaVieController controleur;
    std::string fichierEntree = "test_entree.txt";
    std::string fichierSortieAttendu = "test_sortie.txt";
    JeuDeLaVieController test;
    std::string nom_fichier;

if (controleur.testUnitaire(fichierEntree, fichierSortieAttendu)) {
        std::cout << "Test unitaire réussi. Début de l'application.\n";
        std::cout << "Entrer le nom de votre fichier consommable (sans extension) : ";
        std::cin >> nom_fichier;
        test.setNomFichier(nom_fichier);
        test.ouvertureFichier(nom_fichier + ".txt");
        test.startSimulation();
        return 0;

    } else {
        std::cerr << "Échec du test unitaire.\n";
        return 1;
    }

return 0;
}
