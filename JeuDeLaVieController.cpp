#include "JeuDeLaVieController.h"
#include <fstream>
#include <iostream>
#include <chrono>
#include <thread>



void JeuDeLaVieController::ouvertureFichier(const std::string &chemin) {
    std::ifstream fichier(chemin);

    if (!fichier.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier.\n";
        return;
    }
   
    int hauteur, largeur;
    fichier >> hauteur >> largeur;

  
    grille.initialiser(largeur, hauteur);
    
    
    for (int x = 0; x < hauteur; x++) {
        for (int y = 0; y < largeur; y++) {
            int etat;
            fichier >> etat;
            grille.setCellule(x, y, etat);
        }
    }

   
    

    fichier.close();
}


void JeuDeLaVieController::setCellule(int x, int y, bool etat){
    grille.setCellule(x,y,etat);
}

void JeuDeLaVieController::afficherGrille(){
    grille.afficher();
}



void JeuDeLaVieController::startSimulation() {
    Vue* display = nullptr;
    int touche;
    int finis=false;
    while (finis==false)
    {
        std::cout<<"Dans quel mode souhaitez-vous vous rendre ? "<<"1: Mode Console      2: Mode Graphique"<<std::endl;
        std::cin>>touche;
        if (touche == 1){
            display = new Vue_Console();
            std::cout << "Matrice initiale :\n";
            grille.afficher();
            std::vector<std::vector<int>> matrice = grille.nouvGrille(grille.getMatrice()); 
    
            std::cout << "Etat 1 :\n";
            display->affichage(matrice);

            int steps = 30;
            for (int i = 1; i < steps; ++i) {
                std::cout << "Etape " << i + 1 << " :\n";
                matrice = grille.nouvGrille(matrice);
                display->affichage(matrice);
            }  
            delete display;
            finis = true;
        }
        else if (touche == 2){
            display = new Vue_Graphique();
            std::vector<std::vector<int>> matrice = grille.nouvGrille(grille.getMatrice());
            display->creationFenetre(matrice);
            display->affichage(matrice);
            sf::sleep(sf::milliseconds(500));
            int steps = 30;
            for (int i = 1; i < steps; ++i) {
                if (dynamic_cast<Vue_Graphique*>(display)->estFenetreFermee()) {
                    break; // Sortir de la boucle si la fenêtre est fermée
                }
                matrice = grille.nouvGrille(matrice);
                display->affichage(matrice);
                
                sf::sleep(sf::milliseconds(1000));
            }  
            delete display;
            finis = true;
        }
        else{
            std::cout<<"Erreur ! Aucun mode choisis"<<std::endl;
        }
    }  
}