#ifndef LISTA
#define LISTA

#include<functional>
using namespace std;

template<class H>
class Nodo
{
    private:
        Nodo<H>*succ;
        Nodo<H>*prec;
        H info;
    public:

        /**
         * @brief Costruttore di Nodo.
         * 
         * Questo costruttore crea un nuovo nodo con l'informazione data e i puntatori al nodo successivo e precedente.
         * Se non vengono forniti puntatori al nodo successivo e precedente, vengono impostati a `nullptr`.
         * 
         * @param info L'informazione da memorizzare nel nodo.
         * @param succ Il puntatore al nodo successivo. Default è `nullptr`.
         * @param prec Il puntatore al nodo precedente. Default è `nullptr`.
         */
        Nodo<H>(H info, Nodo<H>*prec=nullptr, Nodo<H>*succ=nullptr);

        /**
         * @brief Distruttore di Nodo.
         * 
         * Questo distruttore elimina il nodo.
         */
        ~Nodo<H>();

        /**
         * @brief Imposta il puntatore al nodo precedente.
         * 
         * Questo metodo imposta il puntatore al nodo precedente.
         * 
         * @param prec Il puntatore al nodo precedente.
         */
        void setPrec(Nodo<H>*prec);

        /**
         * @brief Restituisce il puntatore al nodo precedente.
         * 
         * Questo metodo restituisce il puntatore al nodo precedente.
         * 
         * @return Il puntatore al nodo precedente.
         */
        Nodo<H>*getPrec() const;

        /**
         * @brief Imposta il puntatore al nodo successivo.
         * 
         * Questo metodo imposta il puntatore al nodo successivo.
         * 
         * @param succ Il puntatore al nodo successivo.
         */
        void setSucc(Nodo<H>*succ);

        /**
         * @brief Restituisce il puntatore al nodo successivo.
         * 
         * Questo metodo restituisce il puntatore al nodo successivo.
         * 
         * @return Il puntatore al nodo successivo.
         */
        Nodo<H>*getSucc() const;

        /**
         * @brief Imposta l'informazione del nodo.
         * 
         * Questo metodo imposta l'informazione del nodo.
         * 
         * @param info L'informazione da memorizzare nel nodo.
         */
        void setInfo(H info);

        /**
         * @brief Restituisce l'informazione del nodo.
         * 
         * Questo metodo restituisce l'informazione del nodo.
         * 
         * @return L'informazione del nodo.
         */
        H getInfo() const;
};

template<class H>
class Iterator
{
    private:
        Nodo<H>*a;
    public:

        /**
         * @brief Costruttore di Iterator.
         * 
         * Questo costruttore crea un nuovo iteratore che punta al nodo fornito.
         * Se non viene fornito alcun nodo, l'iteratore punta a `nullptr`.
         * 
         * @param a Il nodo a cui l'iteratore dovrebbe puntare. Default è `nullptr`.
         */
        Iterator<H>(Nodo<H>*a=nullptr);

        /**
         * @brief Distruttore di Iterator.
         * 
         * Questo distruttore elimina l'iteratore.
         */
        ~Iterator<H>();

        /**
         * @brief Operatore di incremento prefisso.
         * 
         * Questo operatore incrementa l'iteratore al nodo successivo.
         * 
         * @return L'iteratore incrementato.
         */
        Iterator<H>& operator++();

        /**
         * @brief Operatore di dereferenziazione.
         * 
         * Questo operatore restituisce l'informazione contenuta nel nodo a cui l'iteratore sta puntando.
         * 
         * @return L'informazione contenuta nel nodo a cui l'iteratore sta puntando.
         */
        H operator*();

        /**
         * @brief Operatore di confronto di uguaglianza.
         * 
         * Questo operatore confronta due iteratori per verificare se puntano allo stesso nodo.
         * 
         * @param b L'iteratore da confrontare.
         * @return `true` se i due iteratori puntano allo stesso nodo, `false` altrimenti.
         */
        bool operator!=(const Iterator&b);
};

template<class H>
class Lista
{
    protected:
        Nodo<H>*testa;
        size_t s;

        /**
         * @brief Trova un nodo nella lista.
         * 
         * Questo metodo cerca un nodo nella lista che contiene l'informazione fornita.
         * Se il nodo viene trovato, viene restituito un puntatore a quel nodo.
         * Se il nodo non viene trovato, viene restituito un puntatore nullo.
         * 
         * @param x L'informazione da cercare nella lista.
         * @return Un puntatore al nodo che contiene l'informazione, se trovato. Altrimenti, `nullptr`.
         */
        Nodo<H>*find(H x) const;

    public:

        /**
         * @brief Costruttore di Lista.
         * 
         * Questo costruttore crea una nuova lista vuota.
         */
        Lista<H>();

        /**
         * @brief Distruttore di Lista.
         * 
         * Questo distruttore elimina la lista.
         */
        ~Lista<H>();

        /**
         * @brief Restituisce un iteratore all'inizio della lista.
         * 
         * Questo metodo restituisce un iteratore che punta al primo nodo della lista.
         * 
         * @return Un iteratore all'inizio della lista.
         */
        Iterator<H> begin() const;

        /**
         * @brief Restituisce un iteratore alla fine della lista.
         * 
         * Questo metodo restituisce un iteratore che punta alla fine della lista.
         * 
         * @return Un iteratore alla fine della lista.
         */
        Iterator<H> end() const;
        
        /**
         * @brief Svuota la lista.
         * 
         * Questo metodo rimuove tutti i nodi dalla lista, liberando la memoria allocata per ciascuno di essi.
         * Dopo che questo metodo è stato chiamato, la lista è vuota.
         * 
         * @return Un puntatore a questa lista, che ora è vuota.
         */
        Lista<H>*clear();

        /**
         * @brief Restituisce la dimensione della lista.
         * 
         * Questo metodo restituisce la dimensione della lista.
         * 
         * @return La dimensione della lista.
         */
        size_t getSize() const;

        /**
         * @brief Aggiunge un elemento alla fine della lista.
         * 
         * Questo metodo aggiunge un elemento alla fine della lista.
         * 
         * @param x L'elemento da aggiungere alla lista.
         * @return Un puntatore alla lista.
         */
        virtual Lista<H>*ins(H x)=0;

        /**
         * @brief Rimuove un elemento dalla lista.
         * 
         * Questo metodo rimuove un elemento dalla lista.
         * 
         * @param x L'elemento da rimuovere dalla lista.
         * @return Un puntatore alla lista.
         */
        virtual Lista<H>*del(H x)=0;

        /**
         * @brief Riduce la lista a un valore.
         * 
         * Questo metodo riduce la lista a un singolo valore, utilizzando una funzione lambda.
         * 
         * @param lambda La funzione lambda da utilizzare per ridurre la lista.
         * @return Il valore ridotto della lista.
         */
        template<class T>
        T reduce(std::function<T(H,T)> lambda);

        /**
         * @brief Controlla se un elemento è presente nella lista.
         * 
         * Questo metodo controlla se un elemento è presente nella lista.
         * 
         * @param x L'elemento da cercare nella lista.
         * @return `true` se l'elemento è presente nella lista, `false` altrimenti.
         */
        bool search(H x) const;

        /**
         * @brief Stampa la lista.
         * 
         * Questo metodo stampa la lista.
         */
        void stampa() const;

        template<class T>
        friend std::ostream& operator <<(std::ostream &str, const Lista<T>&a);
};

template<class H>
class OrderedList: public Lista<H>
{
    private:
        using Lista<H>::testa;
        using Lista<H>::s;
        using Lista<H>::find;
        Nodo<H>*coda;
    public:
        using Lista<H>::begin;
        using Lista<H>::end;
        using Lista<H>::clear;
        using Lista<H>::getSize;
        using Lista<H>::reduce;
        using Lista<H>::search;
        using Lista<H>::stampa;

        /**
         * @brief Costruttore di OrderedList.
         * 
         * Questo costruttore crea una nuova lista ordinata vuota.
         */
        OrderedList<H>();

        /**
         * @brief Distruttore di OrderedList.
         * 
         * Questo distruttore elimina la lista ordinata.
         */
        ~OrderedList<H>();

        /**
         * @brief Inserisce un elemento nella lista ordinata.
         * 
         * Questo metodo inserisce un nuovo elemento nella lista mantenendo l'ordine degli elementi.
         * L'elemento viene inserito nella posizione corretta in base al criterio di ordinamento definito per la lista.
         * 
         * @param x L'elemento da inserire nella lista.
         * @return Un puntatore alla lista dopo l'inserimento dell'elemento.
         */
        Lista<H>*ins(H x) override;

        /**
         * @brief Rimuove un elemento dalla lista ordinata.
         * 
         * Questo metodo rimuove un elemento dalla lista ordinata.
         * 
         * @param x L'elemento da rimuovere dalla lista.
         * @return Un puntatore alla lista dopo la rimozione dell'elemento.
         */
        Lista<H>*del(H x) override;
};

#include "Lista.cpp"

#endif