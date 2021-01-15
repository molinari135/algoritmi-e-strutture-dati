# Pila

## Indice
1. **[Notazione di una pila](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Pila.md#notazione-di-una-pila)**
2. **[Accesso ad una pila](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Pila.md#accesso-ad-una-pila)**
3. **[Operazioni in una pila](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Pila.md#operazioni-in-una-pila)**
4. **[Specifica sintattica](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Pila.md#specifica-sintattica)**
5. **[Specifica semantica](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Pila.md#specifica-semantica)**
6. **[Realizzazioni di una pila](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Pila.md#rappresentazione-di-una-pila)**
7. **[Pile e procedure ricorsive](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Pila.md#pile-e-procedure-ricorsive)**
8. **[Complessità di una pila](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Complessit%C3%A0.md#pila-e-coda)**

Una **pila** è una sequenza di elementi di un certo tipo.

## Notazione di una pila
Indichiamo la pila con la notazione

> P = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > con n &ge; 0

## Accesso ad una pila
Gli accessi possibili sono applicati unicamente **ad un solo estremo**, ovvero la "testa" (**accesso agli estremi**).

## Operazioni in una pila
Tutte le operazioni vanno effettuate **solo all'estremo superiore** della pila, ovvero alla sua sommità. Può essere vista come un **caso speciale di lista** in cui l'ultimo elemento inserito è il primo ad essere rimosso (**LIFO**) e non è possibile accedere ad alcun elemento che non sia quello in testa.

###### LIFO: Last In, First Out (L'ultimo inserito è il primo che viene tirato fuori)

## Specifica sintattica
**Tipi**: 
* pila, boolean, tipoelem

**Operatori**:
* creapila: ( ) &rightarrow; pila
* pilavuota: (pila) &rightarrow; boolean
* leggipila: (pila) &rightarrow; tipoelem
* fuoripila: (pila) &rightarrow; pila
* inpila: (pila, tipoelem) &rightarrow; pila

## Specifica semantica
**Tipi**:
* **pila**: insieme delle sequenze P = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > con n &ge; 0 di elementi di tipo **tipoelem** gestita con accesso LIFO
* **boolean**: insieme dei valori di verità

**Operatori**:
* `creapila() = P`
  * **Precondizione:** *(nessuna)*
  * **Postcondizione:** P = < >
* `pilavuota(P) = b`
  * **Precondizione:** *(nessuna)*
  * **Postcondizione:** se P = < >
    * Vero, b = true
    * Falso, b = false
* `leggipila(P) = a`
  * **Precondizione:** P = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > con n &ge; 1
  * **Postcondizione:** a = a<sub>1</sub>
* `fuoripila(P) = P'`
  * **Precondizione:** P = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > con n &ge; 1
  * **Postcondizione:** P' = < a<sub>2</sub>, a<sub>3</sub>, ..., a<sub>n</sub> >
    * P' = < > se n = 1
* `inpila(P, a) = P'`
  * **Precondizione:** P = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > con n &ge; 0
  * **Postcondizione:** P' = < **a**, a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> >
  
## Rappresentazione di una pila
La pila è un caso particolare di **lista** e possiamo definire la seguente corripondenza tra gli operatori:
* `creapila()` &rightarrow; `crealista()`
* `pilavuota(p)` &rightarrow; `listavuota(p)`
* `leggipila(p)` &rightarrow; `leggilista(**primolista(p)**, p)`
* `fuoripila(p)` &rightarrow; `canclista(**primolista(p)**, p)`
* `inpila(p, a)` &rightarrow; `inslista(**primolista(p)**, p, a)`

### Rappresentazione con vettore
Le pile si possono rappresentare mediante vettore memorizzando gli *n* elementi della pila, in **ordine inverso**, nelle prime n posizioni del vettore, mantenendo un **cursore alla testa della pila**. Questa implementazione è svantagiosa perchè richiede di definire una dimensione degli elementi massimi della pila.

### Rappresentazione con puntatori
Si possono anche implementare utilizzando i **puntatori**, riferendosi alla cella che si trova in cima con un puntatore.

## Pile e procedure ricorsive
L'esecuzione di una procedura ricorsiva prevede il salvataggio dei dati su cui lavora la procedura al momento della chiamata ricorsiva. Tali dati vengono "ripristinati" quando la computazione "interna" termina in quanto è un meccanismo **LIFO**. Le diverse chiamate attive sono organizzate in una pila. Nella pila vanno salvati i **parametri** (e le eventuali variabili locali), il **punto di ritorno**, cioè l'etichetta della istruzione da cui ripartire al termine della computazione "interna". Grazie alle pile è sempre possibile, dato un programma ricorsivo, trasformarlo in uno iterativo.
