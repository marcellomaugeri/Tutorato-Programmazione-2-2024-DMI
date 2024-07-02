/**
 * @author MoonLightLucrix
 * @link https://github.com/MoonLightLucrix
*/
#ifndef ANIMALE
#define ANIMALE

#include<iostream>
#include<cstdlib>
#include<cstring>

class Animale
{
    protected:
        std::string nome;
        float peso;
    public:

        /**
         * @brief Costruttore di default della classe Animale con parametri opzionali.
         * 
         * Questo costruttore permette di creare un oggetto Animale senza specificare nome e peso,
         * oppure di specificarli al momento della creazione. Se non specificati, il nome sarà una stringa vuota
         * e il peso sarà 0.
         * 
         * @param nome Il nome dell'animale (default: stringa vuota).
         * @param peso Il peso dell'animale in chilogrammi (default: 0).
         */
        Animale(std::string nome="", float=0);

        /**
         * @brief Distruttore della classe Animale.
         * 
         * Questo distruttore viene chiamato automaticamente quando un oggetto Animale viene distrutto.
         * Serve per rilasciare le risorse o per eseguire operazioni di pulizia specifiche della classe.
         */
        ~Animale();

        /**
         * @brief Imposta il nome dell'animale.
         * 
         * Questo metodo permette di modificare il nome dell'animale con il valore fornito.
         * 
         * @param nome Il nuovo nome da assegnare all'animale.
         */
        void setNome(std::string nome);

        /**
         * @brief Restituisce il nome dell'animale.
         * 
         * Questo metodo consente di ottenere il nome corrente dell'animale.
         * 
         * @return Il nome dell'animale come stringa.
         */
        std::string getNome() const;

        /**
         * @brief Imposta il peso dell'animale.
         * 
         * Questo metodo permette di modificare il peso dell'animale con il valore fornito.
         * 
         * @param peso Il nuovo peso da assegnare all'animale, espresso in chilogrammi.
         */
        void setPeso(float peso);

        /**
         * @brief Restituisce il peso dell'animale.
         * 
         * Questo metodo consente di ottenere il peso corrente dell'animale.
         * 
         * @return Il peso dell'animale, espresso in chilogrammi.
         */
        float getPeso() const;

        /**
         * @brief Metodo virtuale puro che restituisce il verso dell'animale.
         * 
         * Questo metodo deve essere implementato nelle classi derivate per fornire il verso specifico dell'animale.
         * 
         * @return Il verso dell'animale come stringa.
         */
        virtual std::string verso() const=0;

        /**
         * @brief Sovraccarica l'operatore < per confrontare due oggetti Animale.
         * 
         * Questo operatore determina se un oggetto Animale è "minore" di un altro basandosi prima sul loro peso.
         * Se i pesi sono diversi, l'animale con il peso minore è considerato minore. Se i pesi sono uguali,
         * si effettua un ulteriore controllo sul tipo degli animali: un Gatto è considerato minore di un Cane.
         * 
         * @param a Riferimento costante al primo oggetto Animale da confrontare.
         * @param b Riferimento costante al secondo oggetto Animale da confrontare.
         * @return true se l'oggetto a è considerato minore dell'oggetto b, false altrimenti.
         */
        friend bool operator <(const Animale&a, const  Animale&b);

        /**
         * @brief Sovraccarica l'operatore > per confrontare due oggetti Animale.
         * 
         * Questo operatore determina se un oggetto Animale è "maggiore" di un altro basandosi prima sul loro peso.
         * Se i pesi sono diversi, l'animale con il peso maggiore è considerato maggiore. Se i pesi sono uguali,
         * si effettua un ulteriore controllo sul tipo degli animali: un Cane è considerato maggiore di un Gatto.
         * 
         * @param a Riferimento costante al primo oggetto Animale da confrontare.
         * @param b Riferimento costante al secondo oggetto Animale da confrontare.
         * @return true se l'oggetto a è considerato maggiore dell'oggetto b, false altrimenti.
         */
        friend bool operator >(const Animale&a, const Animale&b);

        /**
         * @brief Sovraccarica l'operatore <= per confrontare due oggetti Animale.
         * 
         * Questo operatore determina se un oggetto Animale è "minore o uguale" a un altro. Un oggetto Animale è considerato
         * minore o uguale a un altro se il suo peso è minore o uguale al peso dell'altro oggetto, o, in caso di peso uguale,
         * se l'oggetto è di un tipo considerato minore o uguale secondo specifiche regole di dominio (ad esempio, tra tipi specifici di animali).
         * 
         * @param a Riferimento costante al primo oggetto Animale da confrontare.
         * @param b Riferimento costante al secondo oggetto Animale da confrontare.
         * @return true se l'oggetto a è considerato minore o uguale all'oggetto b, false altrimenti.
         */
        friend bool operator <=(const Animale&a, const  Animale&b);

        /**
         * @brief Sovraccarica l'operatore >= per confrontare due oggetti Animale.
         * 
         * Questo operatore determina se un oggetto Animale è "maggiore o uguale" a un altro. Un oggetto Animale è considerato
         * maggiore o uguale a un altro se il suo peso è maggiore o uguale al peso dell'altro oggetto, o, in caso di peso uguale,
         * se l'oggetto è di un tipo considerato maggiore o uguale secondo specifiche regole di dominio (ad esempio, tra tipi specifici di animali).
         * 
         * @param a Riferimento costante al primo oggetto Animale da confrontare.
         * @param b Riferimento costante al secondo oggetto Animale da confrontare.
         * @return true se l'oggetto a è considerato maggiore o uguale all'oggetto b, false altrimenti.
         */
        friend bool operator >=(const Animale&a, const Animale&b);

        /**
         * @brief Sovraccarica l'operatore != per confrontare due oggetti Animale.
         * 
         * Determina se due oggetti Animale sono diversi basandosi sul loro peso e tipo.
         * Utilizza l'operatore == per verificare l'uguaglianza e ne nega il risultato per determinare la disuguaglianza.
         * 
         * @param a Riferimento costante al primo oggetto Animale da confrontare.
         * @param b Riferimento costante al secondo oggetto Animale da confrontare.
         * @return true se gli oggetti sono diversi, false se sono uguali.
         */
        friend bool operator !=(const Animale&a, const Animale&b);

        /**
         * @brief Sovraccarica l'operatore == per confrontare due oggetti Animale.
         * 
         * Questo operatore determina se due oggetti Animale sono uguali. Due oggetti Animale sono considerati uguali se hanno lo stesso peso
         * e sono dello stesso tipo specifico (entrambi Cani o entrambi Gatti). La verifica del tipo specifico è realizzata tramite dynamic_cast,
         * che controlla se il puntatore all'oggetto può essere convertito in modo sicuro al tipo specificato (Cane o Gatto).
         * 
         * @param a Riferimento costante al primo oggetto Animale da confrontare.
         * @param b Riferimento costante al secondo oggetto Animale da confrontare.
         * @return true se gli oggetti hanno lo stesso peso e sono dello stesso tipo specifico, false altrimenti.
         */        
        friend bool operator ==(const Animale&a, const Animale&b);

        friend std::ostream& operator <<(std::ostream &str, const Animale&a);
};

class Gatto: public Animale
{
    public:

        /**
         * @brief Costruttore di default per la classe Gatto che permette di creare un oggetto Gatto con nome e peso opzionali.
         * 
         * Questo costruttore inizializza un nuovo oggetto Gatto. Il nome e il peso possono essere specificati; se non lo sono,
         * il nome sarà una stringa vuota e il peso sarà 0. Questo permette di creare oggetti Gatto senza dover fornire immediatamente
         * tutti i dettagli.
         * 
         * @param nome Il nome del gatto come stringa. Il valore di default è una stringa vuota.
         * @param peso Il peso del gatto come numero in virgola mobile. Il valore di default è 0.
         */
        Gatto(std::string nome="", float peso=0);

        /**
         * @brief Distruttore per la classe Gatto.
         * 
         * Questo distruttore viene chiamato automaticamente quando un oggetto Gatto viene distrutto, sia a causa dell'uscita dallo scope
         * che se eliminato esplicitamente tramite delete. È responsabile della pulizia delle risorse allocate dinamicamente all'interno
         * dell'oggetto, se presenti. Per la classe Gatto, questo distruttore è attualmente implementato come distruttore di default,
         * ma può essere personalizzato per eseguire operazioni di pulizia specifiche se necessario in futuro.
         */
        ~Gatto();

        /**
         * @brief Restituisce il verso caratteristico di un gatto.
         * 
         * Questo metodo sovrascrive il metodo virtuale puro `verso` nella classe base `Animale`. Quando invocato su un oggetto di tipo Gatto,
         * restituisce una stringa che rappresenta il verso di un gatto, in questo caso "Miao!".
         * 
         * @return Una stringa che rappresenta il verso di un gatto.
         */
        std::string verso() const override;
};

class Cane: public Animale
{
    public:

        /**
         * @brief Costruttore di default per la classe Cane che permette di creare un oggetto Cane con nome e peso opzionali.
         * 
         * Questo costruttore inizializza un nuovo oggetto Cane. Il nome e il peso possono essere specificati; se non lo sono,
         * il nome sarà una stringa vuota e il peso sarà 0. Questo permette di creare oggetti Cane senza dover fornire immediatamente
         * tutti i dettagli.
         * 
         * @param nome Il nome del cane come stringa. Il valore di default è una stringa vuota.
         * @param peso Il peso del cane come numero in virgola mobile. Il valore di default è 0.
         */
        Cane(std::string nome="", float peso=0);

        /**
         * @brief Distruttore per la classe Cane.
         * 
         * Questo distruttore viene chiamato automaticamente quando un oggetto Cane viene distrutto, sia a causa dell'uscita dallo scope
         * che se eliminato esplicitamente tramite delete. È responsabile della pulizia delle risorse allocate dinamicamente all'interno
         * dell'oggetto, se presenti. Per la classe Cane, questo distruttore è attualmente implementato come distruttore di default.
         */
        ~Cane();

        /**
         * @brief Restituisce il verso caratteristico di un cane.
         * 
         * Questo metodo sovrascrive il metodo virtuale puro `verso` nella classe base `Animale`. Quando invocato su un oggetto di tipo Cane,
         * restituisce una stringa che rappresenta il verso di un cane, in questo caso "Bau!".
         * 
         * @return Una stringa che rappresenta il verso di un cane.
         */
        std::string verso() const override;
};

#endif