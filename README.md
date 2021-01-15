# Strutture dati
###### Realizzazioni di varie strutture dati con specifica sintattica e semantica

Ci sono strutture dati che si sviluppano in una dimensione e possono essere considerate come sequenze di oggetti. Queste strutture sono dette **lineari**.
Per distinguerla dalle altre strutture dati vanno analizzati:
- I modi di accedere alle posizioni in cui operare (**accesso**):
  - Accesso diretto
  - Accesso per scansione
  - Accesso agli estremi
      
- I modi di agire nella posizione individuata (**operazioni**):
  - Lettura di un valore di un componente (ispezione)
  - Aggiornamento del valore di un componente (cambio di valore)
  - Inserimento di un nuovo componente (scrittura)
  - Rimozione di un componente (cancellazione)

#### In questa tabella vengono riassunti i tipi di accesso e le operazioni applicate sulle varie strutture dati lineari

Nome struttura | Tipo di accesso | Operazioni
---------------|-----------------|-----------
Lista | Diretto (primo elemento), Scansione | Si possono effettuare su qualsiasi elemento
Pila | Diretto (primo elemento), Estremi (solo un estremo) | Si possono effettuare solo al primo elemento
Coda | Diretto (primo ed ultimo elemento), Estremi | Si possono effettuare alcune al primo elemento e altre solo all'ultimo

## Albero

### Definizione di grafo

#### Notazione di un grafo
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

### Albero

#### Notazione di un albero
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

### Proprietà di un albero
* Un albero è un **grafo aciclico**, in cui per ogni nodo c'è un arco entrante
  * Tranne che per la radice, che non ne ha nessuno
* Un albero è un grafo **debolmente connesso**
* Se esiste un cammino che va da un nodo *u* ad un nodo *v*, tale cammino è unico
* In un albero esiste **un solo cammino** che va dalla radice a qualunque altro nodo
* Tutti i nodi di un albero (tranne r) possono essere ripartiti in insiemi disgiunti **ciascuno dei quali individua un albero**

### Definizione ricorsiva di albero
Un **albero** è un grafo orientato che, o è vuoto, oppure:
- Esiste un **nodo r detto radice** senza predecessori con n &ge; nodi successivi a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>
- Tutti gli altri sono ripartiti in *n* sottoalberi mutualmente disgiunti T<sub>1</sub>, T<sub>2</sub>, ..., T<sub>n</sub> aventi rispettivamente a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> come radice

L'albero è spesso utilizzato per rappresentare **relazioni gerarchiche** tra oggetti.

[Immagine di un albero con descrizione]

### Definizioni
**Profondità di un nodo**: la lunghezza del percorso dalla radice al nodo (ad esempio, il numero degli archi attraversati)
**Livello**: l'insieme dei nodi alla stessa profondità
**Altezza dell'albero**: massimo livello delle sue foglie

### Specifica sintattica
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

### Specifica semantica
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
    
### Visita di alberi
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

###### Scambiando l'ordine delle istruzioni (1) e (2) si ottiene la postvisita

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
        
### Rappresentazione di un albero

#### Rappresentazione con vettore dei padri
Una possibile realizzazione è quella con il vettore dei padri:
* il vettore contiene esattamente *n* elementi, quanti sono i nodi
* ogni elemento del vettore rappresenta un nodo
* ogni elemento del vettore contiene l'indice del nodo padre

Vantaggi | Svantaggi
---------|----------
Visitare i nodi lungo percorsi che vanno da foglie a radice è più facile | Inserire e cancellare sottoalberi è più complesso

#### Rappresentazione con liste di figli
Un'altra realizzazione è quella con le liste di figli:
* ogni elemento del vettore, oltre a memorizzare le informazioni sul nodo, memorizza un riferimento all'inizio della lista dei figli
* la lista dei figli contiene tanti elementi quanti sono i successori del nodo

#### Rappresentazione con lista con primo figlio/fratello
Altra realizzazione vede una lista con primo figlio/fratello:
* Si utilizza una lista
* Ogni elemento della lista, oltre a contenere le informazioni sul nodo, contiene un riferimento alla posizione nella lista del primo figlio e del primo fratello
* Può essere utilizzata una rappresentazione con aera di memoria condivisa tipo quella utilizzata per liste basata su cursori
* Ogni elemento del vettore conterrà due cursori, uno al primo figlio e uno al fratello successivo

Esiste anche la rappresentazione con il vettore dei figli, però si rischia di sprecare memoria se molti nodi hanno grado minore del grado massimo k.

Le realizzazioni precedenti si possono migliorare con l'applicazione dei puntatori, nel caso padre/primo-figlio/fratello.

#### Rappresentazione con lista dinamica
Si può anche rappresentare un albero mediante lista dinamica:
* La radice è il primo elemento di una lista, i successivi elementi saranno dei riferimenti ai sottoalberi della radice
* Ogni riferimento punta ad un sottoalbero che a sua volta sarà il primo elemento di una lista
* I nodi delle liste possono assumere diversi valori:
  * Nodo effettivo dell'albero: un campo per il valore del nodo e un puntatore all'inizio della lista o a null se foglia
  * Nodo ausiliario: nodo con due puntatori, inizio lista sottoalbero e puntatore fratello
  
## Albero binario
Un **albero binario** è un albero ordinato in cui ogni nodo ha al più **due** figli e si fa distinzione tra il **figlio sinistro** ed il **figlio destro** di un nodo.

Due alberi T e U aventi gli stessi nodi, gli stessi figli per ogni nodo e la stessa radice, sono distinti qualora un nodo u sia designato come figlio sinistro di un nodo v in T e come figlio destro del medesimo nodo in U.

[Immagine albero binario]

Ogni albero *n*-ario ordinato T si può rappresentare con un albero binario B avente gli stessi nodi e la stessa radice: in B ogni nodo ha come figlio sinistro il primo figlio in T e come figlio destro il fratello successivo in T. L'equivalenza vale ai fini della **previsita**. Le sequenze di nodi esaminati su T e B coincidono se T e B sono visitati in previsita.

### Specifica sintattica
**Tipi**:
* alberobin, boolean, nodo

**Operatori**:
* creabinalbero: ( ) &rightarrow; alberobin
* binalberovuoto: (alberobin) &rightarrow; boolean
* binradice: (alberobin) &rightarrow; nodo
* binpadre: (alberobin, nodo) &rightarrow; nodo
* figliosinistro: (alberobin, nodo) &rightarrow; nodo
* figliodestro: (alberobin, nodo) &rightarrow; nodo
* sinistrovuoto: (alberobin, nodo) &rightarrow; boolean
* destrovuoto: (alberobin, nodo) &rightarrow; boolean
* costrbinalbero: (alberobin, alberobin) &rightarrow; alberobin
* cancsottobinalbero: (alberobin, nodo) &rightarrow; alberobin

### Specifica semantica
**Tipi**:
* **alberobin**: insieme degli alberi binari T = (N, A), nei quali ad ogni nodo è associato un livello
* **boolean**: insieme dei valori di verità
* **nodo**: unità dell'albero

**Operatori**:
* `creabinalbero() = T'`
  * **Precondizione:** *(nessuna*)
  * **Postcondizione:** T' = (&emptyset;, &emptyset;) = &wedge;
* `binalberovuoto(T) = b`
  * **Precondizione:** *(nessuna*)
  * **Postcondizione:** T = &wedge;
    * **Vero**, b = true
    * **Falso**, b = false
* `binradice(T) = u`
  * **Precondizione:** T &ne; &wedge;
  * **Postcondizione:** livello(u) = 0
    * u &rightarrow; radice di T
* `binpadre(T, u) = v`
  * **Precondizione:** T &ne; &wedge;, u &in; N, livello(u) > 0
  * **Postcondizione:** (v, u) &in; A, livello(v) = livello(u) - 1
    * v &rightarrow; padre di u
* `figliosinistro(T, u) = v`
  * **Precondizione:** T &ne; &wedge;, u &in; N, sinistrovuoto(T, u) = false
  * **Postcondizione:** v &rightarrow; figlio sinistro di u in T
* `figliodestro(T, u) = v`
  * **Precondizione:** T &ne; &wedge;, u &in; N, destrovuoto(T, u) = false
  * **Postconizione:** v &rightarrow; figlio destro di u in T
* `sinistrovuoto(T, u) = b`
  * **Precondizione:** T &in; &wedge;, u &in; N
  * **Postcondizione:** u ha un figlio sinistro
    * **Vero**, b = false
    * **Falso**, b = true
* `destrovuoto(T, u) = b`
  * **Precondizione:** T &ne; &wedge;, u &in; N
  * **Postcondizione:** u ha un figlio destro
    * **Vero**, b = false
    * **Falso**, b = true
* `costrbinalbero(T, T') = T''`
  * **Precondizione:** *(nessuna)*
  * **Postcondizione:** T'' si ottiene da T e T' introducendo automaticamente un nuovo nodo r'' (radice di T'') che avrà come sottoalbero sinistro T e sottoalbero destro T'
    * Se T e T' sono vuoti, l'operatore inserisce la sola radice r''
    * Se solo T è vuoto, r'' non avrà figlio sinistro
    * Se solo T' è vuoto, r'' non avrà figlio destro
 * `cancsottobinalbero(T, u) = T'`
  * **Precondizione:** T &ne; &wedge;
  * **Postcondizione:** T' si ottiene da T eliminando il sottoalbero di radice u, con tutti i suoi discendenti
  
### Operatori aggiuntivi - Specifica sintattica
**Tipi**:
* tipoelem

**Operatori**:
* legginodo: (alberobin, nodo) &rightarrow; tipoelem
* scrivinodo: (alberobin, nodo, tipoelem) &rightarrow; alberobin

### Operatori aggiuntivi - Specifica semantica
**Tipi**:
* **tipoelem**: tipo dell'etichetta del nodo (int, char, ...)

**Operatori**:
* `legginodo(T, u) = a`
  * **Precondizione:** T &ne; &wedge;, u &in; N, u è un nodo di T
  * **Postcondizione:** a è il valore associato al nodo n in T
* `scrivinodo(T, u, a) = T'`
  * **Precondizione:** T &ne; &wedge;, n &in; N, n è un nodo di T
  * **Postcondizione:** T' si ottiene assegnando al nodo n il valore a nell'albero T
  
### Note sugli alberi binari
Nell'algebra precedente si enfatizza la natura **ricorsiva** degli alberi e di costruire l'albero binario dal basso verso l'alto, cioè dal livello delle foglie verso la radice. Questa scelta non sempre è opportuna e occorre sostituire l'operatore di costruzione con tre operatori nuovi:

### Nuovi operatori - Specifica sintattica
**Operatori**:
* insbinradice: (alberobin, nodo) &rightarrow; alberobin
* insfigliosinistro: (alberobin, nodo) &rightarrow; alberobin
* insfigliodestro: (alberobin, nodo) &rightarrow; alberobin

### Nuovi operatori - Specifica semantica
**Operatori**:
* `insbinradice(T, u) = T'`
  * **Precondizione:** T = &wedge;
  * **Postcondizione:** T' = (N, A), N = {u}, livello(u) = 0, A = &emptyset;
* `insfigliosinistro(T, u) = T'`
  * **Precondizione:** T &ne; &wedge;, u &in; N, sinistrovuoto(T, u) = true
  * **Postcondizione:** N' = N &cup; {v}, T' si ottiene da T aggiungendo v come figlio sinistro di u
* `insfigliodestro(T, u) = T'`
  * **Precondizione:** T &ne; &wedge;, u &in; N, destrovuoto(T, u) = true
  * **Postcondizione:** N' = N &cup; {v}, T' si ottiene da T aggiungendo v come figlio destro di u
  
### Visite
Oltre alle visite per gli alberi *n*-ari, ci sono:
* **Vista simmetrica**: richiede prima la visita del sottoalbero sinistro, poi l'analisi della radice, e poi la visita del sottoalbero destro;

        visitaSimmetrica(ALBEROBIN T, NODO u) {
          if (!SINISTROVUOTO(T, u)) {
            visitaSimmetrica(T, FIGLIOSINISTRO(T, u));
          }
          {visita u}
          if (!DESTROVUOTO(T, u)) {
            visitaSimmetrica(T, FIGLIODESTRO(T, u));
          }
        }
        
* **Visita per livelli**
  
        visitaLivelli(ALBEROBIN T) {
          Coda coda = CREACODA();
          incoda(BINRADICE(T));
          while (!CODAVUOTA(coda)) {
            NODO u = LEGGICODA(coda);
            FUORICODA(coda);
            {visita u}
            if (!SINISTROVUOTO(T, u))
              INCODA(FIGLIOSINISTRO(T, u);
            if (!DESTROVUOTO(T, u))
              INCODA(FIGLIODESTRO(T, u);
          }
        }
        
### Rappresentazione di un albero binario

#### Rappresentazione con vettore
Una possibile rappresentazione di un albero binario è quella **sequenziale** mediante vettore. La radice è in prima posizione; per il generico non p memorizzato in posizione i, se esiste il figlio sinistro è memorizzato in posizione 2i, se esiste il figlio destro è memorizzato in posizione 2i+1. Se l'albero è vuoto, alcune celle del vettore non corrispondono a nulla. Questo potrebbe essere un problema con linguaggi a tipizzazione forte. Conviene utilizzare un **boolean** per indicare che effettivamente in quella posizione c'è un nodo.

#### Rappresentazione con lista
Nella realizzazione con lista valgono le stesse considerazioni fatte per gli alberi *n*-ari ma in questo caso se l'albero è vuoto, la lista è vuota. Se l'albero non è vuoto, contiene:
* La **radice*
* Una lista che rappresenta il **sotto-albero sinistro** nello stesso modo
* Una lista che rappresenta il **sotto-albero destro** nello stesso modo

#### Rappresentazione con lista attraverso puntatori
Gli alberi binari si possono anche rappresentare attraverso una lista con puntatori per rendere **dinamica** l'implementazione.

## Grafo
Il **grafo** è una struttura composta da **nodi** e **archi** che rappresenta una relazione binaria sull'insieme costituito dai nodi. 
* I nodi sono usati per rappresentare oggetti;
* Gli archi per rappresentare relazioni tra coppie di oggetti.

#### Notazione di un grafo
Indichiamo il grafo con

> G = (N, A)

Dove

> **N** è l'insieme finito dei **nodi**

> **A** è un insieme finito di coppie ordinate di nodi rappresentanti gli **archi orientati**

### Specifica sintattica
**Tipi**:
* grafo, boolean, nodo, lista, tipoelem

**Operatori**:
* crea: ( ) &rightarrow; grafo
* vuoto: (grafo) &rightarrow; boolean
* insnodo: (grafo, nodo) &rightarrow; grafo
* insarco: (grafo, nodo, nodo) &rightarrow; grafo
* cancnodo: (grafo, nodo) &rightarrow; grafo
* cancarco: (grafo, nodo, nodo) &rightarrow; grafo
* adiacenti: (grado, nodo) &rightarrow; lista
* esistenodo: (grafo, nodo) &rightarrow; boolean
* esistearco: (grafo, nodo, nodo) &rightarrow; boolean
* legginodo: (grafo, nodo) &rightarrow; tipoelem
* scrivinodo: (grafo, nodo, tipoelem) &rightarrow; grafo

### Specifica semantica
**Tipi**:
* **grafo**: insieme G = (N, A) con N sottoinsieme finito di elementi di tipo **nodo**
* **nodo**: insieme finito qualsiasi
* **lista**: lista di elementi di tipo **nodo**
* **boolean**: insieme dei valori di verità

**Operatori**:
* `crea() = G`
  * **Precondizione:** *(nessuna)*
  * **Postcondizione:** G = (N, A) con N = &emptyset; e A = &emptyset;
* `vuoto(G) = b`
  * **Precondizione:** *(nessuna)*
  * **Postcondizione:** G = (N, A) con N = &emptyset; e A = &emptyset;
    * **Vero**, b = true
    * **Falso**, b = false
* `insnodo(G, u) = G'`
  * **Precondizione:** G = (N, A), u &in; N
  * Postcondizione:** G' = (N', A) con N' = N &cup; {u}
* `insarco(G, u, v) = G'`
  * **Precondizione:** G = (N, A), u &in; N, v &in; N, {u, v} &notin; A
  * **Postcondizione:** G' = (N, A') con A' = A &cup; {(u, v)}
* `cancnodo(G, u) = G'`
  * **Precondizione:** G = (N, A), u &in; N
  * **Postcondizione:** G' = (N', A) con N' = N \ {u}
* `cancarco(G, u, v) = G'`
  * **Precondizione:** G = (N, A), u &in; N, v &in; N, (u, v) &in; A
  * **Postcondizione:** G' = (N, A') con A' = A \ {(u, v)}
* `adiacenti(G, u) = L`
  * **Precondizione:** G = (N, A), u &in; N
  * **Postcondizione:** L è una lista che contiene una e una sola volta gli elmenti di A(u) = {v &in; N | (u, v) &in; A}
* `esistenodo(G, u) = b`
  * **Precondizione:** G = (N, A)
  * **Postcondizione:** u &in; N
    * **Vero**, b = true
    * **Falso**, b = false
* `esistearco(G, u, v) = b`
  * **Precondizione:** G = (N, A), u &in; N, v &in; N
  * **Postcondizione:** (u, v) &in; A
    * **Vero**, b = true
    * **Falso**, b = false
* `legginodo(G, u) = a`
  * **Precondizione:** G = (N, A), u &in; N
  * **Postcondizione:** a è il valore del nodo n in G
* `scrivinodo(G, u, a) = G'`
  * **Precondizione:** G = (N, A), u &in; N
  * **Postcondizione:** G' si ottiene da G aggiungendo il valore di a al nodo u
  
####### Oltre ai già considerati *legginodo* e *scrivinodo*, potrebbero avere senso altri due operatori denominati *leggiarco* e *scriviarco*.

### Rappresentazione di un grafo

#### Rappresentazione con matrice di adiacenza
La più semplice rappresentazione utilizza una matrice N x N. Se il grafo è pesato, nella matrice si utilizzano i pesi degli archi al posto degli elementi binari. Nel caso in cui il grafo non sia orientato, la matrice risulterà simmetrica rispetto alla diagonale principale.

#### Rappresentazione con matrice di adiacenza estesa
Aggiungendo
* MARK, flag che ha valore falso o 0 se il nodo è stato rimosso
* ARCHI, contiene il numero somma degli entranti e uscenti dal generico nodo
si ottiene una matrice di adiacenza estesa.

#### Rappresentazione con vettore di adiacenza
Un'altra rappresenzazione prevede l'implementazione del grafo con due vettori, il vettore NODI e il vettore ARCHI. Il vettore NODI è formato da N elementi e NODI(i) contiene un cursore alla posizione di ARCHI a partire dalla quale è memorizzato A(i).

#### Rappresentazione con lista di adiacenza
Se il grafo non è orientato, è necessario rappresentare ogni arco due volte. Se i grafi sono etichettati sui nodi e/o sugli archi, i pesi possono essere memorizzati in vettori PESINODI(n) e PESIARCHI(m).

In alternativa, si può utilizzare un vettore di nodi A ed n liste. Una generica componente A(i) del vettore è il puntatore alla lista i-esima in cui sono memorizzati i nodi adiacenti a i.

### Visita di un grafo
Esistono dei metodi sistematici per esplorare un grafo "visitando" almeno una volta ogni nodo ed ogni arco di un **grafo non orientato e connesso** oppure **orientato e fortemente connesso**.

Si illustrano **due** algoritmi:
* **Depth first search (DFS)**: l'alrgoritmo prevede che contrassegniamo un vertice appena lo visitiamo e poi cerchiamo di spostarci in un vertice adiacente non contrassegnato. Se non ci sono vertici non marcati, indietreggiamo lungo i vertici già visitati finchè arriviamo ad un vertice che risulta adiacente ad uno non visitato e continuiamo così il procedimento.

        DFS (G: grafo; u: nodo)
          {esamina il nodo u e marcalo "visitato"}
          for (TUTTI I v € A(u)) do
            {esamina l'arco (u, v)}
            if (v NON E' "VISITATO") then
              DFS(G, v)

* **Breadth first search (BFS)**: in questo schema ogni vertice adiacente al vertice corrente è visitato prima di spostarsi dal vertice corrente stesso. I nodi sono visitati in ordine di distanza crescente dal nodo di partenza u, dove la distanza da u ad un generico nodo v è il minimo numero di archi in un cammino da u a v. Conviene tenere in una coda i vertici visitati ma non completamente "esaminati".

        BFS (G: grafo; u:nodo)
          CREACODA(Q)
          INCODA(Q, u)
          while not (CODAVUOTA(Q)) do 
            u = LEGGICODA(Q)
            FUORICODA(Q)
            {esamina u e marcalo "visitato"}
            for (TUTTI I NODI v € A(u)) do
              {esamina l'arco (u, v)}
              if (n non è marcato "visitato" and v !€ Q) then
                INCODA(Q, v)
                
### Algoritmo generale di visita di un grafo

        repeat
          "SCEGLI UN NODO j DA Q"
          if (ESISTE UN NODO NON VISITATO ADIACENTE A j) then
            "VISITA E PONI IN R E IN Q UNO O PIU' NODI k1, k2, ... ADIACENTI A j E NON ANCORA VISITATI"
            "PONI IN B GLI ARCHI (j, k1), (j, k2), ..."
          else "ELIMINA j DA Q"
        until (Q = {})
  
## Code con priorità
### Specifica sintattica
**Tipi:**
* prioricoda, tipoelem

**Operatori:**
* creaprioricoda: () &rightarrow; prioricoda
* inserisci: (tipoelem, prioricoda) &rightarrow; prioricoda
* min: (prioricoda) &rightarrow; tipoelem
* cancellamin: (prioricoda) &rightarrow; prioricoda

### Specifica semantica
**Tipi:**
* **prioricoda**: insieme di code con priorità con elementi di tipo **tipoelem**

**Operatori:**
* `creaprioricoda() = A`
  * **Precondizione**: *nessuna*
  * **Postconizione**: A = &emptyset;
* `inserisci(x, A) = A'`
  * **Precondizione:** x &notin; A
  * **Postcondizione:** A' = A &cup; {x}
* `min(A) = x`
  * **Precondizione:** A &ne; &emptyset;
  * **Postcondizione:** x &in; A e x < y &forall; y &in; A, x &ne; y
* `cancellamin(A) = A'`
  * **Precondizione:** A &ne; &emptyset;
  * **Postcondizione:** A' = A \ {x}, x = `min(A)`
