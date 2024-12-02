#ifndef VUE_H
#define VUE_H

#include "Grille.h"

class Vue {
public:
    virtual void display(const Grille& grille) = 0;
    virtual ~Vue() = default;
};

#endif
