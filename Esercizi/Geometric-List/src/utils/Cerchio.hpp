/**
 * @author MoonLightLucrix
 * @link https://github.com/MoonLightLucrix
*/
#ifndef CERCHIO
#define CERCHIO

#include<cmath>

class Cerchio
{
    private:
        double r;
        double d;
        double perimetro;
        double area;
    public:

        /**
         * @brief Costruttore della classe Cerchio con parametro opzionale.
         * 
         * Questo costruttore inizializza un oggetto Cerchio con un raggio specificato.
         * Se non viene fornito alcun valore per il raggio, il valore di default sarà 0.
         * 
         * @param r Il raggio del cerchio. Default a 0 se non specificato.
         */
        Cerchio(double r=0);

        /**
         * @brief Distruttore della classe Cerchio.
         * 
         * Questo distruttore viene chiamato automaticamente quando un oggetto Cerchio viene distrutto.
         * Si occupa di liberare le risorse allocate dall'oggetto, se necessario.
         */
        ~Cerchio();

        /**
         * @brief Imposta il raggio del cerchio e aggiorna diametro, perimetro e area.
         * 
         * Questo metodo permette di modificare il raggio del cerchio con un nuovo valore.
         * A seguito della modifica del raggio, vengono automaticamente aggiornati anche
         * il diametro, il perimetro e l'area del cerchio per mantenere la coerenza dell'oggetto.
         * 
         * @param r Il nuovo valore del raggio da impostare per il cerchio. Deve essere un valore non negativo.
         */
        void setRaggio(double r);

        /**
         * @brief Restituisce il raggio del cerchio.
         * 
         * Questo metodo consente di ottenere il valore corrente del raggio del cerchio.
         * 
         * @return Il valore del raggio del cerchio.
         */
        double getRaggio() const;

        /**
         * @brief Calcola e restituisce il diametro del cerchio.
         * 
         * Questo metodo utilizza il raggio del cerchio per calcolare il diametro.
         * Il diametro è definito come il doppio del raggio del cerchio.
         * 
         * @return Il diametro del cerchio.
         */
        double calcolaDiametro();

        /**
         * @brief Restituisce il diametro del cerchio.
         * 
         * Questo metodo consente di ottenere il valore corrente del diametro del cerchio.
         * 
         * @return Il valore del diametro del cerchio.
         */
        double getDiametro() const;

        /**
         * @brief Calcola e restituisce il perimetro del cerchio.
         * 
         * Questo metodo utilizza il raggio del cerchio per calcolare il perimetro.
         * Il perimetro è definito come la lunghezza della circonferenza del cerchio.
         * 
         * @return Il perimetro del cerchio.
         */
        double calcolaPerimetro();

        /**
         * @brief Restituisce il perimetro del cerchio.
         * 
         * Questo metodo consente di ottenere il valore corrente del perimetro del cerchio.
         * 
         * @return Il valore del perimetro del cerchio.
         */
        double getPerimetro() const;

        /**
         * @brief Calcola e restituisce l'area del cerchio.
         * 
         * Questo metodo utilizza il raggio del cerchio per calcolare l'area.
         * L'area è definita come la superficie racchiusa dalla circonferenza del cerchio.
         * 
         * @return L'area del cerchio.
         */
        double calcolaArea();

        /**
         * @brief Restituisce l'area del cerchio.
         * 
         * Questo metodo consente di ottenere il valore corrente dell'area del cerchio.
         * 
         * @return Il valore dell'area del cerchio.
         */
        double getArea() const;

        /**
         * @brief Confronta due oggetti Cerchio per determinare se il primo ha un'area minore del secondo.
         * 
         * @param a Il primo oggetto Cerchio da confrontare.
         * @param b Il secondo oggetto Cerchio da confrontare.
         * @return `true` se l'area di 'a' è minore dell'area di 'b', altrimenti `false`.
         */
        friend bool operator <(const Cerchio&a, const Cerchio&b);

        /**
         * @brief Confronta due oggetti Cerchio per determinare se il primo ha un'area maggiore del secondo.
         * 
         * @param a Il primo oggetto Cerchio da confrontare.
         * @param b Il secondo oggetto Cerchio da confrontare.
         * @return `true` se l'area di 'a' è maggiore dell'area di 'b', altrimenti `false`.
         */
        friend bool operator >(const Cerchio&a, const Cerchio&b);

        /**
         * @brief Confronta due oggetti Cerchio per determinare se il primo ha un'area minore o uguale a quella del secondo.
         * 
         * @param a Il primo oggetto Cerchio da confrontare.
         * @param b Il secondo oggetto Cerchio da confrontare.
         * @return `true` se l'area di 'a' è minore o uguale all'area di 'b', altrimenti `false`.
         */
        friend bool operator <=(const Cerchio&a, const Cerchio&b);

        /**
         * @brief Confronta due oggetti Cerchio per determinare se il primo ha un'area maggiore o uguale a quella del secondo.
         * 
         * @param a Il primo oggetto Cerchio da confrontare.
         * @param b Il secondo oggetto Cerchio da confrontare.
         * @return `true` se l'area di 'a' è maggiore o uguale all'area di 'b', altrimenti `false`.
         */
        friend bool operator >=(const Cerchio&a, const Cerchio&b);

        /**
         * @brief Confronta due oggetti Cerchio per determinare se il primo ha un'area diversa a quella del secondo.
         * 
         * @param a Il primo oggetto Cerchio da confrontare.
         * @param b Il secondo oggetto Cerchio da confrontare.
         * @return `true` se l'area di 'a' è diversa all'area di 'b', altrimenti `false`.
         */
        friend bool operator !=(const Cerchio&a, const Cerchio&b);

        /**
         * @brief Confronta due oggetti Cerchio per determinare se il primo ha un'area uguale a quella del secondo.
         * 
         * @param a Il primo oggetto Cerchio da confrontare.
         * @param b Il secondo oggetto Cerchio da confrontare.
         * @return `true` se l'area di 'a' è uguale all'area di 'b', altrimenti `false`.
         */
        friend bool operator ==(const Cerchio&a, const Cerchio&b);

        friend std::ostream& operator <<(std::ostream &str, const Cerchio&a);
};

#include "Cerchio.cpp"

#endif
