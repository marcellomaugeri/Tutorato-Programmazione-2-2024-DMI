#include<iostream>
#include<cstdlib>
#include<cstring>
#include "utils/Cerchio.hpp"
#include "utils/Lista.hpp"
#include "utils/GeometricList.hpp"
using namespace std;

int main(int argc, char**argv)
{
    //esercizio n.1
    Cerchio*a=new Cerchio(3);
    Cerchio*b=new Cerchio(2);
    Cerchio*c=new Cerchio(5);
    if(*a>*b)
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
    cout<<endl;
    if(*a<=*b)
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
    cout<<endl;
    if(*a==*c)
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
    cout<<endl;
    if(*b<=*c)
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
    cout<<endl<<endl;

    //esercizio n.2
    OrderedList<int>*o=new OrderedList<int>();

    //o->ins(3)->ins(6)->ins(10)->ins(56)->ins(8)->ins(7)->ins(21)->ins(6)->stampa();
    //cout<<endl;
    //oppure
    cout<<*o->ins(3)->ins(6)->ins(10)->ins(56)->ins(8)->ins(7)->ins(21)->ins(6)<<endl;

    //o->del(56)->del(21)->del(3)->del(6)->ins(34)->ins(100)->stampa();
    //cout<<endl;
    //oppure
    cout<<*o->del(56)->del(21)->del(3)->del(6)->ins(34)->ins(100)<<endl;

    delete o;
    cout<<endl;
    
    //esercizio n.3
    GeometricList*g=new GeometricList();
    g->ins(*a)->ins(*b)->ins(*c)->stampa();
    cout<<endl;
    cout<<"Media: "<<g->mediaArea()<<endl;
    delete g;
    delete a;
    delete b;
    delete c;
    exit(EXIT_SUCCESS);
}