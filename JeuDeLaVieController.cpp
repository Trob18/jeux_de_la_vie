#include "JeuDeLaVieController.h"
#include <thread>
#include <chrono>

JeuDeLaVieController::JeuDeLaVieController(int largeur, int hauteur, Vue* vue)
    : grille(largeur, hauteur), vue(vue) {}

void JeuDeLaVieController::startSimulation() {
    while (true) {
        grille.updateGrille();
        vue->display(grille);
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Pause d'une seconde.
    }
}

void JeuDeLaVieController::temps_iteration(int temps) {
    std::this_thread::sleep_for(std::chrono::milliseconds(temps));
    grille.updateGrille();
    vue->display(grille);
}
