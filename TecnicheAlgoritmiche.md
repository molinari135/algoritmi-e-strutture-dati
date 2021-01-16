# Tecniche algoritmiche

## Classificazione dei problemi: problemi di ricerca, di decisione, di ottimizzazione

I problemi si possono classificare in:
* Problemi di **ricerca**
* Problemi di **decisione**
* Problemi di **ottimizzazione**

Nella **concettualizzazione** si fornisce una specifica del problema, si stabiliscono le caratteristiche strutturali del problema senza fare riferimeento ai metodi per la risoluzione.
Nella **realizzazione** si passa dalla specifica del problema alle scelte per la sua risoluzione, che coinvolgono la definizione dell'algoritmo risolutivo e la realizzazione del programma.

## Specifica del problema
La **specifica del problema** richiede:
* La **scelta dell'input**: si stabilisce che i valori di alcune variabili in gioco siano i dati di ingresso del problema. 
  * L'insieme di tali valori è lo *spazio di input del problema*;
* La **scelta dello scopo della risoluzione**: si stabilisce che i valori di alcune variabili in gioco rappresentino le soluzioni del problema. 
  * L'insieme di tali valori è lo *spazio delle soluzioni*;
* L'identificazione del **legame che i vincoli del problema impongono tra i valori dello spazio di input e i valori dello spazio delle soluzioni**.
  * Ciò conduce alla definizione della *relazione caratteristica* del problema;
* La determinazione di quali **informazioni in uscita** si vuole che il processo risolutivo del problema produca.
  * Queste informazioni stabiliscono lo *spazio di outpout* e il **quesito del problema**.
  
#### Esempio
**Determinare la posizione di un numero intero in un vettore di numeri interi.
Variabili:** 
* Un vettore **v**;
* Un indice **k**;
* Un numero intero **m**.

| Spazio di input | Spazio delle soluzioni | Relazione caratteristica | Spazio di output |
|-----------------|------------------------|--------------------------|------------------|
Insieme delle possibili coppie formate da un vettore **v** e un numero intero **m** | Insieme degli indici di ogni possibile vettore | Associa ad ogni coppia (**v**, **m**) una posizione **k** se e solo se il **k**-esimo elemento di **v** coincide con **m**; la relazione la chiamiamo **r<sub>vett</sub>** | Contiene lo spazio delle soluzioni più un particolare simbolo che denota l'assenza di soluzioni |

Il **quesito** stabilisce che, per ogni configurazione che ammette soluzione, vogliamo come output un qualunque elemento dello spazio delle soluzioni legato a quella configurazione dalla relazione caratteristica.

Sia `V = [7, 5, 3, 7, 2]` con
r<sub>vett</sub>:
`< [7, 5, 3, 7, 2], 7 > = 1`
`< [7, 5, 3, 7, 2], 5 > = 2`
`...`
`< [7, 5, 3, 7, 2], 7 > = 4`
`...`

Poichè esiste un numero infinito di vettori, **r<sub>vett</sub> è di **dimensione infinita**. Consideriamo l'elemento dello spazio di input formato dal vettore **v** e dal numero **m = 7**.

**r<sub>vett</sub>** associa e tale elemento due possibili valori dello spazio delle soluzioni: `1` e `4`.

Il quesito stabilisce che, nel problema considerato, possiamo essere interesati a una qualunque soluzione, a tutte le solzioni, alla "migliore" soluzione ecc...

### Specifica di un problema: definizione
La specifica di un problema è una quintupla 

> < I, S, R, O, Q > 

dove:
* **I** è lo **spazio di input**;
* **S** è lo **spazio delle soluzioni**;
* **R** &subset; `I x S` è una relazione su `I` ed `S` detta **relazione caratteristica**;
* **O** è lo **spazio di output**;
* **Q** è una regola, detta **quesito**, che sulla base della relazione caratteristica `R`, consente di definire una relazione du `I` e `O`: `R`<sub>q</sub> &subset; `I x O`

Una particolare istanza del problema si ottiene ogni volta che scegliamo un particolare valore dei dati in ingresso. In relazione ad un problema e ad una sua istanza, diamo la nozione di **soluzione**.

## Problema di ricerca
Tra tutte le possibili soluzioni siamo interessati a conoscere una qualunque delle soluzioni del problema per l’istanza che stiamo considerando, oppure, nel caso non esista soluzione, siamo interessati a saperlo.
Introduciamo nello spazio di output il simbolo &perp; che individua l’assenza di soluzioni.

### Problema di ricerca: definizione
Un problema di ricerca P è un problema specificato con una quintupla del tipo

> < I, S, R, S &cup; {&perp;}, qric >

dove:
* **qric** è la regola che definisce, in base ad R, la relazione **R<sub>qric</sub>** contenente tutti e soli i seguenti elementi
  * Ogni coppia contenuta in R
  * Una coppia **<i, &perp;>** per ogni istanza I di P per la quale P non ha soluzioni
  
#### Esempio - Problema delle N regine
Dato un intero positivo N si determini un posizionamento di N regine in una scacchiera NxN tale che nessuna regina minacci qualche altra regina.

**Specifica:** la quintupla

< N<sup>+</sup>, D, R, D &cup; {&perp;}, qric >

* **N<sup>+</sup>**: insieme dei numeri interi positivi
* **D**: insieme delle disposizioni di regine in scacchiere di ogni dimensione
  * numero regine = dimensione scacchiera
* **R**: relazione che contiene tutte e sole le coppie **<x, y>** in cui **x &in; N<sup>+</sup>** e **y** è una **disposizione di x regine nella scacchiera x &times; x in cui nessuna regina minaccia le altre**

## Problema di decisione
La risposta è **vero** o **falso** a seconda che il dato di ingresso soddisfi o meno una cerca proprietà. Dunque lo spazio di output contiene solo i due valori di verità.

### Problema di decisione: definizione
Un problema di decisione P è un problema specificato con una quintupla del tipo

> P = < I, S, R, {true, false}, qdec >

dove:
* **qdec** è il quesito che stabilisce la funzione **R<sub>qdec</sub>: I &rightarrow; {true, false}**, tale che per ogni istanza **i** di P, R<sub>qdec</sub>(i) vale
  * **true** se &exsist; s &in; S t.c. <i, s> &in; R
  * **false** altrimenti

### Problema di decisione: soluzione
Un problema di decisione P può essere risolto in due modi:
* Trasformandolo nel corrispettivo problema di ricerca P'
  * Se la risposta di P' è {&perp;} allora la soluzione di P è **false**, altrimenti è **true**
  * **Approccio non costruttivo:** trovare una soluzione a P senza risolvere il corrispettivo problema di ricerca P'

#### Esempio - Problema di partizionamento
Sono dati k numeri interi positivi n<sub>1</sub>, ..., n<sub>k</sub> la cui somma è 2m (per un certo intero m). Decidere se i k numeri possano essere ripartiti in due gruppi in modo che la somma dei componenti di ogni gruppo sia m.

Dunque, se **n<sub>a<sub>1</sub></sub>, ..., n<sub>a<sub>p</sub></sub>** e **n<sub>b<sub>1</sub></sub>, ..., n<sub>b<sub>q</sub></sub>** sono i due gruppi di numeri (cioè **p+q = k**), deve essere:

> sommatoria(n<sub>a<sub>i</sub></sub>) = sommatoria(n<sub>b<sub>j</sub></sub>) = m

**Spazio di input:** insieme I di tutti i possibili insiemi di interi la cui somma è pari
**Spazio delle soluzioni:** insieme S si tutte le possibili coppie di insiemi di interi
**Relazione caratteristica:** insieme R di tutte e sole le coppie **<x, y>** tali che
* x &in; I, y &in; S
* y = <y<sub>1</sub>, y<sub>2</sub>> è una coppia di insiemi tali che
  * y<sub>1</sub> &cap; y<sub>2</sub> = &emptyset;
  * y<sub>1</sub> &cup; y<sub>2</sub> = x
  * sommatoria(y<sub>1</sub>) = sommatoria(y<sub>2</sub>)

Ad esempio, il vettore `[1, 2, 2, 4, 7]` viene partizionato in `[1, 7]` e `[2, 2, 4]`.

## Problemi di ottimizzazione
Alle soluzioni ammissibili è associata una misura (costo, obiettivo): risolvere il problema non significa trovare una qualunque soluzione, ma la migliore soluzione secondo la misura o criterio di preferenza fissato.

### Problemi di ottimizzazione: definizione
Un problema di ottimizzazione P è un problema specificato con una quintupla del tipo:

> <I, S, R, S &cup; {&perp;}, q<sub>ott</sub>(M, m, &subset;) >

dove:
* **M** è un insieme qualsiasi
* **m** è una funzione del tipo **I x S &rightarrow; M** detta **funzione obiettivo** di P
  * Per una cerca istanza i &in; I il valore **m(i, s)** rappresenta una **misura** dell'elemento S nello spazio delle soluzioni
* **&subset;** è una relazione di ordinamento su M (x &subset; y "x *migliore* y")

#### Esempio - Problema dello zaino
Un ladro durante una rapina in un negozio si trova di fronte a n articoli: l’articolo i-esimo ha un valore di pi euro e un peso di ci chilogrammi, dove sia pi che ci, per semplicità, sono interi. Il ladro vuole prendere gli articoli di maggior valore ma il suo zaino può sopportare un peso massimo di B chilogrammi. Cosa gli conviene fare?

Per formalizzare il problema, occorre considerare 2n+1 interi positivi:

> P<sub>1</sub>, ..., P<sub>n</sub>, C<sub>1</sub>, ..., C<sub>n</sub>, B

Dove:
* **P<sub>1</sub>, ..., P<sub>n</sub>** sono detti **profitti**
* **C<sub>1</sub>, ..., C<sub>n</sub>** sono detti **costi**
* **B** è detto **budget** (bilancio)

Dati 2n+1 interi positivi:

> P<sub>1</sub>, ..., P<sub>n</sub>, C<sub>1</sub>, ..., C<sub>n</sub>, B

Trovare n valori interi x<sub>1</sub>, ..., x<sub>n</sub> tali che
* X<sub>i</sub> &in; {0, 1} (1 &le; i &le; n)
* sommatoria(P<sub>i</sub>X<sub>i</sub>) = MAX
* sommatoria(C<sub>i</sub>X<sub>i</sub>) &le; B

**Specifica**
Lo spazio di input **I** è l'insieme delle coppie (n, q) dove n è un intero positivo e q è una sequenza di 2n+1 interi positivi.
L'elemento di questo spazio è:

> (n, (P<sub>1</sub>, ..., P<sub>n</sub>, C<sub>1</sub>, ..., C<sub>n</sub>, B))

Lo spazio delle soluzioni **S** è l'insieme delle sequenze finite:

> < X<sub>1</sub>, ..., X<sub>n</sub> >

con **n &in; N<sup>+</sup>** e **X<sub>i</sub> &in; {0, 1}**

La relazione caratteristica è data dall'insieme delle coppie:

> (n, (P<sub>1</sub>, ..., P<sub>n</sub>, C<sub>1</sub>, ..., C<sub>n</sub>, B)), (X<sub>1</sub>, ..., X<sub>n</sub>)

tali che sommatoria(C<sub>i</sub>X<sub>i</sub>) &le; B

Il quesito è **q<sub>ott</sub>(n, m, &ge;)** dove m = sommatoria(P<sub>i</sub>X<sub>i</sub>)
