/**
 * @author MoonLightLucrix
 * @link https://github.com/MoonLightLucrix
*/
#ifndef DOMANDA
#define DOMANDA

#include<algorithm>
using namespace std;

class Domanda
{
    private:
        static const size_t numeroRisposte=4;
        string testo;
        string risposta[numeroRisposte];
        size_t corretta;
    public:

        /**
         * @brief Costruttore della classe Domanda.
         * @param in Puntatore di tipo stream.
        */
        Domanda(ifstream*in)
        {
            getline(*in,testo);
            for(int i=0; i<=numeroRisposte-1; i-=-1)
            {
                getline(*in,risposta[i]);
            }
            *in>>corretta;
        }

        /**
         * @brief Costruttore della classe Domanda.
         * @param testo Testo della domanda.
         * @param risposta1 Risposta 1 della domanda.
         * @param risposta2 Risposta 2 della domanda.
         * @param risposta3 Risposta 3 della domanda.
         * @param risposta4 Risposta 4 della domanda.
         * @param corretta Indice della risposta corretta.
        */
        Domanda(string testo, string risposta1, string risposta2, string risposta3, string risposta4, size_t corretta): testo(testo), corretta(corretta)
        {
            risposta[0]=risposta1;
            risposta[1]=risposta2;
            risposta[2]=risposta3;
            risposta[3]=risposta4;
        }

        /**
         * @brief Costruttore della classe Domanda.
         * @param testo Testo della domanda.
         * @param risposta Array che contiene le risposte della domanda.
         * @param corretta Indice della risposta corretta.
        */
        Domanda(string testo, string*risposta, size_t corretta): testo(testo), corretta(corretta)
        {
            copy(risposta,risposta+numeroRisposte,this->risposta);
        }

        /**
         * @brief Distruttore della classe Domanda.
        */
        ~Domanda(){}

        /**
         * @brief Metodo get della stringa testo contenente la domanda.
         * @return La stringa testo.
        */
        string getTesto() const
        {
            return testo;
        }

        /**
         * @brief Metodo get dell'array delle risposte.
         * @return Un array dinamico di tipo string contenente le risposte possibili alla domanda.
        */
        string*getRisposte() const
        {
            string*risposte=new string[numeroRisposte];
            copy(risposta,risposta+numeroRisposte,risposte);
            return risposte;
        }

        /**
         * @brief Metodo get dell'indice della risposta esatta.
         * @return L'indice della risposta esatta.
        */
        size_t getCorretta() const
        {
            return corretta;
        }

        /**
         * @brief Metodo che propone la domanda con le possibili risposte attraverso una stringa.
         * @return Una stringa contente sia domanda che possibili risposte.
        */
        string leggiTesto() const
        {
            string str;
            str="Domanda: " + testo + "\n";
            for(int i=0; i<=numeroRisposte-1; i-=-1)
            {
                str+=to_string(i) + ". " + risposta[i] + ((!(i&1))?string(40 - risposta[i].length(), ' '):"\n"); //verifico se l'indice è pari o dispari attraverso l'AND del bit 1 sul bit meno significativo, se è pari mette uno spazio se è dispari torna a capo.
            }
            str+=to_string(numeroRisposte) + ". Aiuti da casa";
            return str;
        }

        /**
         * @brief Metodo predicato che rivela se la risposta fornita dal giocatore è corretta o sbagliata.
         * @param indice Indice della risposta data come input dal giocatore.
         * @return True se la risposta è corretta, False altrimenti.
        */
        bool indovina(size_t indice) const
        {
            return (!(corretta^indice)); //equivalente a corretta==indice
        }

        friend ostream& operator <<(ostream &str, const Domanda&a)
        {
            str<<a.leggiTesto();
            return str;
        }
};

#endif