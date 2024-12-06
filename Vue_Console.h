#ifndef VUE_CONSOLE_H
#define VUE_CONSOLE_H

#include "Vue.h"
#include <vector>

class Vue_Console : public Vue {
public:
    void affichage(const std::vector<std::vector<int>>& matrice) override;
};

#endif