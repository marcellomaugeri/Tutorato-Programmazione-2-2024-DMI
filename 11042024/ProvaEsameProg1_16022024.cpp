#include<iostream>
#include<fstream>

using namespace std;

int main(int argc, char* argv[]){
    //Verifico che ci siano esattamente 5 argomenti, altrimenti, mostro un errore nello standard error e termino il programma.
    if(argc != 5){
        cerr << "Usage: inserire path del file di input, del file di output e valori n e m della matrice" << endl;
        return 1;
    }

    //argv[1] contiene il path del file di input. Verifico che il file di input al path argv[1] esista
    ifstream instream(argv[1]);
    if(!instream){
        cerr << "Errore nell'apertura del file di input" << endl;
        return 1;
    }

    //argv[2] contiene il path del file di output. Verifico che il file di output al path argv[2] esista, altrimenti verrà creato automaticamente.
    ofstream outstream(argv[2]);
    if(!outstream){
        cerr << "Errore nell'apertura del file di output" << endl;
        return 1;
    }

    //Stampo elemento per elemento del file di input. Ogni elemento è separato da uno spazio o un carattere di tabulazione come richiesto dal testo.
    string elemento;
    cout << "Elementi del file di input:" << endl;
    while(instream >> elemento){
        cout << elemento << endl;
    }
    cout << endl;

    //Rewind del file di input, in modo da poterlo leggere nuovamente da zero
    instream.clear(); //Pulisce dei flag che vengono impostati quando si raggiunge la fine del file
    instream.seekg(0); //Posiziona il cursore all'inizio del file

    //argv[3] e argv[4] contengono i valori di n e m della matrice che rappresentano il numero di righe e colonne. stoi permette di convertire una stringa in numero intero. In generale, eventuali caratteri vengono ignorati, ma se nessun numero è presente, verrà lanciata un'eccezione
    int n, m;
    n = stoi(argv[3]);
    m = stoi(argv[4]);
    //cout << n << " " << m << endl;

    //Approfondimento: se volessimo gestire il caso in cui n e m non sono validi, possiamo farlo con un blocco try-catch. In questo caso, se n e m non sono validi, vengono impostati a 1, ma possiamo gestire l'errore in modo diverso
    /*try{
        n = stoi(argv[3]);
        m = stoi(argv[4]);
    }catch(invalid_argument e){
        n = 1;
        m = 1;
    }*/
    
    //Creo una matrice di dimensioni n x m di puntatori a double. Ogni elemento della matrice quindi conterrà un puntatore ad una variabile double. Inizializzo ogni elemento della matrice con il valore letto dal file di input
    double ***matrice = new double**[n]; //Istanzio un array di doppio puntatore a double di dimensione n
    for(int i = 0; i < n; i++){
        matrice[i] = new double*[m]; //Per ogni riga, istanzio un array di puntatori a double di dimensione m
        for(int j = 0; j < m; j++){
            matrice[i][j] = new double; //Per ogni elemento della matrice, istanzio un double
            instream >> elemento; //Leggo un elemento dal file di input
            *matrice[i][j] = stod(elemento); //Converto l'elemento in double e lo assegno alla locazione di memoria puntata dall'elemento della matrice
        }
    }

    //B) Stampo la matrice
    cout << "Matrice: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << *matrice[i][j] << " ";
        }
        cout << endl;
    }

    //Copia la matrice in matrice2
    double ***matrice2 = new double**[n];
    for(int i = 0; i < n; i++){
        matrice2[i] = new double*[m];
        for(int j = 0; j < m; j++){
            matrice2[i][j] = new double;
            *matrice2[i][j] = *matrice[i][j]; //Copia il valore della matrice originale nella matrice copia
        }
    }

    //C) Traspongo la matrice e la stampo sull'output stream
    cout << endl << "Matrice trasposta: " << endl;
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            cout << *matrice[i][j] << " ";
        }
        cout << endl;
    }



}