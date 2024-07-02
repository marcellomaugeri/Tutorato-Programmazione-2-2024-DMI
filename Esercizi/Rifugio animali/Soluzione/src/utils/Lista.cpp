/**
 * @author MoonLightLucrix
 * @link https://github.com/MoonLightLucrix
*/
template<class T>
Nodo<T>::Nodo(T info, Nodo<T>*succ): info(info), succ(succ) {}

template<class T>
Nodo<T>::~Nodo(){}

template<class T>
void Nodo<T>::setSucc(Nodo<T>*succ)
{
    this->succ=succ;
}

template<class T>
Nodo<T>* Nodo<T>::getSucc() const
{
    return succ;
}

template<class T>
void Nodo<T>::setInfo(T info)
{
    this->info=info;
}

template<class T>
T Nodo<T>::getInfo() const
{
    return info;
}

template<class T>
Iterator<T>::Iterator(Nodo<T>*a): a(a) {}

template<class T>
Iterator<T>::~Iterator(){}

template<class T>
Iterator<T>& Iterator<T>::operator++()
{
    a=a->getSucc();
    return *this;
}

template<class T>
T Iterator<T>::operator*()
{
    return a->getInfo();
}

template<class T>
bool Iterator<T>::operator!=(const Iterator<T>&b)
{
    return (a!=b.a);
}

template<class T>
Lista<T>::Lista(): testa(nullptr), s(0) {}

template<class T>
Lista<T>::~Lista()
{
    clear();
}

template<class T>
Nodo<T>*Lista<T>::find(T x) const
{
    Nodo<T>*a;
    for(a=testa; a; a=a->getSucc())
    {
        if(*a->getInfo()==*x)
        {
            break;
        }
    }
    return a;
}

template<class T>
Iterator<T> Lista<T>::begin() const
{
    return Iterator<T>(testa);
}

template<class T>
Iterator<T> Lista<T>::end() const
{
    return Iterator<T>();
}

template<class T>
Lista<T>* Lista<T>::clear()
{
    Nodo<T>*a;
    while(testa)
    {
        a=testa;
        testa=testa->getSucc();
        delete a;
        s-=1;
    }
    return this;
}

template<class T>
size_t Lista<T>::getSize() const
{
    return s;
}

template<class T>
bool Lista<T>::contains(T x) const
{
    return (find(x));
}

template<class T>
void Lista<T>::stampa() const
{
    Nodo<T>*a;
    std::cout<<"[";
    for(a=testa; a; a=a->getSucc())
    {
        std::cout<<*a->getInfo()<<((a->getSucc())?", ":"");
    }
    std::cout<<"]";
}

template<class T>
std::ostream& operator <<(std::ostream &str, const Lista<T>&a)
{
    a.stampa();
    return str;
}

template<class T>
OrderedLinkedList<T>::OrderedLinkedList(){}

template<class T>
OrderedLinkedList<T>::~OrderedLinkedList(){}

template<class T>
Lista<T>* OrderedLinkedList<T>::ins(T x)
{
    Nodo<T>*a=new Nodo<T>(x);
    if(!s)
    {
        testa=a;
    }
    else
    {
        if(*x<=*testa->getInfo())
        {
            a->setSucc(testa);
            testa=a;
        }
        else
        {
            Nodo<T>*b;
            bool min;
            for(b=testa; b->getSucc(); b=b->getSucc())
            {
                if((min=(*x<=*b->getSucc()->getInfo())))
                {
                    a->setSucc(b->getSucc());
                    b->setSucc(a);
                    break;
                }
            }
            if(!min)
            {
                b->setSucc(a);
                a->setSucc(nullptr);
            }
        }
    }
    s-=-1;
    return this;
}

template<class T>
Lista<T>* OrderedLinkedList<T>::adotta(T x)
{
    Nodo<T>*a=find(x);
    if(a)
    {
        if(a==testa)
        {
            testa=testa->getSucc();
        }
        else
        {
            Nodo<T>*b;
            for(b=testa; b->getSucc()==a; b=b->getSucc()){}
            b->setSucc(a->getSucc());
        }
        delete a;
        s-=1;
    }
    return this;
}
