#ifndef PUNTO_H
#define PUNTO_H

class Punto {
    private:
        // Coordinate del punto
        float x;
        float y;

    public:
        // Costruttore per impostare le coordinate iniziali
        Punto(float x, float y);
        // Costruttore che copia un punto
        Punto(const Punto& p);

        // Metodi per accedere alle coordinate
        float getX() const;
        float getY() const;

        // Metodi per impostare le coordinate
        void setX(float x);
        void setY(float y);

        // Metodo per calcolare la distanza dall'origine
        float distanzaOrigine() const;

        // Metodo per calcolare la distanza da un altro punto
        float distanza(const Punto& p) const;
};

#endif