#include "quadrato.h"

Quadrato::Quadrato(Punto& p1, Punto& p2, Punto& p3, Punto& p4) : Quadrilatero(p1, p2, p3, p4) {
    // Controllo che il quadrato sia tale
    float lato = punti[0].distanza(punti[1]);
    for(int i = 1; i < n; i++){
        if(punti[i].distanza(punti[(i + 1) % n]) != lato){
            throw "I punti non formano un quadrato";
        }
    }
}