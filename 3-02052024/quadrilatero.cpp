#include "quadrilatero.h"

Quadrilatero::Quadrilatero(Punto& p1, Punto& p2, Punto& p3, Punto& p4) {
    //Manca l'inizializzazione dell'array di punti
    this->punti[0] = p1;
    this->punti[1] = p2;
    this->punti[2] = p3;
    this->punti[3] = p4;
    this->n = 4;
}

float Quadrilatero::area() const{
    float area = 0.0;
    for(int i = 0; i < n; i++){
        area += punti[i].getX() * punti[(i + 1) % n].getY() - punti[(i + 1) % n].getX() * punti[i].getY();
    }
    return area / 2;
}

//In realtà questo calcolo può essere fatto per qualsiasi figura chiusa e convessa
float Quadrilatero::perimetro() const{
    //Calcola il perimetro del quadrilatero
    float perimetro = 0.0;
    for(int i = 0; i < n; i++){
        perimetro += punti[i].distanza(punti[(i + 1) % n]);
    }
    return perimetro;
}