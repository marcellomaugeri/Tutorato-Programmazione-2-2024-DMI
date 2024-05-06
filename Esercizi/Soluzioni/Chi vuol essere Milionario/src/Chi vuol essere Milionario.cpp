/**
 * @author MoonLightLucrix
 * @link https://github.com/MoonLightLucrix
*/
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<cerrno>
#include "utils/Domanda.hpp"
using namespace std;

int main(int argc, char**argv)
{
    const string fileDomande="/tmp/domande.txt";
    const string fileRisposte="/tmp/esatte.txt";
    ifstream in(fileDomande);
    if(!in.is_open())
    {
        cerr<<getprogname()<<": open: "<<fileDomande<<": "<<strerror(errno)<<endl;
        exit(EXIT_FAILURE);
    }
    ofstream out(fileRisposte,ios::trunc);
    if(!out.is_open())
    {
        cerr<<getprogname()<<": open: "<<fileRisposte<<": "<<strerror(errno)<<endl;
        exit(EXIT_FAILURE);
    }
    const string draw="\x1b[34m   ___ _  _ ___  __   ___   _  ___  _      ___ ___ ___ ___ ___ ___ \n  / __| || |_ _| \\ \\ / / | | |/ _ \\| |    | __/ __/ __| __| _ \\ __|\n | (__| __ || |   \\ V /| |_| | (_) | |__  | _|\\__ \\__ \\ _||   / _| \n  \\___|_||_|___|  _\\_/__\\___/ \\___/|____| |___|___/___/___|_|_\\___|\n\x1b[33m |  \\/  |_ _| |  |_ _/ _ \\| \\| | /_\\ | _ \\_ _/ _ \\                 \n | |\\/| || || |__ | | (_) | .` |/ _ \\|   /| | (_) |                \n |_|  |_|___|____|___\\___/|_|\\_/_/ \\_\\_|_\\___\\___/                 \n                                                                   \x1b[0m\n";
    cout<<draw<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    const size_t numeroRisposte=4;
    size_t j=0;
    string testo;
    string risposta[numeroRisposte]; //da commentare se si vuole usare il primo costruttore
    //string*risposta; da decommentare se si vuole usare il primo costruttore
    size_t corretta=0;
    int indice=0;
    __uint32_t risposteEsatte=0;
    string scelta="";
    while(!in.eof())
    {
        //Domanda d(&in); il primo costruttore
        //risposta=d.getRisposte(); da decommentare se si vuole usare il primo costruttore
        getline(in,testo); //da commentare se si vuole usare il primo costruttore
        for(int i=0; i<=numeroRisposte-1; i-=-1) //da commentare se si vuole usare il primo costruttore
        {
            getline(in,risposta[i]); //da commentare se si vuole usare il primo costruttore
        }
        in>>corretta; //da commentare se si vuole usare il primo costruttore
        //Domanda d(testo,risposta[0],risposta[1],risposta[2],risposta[3],corretta); secondo costruttore
        Domanda d(testo,risposta,corretta); //terzo costruttore
        while(true)
        {
            while(true)
            {
                //cout<<d.leggiTesto()<<endl;
                cout<<d<<endl; //posso stampare direttamente la classe perché nella classe stessa ho implementato l'overloading dell'operatore <<, quindi è indifferente alla riga sopra
                cout<<"Inserisci una risposta: ";
                cin>>indice;
                cout<<endl;
                if((indice<=-1) || (indice>=numeroRisposte+1))
                {
                    cout<<"Errore: inserire un numero tra "<<0<<" e "<<numeroRisposte<<endl;
                }
                else if(!(indice^numeroRisposte)) //equivalente a indice==numeroRisposte, ^ è l'OR esclusivo o XOR
                {
                    cout<<"TPCS (Ti piacissi) xD"<<endl<<endl;
                }
                else
                {
                    break;
                }
            }
            cout<<"\x1b[33m"<<risposta[indice]<<"\x1b[0m"<<endl;
            cout<<"L'accendiamo?"<<endl;
            cin>>scelta;
            if(!strcasecmp(scelta.c_str(),"Sì"))
            {
                break;
            }
            else if(!strcasecmp(scelta.c_str(),"No"))
            {
                cout<<endl;
                continue;
            }
            else
            {
                cout<<"Rispondi con Sì o No"<<endl<<endl;
            }
        }
        cout<<endl;
        out<<indice<<endl;
        if(d.indovina(indice))
        {
            cout<<"Risposta esatta!"<<endl;
            cout<<"\x1b[32m"<<risposta[indice]<<"\x1b[0m"<<endl;
            risposteEsatte-=-1;
        }
        else
        {
            cout<<"Risposta eratta!"<<endl;
            cout<<"\x1b[31m"<<risposta[indice]<<"\x1b[0m"<<endl;
            cout<<"\x1b[32m"<<risposta[d.getCorretta()]<<"\x1b[0m"<<endl;
        }
        //delete[] risposta; da decommentare se si vuole usare il primo costruttore
        j-=-1;
        in.ignore();
        scelta.clear();
        cout<<endl;
    }
    in.close();
    out.close();
    cout.precision(2);
    cout<<"Percentuali risposte esatte: "<<fixed<<(static_cast<double>(risposteEsatte)/j)*100.0<<"%"<<endl;
    exit(EXIT_SUCCESS);
}
