/*
    DISCLAIMER: Questo codice è stato scritto in maniera veloce durante la lezione del 14/05/2024, per cui, non rappresenta la versione definitiva e ottimizzata del codice.
    Pertanto, si sconsiglia di utilizzarlo come riferimento per gli esami, quanto piuttosto per comprendere i concetti base.
*/

template <class T>
class Node{
    private:
        T elem;
        Node<T>* succ;
    
    public:
        //Costruttore di default, quindi il successivo è un puntatore nullo
        Node(){
            succ = nullptr;
        }

        //Costruttore con l'inserimento dell'elemento, il più utilizzato
        Node(T elem){
            this->elem = elem;
            succ = nullptr;
        }

        //Costruttore in cui viene inserito anche il successivo, ha senso solo nell'implementazione della lista con inserimento in testa
        Node(T elem, Node<T>* succ){
            this->elem = elem;
            this->succ = succ;
        }

        //Getter e setter dell'elemento
        T getElem(){
            return elem;
        }
        void setElem(T elem){
            this->elem = elem;
        }

        //Getter e setter del successivo
        Node<T>* getSucc(){
            return succ;
        }
        void setSucc(Node<T>* succ){
            this->succ = succ;
        }
};