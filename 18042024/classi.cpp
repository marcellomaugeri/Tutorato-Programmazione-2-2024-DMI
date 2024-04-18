#include<iostream>
//#define DIM 100
using namespace std;

const int DIM=100;

typedef struct{
    string name;
    int fame;
} AnimalStruct;

class Animal{
    private:
        int fame; //Numero da 0 a 100 -> a 0 muore, a 100 non può più mangiare
        string name;

    public:
        Animal(string name){
            this->name = name;
            this->fame = 50;
        }

        Animal(string name, int fame){
            this->name = name;
            this->fame = fame;
        }

        Animal(){ //Costruttore di default
            this->name = "noname";
            this->fame = 50;
        }
    
        void mangia(int quantita){ //Numero da 0 a 100 che indica quanto si riempie lo stomaco
            //fame = fame + quantita;
            if(fame + quantita > 100)
                fame = 100;
            else
                fame += quantita;
            //Alternativa con operatore ternario
            //fame = fame + quantita > 100 ? 100 : fame + quantita;
        }

        //Metodi getter
        int get_fame(){
            return fame;
        }

        string get_name(){
            return name;
        }

        //Metodi setter
        /*void set_fame(int fame){
            this->fame = fame;
        }*/

        void set_name(string name){
            this->name = name;
        }
};

int main(int argc, char** argv){
    Animal *leone = new Animal("leone", 100);
    cout << leone->get_name() << endl;
    //leone->mangia(100);
    cout << leone->get_fame() << endl;
}