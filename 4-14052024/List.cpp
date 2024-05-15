/*
    DISCLAIMER: Questo codice è stato scritto in maniera veloce durante la lezione del 14/05/2024, per cui, non rappresenta la versione definitiva e ottimizzata del codice.
    Pertanto, si sconsiglia di utilizzarlo come riferimento per gli esami, quanto piuttosto per comprendere i concetti base.
*/

template <class T>
class List{
    private:
        Node<T>* head;

    public:
        List(){
            head = nullptr;
        }

        //Inserimento in testa, ci sono due casi: lista vuota e lista non vuota
        //Nel caso della lista non vuota, il nuovo nodo diventa diventa la nuova testa, mentre il successivo della nuova testa è l'attuale testa
        //Nel caso della lista vuota, il nuovo nodo diventa la testa
        void insertHead(T elem){
            Node<T>* nuovoNodo = new Node<T>(elem);
            if(this->isEmpty()){
                //Lista vuota
                head = nuovoNodo;
            } else {
                //Lista non vuota;
                nuovoNodo->setSucc(head);
                head = nuovoNodo;
            }
        }

        //Inserimento in coda, ci sono due casi: lista vuota e lista non vuota
        //Nel caso della lista non vuota, scorro la lista fino a trovare l'ultimo nodo e lo collego al nuovo nodo
        //Nel caso della lista vuota, il nuovo nodo diventa la testa
        void insertTail(T elem){
            Node<T>* nuovoNodo = new Node<T>(elem);
            if(this->isEmpty()){
                //Lista vuota
                head = nuovoNodo;
            } else {
                //Lista non vuota
                Node<T>* temp = head;
                while(temp->getSucc() != nullptr){
                    temp = temp->getSucc();
                }
                temp->setSucc(nuovoNodo);
            }
        }

        //Implementazione alternativa dell'inserimento in coda. In questo caso, utilizzo due puntatori, uno che scorre la lista e uno che tiene traccia del nodo precedente
        void insertTailAlternative(T elem){
            Node<T>* nuovoNodo = new Node<T>(elem);
            if(this->isEmpty()){
                //Lista vuota
                head = nuovoNodo;
            } else {
                //Lista non vuota
                Node<T>* p2 = head;
                Node<T>* p1 = nullptr;
                while(p2 != nullptr){
                    p1 = p2;
                    p2 = p2->getSucc();
                }
                //All'uscita da questo ciclo, p2 sarà nullo mentre p1 sarà l'ultimo nodo della lista
                p1->setSucc(nuovoNodo);
            }
        }

        //Inserimento ordinato, ci sono tre casi: lista vuota, lista con un solo elemento e lista con almeno due elementi
        //(ATTENZIONE: il codice può essere semplificato di molto, ma è stato scritto in questo modo per rendere più chiaro il concetto
        void insertOrdered(T elem){
            Node<T>* nuovoNodo = new Node<T>(elem);
            if(this->isEmpty()){
                //Lista vuota
                head = nuovoNodo;
            } else {
                //Lista con un solo elemento
                if(head->getSucc() == nullptr){
                    if(head->getElem() > elem){
                        nuovoNodo->setSucc(head);
                        head = nuovoNodo;
                    } else {
                        head->setSucc(nuovoNodo);
                    }
                } else {
                    //Lista con almeno due elementi, scorro la lista fino a trovare il nodo che ha un elemento maggiore di quello da inserire
                    //Suggerimento: invertire il segno per avere una lista ordinata in modo decrescente
                    Node<T>* p1 = nullptr;
                    Node<T>* p2 = head;
                    while(p2 != nullptr && p2->getElem() < elem){
                        p1 = p2;
                        p2 = p2->getSucc();
                    }
                    //Caso 0: il nuovo nodo va in testa perché è minore di tutti gli altri
                    if(p1 == nullptr){
                        nuovoNodo->setSucc(head);
                        head = nuovoNodo;
                    } else if (p2 == nullptr){ //Caso 1: il nodo va in coda perché è maggiore di tutti gli altri
                        p1->setSucc(nuovoNodo);
                    } else { //Caso 2: caso generale, siamo da qualche parte in mezzo alla lista
                        p1->setSucc(nuovoNodo);
                        nuovoNodo->setSucc(p2);
                    }
                }
            }   
        }

        //Verifica se la lista è vuota. In particolare, restituisce true se la testa è un puntatore nullo
        bool isEmpty(){
            return head == nullptr;
        }

        //Stampa la lista scorrendo tutti i nodi attraverso l'uso di un nodo temporaneo che inizialmente punta alla testa
        void print(){
            Node<T>* temp = head;
            while(temp != nullptr){
                //Visualizza l'elemento
                std::cout << temp->getElem() << " ";
                //Sposto il puntatore del nodo temporaneo al suo successivo
                temp = temp->getSucc();
            }
            std::cout << std::endl;
        }
};