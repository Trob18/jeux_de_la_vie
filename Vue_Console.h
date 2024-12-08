#ifndef VUE_CONSOLE_H
#define VUE_CONSOLE_H

#include "Vue.h"
#include <vector>

class Vue_Console : public Vue {
public:
    void creationFenetre(const std::vector<std::vector<int>>& matrice);
    void affichage(const std::vector<std::vector<int>>& matrice, std::vector<std::vector<int>> matriceObstacle) override;
};

#endif