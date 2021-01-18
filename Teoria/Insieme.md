## Insieme

## Indice
1. **[Notazione di un insieme](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Insieme.md#notazione-di-un-insieme)**
2. **[Operazioni in un insieme](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Insieme.md#operazioni-in-un-insieme)**
3. **[Specifica sintattica](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Insieme.md#specifica-sintattica)**
4. **[Specifica semantica](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Insieme.md#specifica-semantica)**
5. **[Rappresentazione di un insieme](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Insieme.md#rappresentazione-di-un-insieme)**
6. **[Alcune implementazioni](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Insieme.md#altre-implementazioni)**
7. **[Complessità di un insieme](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Complessit%C3%A0Computazionale.md#insiemi)**

Un **insieme** è una collezione di elementi di tipo omogeneo. A differenza delle liste, **gli elementi non sono caratterizzati da una posizione** nè possono apparire più di una volta.

## Notazione di un insieme
In matematica possono essere definiti *estensionalmente*

> A = { giallo, rosso, blu }

oppure *intensionalmente* attraverso le proprietà che devono avere i componenti

> B = { numeri reali compresi tra 0 e 1 }

In informatica ci riferiamo al modo **estensionale**.

## Operazioni in un insieme
Le operazioni principali sono **unione, intersezione e differenza**.

## Specifica sintattica
**Tipi**:
* insieme, boolean, tipoelem

**Operatori**:
* creainsieme: ( ) &rightarrow; insieme
* insiemevuoto: (insieme) &rightarrow; boolean
* appartiene: (insieme, tipoelem) &rightarrow; boolean
* inserisci: (insieme, tipoelem) &rightarrow; insieme
* cancella: (insieme, tipoelem) &rightarrow; insieme
* unione: (insieme, insieme) &rightarrow; insieme
* intersezione: (insieme, insieme) &rightarrow; insieme
* differenza: (insieme, insieme) &rightarrow; insieme

## Specifica semantica
**Tipi**:
* **insieme**: collezione di elementi di tipo **tipoelem**
* **boolean**: insieme dei valori di verità

**Operatori**:
* `creainsieme() = A`
  * **Precondizione:** *(nessuna)*
  * **Postcondizione:** A = { }
* `insiemevuoto(A) = b`
  * **Precondizione:** *(nessuna)*
  * **Postcondizione:** se A = { }
    * Vero, b = true
    * Falso, b = false
* `appartiene(A, x) = b`
  * **Precondizione:** *(nessuna)*
  * **Postcondizione:** x &in; A
    * Vero, b = true
    * Falso, b = false
* `inserisci(A, x) = A'`
  * **Precondizione:** x &notin; A
  * **Postcondizione:** A' = A &cup; {x}
* `cancella(A, x) = A'`
  * **Precondizione:** x &in; A
  * **Postcondizione:** A' = A \ {x}
* `unione(A, B) = C`
  * **Precondizione:** *(nessuna)*
  * **Postcondizione:** C = A &cup; B
* `intersezione(A, B) = C`
  * **Precondizione:** *(nessuna)*
  * **Postcondizione:** C = A &cap; B
* `differenza(A, B) = C`
  * **Precondizione:** *(nessuna)*
  * **Postcondizione:** C = A \ B
  
## Rappresentazione di un insieme
### Rappresentazione con liste non ordinate
Un insieme si può rappresentare con un **vettore booleano** se il linguaggio utilizzato non prevede il tipo insieme. Per rappresentare un insieme A di interi, si fa uso di un vettore booleano di *n* bit, il cui *k*-esimo valore sarà *vero* se k appartiene ad A e *falso* altrimenti.

Un'altra rappresentazione si avvale di una **lista** i cui elementi sono quelli dell'insieme, così da evitare che gli elementi siano assolutamente degli interi.
Gli elementi della lista sono quelli dell'insieme. Nel caso si usino realizzazioni con strutture dinamiche, l'occupazione di memoria è proporzionale al numero degli elementi presenti nell'insieme. Si fa uso delle seguenti **classi** (OOP):

`class Cella {
  tipoelem elemento;
  posizione successivo;
}`

`class Insieme {
  Cella* posizione;
}`

L'inserimento avviene **in testa alla lista** semplice con cui è realizzato l'insieme sempre dopo aver controllato se l'elemento da inserire non sia già presente nella struttura.

- L'operatore `appartiene` deve scorrere tutta la lista per verificare se l'elemento è presente;
- L'operatore `inserisci` deve chiamare `appartiene` e se l'elemento non è presente nella lista lo deve inserire;
- L'operatore `cancella` è simila ad `appartiene`, dopo aver individuato l'elemento lo deve rimuovere dalla lista;
- Gli operatori `insersezione`, `unione` e `differenza` devono scandire la lista:
  - `unione`: inserisci in C tutti gli elementi di B, poi inserisci gli elementi di A se non appartiengono a C;
  - `intersezione`: C vuoto, scorri A se l'elemento è in B lo metti in C;
  - `differenza`: C vuoto, scorri A se l'elemento non è in B lo metti in C;

### Rappresentazione con liste ordinate
Se è definita una relazione &le; di ordinamento totale sugli elementi dell'insieme, esso può essere rappresentato con una lista ordinata per valori crescenti degli elementi utilizzando due puntatori che scorrono ognuno su un insieme.

- L'operatore `appartiene` effettua una ricerca in una lista ordinata;
- L'operatore `inserimento` richiede di scandire tutta la lista, nella peggiore delle ipotesi;
- L'operatore `cancellazione` effettua una ricerca in una lista ordinata;
- Le operazioni `unione`, `intersezione`, `differenza` sono facilitate dal fatto di poter scorrere due liste ordinate;

## Altre implementazioni
Esistono altri modi per rappresentare gli insiemi tramite **dizionario** e con un **albero bilanciato**. Quando si fa uso del dizionario, esso conterrà solo chiavi, ovvero gli elementi dell'insieme.
