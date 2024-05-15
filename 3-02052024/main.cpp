#include "punto.h"
#include "quadrilatero.h"
#include "quadrato.h"
#include<iostream>

using namespace std;

int main(int argc, char** argv){
    //Esempio di eccezione
    double dividendo = 10;
    int divisore = 1;
    cout << "Dividi 10 per:" << endl;
    cin >> divisore;
    try{
        if(divisore == 0){
            throw "Divisione per zero impossibile";
        }
        double risultato = dividendo / divisore;
        cout << "Il risultato è: " << risultato << endl;
    }catch(const char* msg){ //msg di default contiene l'eccezione
        cerr << msg << endl;
    }

    // Creo un punto con coordinate (3, 4)
    Punto p(3, 4);
    Punto p2(5, 6);
    cout << "Distanza dall'origine: " << p.distanzaOrigine() << std::endl;
    cout << "Distanza tra i due punti: " << p.distanza(p2) << std::endl;
    return 0;
}