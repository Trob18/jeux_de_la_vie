#ifndef VUEGRAPHIQUE_H
#define VUEGRAPHIQUE_H

#include <SFML/Graphics.hpp>
#include "Vue.h"
#include <vector>


class Vue_Graphique : public Vue {

private:
    sf::RenderWindow window; 
    bool fenetreFermee = false;
    int delai;

public:
    void creationFenetre(const std::vector<std::vector<int>>& matrice);
    void affichage(const std::vector<std::vector<int>>& matrice);
    const bool estFenetreFermee();
    void bouton();
    int getDelai();
    void setDelai(int nouveauDelai);


};

#endif