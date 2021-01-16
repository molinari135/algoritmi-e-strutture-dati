# Albero

## Indice
1. **[Definizione di grafo](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Albero.md#definizione-di-grafo)**
2. **[Notazione di un albero](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Albero.md#albero-1)**
3. **[Proprietà di un albero](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Albero.md#propriet%C3%A0-di-un-albero)**
4. **[Definizione ricorsiva di un albero](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Albero.md#definizione-ricorsiva-di-albero)**
5. **[Definizioni](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Albero.md#definizioni)**
6. **[Specifica sintattica](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Albero.md#specifica-sintattica)**
7. **[Specifica semantica](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Albero.md#specifica-semantica)**
8. **[Visita di alberi](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Albero.md#visita-di-alberi)**
9. **[Rappresentazione di un albero](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Albero.md#rappresentazione-di-un-albero)**
10. **[Complessità di un albero](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Complessit%C3%A0.md#alberi)**

## Definizione di grafo
## Notazione di un grafo
Un **grafo** G è definito dalla coppia **<N, A>** dove

> **N** è l'insieme dei **nodi**

> **A** è l'insieme degli **archi**

Un grafo può essere:
* **Orientato**, se un arco è definito da un nodo *ui* ad un nodo *uj* che appartengono all'insieme dei nodi N
* **Non orientato**, se un arco è definito da un nodo *ui* ad un nodo *uj* che appartengono all'insieme dei nodi N e viceversa
  * I grafi non orientati sono usati per prappresentare relazioni simmetriche tra oggetti
  
[Immagine grafo orientato]

[Immagine grafo non orientato]

In un grafo orientato G, un **cammino** è una sequenza di nodi tali che il cammino parte dal nodo *u0* e arriva al nodo *uk* ed ha una lunghezza uguale a *k*.
* Se non ci sono nodi ripetuti, il cammino è **semplice**
* Se *u0* = *uk*, il cammino è **chiuso**
  * Un cammino semplice e chiuso di dice **ciclo**
  
[Immagine cammino semplice]

[Immagine ciclo]

Un grafo è detto **completo** se per ogni coppia di nodi esiste un arco che va da un nodo all'altro.
Un grafo G = <N, A> è **connesso** se dati *u* e *v* appartenenti all'insieme dei nodi N, esiste un cammino da *u* a *v* o un cammino da *v* a *u*.
Il grafo G è detto **fortemente connesso** se **per ogni coppia** di nodi *u* e *v* **esiste almeno un cammino** da *u* a *v* ed almeno un cammino da *v* ad *u*.

[Immagine grafo non fortemente connesso]

## Albero
## Notazione di un albero
L'albero è un grafo definito dalla coppia

> T = < N, A >

Dove 
* **A** è un insieme di **coppie non ordinate**
* **N** è un insieme di **nodi**

Il **numero degli archi** è uguale al numero di nodi, meno 1

> |A| = |N| - 1

L'albero T si dice **connesso**, ovvero per ogni coppia di nodi *u* e *v* in N, se esiste una sequenza di nodi distinti tali che u = u<sub>0</sub> e v = u<sub>k</sub> e ogni coppia di nodi contigui è un arco di A.
Un **albero radicato** è ottenuto da un albero libero designando arbitrariamente un nodo **r** come **radice** e **ordinando i nodi per livelli**.

[Immagine albero non radicato]

[Immagine albero radicato]

[Immagine albero radicato ordinato]

In un albero radicato:
* La radice **r** è a livello 0 e tutti i nodi *u* tali che <u, r> appartiene ad A, sono **figli di r** e stanno a livello 1
  * In questo modo, **r è il padre**
* Nodi con lo stesso padre sono detti **fratelli**
* Nodi terminali senza figli sono detti **foglie**
* Un **albero ordinato** è ottenuto da uno **radicato** stabilendo un ordinamento tra nodi allo stesso livello.

## Proprietà di un albero
* Un albero è un **grafo aciclico**, in cui per ogni nodo c'è un arco entrante
  * Tranne che per la radice, che non ne ha nessuno
* Un albero è un grafo **debolmente connesso**
* Se esiste un cammino che va da un nodo *u* ad un nodo *v*, tale cammino è unico
* In un albero esiste **un solo cammino** che va dalla radice a qualunque altro nodo
* Tutti i nodi di un albero (tranne r) possono essere ripartiti in insiemi disgiunti **ciascuno dei quali individua un albero**

## Definizione ricorsiva di albero
Un **albero** è un grafo orientato che, o è vuoto, oppure:
- Esiste un **nodo r detto radice** senza predecessori con n &ge; nodi successivi a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>
- Tutti gli altri sono ripartiti in *n* sottoalberi mutualmente disgiunti T<sub>1</sub>, T<sub>2</sub>, ..., T<sub>n</sub> aventi rispettivamente a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> come radice

L'albero è spesso utilizzato per rappresentare **relazioni gerarchiche** tra oggetti.

[Immagine di un albero con descrizione]

## Definizioni
* **Profondità di un nodo**: la lunghezza del percorso dalla radice al nodo (ad esempio, il numero degli archi attraversati)
* **Livello**: l'insieme dei nodi alla stessa profondità
* **Altezza dell'albero**: massimo livello delle sue foglie

## Specifica sintattica
**Tipi**:
* albero, boolean, nodo

**Operatori**:
* creaalbero: ( ) &rightarrow; albero
* alberovuoto: (albero) &rightarrow; boolean
* insradice: (albero, nodo) &rightarrow; albero
* radice: (albero) &rightarrow; nodo
* padre: (albero, nodo) &rightarrow; nodo
* foglia: (albero, nodo) &rightarrow; boolean
* primofiglio: (albero, nodo) &rightarrow; nodo
* ultimofratello: (albero, nodo) &rightarrow; boolean
* succfratello: (albero, nodo) &rightarrow; nodo
* insprimosottoalbero: (albero, albero, nodo) &rightarrow; albero
* inssottoalbero: (albero, albero, nodo) &rightarrow; albero
* cansottoalbero: (albero, nodo) &rightarrow; albero

## Specifica semantica
**Tipi**:
* **albero**: insieme degli alberi ordinati T = <N, A> in cui ad ogni **nodo** n in N è associato il livello(n)
* **boolean**: insieme dei valori di verità
* **nodo**: insieme qualsiasi (finito)

**Operatori**:
* `creaalbero() = T'`
  * **Precondizione:** *(nessuna)*
  * **Postcondizione:** T' = (&emptyset;, &emptyset;) = &wedge;
* `alberovuoto(T) = b`
  * **Precondizione:** *(nessuna)*
  * **Postcondizione:** se T = &wedge;
    * **Vero**, b = true
    * **Falso**, b = false
* `insradice(T, u) = T'`
  * **Precondizione:** T = &wedge;
  * **Postcondizione:** T' = (N, A), N = {u}, livello(u) = 0, A &ne; (0, 0)
* `radice(T) = u`
  * **Precondizione:** T &ne; &wedge;, &exists; v tale che livello(v) = 0
  * **Postcondizione:** u = v
* `padre(T, u) = v`
  * **Precondizione:** T &ne; &wedge;, u &in; N, livello(u) > 0
  * **Postcondizione:** <v, u> &in; A, livello(u) = livello(v) + 1
* `foglia(T, u) = b`
  * **Precondizione:** T &ne; &wedge;, u &in; N
  * **Postcondizione:** &exists; v &in; A con livello(v) = livello(u) + 1
    * **Non esiste**, b = true
    * **Esiste**, b = false
* `primofiglio(T, u) = v`
  * **Precondizione:** T &ne; &wedge;, u &in; N, foglia(T, u) = false
  * **Postcondizione:** <u, v> &in; A, livello(v) = livello(u) + 1
* `ultimofratello(T, u) = b`
  * **Precondizione:** T &ne; &wedge;, u &in; N
  * **Postcondizione:** se altri fratelli di u che lo seguono nella relazione d'ordine
    * **Non esistono**, b = true
    * **Esistono**, b = false
* `succfratello(T, u) = v`
  * **Precondizione:** T &ne; &wedge;, u &in; N, ultimofratello(T, u) = false
  * **Postcondizione:** v è il fratello di u che lo segue nella relazione d'ordine
* `insprimosottoalbero(T, T', u) = T''`
  * **Precondizione:** T &ne; &wedge;, T' &ne; &wedge;, u &in; N
  * **Postcondizione:** T'' è l'albero ottenuto da T aggiungendo l'albero T' di radice r'
    * r' diventa nuovo primo figlio di u
* `inssottoalbero(T, T', u) = T''`
  * **Precondizione:** T &ne; &wedge;, T' &ne; &wedge;, u &in; N, u non è radice di T
  * **Postcondizione:** T'' è l'albero ottenuto da T aggiungendo il sottoalbero T' di radice r'
    * r' diventa il nuovo fratello che segue u nella relazione d'ordine
* `cansottoalbero(T, u) = T'`
  * **Precondizione:** T &ne; &wedge;, u &in; N
  * **Postcondizione:** T' è ottenuto da T rimuovendo il sottoalbero di radice u
    * vengono eliminati u e tutti i suoi discendenti
    
## Visita di alberi
Consiste nel pianificare e seguire una "rotta" che consenta di esaminare **ogni nodo** dell'albero **esattamente una volta**. Esistono modi diversi per effettuare una visita corrispondente all'ordine con cui si intende seguire la struttura.

> **Visita di un albero**: algoritmo per "visitare" tutti i nodi di un albero.

Esistono **due** metodi di visita:
* In profondità (**depth-first search**, a scandaglio): **DFS**
  * Vengono visitati i rami, uno dopo l'altro
  * Ha **tre** varianti
    * **previsita (preordine)**: consiste nell'esaminare r e poi, nell'ordine, effettuare la previsita di T1, T2, ..., Tk
    * **postvisita (postordine)**: consiste nel fare, nell'ordine, prima la postvisita di T1, T2, ..., Tk e poi nell'esaminare la radice r
    * **invisita (ordinamento simmetrico)**: consiste nel fare, nell'ordine la invisita di T1, T2, ..., Ti, nell'esaminare r, e poi effettuare, nell'ordine, la invisita di T(i+1), ..., Tk per un prefissato i >= 1
* In ampiezza (**breadth-first search**, a ventaglio): **BFS**
  * Avviene a livelli, partendo dalla radice
    * **in ampiezza**: la visita avviene per livelli
  
Sia T un albero, non vuoto, di radice r. Se r non è foglia ed ha k (> 0) figli, siano T1, T2, ..., Tk i sottoalberi di T aventi come radici i figli di r.

        PREVISITA(var T:albero; U:nodo) {
          nodo C;
          {esamina nodo U};     // (1)
          if (!FOGLIA(U, T)) {  // (2)
            C = PRIMOFIGLIO(U, T);
            while (!ULTIMOFRATELLO(C, T)) {
              PREVISITA(T, C);
              C = SUCCFRATELLO(C, T);
            }
            PREVISITA(T, C);
          }
        }

##### Scambiando l'ordine delle istruzioni (1) e (2) si ottiene la postvisita

        INVISITA(var T:albero; U:nodo, i:int) {
          if (FOGLIA(U, T)) {
            {esamina U}
          } else {
            nodo C = PRIMOFIGLIO(U, T);
            int k = 0;
            while (!ULTIMOFRATELLO(C, T) and k < i) {
              k = k + 1;
              INVISITA(T, C, i);
              C = SUCCFRATELLO(C, T);
            }
            {esamina nodo U}
            while (!ULTIMOFRATELLO(C, T)) {
              INVISITA(T, C, i);
              C = SUCCFRATELLO(C, T);
            }
          }
        }
        
## Rappresentazione di un albero
### Rappresentazione con vettore dei padri
Una possibile realizzazione è quella con il vettore dei padri:
* il vettore contiene esattamente *n* elementi, quanti sono i nodi
* ogni elemento del vettore rappresenta un nodo
* ogni elemento del vettore contiene l'indice del nodo padre

Vantaggi | Svantaggi
---------|----------
Visitare i nodi lungo percorsi che vanno da foglie a radice è più facile | Inserire e cancellare sottoalberi è più complesso

### Rappresentazione con liste di figli
Un'altra realizzazione è quella con le liste di figli:
* ogni elemento del vettore, oltre a memorizzare le informazioni sul nodo, memorizza un riferimento all'inizio della lista dei figli
* la lista dei figli contiene tanti elementi quanti sono i successori del nodo

### Rappresentazione con lista con primo figlio/fratello
Altra realizzazione vede una lista con primo figlio/fratello:
* Si utilizza una lista
* Ogni elemento della lista, oltre a contenere le informazioni sul nodo, contiene un riferimento alla posizione nella lista del primo figlio e del primo fratello
* Può essere utilizzata una rappresentazione con aera di memoria condivisa tipo quella utilizzata per liste basata su cursori
* Ogni elemento del vettore conterrà due cursori, uno al primo figlio e uno al fratello successivo

Esiste anche la rappresentazione con il vettore dei figli, però si rischia di sprecare memoria se molti nodi hanno grado minore del grado massimo k.

Le realizzazioni precedenti si possono migliorare con l'applicazione dei puntatori, nel caso padre/primo-figlio/fratello.

### Rappresentazione con lista dinamica
Si può anche rappresentare un albero mediante lista dinamica:
* La radice è il primo elemento di una lista, i successivi elementi saranno dei riferimenti ai sottoalberi della radice
* Ogni riferimento punta ad un sottoalbero che a sua volta sarà il primo elemento di una lista
* I nodi delle liste possono assumere diversi valori:
  * Nodo effettivo dell'albero: un campo per il valore del nodo e un puntatore all'inizio della lista o a null se foglia
  * Nodo ausiliario: nodo con due puntatori, inizio lista sottoalbero e puntatore fratello
