# Coda

## Indice
1. **[Notazione di una coda](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Coda.md#notazione-di-una-coda)**
2. **[Accesso ad una coda](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Coda.md#accesso-ad-una-coda)**
3. **[Operazioni in una coda](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Coda.md#operazioni-in-una-coda)**
4. **[Specifica sintattica](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Coda.md#specifica-sintattica)**
5. **[Specifica semantica](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Coda.md#specifica-semantica)**
6. **[Rappresentazione di una coda](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Coda.md#rappresentazione-di-una-coda)**
7. **[Complessità di una coda](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Complessit%C3%A0.md#pila-e-coda)**

Una **coda** è un tipo astratto che consente di rappresentare una sequenza di elementi in un cui è possibile aggiungere elementi dal "fondo" e toglierli dalla "testa".

## Notazione di una coda
Indichiamo la coda con la notazione

> q = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > con n &ge; 0

## Accesso ad una coda
Per poter **aggiungere** elementi si accede ad un estremo ("fondo") mentre per poterli **togliere** si accede all'estremo opposto ("testa"). Il funzionamento è identico a quello di una fila ad una cassa (**accesso agli estremi**).

## Operazioni in una coda
Le operazioni vengono effettuate solo **in prima ed ultima posizione**.

## Specifica sintattica
**Tipi**: 
* coda, boolean, tipoelem

**Operatori**:
* creacoda: ( ) &rightarrow; coda
* codavuota: (coda) &rightarrow; boolean
* leggicoda: (coda) &rightarrow; tipoelem
* fuoricoda: (coda) &rightarrow; coda
* incoda: (coda, tipoelem) &rightarrow; coda

## Specifica semantica
**Tipi**:
* **coda**: insieme delle sequenze q = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> >, n &ge; 0, di elementi di tipo **tipoelem** caratterizzata dall'accesso **FIFO**;
* **boolean**: insieme dei valori di verità

**Operatori**:
* `creacoda() = q`
  * **Precondizione:** *(nessuna)*
  * **Postcondizione:** q = < >
* `codavuota(q) = b`
  * **Precondizione:** *(nessuna)*
  * **Postcondizione:** se q = < >
    * Vero, b = true
    * Falso, b = false
* `leggicoda(q) = a`
  * **Precondizione:** q = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > con n &ge; 1
  * **Postcondizione:** a = a<sub>1</sub>
* `fuoricoda(q) = q'`
  * **Precondizione:** q = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > con n &ge; 1
  * **Postcondizione:** q' = < a<sub>2</sub>, ..., a<sub>n</sub> >
    * q' = < > se n = 1
* `incoda(q, a) = q'`
  * **Precondizione:** q = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > con n &ge; 0
  * **Postcondizione:** q' = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>, **a**>
  
## Rappresentazione di una coda
In generale le possibili rappresentazioni delle code sono analoghe a quelle delle **pile** consentendo solo l'accesso sia all'elemento inserito per primo sia all'elemento inserito per ultimo.

### Rappresentazione con puntatori
La coda può essere rappresentata con *n* celle, la prima delle quali è indirizzata da un **puntatore "testa"** e l'ultima da un **puntatore "fondo"**. La coda vuota è individuata dal valore nullo *null* del puntatore di testa.

### Rappresentazione con vettore circolare
Per le code la rappresentazione sequenziale non è agevole come per le pile, quindi è utile **gestire l'array in modo circolare**. Il vettore circolare è inteso come un array di *maxlung* elementi, con indice da 0 a *maxlung - 1*, in cui consideriamo l'elemento di indice 0 come successore di quello di indice *maxlung - 1*. Si utilizzano due variabili:
- **Primo**: indica la posizione dell'array in cui è memorizzato l'elemento inserito per primo
- **Ultimo**: si riferisce all'ultimo elemento inserito (oppure definisce la lunghezza della coda)
