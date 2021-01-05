# Calcolo della complessità

## Teoria della complessità
Lo studio della computabilità aiuta a stabilire **quali problemi ammettono una soluzione** algoritmica e quali no. Per i problemi computabili, interessa conoscere la **complessità degli algoritmi che li risolvono**.

- **Complessità di un algoritmo**: è una misura delle risorse di calcolo consumate durante la computazione.

- **Efficienza di un algoritmo**: è inversamente proporzionale alla sua complessità.

La teoria della complessità studia l'uso delle risorse di calcolo necessarie per la computazione di algoritmi e, più in generale, per la soluzione di problemi. Questo studio è importante al fine di:
* Poter confrontare algoritmi diversi che risolvono lo stesso problema;
* Stabilire se dei problemi ammettono algoritmi risolutivi che sono praticamente computabili.

### Valutazione dell'efficienza di programmi
Un programma è più efficiente di un altro se la sua esecuzione richiede meno risorse di calcolo. Le **risorse di calcolo** che si consierano sono:
* Il **tempo** di elaborazione richiesto;
* La **quantità** di memoria necessaria.

Se si potesse valutare il tempo di calcolo in unità standard, come i secondi, la valutazione del costo di un programma sarebbe semplice: basterebbe eseguire il programma misurando il tempo necessario per l'esecuzione.

Dato che non è possibile fare ciò perchè bisogna considerare le condizioni in cui si effettuano le prove, bisogna considerare:
* L'elaboratore su cui il programma viene eseguito;
* Il compilatore usato per la traduzione;
* La modalità di ingresso dei dati;
* La significatività dei dati sui quali è eseguita la prova.
E utilizzando una unità di tempo standard, come i secondi, **non si ottiene una valutazione oggettiva** del costo di esecuzione di un programma.

### Complessità computazionale
L'efficienza di un programma è legata alla complessità dell'algoritmo. La teoria della complessità studia in **modo oggettivo** l'uso delle risorse di calcolo necessarie per la computazione di algoritmi. Per risolvere un problema, spesso sono disponibili molti algoritmi diversi.

> Come scegliere il migliore?

In genere, si valuta la bontà di un algoritmo oppure si **confrontano** più algoritmi sulla base del comportamento che questi presentano al crescere della dimensione del problema.

### Risorse di interesse
Le risorse di interesse sono **tempo** e **spazio di memoria**, quindi per un algoritmo di parla di:
* Complessità in tempo;
* Complessità in spazio.

In ogni caso, per valutare la complessità, occorre definire un **modello di costo** che dipende dal particolare modello di macchina astratta a cui si fa riferimento.

L'analisi dell'efficienza di un programma è basa sull'ipotesi che **il costo di ogni istruzione semplice e di ogni operazione di confronto sia pari ad un'unità di costo**, indipendentemente dal linguaggio e dal sistema usato.

Ci limiteremo a **contare le operazioni eseguite o alcune operazioni chiave** ammettendo che il tempo complessivo di esecuzione sia proporzionale al numero di tali operazioni.

> Tratteremo spesso come **non significative le costanti moltiplicative** e studieremo le funzioni di complessità nel loro ordine di grandezza.

### Dimensione dell'input
Il costo di esecuzione di un programma **dipende anche dai dati di ingresso**.

> Ad esempio, il costo di esecuzione di un programma di ordinamento di un insieme di numeri, dipende dalle dimensione dell'insieme che si considera.

Per tener conto del numero di dati con cui si esegue il programma, assumiamo che **la dimensione dell'input rappresenti l'argomento della funzione che esprime il costo** di esecuzione di un programma.

Si può caratterizzare tale dimensione mediante un intero **n** che è identificato nella Macchina di Turing come la lunghezza della porzione di nastro che contiene i dati di ingresso.

> Esempi:
> * Se si opera su matrici, n sarà il numero dei suoi elementi;
> * Se si opera su un insieme, n sarà il numero dei suoi elementi;
> * Se si opera su un grafo, n sarà il numero dei nodi o il numeri di archi o la somma dei due numeri.

### Complessità in spazio
La complessità in spazio è il **massimo spazio invaso dalla memoria durante l'esecuzione** dell'algoritmo. Anche in questo caso ci si limita in genere allo studio della **complessità asintotica**.

> In ogni caso, è bene evitare di assumere di avere memoria infinita.

Il costo è **unario** per i dati di tipo semplice, mentre è dato da:

> **n** &times; dimensione di un elemento (per array di **n** elementi)

Il costo di un record è dato dalla somma dei costo delle singole componenti.

Esempio:

        somma = 0;
        for i = 1 to n do
          somma = somma + A[i]
          
Ha complessità in spazio pari a *13* se *n = 10*, in quanto:
  
        somma = 0               // complessità = 1
        for i = 1 to n do       // complessità = 1 + (N + 1)
          somma = somma + A[i]  // complessità = 1 + (N + 1) + 1
        // complessità = 13 se n = 10
        
Fissata la dimensione *n*, il tempo che un algoritmo impiega a risolvere il problema è la **complessità in tempo**.

> L'obiettivo principale sta nell'**esprimere la complessità in tempo come funzione di n**.

Spesso ci si limita a studiare il comportamento di tale funzione al crescere di *n* e quindi si studia la **complessità asintotica** (o semplicemente **complessità**).

## Complessità asintotica
Lo studio della complessità asintotica è motivato dal fatto che gli algoritmi sono sempre definiti per *n* generico.

### Il modello di costo
Assumiamo che i seguenti costi di esecuzione di ogni istruzione semplice
Istruzione | Esempio | Costo
-----------|---------|-------
Assegnazione | &leftarrow; | 1
Aritmetica | +, -, / | 1
Logica | AND, OR, NOT | 1
Confronto | &le;, &ge;, <, >, =, &ne; | 1
Lettura/Scrittura | | 1

Il costo di esecuzione di un'istruzione composta è pari alla somma dei costi delle istruzioni che la compongono.

#### Costo di una operazione di selezione

        if (cond)
          then {S1}
          else {S2}

- Se `cond` è vera
  - Costo test `cond` + costo `S1` 
- Se `cond` è falsa
  - Costo test `cond` + costo `S2`
  
#### Costo di una istruzione di ciclo

      while (cond) do 
        {S1}
        
- Costo test `cond` + (costo test `cond` + costo `S1`) &times; **n**
  - Se il ciclo è ripetuto **n** volte
  
#### Costo di un ciclo `repeat`

        repeat {S1}
        until (cond)
        
- (costo test `cond` + costo `S1`) &times; **n**
  - Se il ciclo è ripetuto **n** volte
  
#### Costo di una istruzione `for`

        i = 1               // costo = 1
        while (i <= n) do
          S1;
          i = i + 1;        // costo = 1 + 1 = 2

- 2 + (costo `S1` + 3) &times; `n` 

Esempio:

        int MIN (B: vettore per riferimento; int j, k)  // C1 = 1
        int m, i;                                       // 0 = 1
          m = B[j];                                     // C2 = 1
          for (i = j + 1) to k do                       // C3 = n
            if B[i] < m then                            // C4 = n-1
              m = B[i];                                 // C5 = n-1
          return m;                                     // C6 = 1
          
Il tempo di calcolo T(n) di `MIN` si ottiene sommando su tutte le istruzioni il prodotto del costo di ciascuna istruzione per il numero di volte che tale istruzione è eseguita:

> T(n) = C1 + C2 + C3 &times; n + C4 (n - 1) + C5 (n - 1) + C6 =
>      = (C3 + C4 + C5) &times; n + (C1 + C2 + C6 - C4 - C5)

Pertanto, il tempo di calcolo di `MIN` può essere espresso come

> T(n) = an + b, con a e b costanti intere positive

### Complessità e configurazioni
A parità di dimensione di dati, il tempo di esecuzione può dipendere dalla specifica configurazione dei dati. Si considerano di solito **tre** differenti tipi di complessità:
1. **Caso pessimo**: si ottiene considerando quella particolare configurazione che, a parità di dimensione dei dati, dà luogo al massimo tempo di calcolo. La corrispondente funzione di complessità è indicata con **f<sub>pess</sub>(n)**;
2. **Caso medio**: si riferisce al tempo di calcolo mediato su tutte le possibili configurazioni dei dati, sempre per una data dimensione *n*. Funzione di complessità: **f<sub>med</sub>(n)**;
3. **Caso ottimo**: si ottiene considerando la configurazione che dà luogo al minimo tempo di calcolo. La corrispondente funzione di complessità è indicata con **f<sub>ott</sub>(n)**.

Esistono particolari algoritmi in cui tutte le possibili configurazioni dei dati sono equivalenti per quanto riguarda la complessità in tempo. In questo caso, la complessità ottima, pessima e media **coincidono**.

