#include "Vue_Console.h"
#include <iostream>

void Vue_Console::creationFenetre(const std::vector<std::vector<int>>& matrice){
        // fonction vide
    }


void Vue_Console::affichage(const std::vector<std::vector<int>>& matrice, std::vector<std::vector<int>> matriceObstacle) {
    for (size_t i = 0; i < matrice.size(); ++i) {           
        const auto& ligne = matrice[i];                    
        const auto& ligneObstacle = matriceObstacle[i];    

        for (size_t j = 0; j < ligne.size(); ++j) {        
            if (ligneObstacle[j] == 2) {                  
                std::cout << ligneObstacle[j] << " ";     
            } else {
                std::cout << ligne[j] << " ";            
            }
        }
        std::cout << "\n";
    }
}