#ifndef VUECONSOLE_H
#define VUECONSOLE_H

#include "Vue.h"
#include <iostream>

class VueConsole : public Vue {
public:
    void display(const Grille& grille) override;
};

#endif
