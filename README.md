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
