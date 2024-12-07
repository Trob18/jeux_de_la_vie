#include "Vue_Graphique.h"


void Vue_Graphique::setDelai(int nouveauDelai){
    delai = nouveauDelai;
}

int Vue_Graphique::getDelai(){
    return delai;
}



const bool Vue_Graphique::estFenetreFermee(){
    return fenetreFermee;
}




void Vue_Graphique::creationFenetre(const std::vector<std::vector<int>>& matrice){
    int cell_size = 20; 
    window.create(
        sf::VideoMode(matrice[0].size() * cell_size, matrice.size() * cell_size),
        "Jeu de la Vie"
    );
}

void Vue_Graphique::affichage(const std::vector<std::vector<int>>& matrice) {
    int cell_size = 20;
    sf::RectangleShape cell(sf::Vector2f(cell_size, cell_size));

    sf::Event event;
    if (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                fenetreFermee = true;
                return;
            }
        }
    }

    for (int x = 0; x < matrice.size(); ++x) {
        for (int y = 0; y < matrice[x].size(); ++y) {
            cell.setPosition(y * cell_size, x * cell_size);
            if (matrice[x][y] == 1) {
                cell.setFillColor(sf::Color::Blue);
            } else {
                cell.setFillColor(sf::Color::White);
            }
            window.draw(cell);
        }
    }

    window.display(); 
        
}


void Vue_Graphique::bouton(){
    sf::Event appuie;
    while (window.pollEvent(appuie)){
        if (appuie.type == sf::Event::KeyPressed){
            if(appuie.key.code == sf::Keyboard::Up){
                delai = std::max(100, delai - 100);
            } else if(appuie.key.code == sf::Keyboard::Down){
                delai = std::min(2000, delai + 100);
            }
        }
    }
}


