# Chi vuol essere <s>promosso</s> milionario?
## Obiettivi: approfondire le classi e gli stream<br>Difficoltà: Facile

Scrivere un programma in C++ che definisca una classe Domanda.<br>
Gli attributi della classe Domanda, tutti privati, sono:
- _testo_ che rappresenta la vera e propria domanda.
- Un array di 4 elementi di _risposte_ le quali contengono le stringhe con le possibili risposte.
- _corretta_, indice della risposta corretta.

I metodi della classe invece sono:
- Il costruttore che prende in input un puntatore a stream contenente il testo della domanda, le 4 risposte e un numero da 0 a 3, indicante la risposta corretta, tutti separati da uno spazio.
- Il costruttore che prende in input gli attributi separatamente, quindi 5 stringhe diverse e un intero indicante l’indice.
- Il costruttore che prenda in input (1) la stringa testo, (2) un array di 4 elementi di risposte, le quali dovranno essere copiate in un nuovo array, (3) l’indice di risposta corretta.
- Il metodo _leggi\_testo_ il quale presenta il testo della domanda e le risposte numerate.
- La funzione _indovina_ la quale prende in input un indice corrispondente e restituisce un bool che indica se la risposta è corretta oppure no.

Scrivere un main il quale legga un file in input contenente il numero di domande presenti, seguito da blocchi di domande (5 righe) separati da una riga vuota. Si crei un array di domande e si riempia con le domande del file. Successivamente, scorrere tutte le domande, mostrarne il testo e attendere in input dall’utente la selezione della risposta. Infine, mostrare la percentuale di domande con risposta corretta e inserire in un file di output gli indici delle risposte date.

Esempio di domanda all’interno del file di input:

#### domande.txt
```txt
Qual è la capitale della Bulgaria?
Roma
Sofia
Budapest
Bucarest
1
```