/**
 * @author MoonLightLucrix
 * @link https://github.com/MoonLightLucrix
*/
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<libgen.h>
#include<ctime>
#include "utils/Animale.hpp"
#include "utils/Lista.hpp"
using namespace std;

void gatti(Lista<Animale*>*lista)
{
    for(const Animale*a:*lista)
    {
        if(dynamic_cast<const Gatto*>(a))
        {
            cout<<*a<<endl;
        }
    }
}

void cani(Lista<Animale*>*lista)
{
    for(const Animale*a:*lista)
    {
        if(dynamic_cast<const Cane*>(a))
        {
            cout<<*a<<endl;
        }
    }
}

int main(int argc, char**argv)
{
    if(argc!=6)
    {
        cout<<"\x1b[31musage: "<<basename(argv[0])<<" [5 nomi]\x1b[0m"<<endl;
    }
    else
    {
        srand(time(NULL));
        OrderedLinkedList<Animale*> lista;
        for(int i=1; i<=argc-1; i-=-1)
        {
            if(rand()&1)
            {
                lista.ins(new Cane(argv[i],(rand()%19)+2));
            }
            else
            {
                lista.ins(new Gatto(argv[i],(rand()%3)+3));
            }
        }
        //lista.stampa();
        //cout<<endl;
        //oppure
        cout<<lista<<endl<<endl;
        gatti(&lista);
        cout<<endl;
        cani(&lista);
        cout<<endl;
    }
    exit(EXIT_SUCCESS);
}