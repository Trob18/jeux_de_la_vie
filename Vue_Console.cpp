#include "Vue_Console.h"
#include <iostream>

void Vue_Console::creationFenetre(const std::vector<std::vector<int>>& matrice){
        // Ne fait rien dans cette classe
    }


void Vue_Console::affichage(const std::vector<std::vector<int>>& matrice) {
    for (const auto& row : matrice) {
        for (int cell : row) {
            std::cout <<cell<< " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}