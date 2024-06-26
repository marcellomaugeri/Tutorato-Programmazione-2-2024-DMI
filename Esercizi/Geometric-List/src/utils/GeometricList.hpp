#ifndef GEOMETRICLIST
#define GEOMETRICLIST

class GeometricList
{
    private:
        OrderedList<Cerchio> l;
    public:

        /**
         * @brief Costruttore di default per la classe GeometricList.
         * 
         * Inizializza una nuova istanza della classe GeometricList.
         * La lista viene inizializzata vuota, pronta per accogliere elementi di tipo Cerchio.
         */
        GeometricList();

        /**
         * @brief Distruttore della classe GeometricList.
         * 
         * Distrugge l'istanza della classe GeometricList.
         * Tutti gli elementi presenti nella lista vengono eliminati.
         */
        ~GeometricList();

        /**
         * @brief Inserisce un cerchio nella lista.
         * 
         * Questo metodo consente di inserire un cerchio nella lista.
         * 
         * @param c Il cerchio da inserire nella lista.
         * @return Un puntatore al tipo GeometricList.
         */
        GeometricList*ins(Cerchio c);

        /**
         * @brief Calcola la media delle aree dei cerchi presenti nella lista.
         * 
         * Questo metodo calcola la media delle aree dei cerchi presenti nella lista.
         * 
         * @return La media delle aree dei cerchi presenti nella lista.
         */
        double mediaArea();

        /**
         * @brief Stampa la lista di cerchi.
         * 
         * Questo metodo stampa la lista di cerchi.
         */
        void stampa();
};

#include "GeometricList.cpp"

#endif