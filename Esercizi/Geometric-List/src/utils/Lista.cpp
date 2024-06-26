/**
 * @author MoonLightLucrix
 * @link https://github.com/MoonLightLucrix
*/
template<class H>
Nodo<H>::Nodo(H info, Nodo<H>*prec, Nodo<H>*succ): info(info), prec(prec), succ(succ) {}

template<class H>
Nodo<H>::~Nodo(){}

template<class H>
void Nodo<H>::setPrec(Nodo<H>*prec)
{
    this->prec=prec;
}

template<class H>
Nodo<H>* Nodo<H>::getPrec() const
{
    return prec;
}

template<class H>
void Nodo<H>::setSucc(Nodo<H>*succ)
{
    this->succ=succ;
}

template<class H>
Nodo<H>* Nodo<H>::getSucc() const
{
    return succ;
}

template<class H>
void Nodo<H>::setInfo(H info)
{
    this->info=info;
}

template<class H>
H Nodo<H>::getInfo() const
{
    return info;
}

template<class H>
Iterator<H>::Iterator(Nodo<H>*a): a(a) {}

template<class H>
Iterator<H>::~Iterator(){}

template<class H>
Iterator<H>& Iterator<H>::operator++()
{
    a=a->getSucc();
    return *this;
}

template<class H>
H Iterator<H>::operator*()
{
    return a->getInfo();
}

template<class H>
bool Iterator<H>::operator!=(const Iterator<H>&b)
{
    return (a!=b.a);
}

template<class H>
Lista<H>::Lista(): testa(nullptr), s(0) {}

template<class H>
Lista<H>::~Lista()
{
    clear();
}

template<class H>
Nodo<H>*Lista<H>::find(H x) const
{
    Nodo<H>*a;
    for(a=testa; a; a=a->getSucc())
    {
        if(a->getInfo()==x)
        {
            break;
        }
    }
    return a;
}

template<class H>
Iterator<H> Lista<H>::begin() const
{
    return Iterator<H>(testa);
}

template<class H>
Iterator<H> Lista<H>::end() const
{
    return Iterator<H>();
}

template<class H>
Lista<H>* Lista<H>::clear()
{
    Nodo<H>*a;
    while(testa)
    {
        a=testa;
        testa=testa->getSucc();
        delete a;
        s-=1;
    }
    return this;
}

template<class H>
size_t Lista<H>::getSize() const
{
    return s;
}

template<class H>
template<class T>
T Lista<H>::reduce(std::function<T(H,T)> lambda)
{
    T accumulator=T();
    Nodo<H>*a;
    for(a=testa; a; a=a->getSucc())
    {
        accumulator=lambda(a->getInfo(),accumulator);
    }
    return accumulator;
}

template<class H>
bool Lista<H>::search(H x) const
{
    return (find(x));
}

template<class H>
void Lista<H>::stampa() const
{
    Nodo<H>*a;
    std::cout<<"[";
    for(a=testa; a; a=a->getSucc())
    {
        std::cout<<a->getInfo()<<((a->getSucc())?", ":"");
    }
    std::cout<<"]";
}

template<class H>
std::ostream& operator <<(std::ostream &str, const Lista<H>&a)
{
    a.stampa();
    return str;
}

template<class H>
OrderedList<H>::OrderedList(): Lista<H>(), coda(nullptr) {}

template<class H>
OrderedList<H>::~OrderedList(){}

template<class H>
Lista<H>* OrderedList<H>::ins(H x)
{
    Nodo<H>*a=new Nodo<H>(x);
    if(!s)
    {
        testa=coda=a;
    }
    else
    {
        if(x<=testa->getInfo())
        {
            a->setSucc(testa);
            testa->setPrec(a);
            a->setPrec(nullptr);
            testa=a;
        }
        else if(coda->getInfo()<=x)
        {
            a->setPrec(coda);
            coda->setSucc(a);
            a->setSucc(nullptr);
            coda=a;
        }
        else
        {
            for(Nodo<H>*b=testa; b->getSucc(); b=b->getSucc())
            {
                if(x<=b->getSucc()->getInfo())
                {
                    a->setSucc(b->getSucc());
                    a->setPrec(b);
                    b->getSucc()->setPrec(a);
                    b->setSucc(a);
                    break;
                }
            }
        }
    }
    s-=-1;
    return this;
}

template<class H>
Lista<H>* OrderedList<H>::del(H x)
{
    Nodo<H>*a=find(x);
    if(a)
    {
        if(a==testa)
        {
            testa=testa->getSucc();
            testa->setPrec(nullptr);
        }
        else if(a==coda)
        {
            coda=coda->getPrec();
            coda->setSucc(nullptr);
        }
        else
        {
            a->getPrec()->setSucc(a->getSucc());
            a->getSucc()->setPrec(a->getPrec());
        }
        delete a;
        s-=1;
    }
    return this;
}
