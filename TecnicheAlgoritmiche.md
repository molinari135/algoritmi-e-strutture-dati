# Tecniche algoritmiche

## Indice
1. **[Classificazione dei problemi](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/TecnicheAlgoritmiche.md#classificazione-dei-problemi-problemi-di-ricerca-di-decisione-di-ottimizzazione)**
2. **[Spazio di ricerca](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/TecnicheAlgoritmiche.md#spazio-di-ricerca-definizione-e-propriet%C3%A0)**
3. **[Paradigma selettivo]()**
4. **[Paradigma generativo]()**

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

Poichè esiste un numero infinito di vettori, **r<sub>vett</sub>** è di **dimensione infinita**. Consideriamo l'elemento dello spazio di input formato dal vettore **v** e dal numero **m = 7**.

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

> < N<sup>+</sup>, D, R, D &cup; {&perp;}, qric >

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

## Spazio di ricerca: definizione e proprietà
* **Specifica di un problema**: definisce la struttura del problema indipendentemente dal modo in cui il problema verrà risolto
* **Spazio delle soluzioni:** è caratteristica generale del problema e non fornisce indicazioni sulle soluzioni per una generica istanza
* **Spazio di ricerca:** è uno strumento che ci aiuta a "caratterizzare" le potenziali soluzioni ad una generica istanza di un problema, per orientare la scelta di un algoritmo solutivo

Definire lo **spazio di ricerca** per un problema P significa stabilire un metodo che, per ogni istanza i di P, definisce un insieme con associate due funzioni:
* **funzione di ammissibilità:** permette di verificare se un elemento dello spazio di ricerca corrisponde effettivamente ad una soluzione
* **funzione di risposta:** permette di ottenere, dagli elementi dello spazio di ricerca, le corrispondenti risposte per i

Sia **i** una istanza di un problema

> P = < I, S, R, S &cup; {&perp;}, Q >

Uno spazio di ricerca di P per l'istanza i è costituito da:
* un insieme Z<sub>i</sub> con associate due funzioni
  * la funzione di ammissibilità: **a: Z<sub>i</sub> &rightarrow; {true, false}**
  * la funzione di risposta: **o: z<sub>i</sub> &rightarrow; s**

Entrambe le funzioni devono soddisfare le seguenti condizioni:
* Per ogni elementi z di Z<sub>i</sub>
  * a(z) = true se e solo se o(z) è soluzione di P per i
* i ha risposta positiva se e solo se v<sub>i</sub> è almeno un elemento z di Z<sub>i</sub> per cui
  * a(z) = true e o(z) è una risposta a P per i

Uno spazio di ricerca di P per l'istanza i è costituito, inoltre, da:
* Un metodo per rappresentare ogni elemento di Z<sub>i</sub> mediante una struttura di dati (vettore, matrice, lista, albero, ...) e per esprimere la funzione di ammissibilità e di risposta in termini di tale struttura

## Struttura dello spazio di ricerca per problemi di ricerca con risposta positiva
* L'insieme **{s &in; S | (i, s) &in; R}** rappresenta le soluzioni di P per l'istanza i
  * Per un problema di ricerca, questo insieme coincide con l'insieme delle risposte
* L'insieme **{s &in; S | &exists; z &in; Z<sub>i</sub>, a(z) = true &wedge; o(z) = s}** è costituito dalle soluzioni di P per l'istanza i che sono rappresentate nello spazio di ricerca
* Lo **spazio di ricerca non rappresenta necessariamente tutte le soluzioni ad i**
  * Se esistono risposte positive per i, basta che **una** sia rappresentata nello spazio di ricerca

Per i **problemi di ottimizzazione** valgono le seguenti osservazioni:
* La definizione di spazio di ricerca stabilisce che la funzione di ammissibilità deve assicurare che **&forall;z &in; Z<sub>i</sub>, a(z) = true IF (i, o(z)) &in; R**
  * Queste condizioni sono relative alla relazione caratteristica e non al quesito
* Ottenere una risposta per una cerca istanza significa calcolare una soluzione ottimale: lo spazio di ricerca deve includere **almeno** un elemento dal quale si possa ottenere **una soluzione ottimale** all'istanza

Per un problema di ottimizzazione:
* L'insieme **{s &in; S | (i, s) &in; R &wedge; &notexists;s' &in; S, (i, s') &in; R &wedge; m(i, s') &subset; m(i, s)}** rappresenta le soluzioni **ottimali** di P per l'istanza i
  * Rappresenta è risposte a P per I
* Uno spazio di ricerca per i di P deve contenere la rappresentazione di **almeno una** tra le soluzioni ottimali se esistono
  * Ovvero, **non** deve essere **vuota l'intersezione** tra i seguenti insiemi
    * **{s &in; S | (i, s) &in; R &wedge; &notexists; s' &in; S, (i, s') &in; R &wedge; m(i, s') &subset; m(i, s)}**
    * **{s &in; S | &exists; z &in; Z<sub>i</sub>, a(z) = true &wedge; o(z) = s}**

#### Esempio: ricerca di un elemento in un vettore
Consideriamo una generica istanza del problema con input un vettore V di n elementi e un numero m.

* Lo **spazio di ricerca** associato a tale istanza è l'**insieme** dei valori che sono **indici del vettore**
  * Interi da 1 a n
* La **funzione di ammissibilità** verifica, dato un **j**, se `v[j] = m`
* La **funzione di risposta** restituisce **j**
* La **struttura dati** per rappresentare i singoli elementi dell'insieme è una **semplice variabile di tipo intero**

## Differenze tra spazio delle soluzioni e spazio di ricerca per un problema P
Lo **spazio delle soluzioni** è una componente della specifica del prolema e fa globalmente riferimento a **tutte le** possibili **soluzioni** per il problema.

Lo **spazio di ricerca** fornisce uno strumento per **caratterizzare le soluzioni** di ogni singola istanza del problema. Esso determina anche, per ogni istanza del problema, una struttura di dati e un **meccanismo per verificare**, tramite la formulazione della funzione di ammissibilità in termini di tale struttura, **se una sua configurazione corrisponde o meno ad una soluzione** per l'istanza e un **metodo per derivare**, tramite la formulazione della funzione di risposta, **una risposta** all'istanza.
  
### Spazio di ricerca per un problema P
Esistono diversi modi per determinare uno spazio di ricerca di un problema. Criteri per valutare la qualità di una scelta rispetto ad un'altra:
* Lo **spazio di ricerca** deve caratterizzare la soluzioni ad una istanza in modo non ridondante:
  * Per questo motivo, è opportuno scegliere una struttura dati che escluda a priori configurazioni che non corrispondono ad alcuna soluzione
* Lo **spazio di ricerca** non deve essere una banale riformulazione del problema e della sua relazione caratteristica nè deve nascondere la difficoltà di un problema
  * Deve fornire elementi significativi per la comprensione della struttura del problema e delle sue soluzioni

#### Esempio: problema delle n regine
Sia **i** la dimensione della scacchiera:
* L'insieme che forma lo **spazio di ricerca** è l'insieme di tutte le possibili scacchiere di dimensione **i** in cui sono poste **i** regine
* La **funzione di ammissibilità** verifica se la scacchiera soddisfa i vincoli del problema, cioè se non esistono nella scacchiera due regine piazzate nella stessa riga o colonna o diagonale
* La **funzione di risposta** è la funzione di identità
* La **struttura di dati** può essere una matrice **i x i** di caratteri in cui il carattere **q** oppure **&star;** indica la posizione della regina

Ma la rappresentazione è migliorabile?
Per esclidere configurazioni con due regine sulla stessa riga, rappresentiamo al configurazione di scacchiera mediante un **vettore** di dimensione **i** con elementi interi compresi tra **1** ed **i**: se l'elemento in posizione **j** del vettore è **h**, vuol dire che la **regina** della **riga j** è in **colonna h**.

Per escludere configurazioni errate, basta escludere vettori che hanno valori uguali in posizioni diverse.

Allora, per il problema della n regine:
* L'insieme degi elementi dello **spazio di ricerca** coincide con tutti i possibili modi di memorizzare i valori da **1** a **i** in un vettore **V** con i elementi
  * Tutte le possibili permutazioni di (1, ..., i)
* La **funzione di ammissibilità** verifica se il generico elemento dello spazio di ricerca, cioè il generico vettore **V**, non contenga due elementi in posizione **h** e **k** tali che **due regine stiano nella stessa diagonale**
* La **funzione di risposta** ricostruisce semplicemente, a patire da un generico vettore, la corripondente configurazione della scacchiera

## Tecniche algoritmiche
Le tecniche algoritmiche sono basate su diversi paradigmi di utilizzo dello spazio di ricerca:
* La tecnica di **enumerazione**
* La tecnica di **backtracking**
* La tecnica **greedy**
* La tecnica **divide et impera**

I paradigmi sono:
* Il paradigma **selettivo**
  * Sono tecniche di progetto di algoritmi che
    * Per l'istanza del problema presa in considerazione, visitano lo spazio di ricerca tentando di trovare un elemento ammissibile
    * Fanno riferimento all'intero spazio di ricerca che viene esplorato con sistematicità in una definita modalità
  * Appartengono a questo paradigma, la tecnica **enumerativa** e quella di **backtracking**
* Il paradigma **generativo**
  * Sono tecniche di progetto di algoritmi che
    * Generano direttamente la soluzione senza selezionarla tra gli elementi dello spazio di ricerca
    * Considerano lo spazio di ricerca esclusivamente in fase di progetto dell'algoritmo allo scopo di caratterizzare le soluzioni del problema e definire una strategia risolutiva diretta per ogni istanza
  * Appartengono a questo paradigma la tecnica **greedy** e al tecnica **divide-et-impera**

## Paradigma selettivo
A questo paradigma appartengono la **tecnica enumerativa** e la **tecnica backtracking**.

## Tecnica enumerativa
Si basa sulla sistematica ispezione, elemento per elemento, dello spazio di ricerca associato ad una istanza di un problema, è una tecnica che **garantisce**, se lo spaizo di ricerca è finito, una **terminazione**:
* Per un problema di **ricerca**, si termina quando
  * Si è individuato un elemento **ammissibile**
  * Lo **spazio di ricerca si è esaurito**
* Per un problema di **ottimizzazione** si dovrà confrontare, ai fini della selezione, tutti gli elementi **ammissibili** e la terminazione è data dall'**esaurimento dello spazio di ricerca**.

Per garantire la possibilità di una visita sistematica di **uno spazio di ricerca** si associa ad esso una relazione di ordinamento totale in modo da definire per lo spazio **Z<sub>i</sub>** associato ad **i**:
* Un metodo per stabilire il **primo** elemento da considerare
* Un metodo per stabilire l'elemento **successivo**
* Un metodo per verificare **se si sono esaminati tutti** gli elementi

### Algoritmo enumerativo per problemi di ricerca
1. Considera il primo elemento **x** dello spazio di ricerca
2. Se **a(x) = true**, allora fornisci **o(x)** come risultato
3. Se tutti gli elementi dello spazio di ricerca sono stati esaminati, fornisci **&perp;** come risultato
4. Altrimenti considera come nuovo **x** l'elemento successivo dello spazio di ricerca e ripeti dal punto 2

#### Esempio: gioco dell'otto
I tasselli numerati devono essere disposti ordinati lungo i bordi: la soluzione può essere ricercata esaminando tutte le possibili disposizioni generate attraverso mosse successive. **Il provedimento di ricerca è rappresentabile mediante un albero un albero che ha nei nodi le configurazioni possibili generate mossa dopo mossa**

**Stato iniziale**
| 2 | 8 | 3 |     
|---|---|---|     
| 1 | 6 | 4 |     
| 7 |   | 5 |     

**Stato finale**
| 1 | 2 | 3 |
|---|---|---|
| 8 |   | 4 |
| 7 | 6 | 5 |

### Algoritmo enumerativo per problemi di ottimizzazione
1. Considera il primo elemento **x** dello spazio di ricerca
2. Poni come soluzione **ottima corrente = x** se
   * **a(x) = true** e **x** è la **prima soluzione** trovata
   * **a(x) = true** e **x** è **Migliore** della **soluzione ottima corrente**
3. Se tutti gli elementi dello spazio di ricerca sono stati considerati, allora fornisci come risultato **&perp;** se
   * **non** sono state trovate **soluzioni ammissibili**
   * **o(x)** se **x** è soluzione ottima corrente
4. Altrimenti considera come nuovo **x** l'elemento successivo dello spazio di ricerca e ripeti dal punto 2

#### Esempio: gioco dell'otto (*come problema di ottimizzazione*)
Potremmo porci l'obiettivo non solo di trovare una soluzione qualsiasi, ma di trovarne una **ottima**, per esempio, sulla base del criterio "il prima possibile".
Questo si traduce nella possibilità di valutare il numero di mosse che ci porta alla soluzione e nell'esplorare l'intero albero alla ricerca del **cammino più breve** che ci porta alla soluzione (**numero minimo di mosse**).

## Tecnica backtracking
Nella tecnica di backtracking la generazione degli elementi dello spazio di ricerca da visitare avviene secondo un processo suddiviso in **stadi** e basato sul fatto che:
* Ogni elementi dello **spazio di ricerca** è costituito da diverse **componenti** e **ad ogni stadio viene scelta una componente**
* Se **ogni elemento** dello spazio di ricerca è **strutturato in *n* componenti**, dopo **i** stadi (**i < n**) si è costituita una **soluzione parziale**

La caratteristica della tecnica di **backtracking** è che in molti problemi è possibile giungere alla conclusione che la **soluzione parziale** generata è **fallimentare**.
Riconosciuto ciò, **l'algoritmo interrompe il processo di costruzione e tenta altre vie**.

#### Esempio: problema dello string matching
Trovare un'occorrenza di una sequenza P di m caratteri ("pattern") in un'altra sequenza T di n caratteri ("testo"). Le due stringhe P e T sono formate da caratteri tratti dallo stesso alfabeto ed m non supera n.

> **T** = 111**0110**0011101111000

> **P** = 0110

Un algoritmo banale consiste nel cercare di riconoscere il **pattern** a partire dalla prima posizione del **testo** e se il pattern non è interamente riconosciuto, ripetere il procedimento a partire dalla posizione successiva nel testo continuando fino al riconoscimento dell'intero pattern o all'esaurimento del testo.

Se il **pattern** non è riconosciuto, l'algoritmo "**torna**" **(backtracking)** a ripetere il procedimento dalla posizione che segue.

Le stringhe **P** e **T** si possono realizzare con due vettori di caratteri.
Il programma implementa una funzione che restitutisce la **posizione di T** a partire dalla quale si trova la **prima occorrenza di P** (se il pattern occorre nel testo) oppure **n+1 se P non occorre in T**.

#### Funzione che effettua backtracking sugli indici i e j
 
    i = 1;
    j = 1;
    k = 1;
    while ((i <= n) && (j <= m))
     if (T[i] = P[j])
      i = i + 1;
      j = j + 1;
     else
      k = k + 1;
      i = k;
      j = 1;
     if (j > m)
      return k;
     else
      return i;

-----------------------------------

#### Esempio: string matching con algoritmo di Knuth-Morris-Pratt
Trae vantaggio dai confronti già fatti precedentemente sul pattern.
Infatti, se

> **T** = 110111011001

> **P** = 110110

I primi 5 caratteri di P sono uguali ai primi 5 di T, solo se il sesto è diverso. Al momento del **primo backtrack** risulta **i = j = 6** e ripartire con **i = 2** e **j = 1** corriponde a traslare di una posizione il pattern rispetto al testo.

Vale la pena di verificare che nella sottosequenza riconosciuta di **P**

> *11011*1

I primi 4 caratteri non coincidono con gli ultimi quattro, nè i primi 3 con gli ultimi tre

> 1101, 1011, 110, 011

**ma i primi due coincidono con gli ultimi due**

> 11, 11

Non è conveniente ripartire con i = 2 o i = 3 ma con **i = 4** direttamente, poichè i due caratteri a questo punto coincidono con quelli di **T**

> **T** = 110**11**1011001

> **P** = **11***011*0

Conviene quindi ripartire con il backtrack con **i = 6** e **j = 3**. Dato che **6** è proprio il vecchio valore di **i** al momento del **backtrack**, è inutile effettuare backtrack su **i**, basta farlo su **j** assegnando il valore **6** invece che l'attuale **3**

    T = 1101(110110)01     // i = 1, j = 1
    P = (11011)0           // i = 6, j = 3
           (11)0110        // il successivo fallisce
            (110110)       // i = 6, j = 2
                           // OK!

### Metodo
Si considerino due "**coppie**" dei primi **j-1** caratteri del pattern: si dispongano una sotto l'altra in modo che il primo carattere della copia inferiore sia esattamente sotto il secondo carattere della superiore.
Se tutti i caratteri sovrapposti nelle due copie non sono uguali, si traslano di una posizione a destra tutti i caratteri della copia inferiore.
Il procedimento si arresta non appena i caratteri sono identici o quando non ci sono più caratteri sovrapposti.
Il nuovo valore di backtrack da assegnare a j, **succ(j)** è uguale al **numero di caratteri sovrapposti + 1**.
Formalmente si pone per **j = 1**, **succ(j) = 0**.

#### Calcola successivo

    CALC_SUCC(P e SUCC: VETTORE per riferimento; m: INTEGER)
    j = 1; h = 0;, succ(1) = =;
    while (j <= m) {
     if (h == 0) {
      j = j + 1;
      h = 1;
      if (j <= m) {
       if (P[j] == P[1]) {
        succ(j) = 0;
       } else {
        succ(j) = 1;
       }
      }
     } else {
      if (P[j] == P[h]) {
       j = j + 1;
       h = h + 1;
       if (j <= m) {
        if (P[j] == P[h]) {
         succ(j) = succ(h);
        } else {
         succ(j) = h;
        }
       } else {
        h = succ(h);
      }

    STRING2(P e T: VETTORE per riferimento; n, m: INTEGER) = INTEGER
    i = 1; j = 1;
    CALC_SUCC(P, succ, m);
    while (i <= n) && (j <= m) {
     if (j == 0) {         // se j == 0 ricomincia dal primo char di P
      i = i + 1;
      j = 1;
     } else {
      if (T[i] == P[j]) {
       i = i + 1;
       j = j + 1;
      } else {
       j = succ(j);       // se diversi, salta a indice successivo
      }
      if (j > m) {
       return (i - m);
      } else {
       return i;
      }
     }

#### Esempio: problema delle 8 regine con algoritmo di backtracking
Possiamo esprimere la soluzione attraverso una permutazione dei numeri da 1 a 8. La soluione si può esprimere mediante il **vettore V** definito come segue:

    Type posizione = [1 ... 8];
         vettore = array[1 ... 8] of posizione;
    Var V:vettore;

I vincoli imposti sono:
1. Le componenti di V devono costituire una permutazione da 1 a 8; per ogni coppia di indici **i** e **j**, vale `V[i] != V[j]`
2. Non è possibile avere due elementi sulla stessa diagonale, cioè
   * **(i - 1) &ne; (k - 1)**
   * **(i + 1) &ne: (k + 1)**
  
La funzione `VERIFICA` ha il compito di esaminare il vettore **V**:
* se il vettore viola uno dei due vincoli, restituisce **true**
* altrimenti se i vincoli sono ambedue soddisfatti, restituisce **false**

```
OTTO_REGINE(V:VETTORE per riferimento; SUCCESSO: BOOLEAN)
k = 1;
V[k] = 1;
SUCCESSO = false;
repeat
{
 a = VERIFICA(V);
 if (a) {
  repeat
  {
   if (V[k] < 8) {
    b = true;
    V[k] = V[k] + 1;
   } else {
    b = false;
    k = k - 1;
   }
  } until (b || k == 0);
 } else {
  if (k == 8) {
   SUCCESSO == true;
  } else {
   k = k + 1;
   V[k] = 1;
  }
 } until (SUCCESSO || k == 0);
```

### Albero di ricerca con tecnica backtracking
Sia P un problema e sia dato un petodo per associare ad ogni istanza i di P uno spazio di ricerca Z<sub>i</sub>.
Sia definito un modo per strutturare ogni elemento di Z<sub>i</sub> in un numero finito di componenti.
L'albero di ricerca associato a i tramite Z<sub>i</sub> è un albero tale che:
* La radice (livello 0) rappresenta una soluzione parziale fittizia
* Ogni nodo interno a livello j con j > 0 rappresenta una soluzione parziale S in cui sono state scelte le prime j componenti, ed ha tanti figli quanti sono i modi possibili di aggiungere ad S la j+1 esima componente
* Ogni foglia è un elementi di Z<sub>i</sub>

Per un albero di ricerca associato ad una istanza i tramite Z<sub>i</sub> è importante definire:
* Un metodo per rappresentare ogni soluzione parziale (nodo dell'albero)
* Un metodo per stabilire se una soluzione parziale viole i vincoli del problema (stabiliti da R)
* Una funzione di controllo del backtracking **c: nodi &rightarrow; {true, false}** detta **funzione di ammissibilità**
  * **c(n) = true** per ogni nodo interno n dell'albero, se e solo se la soluzione parziale viola i vincoli
  * **c(n) = false** quando il corrispondente elemento dello spazio di ricerca è non ammissibile

#### Esempio: gioco dell'otto con tecnica backtracking
Nell'ipotesi che le mosse siano fatte a caso, il ritorno indietro avviene quando:
* Si genera una configurazione già prodotta
* Si sono già fatte più di un numero fissato di mosse (NMAX) senza arrivare alla soluzione

#### Esempio: problema del partizionamento di un insieme
Dato un insieme **Y = {y1, y2, y3, ..., yn}** di **n** interi positivi la cui somma è **2M**, vogliamo sapere se esiste un sottoinsieme di **Y** la cui somma sia pari a **M**.

Data l'istanza

> Y = {8, 5, 1, 4}

Cerchiamo un **sottoinsieme X** la cui somma sia **9**.
La soluzione può essere espressa mediante un vettore `[x1, ..., x4]` dove

> x<sub>i</sub> &in; {0, 1}, x<sub>1</sub> = 1 IFF y<sub>i</sub> &in; X

L'algoritmo di **backtracking** invece di generare tutte le quadruple `[x1, ..., x4]` costruisce il vettore soluzione partendo dal vettore vuotoo e aggiungendo una componente alla volta.

Il comportamento dell'algoritmo si può descrivere mediante la rappresentazione ad albero dello spazio di ricerca:
* La **radice** rappresenta il **vettore vuoto**
* A **livello 1** abbiamo i **vettori** che è possibile formare con la prima variabile x<sub>1</sub> = 1 e x<sub>1</sub> = 0, e così via
* Solo nelle **foglie** avrò la configurazione completa del vettore e solo alcune delle foglie rappresentano soluzioni **ammissibili**

L'algoritmo di **backtracking** è un algoritmo di visita in pre-ordine dell'albero di ricerca.

## Algoritmo di backtracking
L'algoritmo si riferisce all'albero di ricerca B<sub>i</sub> per l'istanza i di un problema. Si comporta come se effettuasse una [visita in profondità]():
* Ogni volta che nella visita si analizza un nodo, si applica la **funzione di controllo** del backtracking al nodo
  * Se la funzione restituisce **true**, allora quel nodo e tutto il sottoalbero associato al nodo viene abbandonato e la visita continua
* Se il problema è la **ricerca**, la visita termina quando 
  * Si incontra una **soluzione (un nodo foglia con funzione di backtracking = false)** 
  * Quando non esistono altri nodi da visitare
* Se il problema è di **ottimizzazione**, l'algoritmo utilizza una variabile ottimo corrente, che memorizza ad ogni passo il miglior elemento ammissibile
  * L'algoritmo non si interrompe al primo elemento ammissibile trovato, ma continua la visita aggiornando tale variabile

#### Esempio: impostazione dell'algoritmo di backtracking per risolvere il problema dello zaino
* L'**albero di ricerca** si ottiene considerando che, se **n** sono gli oggetti, ogni elemento dello spazio di ricerca si può costruire in **n** stadi dove, all'**i-esimo stadio** si decide se includere o no, nel sottoinsieme rappresentato da **X**, l'**oggetto i-esimo**.
  * L'albero di ricerca è un **albero binario di profondità n**
* Ogni **soluzione parziale** è rappresentata con un **vettore** e un indice (**stadio del processo**)
  * L'elemento **i-esimo** del vettore vale 1 se e solo se l'**i-esimo oggetto** è nello zaino
* La **funzione di controllo del backtracking** su un nodo dell'albero, cui corrisponde la soluzione parziale < X<sub>1</sub>, ..., X<sub>i</sub> >, deve restituire il valore **true** se le scelte fatte portano ad un costo totale maggiore del budget cioè **sommatoria(C<sub>k</sub>X<sub>k</sub>) > B**
  * La funzione, inoltre, vale **true** se il massimo profitto ottenibile con le scelte già fatte è minore del profitto corrispondente all'ottimo corrente, ovvero quando **sommatoria(P<sub>i</sub>X<sub>i</sub>) + sommatoria(P<sub>1</sub>) < P<sub>ott</sub>

## Paradigma generativo
Dal paradigma generativo scaturiscono tecniche di progetto di algoritmi che **generano direttamente la soluzione** senza selezionarla tra gli elementi della spazio di ricerca.
In questo paradigma la spazio di ricerca è considerato esclusivamente in fase di progetto dell'algoritmo allo scopo di caratterizzare le soluzioni del problema e **definire una strategia risolutiva diretta per ogni istanza**.
Appartengono a questo paradigma la tecnica **greedy** e al **divide-et-impera**.

## Tecnica greedy
Si applica principalmente a problemi di ottimizzazione. Richiede che l'algoritmo esegua il processo di costruzione di un elemento dello spazio di ricerca in stadi e si basa sui seguenti principi:
* Ad ogni stadio **i**, per la componente **i-esima** viene scelto il valore che, tra quelli ammissibili, risulta il migliora rispetto da un determinato criterio
* Una volta fatta la scelta per la i-esima componente, si passa a considerare le altre, **senza più tornare sulla decisione presa**

Presuppone che l'algoritmo acquisisca la rappresentazione di un'istanza del problema e disponga di un metodo per organizzare in stadi la costruzione di un elemento dello spazio di ricerca:
1. Poni i a 1 e inizializza z
2. Determina l'insieme A dei valori ammissibili per la componente i-esima di z e se A non è vuoto scegli il migliore in A, rispetto al criterio di preferenza fissato
3. Se l'i-esimo stadio è l'ultimo allora termina e restituisci o(z) come risultato
4. Altrimenti incrementa i di 1 e torna al passo 2

#### Esempio: problema dello zaino (Knapsack)
Come è noto, si dispone di un **budget B** e si deve cercare di massimizzare la rendita scegliendo tra **n** possibili investimenti, ciascuno dei quali caratterizzato da un profitto P<sub>i</sub> e da un costo C<sub>i</sub>.
Il problema viene formulato così:

Dati **2n+1** interi positivi

> P<sub>1</sub>, P<sub>2</sub>, ..., P<sub>n</sub>, C<sub>1</sub>, C<sub>2</sub>, ..., C<sub>n</sub>, B

si vogliono trovare n valori

> X<sub>1</sub>, X<sub>2</sub>, ..., X<sub>n</sub>

tali che
* X<sub>n</sub> &in; {0, 1} (1 &le; i &le; n)
* sommatoria(P<sub>i</sub>X<sub>i</sub>) = MAX
* sommatoria(C<sub>i</sub>X<sub>i</sub>) &le; B

Consideriamo l'istanza **B = 5** e tre elementi disponibili.

| i | Pi | Ci | Pi/Ci |
|---|----|----|-------|
| 1 | 6  | 2  | 3 |
| 2 | 4 | 1 | 4 |
| 3 | 7 | 2 | 3.5 |

Il criterio di base per ordinare le variabili è quello di valutare sia il **costo** che il **profitto** P<sub>i</sub>/C<sub>i</sub>

Una volta effettuato l'ordinamento, si possono scegliere le variabili ponendole al massimo valore compatibile con i vincoli.

Nel caso B = 5 verranno scelti gli oggetti nel seguente ordine:

> i = 2, i = 3, i = 1

e la somma dei costi sarà pari a 5.

### Metodo
Definire una funzione **zainogreedy** che ha come parametri:
* il numero **n** di oggetti denotati dai numeri interi da **0** a **n-1**
* il vettore **P** dei profitti
* il vettore **C** dei costi
* il budget **B**
Il risultato viene restituito nel vettore **X** nel quale la i-esima componente vale **1** se l'oggetto **i** è incluso nella soluzione, e **0** altrimenti.
La funzione ordina in un vettore ausiliario **V** gli oggetti secondo **l'ordine non crescente** del rapporto **PiCi**. Ogni elemento è in corrispondenza di un oggetto e contiene l'indice dell'oggetto in un apposito campo, oltre al rapporto Pi/Ci ad esso associato.
Dopo l'ordinamento, la funzione scandisce il vettore **V**, analizzando **&forall; i** l'oggetto in **V(i)** e decidendo, in base alla compatibilità con il vincolo sul budget, se includerlo o meno nella soluzione.

### Tecnica greedy: Concetti base
Un algoritmo greedy permette di ottenere una soluzione mediante una sequenza di decisioni; in **ogni passo viene presa la decisione che al momento appare migliore**.
Questa strategia euristica **non garantisce sempre una soluzione ottima**.
Affinchè un algoritmo di tipo greedy fornisca la soluzione ottima di un dato problema, occorre che siano verificate due proprietà tra loro correlate:
* La **proprietà della scelta greedy**
  * Assicuta che **si può ottenere una soluzione ottima globale prendendo decisioni che sono ottimi locali**
    * Occorre dimostrare che la soluzione del problema può essere modificata in modo da utilizzare una prima scelta greedy per ridurre il problema ad un sottoproblema più piccolo dello stesso tipo
* La **sottostruttura ottima**
  * Se una **soluzione ottima del problema contiene al suo interno una soluzione ottima dei sottoproblemi**
    * Per dimostrare che una scelta greedy riduce il problema ad un sottoproblema più piccolo dello stesso tipo, occorre dimostrare che una soluzione ottima del problema contiene al suo interno le soluzioni ottime dei sottoproblemi

#### Esempio: problema di selezione di attività
Il problema è quello dell'assegnamento di una risorsa condivisa da un certo numero di attività in competizione tra loro.

Sia **S = {1, 2, ..., n}** un insieme di **n** attività che devono utilizzare una determinata risorsa che non può essere utilizzata contemporaneamente.
Una generica attività **k** è caratterizzata da un **tempo di inizio (attivazione) I<sub>k</sub>** e **un tempo di fine (conclusione) F<sub>k</sub>** con **I<sub>k</sub> &le; F<sub>k</sub>**.

Due attività **k** e **j** sono dette **compatibili** se gli intervalli **(I<sub>k</sub>, F<sub>k</sub>)** e **(I<sub>j</sub>, F<sub>j</sub>) non si sovrappongono**.
Il problema chiede di individuare un insieme che contiene il **massimo numero di attività mutuamente compatibili**.

Si assume che le attività in ingresso siano ordinate in modo crescente rispetto al loro tempo di fine 

> F<sub>1</sub> &le; F<sub>2</sub> &le; F<sub>3</sub> &le; ... &le; F<sub>n</sub>

Lo spazio di ricerca può essere così definito:
* Se **1, ..., n** sono le attivitò relative a una istanza **i**, allora lo spazio di ricerca è l'insieme di tutti i possibili sottoinsiemi di **{1, ..., n}**.

Ad ogni stadio, l'algoritmo sceglie l'attività **k** che, **tra quelle** ancora **disponibili**, rilascia per prima la risorsa condivisa (**minor tempo F<sub>k</sub>**).

Una volta scelta l'attività **k**, si aggiorna l'insieme di attività disponibili, **eliminando** dall'insieme  quelle **incompatibili con k**, cioè quelle che richiedono l'uso della risorsa nel tempo che intercorre tra **I<sub>k</sub>** e **F<sub>k</sub>**.

    GREEDY(I e F: VETTORE; n: INTEGER)
    Variabile A: INSIEME // contiene le attività
    
    CREAINSIEME(A);
    INSERISCI(1, A);
    j = 1;
    for (k = 2; k < n; k++) {
     if (Ik >= Fj) {     // controlla sovrapposizione
      INSERISCI(k, A);
      j = k;
     }
    }

#### Esempio: problema del percorso più breve in un grafo (risolto con algoritmo generativo)
Sia G = (N, A) un **grafo orientato etichettato negli archi** con valori interi positivi. Trovare la lunghezza del percorso più breve che, dato un nodo **r &in; N, &forall; u &in; N**, connetta **r** ad **u**.

Si basa sull'idea di calcolare, in ordine crescente, la **lunghezza dei cammini minimi da r a tutti i nodi del grafo**.

Indichiamo con **S** l'insieme dei nodi di cui, ad un dato istante, si è già calcolata la lunghezza del cammino minimo da **r**.
Utilizzaimo un vettore **dist** con tante componenti quanti sono i nodi del grafo, in modo che **dist(i)** rappresenti la lunghezza del cammino minimo tra quelli che vanno da **r** a **i** passando solo per nodi contenuti in **S** (a parte **i** stesso).
L'ipotesi è che le **distanze siano interi positivi**.
Osserviamo che se il prossimo cammino minimo da generare **C** è da **r** al nodo **u**, tutti i nodi sono in **S**.
Infatti se un nodo **k** di **C** non appartenesse a **S**, vi sarebbe un cammino da **r** a un nodo **k** non contenuto in **S** di lunghezza minore a quella di **C**, contraddicendo l'ipotesi che il prossimo cammino da generare sia **C**.

La lunghezza di **C** e il nodo **u** sono facilmente individuabili; basta calcolare il valore minimo di **dist(i) per i &notin; S**.
Individuato **u**, si inserisci in **S** e **si aggiorna dist** per i nodi che **&notin; S**.

In particolare, se per un certo nodo **z** connesso a **u** da **<u, z>** con etichetta **e** (peso), la somma **dist(u)+e** è minore di **dist(z)**, allora a **dist(z)** va assegnato il nuovo valore **dist(u)+e**.

Viene generato un **albero di copertura T**, radicato in **r**, che include un cammino da **r ad ogni altro nodo**.

L'albero radicato **T** può essere rappresentato con un vettore di padri, inizializzato ad un **albero "fittizio"** in cui tutti i nodi sono **figli di r** connessi ad un **arco fittizio etichettato** con un valore maggiore di tutte le altre etichette (**MAXINT**).

Una **soluzione ammissibile T è ottima se e solo se** viene rispettata la **condizione di Bellman**:
* **dist(i) + C<sub>ij</sub> = dist(j) &forall; (i, j) &in; T**
* **dist(i) + C<sub>ij</sub> &ge; dist(j) &forall; (i, j) &notin; T**

##### Un altro algoritmo (Bellman-Ford) risolve il problema dei cammini minimi nel caso più generale in cui i pesi degli archi possono essere negativi

    CAMMINI_MINIMI(G: GRAFO per riferimento, r: NODO)
    
    CREAINSIEME(S);
    T(r) = 0;
    DIST(r) = 0;
    for (k = 1; k < n; k++) {
     if (k != r) {
      T(k) = r;
      DIST(k) = MAXINT;
     }
     INSERISCI(r, S);
     while (!INSIEMEVUOTO(S)) {
      i = LEGGI(S);
      CANCELLA(i, S);
      for (APPARTIENE(j, S)) {
       if (DIST(i) + Cij < DIST(j)) {
        T(j) = i;
        DIST(j) = DIST(i) + Cij;
        if (!APPARTIENE(j, S) {
         INSERISCI(j, S);
        }
       }
      }
     }
    }

### Algoritmo di Dijkstra
Se la struttura **S** è una coda con priorità, si ottiene un **algoritmo** nodo dal 1959 e attribuito a **Dijkstra**.

In questo caso le operazioni **leggi** e **cancella** sono gli operatori basici disponibili nell'algebra della coda con prorità:

    Min:         (prioricoda) -> tipoelem
    Cancellamin: (prioricoda) -> prioricoda
    
Gli elementi della coda con priorità sono i nodi del grafo e le **priorità** associate, altro non sono che le **distanze** dal nodo origine **r**. Ad ogni iterazione è estratto da S il nodo avente priorità (distanza) minima.

#### Problema del minimo albero di copertura
Dato un grafo **non orientato** e connesso G = (N, A), con pesi sugli archi (non negativi), trovare un albero di copertura per G, cioè un albero avente tutti i nodi in N, ma solo alcuni archi in A, in modo tale che sia *minima la somma dei pesi associati agli archi*.

Il problema può essere risolto con molti algoritmi, dei quali i più noti si devono a Kruskal (1956) e a Prim (1957).

L'algoritmo di **Kruskal** usa la **tecnica "greedy"**.
Dopo aver ordinato gli archi secondo i pesi crescenti, li esamina in tale ordine, inserendoli nella soluzione **se non formano cicli con altri archi già scelti**.
Ad un livello molto generale, l'algoritmo è esprimibile in questi termini:

    KRUSKAL(GRAFO)
     T = vuoto
     {ordina gli archi di G per peso crescente}
     for a = 1 to m do
      if {l'arco a = (i, j) non forma ciclo con altri archi di T} then
       T = T unione (a)

Possiamo rappresentare il **grado G** come preferiamo. Nella realizzazione data di seguito, il grafo è realizzato con un vettore di archi e l'albero T con una lista di archi:

    Definizione dei tipi:
    ARCO: tipo strutturato con componenti
     - i, j: INT
     - PESO: INT
     
    GRAFO: tipo strutturato con componenti
     - A: ARRAY di MAXLUNG elementi di tipo ARCO
     - n, m: INT

Una volta che si considera l'arco, se questo unisce due alberi distinti nella foresta, l'arco viene aggiunto alla foresta e i due alberi fusi in uno.
Nell'algoritmo di Kruskal la costruzione di T avviene per **unione di componenti connesse** rappresentabili come insiemi disgiunti (due componenti connesse si fondono in una con l'aggiunta di un nuovo arco).

    KRUSKAL(G: GRAFO per riferimento)
    variabili:
     h: INT;
     T: LISTA;
     S: MFSET // partizione di un insieme in sottoinsiemi disgiunti
     
     CREALISTA(T)
     {ordina G.A(1), ..., G.A(G.m) per ordine crescente di G.A(h).PESO}
     CREAMFSET(G.n, S)
     for h = 1 to G.m do
      if not TROVA(A(h).i, A(h).j, S) then
       FONDI(A(h).i, A(h).j, S)
       INSLISTA(A(h), PRIMOLISTA(T), T)

## Tecnica divide-et-impera
Deriva dall'idea di determinare la strategia di un problema facendo ricorso al **principio di decomposizione induttiva**. Necessita della disposizione di:
* Una relazione di ordinamento sulle istanze del problema, basata sulla **dimensione di input**
* Un **metodo di risoluzione diretto** per tutte le istanze del problema che non superano una prefissata dimensione limite
* Un meccanismo per suddividere i dati di ingresso relativi ad una istanza in diverse parti, ciascuna di dimensione minore di quella originaria e rappresentante l'input di una nuova istanza dello stesso problema
* Un meccanismo per **comporre le soluzion** per le istanze indivduate dalla suddivisione, per ottenere la soluzione per l'istanza originaria

### Divide-et-impera: algoritmo
1. Se l'input ha dimensinoe inferiore a un certo valore k, allora utilizza un metodo diretto per ottenere il risultato
2. Altrimenti, dividi l'input in parti, ciascuna di dimensione inferiore all'input originario (**divide**)
3. Esegui ricorsivamente l'algoritmo su ciascuno degli input individuati al passo precedente
4. Componi i risultati ottenuti al passo precedente ottenendo il risultato per l'istanza originaria (**impera**)

L'applicazione più nota di questya tecnica si ha negli algoritmi di ordinamento (**natural-merge-sort** e **quicksort**).

#### Esempio: problema del minimo e massimo simultanei
