#ifndef QUADRILATERO_H
#define QUADRILATERO_H
#include "figura.h"
#include "punto.h"

class Quadrilatero : public Figura {
    public:
        // Costruttore
        Quadrilatero(Punto& p1, Punto& p2, Punto& p3, Punto& p4);

        // Metodo per calcolare l'area del quadrilatero
        float area() const;

        // Metodo per calcolare il perimetro del quadrilatero
        float perimetro() const;
};

#endif