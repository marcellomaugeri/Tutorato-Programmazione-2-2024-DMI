/**
 * @author MoonLightLucrix
 * @link https://github.com/MoonLightLucrix
*/
#ifndef LISTA
#define LISTA

template<class T>
class Nodo
{
    private:
        Nodo<T>*succ;
        T info;
    public:

        /**
         * @brief Costruttore di Nodo.
         * 
         * Questo costruttore crea un nuovo nodo con l'informazione data e i puntatori al nodo successivo e precedente.
         * Se non vengono forniti puntatori al nodo successivo e precedente, vengono impostati a `nullptr`.
         * 
         * @param info L'informazione da memorizzare nel nodo.
         * @param succ Il puntatore al nodo successivo. Default è `nullptr`.
         */
        Nodo<T>(T info, Nodo<T>*succ=nullptr);

        /**
         * @brief Distruttore di Nodo.
         * 
         * Questo distruttore elimina il nodo.
         */
        ~Nodo<T>();

        /**
         * @brief Imposta il puntatore al nodo successivo.
         * 
         * Questo metodo imposta il puntatore al nodo successivo.
         * 
         * @param succ Il puntatore al nodo successivo.
         */
        void setSucc(Nodo<T>*succ);

        /**
         * @brief Restituisce il puntatore al nodo successivo.
         * 
         * Questo metodo restituisce il puntatore al nodo successivo.
         * 
         * @return Il puntatore al nodo successivo.
         */
        Nodo<T>*getSucc() const;

        /**
         * @brief Imposta l'informazione del nodo.
         * 
         * Questo metodo imposta l'informazione del nodo.
         * 
         * @param info L'informazione da memorizzare nel nodo.
         */
        void setInfo(T info);

        /**
         * @brief Restituisce l'informazione del nodo.
         * 
         * Questo metodo restituisce l'informazione del nodo.
         * 
         * @return L'informazione del nodo.
         */
        T getInfo() const;
};

template<class T>
class Iterator
{
    private:
        Nodo<T>*a;
    public:

        /**
         * @brief Costruttore di Iterator.
         * 
         * Questo costruttore crea un nuovo iteratore che punta al nodo fornito.
         * Se non viene fornito alcun nodo, l'iteratore punta a `nullptr`.
         * 
         * @param a Il nodo a cui l'iteratore dovrebbe puntare. Default è `nullptr`.
         */
        Iterator<T>(Nodo<T>*a=nullptr);

        /**
         * @brief Distruttore di Iterator.
         * 
         * Questo distruttore elimina l'iteratore.
         */
        ~Iterator<T>();

        /**
         * @brief Operatore di incremento prefisso.
         * 
         * Questo operatore incrementa l'iteratore al nodo successivo.
         * 
         * @return L'iteratore incrementato.
         */
        Iterator<T>& operator++();

        /**
         * @brief Operatore di dereferenziazione.
         * 
         * Questo operatore restituisce l'informazione contenuta nel nodo a cui l'iteratore sta puntando.
         * 
         * @return L'informazione contenuta nel nodo a cui l'iteratore sta puntando.
         */
        T operator*();

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

template<class T>
class Lista
{
    protected:
        Nodo<T>*testa;
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
        Nodo<T>*find(T x) const;

    public:

        /**
         * @brief Costruttore di Lista.
         * 
         * Questo costruttore crea una nuova lista vuota.
         */
        Lista<T>();

        /**
         * @brief Distruttore di Lista.
         * 
         * Questo distruttore elimina la lista.
         */
        ~Lista<T>();

        /**
         * @brief Restituisce un iteratore all'inizio della lista.
         * 
         * Questo metodo restituisce un iteratore che punta al primo nodo della lista.
         * 
         * @return Un iteratore all'inizio della lista.
         */
        Iterator<T> begin() const;

        /**
         * @brief Restituisce un iteratore alla fine della lista.
         * 
         * Questo metodo restituisce un iteratore che punta alla fine della lista.
         * 
         * @return Un iteratore alla fine della lista.
         */
        Iterator<T> end() const;
        
        /**
         * @brief Svuota la lista.
         * 
         * Questo metodo rimuove tutti i nodi dalla lista, liberando la memoria allocata per ciascuno di essi.
         * Dopo che questo metodo è stato chiamato, la lista è vuota.
         * 
         * @return Un puntatore a questa lista, che ora è vuota.
         */
        Lista<T>*clear();

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
        virtual Lista<T>*ins(T x)=0;

        /**
         * @brief Rimuove un elemento dalla lista.
         * 
         * Questo metodo rimuove un elemento dalla lista.
         * 
         * @param x L'elemento da rimuovere dalla lista.
         * @return Un puntatore alla lista.
         */
        virtual Lista<T>*adotta(T x)=0;

        /**
         * @brief Controlla se un elemento è presente nella lista.
         * 
         * Questo metodo controlla se un elemento è presente nella lista.
         * 
         * @param x L'elemento da cercare nella lista.
         * @return `true` se l'elemento è presente nella lista, `false` altrimenti.
         */
        bool contains(T x) const;

        /**
         * @brief Stampa la lista.
         * 
         * Questo metodo stampa la lista.
         */
        void stampa() const;

        template<class U>
        friend std::ostream& operator <<(std::ostream &str, const Lista<U>&a);
};

template<class T>
class OrderedLinkedList: public Lista<T>
{
    private:
        using Lista<T>::testa;
        using Lista<T>::s;
        using Lista<T>::find;
    public:
        using Lista<T>::begin;
        using Lista<T>::end;
        using Lista<T>::clear;
        using Lista<T>::getSize;
        using Lista<T>::contains;
        using Lista<T>::stampa;

        /**
         * @brief Costruttore di OrderedList.
         * 
         * Questo costruttore crea una nuova lista ordinata vuota.
         */
        OrderedLinkedList<T>();

        /**
         * @brief Distruttore di OrderedList.
         * 
         * Questo distruttore elimina la lista ordinata.
         */
        ~OrderedLinkedList<T>();

        /**
         * @brief Inserisce un elemento nella lista ordinata.
         * 
         * Questo metodo inserisce un nuovo elemento nella lista mantenendo l'ordine degli elementi.
         * L'elemento viene inserito nella posizione corretta in base al criterio di ordinamento definito per la lista.
         * 
         * @param x L'elemento da inserire nella lista.
         * @return Un puntatore alla lista dopo l'inserimento dell'elemento.
         */
        Lista<T>*ins(T x) override;

        /**
         * @brief Rimuove un elemento dalla lista ordinata.
         * 
         * Questo metodo rimuove un elemento dalla lista ordinata.
         * 
         * @param x L'elemento da rimuovere dalla lista.
         * @return Un puntatore alla lista dopo la rimozione dell'elemento.
         */
        Lista<T>*adotta(T x) override;
};

#include "Lista.cpp"

#endif
