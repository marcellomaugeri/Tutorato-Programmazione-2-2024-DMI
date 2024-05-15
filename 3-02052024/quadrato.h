#ifndef QUADRATO_H
#define QUADRATO_H

#include "quadrilatero.h"

class Quadrato : public Quadrilatero{
    public:
        // Costruttore
        Quadrato(Punto& p1, Punto& p2, Punto& p3, Punto& p4);
};

#endif