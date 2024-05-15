#ifndef FIGURA_H
#define FIGURA_H
#include "punto.h"

class Figura {
    public:
        // Metodo per calcolare l'area della figura
        virtual float area() const = 0;
        virtual float perimetro() const = 0;

    //Gli attributi devono essere protected e non private per poter essere utilizzati dalle classi derivate
    protected:
        //Array di punti
        Punto* punti;
        //Numero di punti
        int n;
};

#endif