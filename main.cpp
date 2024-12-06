#include "JeuDeLaVieController.h"
#include <iostream>

int main() {
    JeuDeLaVieController test;
    test.ouvertureFichier("fichier.txt");
    test.startSimulation();

    return 0;
}