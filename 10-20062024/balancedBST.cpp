/*
Classe BST, attraverso l'utilizzo dei template, in cui le chiavi duplicate vengono inserite nei sottoalberi destro e sinistro della chiave già presente nel BST in modo alternato.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

template <class T>
class Node {
    private:
        T key;
        Node<T> *left, *right, *parent;
    
    public:
        // Costruttore
        Node(T key = T()) : key(key), left(NULL), right(NULL), parent(NULL) {}

        // Distruttore
        ~Node() {
            delete left;
            delete right;
            delete parent;
        }

        // Getters
        T getKey() {
            return key;
        }

        Node<T>* getLeft() {
            return left;
        }

        Node<T>* getRight() {
            return right;
        }

        Node<T>* getParent() {
            return parent;
        }

        // Setters
        void setKey(T key) {
            this->key = key;
        }

        void setLeft(Node<T>* left) {
            this->left = left;
        }

        void setRight(Node<T>* right) {
            this->right = right;
        }

        void setParent(Node<T>* parent) {
            this->parent = parent;
        }

        // Overload operatore ==
        bool operator==(Node<T>& n) {
            return key == n.getKey(); // Ritorna true se le chiavi sono uguali
        }

        // Overload operatore >
        bool operator>(Node<T>& n) {
            return key > n.getKey(); // Ritorna true se la chiave è maggiore
        }

        // Overload operatore <
        bool operator<(Node<T>& n) {
            return key < n.getKey(); // Ritorna true se la chiave è minore
        }

        // Overload operatore << con friend
        // Implica che l'oggetto in questione venga visto come argomento (vedi Node<T> n)
        friend ostream& operator<<(ostream& os, Node<T>* n) {
            os << n->getKey();
            return os;
        }
};

template <class T>
class BalancedBST {
    private:
        Node<T>* root;

    public:
        // Costruttore
        BalancedBST() {
            root = NULL;
        }

        //Inserimento di un nodo iterativo, ricordiamo che le chiavi duplicate vengono inserite nei sottoalberi destro e sinistro della chiave già presente nel BST in modo alternato
        void insert(T key){
            Node<T>* newNode = new Node<T>(key);
            Node<T>* current = root;
            // Bool per inserire a destra o sinistra
            bool insertOnRight = false;
            // Albero vuoto
            if(current == NULL) {
                root = newNode;
                return;
            }
            while(current != NULL){
                // Chiave uguale all'elemento corrente
                if(*newNode == *current) { // Chiama l'overload dell'operatore sul nodo
                    if(insertOnRight) {
                        if(current->getRight() == NULL) {
                            current->setRight(newNode);
                            newNode->setParent(current);
                            return;
                        } else {
                            current = current->getRight();
                        }
                    } else {
                        if(current->getLeft() == NULL) {
                            current->setLeft(newNode);
                            newNode->setParent(current);
                            return;
                        } else {
                            current = current->getLeft();
                        }
                    }
                    insertOnRight = !insertOnRight;
                }
                // Chiave più piccola dell'elemento corrente
                else if(*newNode < *current) { // Chiama l'overload dell'operatore sul nodo
                    if(current->getLeft() == NULL) {
                        current->setLeft(newNode);
                        newNode->setParent(current);
                        return;
                    } else {
                        current = current->getLeft();
                    }
                } else {
                    if(current->getRight() == NULL) {
                        current->setRight(newNode);
                        newNode->setParent(current);
                        return;
                    } else {
                        current = current->getRight();
                    }
                }
            }
        }

        // Stampa in-order
        void _inorder(Node<T>* node) {
            if(node == NULL) {
                return;
            }
            _inorder(node->getLeft());
            cout << node << " ";
            _inorder(node->getRight());
        }

        // Stampa in-order
        void inorder() {
            _inorder(root);
            cout << endl;
        }

        // Stampa post-order
        void _postorder(Node<T>* node) {
            if(node == NULL) {
                return;
            }
            _postorder(node->getLeft());
            _postorder(node->getRight());
            cout << node << " ";
        }

        // Stampa post-order
        void postorder() {
            _postorder(root);
            cout << endl;
        }
};

int main() {
    srand(20);
    BalancedBST<int> bst;
    //vector<int> keys;
    for(int i=0; i<20; i++){
        bst.insert(rand() % 100);
    }
    cout << "Inorder: ";
    bst.inorder();
    cout << "Postorder: ";
    bst.postorder();
}