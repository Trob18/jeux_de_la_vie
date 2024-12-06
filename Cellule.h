#ifndef CELLULE_H
#define CELLULE_H
#include "Cellule_Suivante.h"

class Cellule{
    private :
        int x;
        int y;
        bool etat_vie;
    public:
        Cellule(int x, int y, bool etat_vie);

        bool getEtat();
        void setEtat(bool etat);
};

#endif