template <class T>
class Node {
    private:
        T data;
        Node<T>* next;
        Node<T>* prev;
    public:
        Node<T>(T data) {
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }

        void setData(T data) {
            this->data = data;
        }
        T getData() {
            return this->data;
        }
        Node<T>* getNext() {
            return this->next;
        }
        Node<T>* getPrev() {
            return this->prev;
        }
        void setNext(Node<T>* next) {
            this->next = next;
        }
        void setPrev(Node<T>* prev) {
            this->prev = prev;
        }

    
    
};

template <class T>
class DoubleLinkedList {

    Node<T>* header;
    Node<T>* trailer;

    public:
        DoubleLinkedList() {
            header = new Node<T>(T());
            trailer = new Node<T>(T());
            header->setNext(trailer);
            trailer->setPrev(header);
        }

        void addFirst(T data) {
            Node<T>* newNode = new Node<T>(data);
            newNode->setNext(header->getNext());
            newNode->setPrev(header);
            header->getNext()->setPrev(newNode);
            header->setNext(newNode);
        }

        void addLast(T data) {
            Node<T>* newNode = new Node<T>(data);
            newNode->setNext(trailer);
            newNode->setPrev(trailer->getPrev());
            trailer->getPrev()->setNext(newNode);
            trailer->setPrev(newNode);
        }

        void remove(T data){
            Node<T>* current = header->getNext();
            while(current != trailer){
                if(current->getData() == data){
                    current->getPrev()->setNext(current->getNext());
                    current->getNext()->setPrev(current->getPrev());
                    delete current;
                    return;
                }
                current = current->getNext();
            }
        }

};