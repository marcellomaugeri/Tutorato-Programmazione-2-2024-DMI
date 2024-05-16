#include<iostream>

using namespace std;

void esercizio1(){
    int x,y;
    int* const p = &x;
    const int*q = &y;
    q = &x;
    //*q = 4; //Questa riga genera errore di compilazione poiché q è un puntatore costante e non è possibile modificare il valore a cui punta
}

void esercizio2(){
    char str[] = {'T','e','s','t'}; 
    char str2[] = "Test";
    cout << sizeof(str) << endl; //La dimensione dell'array è 4 poiché è stato dichiarato un array di 4 caratteri
    cout << sizeof(str2) << endl; //La dimensione dell'array è 5 poiché è stata dichiarata una stringa di 4 caratteri più il carattere nullo
    cout << str << endl; //C'è un errore di esecuzione poiché la stringa non è terminata da un carattere nullo, quindi la stampa continua a leggere in memoria fino a trovare un carattere nullo
    cout << str2 << endl;
}

template <typename T>
T max(T a, T b){
    return (a > b) ? a : b;
}

void esercizio3(){
    //Nota che i :: prima del max sono necessari per indicare che si tratta di una funzione globale e non di una funzione membro 
    cout << ::max(2,5) << endl;
    cout << ::max(2.0,5.0) << endl;
    //cout << ::max(2, 5.0) << endl; //Questa genera errore di compilazione poiché il tipo è ambiguo
    cout << ::max<float>(2, 5.0) << endl;
}

template <typename T>
void fun(const T& x){
    static int count = 0;
    cout << x << " " << "count: " << count << endl;
    ++count;
}

void esercizio4(){
    fun<int>(1); //Output 1 count: 0
    cout << endl;
    fun<int>(2); //Output 2 count: 1
    cout << endl;
    fun<float>(3.0); //Output 3 count: 0 //Il count è 0 poiché la funzione è stata chiamata con un tipo diverso e quindi la variabile statica count è diversa perché appartiene ad un'altra 'istanza' della funzione
    cout << endl;
    fun<int>(4); //Output 4 count: 2
    cout << endl;
}

class Test{
    public:
        //inline static int x = 0;
        static int x;
        Test(){}
};

int Test::x = 0;

void esercizio5(){
    Test t1;
    Test t2;
    cout << "Prima della modifica" << endl;
    cout << t1.x << endl;
    cout << t2.x << endl;
    t1.x = 5;
    cout << "Dopo la modifica" << endl;
    cout << t1.x << endl;
    cout << t2.x << endl;
}

void esercizio6(){
    double m[2][3] = {1,2,3,4,5,6};
    //Puntatore iniziale della matrice
    cout << m << endl;
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            //Prova 1
            //cout << m[i+j] << endl; //Incorretta perché così stiamo mostrando l'indirizzo di memoria di un elemento della matrice
            //Prova 2
            //cout << *(m+i)[j] << endl; //Incorretta perché l'operatore [] ha precedenza sull'operatore *
            //Prova 3
            cout << *(*(m+i)+j) << " "; //Corretta
            //Prova 4
            //cout << m[i]+j << " "; //Incorretta perché stiamo sommando un indirizzo di memoria con un intero, per cui, stiamo mostrando l'indirizzo delle locazioni. Se volessimo accedere al valore, dovremmo scrivere *(m[i]+j)
        }
        cout << endl;
    }
}

class Test2 : public Test{
    public:
        Test2(){}
};

void esercizio7(){
    Test2 t1;
    Test2 t2;
    cout << "Prima della modifica" << endl;
    cout << t1.x << endl;
    cout << t2.x << endl;
    t1.x = 5;
    cout << "Dopo la modifica" << endl;
    cout << t1.x << endl;
    cout << t2.x << endl;
}

class abc {
    void f();
    void g();
    int y;
    long double x;
    double z;
    int* p;
    long double* q;
};

void esercizio8(){
    cout << "int:" << sizeof(int) << endl;
    cout << "long double:" << sizeof(long double) << endl;
    cout << "double:" << sizeof(double) << endl;
    cout << "int*:" << sizeof(int*) << endl;
    cout << "long double*:" << sizeof(long double*) << endl;
    cout << "abc:" << sizeof(abc) << endl;
}

template <class T>
class def{
    void esercizio9();
};

template <class T>
void def<T>::esercizio9(){ }



int main(int argc, char** argv) {
    //esercizio1();    
    //esercizio2();
    //esercizio3();
    //esercizio4();
    //esercizio5();
    //esercizio6();
    //esercizio7();
    //esercizio8();
    //L'esercizio 9 è nella classe def

    return 0;
}