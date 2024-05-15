#include "punto.h"
#include <cmath>
#include<iostream>

// Implementazione dei metodi della classe
/*Punto::Punto(float x_iniziale, float y_iniziale) {
    #ifdef DEBUG
    std::cout << "Costruttore di Punto" << std::endl;
    #endif
    this->x = x_iniziale;
    this->y = y_iniziale;
}*/

Punto::Punto(float x_iniziale, float y_iniziale) : x(x_iniziale), y(y_iniziale) {}

Punto::Punto(const Punto& p) {
    x = p.x;
    y = p.y;
}

// Metodi per accedere alle coordinate
float Punto::getX() const {
    return x;
}

// Alternativa al const errata
/*
float const Punto::getX() {
    return x;
}
*/

// Alternativa al const che restituisce una variabile che non potrà essere modificata
/*
const float Punto::getX() {
    return x;
}
*/

float Punto::getY() const {
    return y;
}

// Metodi per impostare le coordinate
void Punto::setX(float x) {
    this->x = x;
}

//Alternativa che prende in input un float costante
/*
void Punto::setX(const float x) {
    this->x = x;
}
*/

//Alternativa identica alla precedente, cambia solo la sintassi
/*
void Punto::setX(float const x) {
    this->x = x;
}
*/

void Punto::setY(float y) {
    this->y = y;
}

float Punto::distanzaOrigine() const {
    return sqrt(x * x + y * y);
}

float Punto::distanza(const Punto& p) const {
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
}

/* Implementazione alternativa, senza operatore di scope
class Punto {
    private:
        // Coordinate del punto
        float x;
        float y;

    public:
        // Costruttore per impostare le coordinate iniziali
        Punto(float x, float y) : x(x), y(y) {}

        // Metodi per accedere alle coordinate
        float getX() const { return x; }
        float getY() const { return y; }

        // Metodi per impostare le coordinate
        void setX(float x) { this->x = x; }
        void setY(float y) { this->y = y; }

        // Metodo per calcolare la distanza dall'origine
        float distanza() const { return sqrt(x * x + y * y); }

        // Metodo per calcolare la distanza da un altro punto
        float distanza(const Punto& p) const { return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y)); }
};
*/