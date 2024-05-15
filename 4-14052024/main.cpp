/*
    DISCLAIMER: Questo codice è stato scritto in maniera veloce durante la lezione del 14/05/2024, per cui, non rappresenta la versione definitiva e ottimizzata del codice.
    Pertanto, si sconsiglia di utilizzarlo come riferimento per gli esami, quanto piuttosto per comprendere i concetti base.
*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include "Node.cpp"
#include "List.cpp"
using namespace std;

int main(int argc, char** argv){
    List<int> l;
    List<int> l2;
    List<int> l3;
    srand(time(NULL));
    for(int i=0; i<20; i++){
        int elem = rand()%100;
        l.insertHead(elem);
        l2.insertTail(elem);
        l3.insertOrdered(elem);
    }
    l.print();
    l2.print();
    l3.print();
    return 0;
}