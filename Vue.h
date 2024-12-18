#ifndef VUE_H
#define VUE_H

#include <vector>

class Vue {
public:
    virtual void creationFenetre(const std::vector<std::vector<int>>& matrice) = 0;
    virtual void affichage(const std::vector<std::vector<int>>& matrice, std::vector<std::vector<int>> matriceObstcale) = 0;
    virtual ~Vue() = default;
};

#endif 