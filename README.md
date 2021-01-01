# Strutture dati
###### Realizzazioni di varie strutture dati con specifica sintattica e semantica

Ci sono strutture dati che si sviluppano in una dimensione e possono essere considerate come sequenze di oggetti. Queste strutture sono dette lineari.
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

#### In questa tabella vengono riassunti i tipi di accesso e le operazioni applicate sulle varie strutture dati

Nome struttura | Tipo di accesso | Operazioni
---------------|-----------------|-----------
Lista | Diretto (primo elemento), Scansione | Si possono effettuare su qualsiasi elemento
Pila | Diretto (primo elemento), Estremi (solo un estremo) | Si possono effettuare solo al primo elemento
Coda | Diretto (primo ed ultimo elemento), Estremi | Si possono effettuare alcune al primo elemento e altre solo all'ultimo

## Lista
Una lista è una sequenza finita, anche vuota, di elementi dello stesso tipo che possono comparire anche più volte in posizioni diverse (è differente rispetto al concetto di insieme).
Gli elementi della lista, cui sono associate informazioni, sono definiti **atomi** o **nodi**.

[Notazione lista]
Indichiamo la lista con la notazione

> l = < a1, a2, ..., an > con n >= 0

Ad ogni elemento della lista viene associata una posizione

> pos(i)

e un valore

> a(i)

### Accesso lista
Si può accedere direttamente solo al primo elemento della sequenza (**accesso diretto**); per accedere al generico elemento occorre scandire sequenzialmente gli elementi della lista che lo precedono (**accesso per scansione**).

### Operazioni lista
Nelle operazioni, è possibile aggiungere (inserire) e togliere (cancellare) elementi; poichè la lista è a **dimensione variabile**, essa è una struttura dati **dinamica**.

### Lunghezza e sottoliste
La lunghezza di una lista è il numero dei suoi elementi. Se il numero di elementi è zero, la lista si dice vuota.
La lunghezza conta le posizioni, non i simboli distinti, così un simbolo che compare *k* volte, contribuisce con *k* unità alla lunghezza della lista (ad esempio, se il valore '210' compare *10* volte nella lista, verrà contato *10* volte).

Se l = < a1, a2, ..., an > è una lista, allora per ogni *i* e *j* tali che

> 1 <= *i* <= *j* <= n

La sottolista

> < a*i*, ..., a*j* >

si ottiene partendo dalla posizione *i* e prendendo tutti gli elementi fino alla posizione *j* ed è **sottolista** di l

La lista vuota < > è sottolista di qualsiasi lista.

### Specifica sintattica
Tipi:
* lista
* posizione
* boolean
* tipoelem

Operatori:
* crealista: ( ) -> lista
* listavuota: (lista) -> boolean
* leggilista: (lista, posizione) -> tipoelem
* scrivilista: (lista, posizione, tipoelem) -> lista
* primolista: (lista) -> posizione
* finelista: (lista, posizione) -> boolean
* succlista: (lista, posizione) -> posizione
* predlista: (lista, posizione) -> posizione
* inslista: (lista, posizione, tipoelem) -> lista
* canclista: (lista, posizione) -> lista

### Specifica semantica
Tipi:
* lista: insieme delle sequenze l = < a1, a2, ..., an > con n >= 0 di elementi di tipo tipoelem dove l'elemento *i*-esimo ha valore *a(i)* e posizione *pos(i)*
* boolean: insieme dei valori di verità

Operatori:
* crealista() = l'  
  * Precondizione: nessuna    
  * Postcondizione: l' = < >    
* listavuota(l) = b
  * Precondizione: nessuna    
  * Postcondizione: b = true se l = < >; b = false altrimenti    
* leggilista(l, p) = a
  * Precondizione: p = pos(i) con 1 <= i <= n    
  * Postcondizione: a = a(i)    
* scrivilista(l, p, a) = l'
  * Precondizione: p = pos(i) con 1 <= i <= n    
  * Postcondizione: l' = < a1, a2, ..., a, ..., an >    
* primolista(l) = p
  * Precondizione: p = pos(i) con 1 <= i <= n    
     * Oppure, listavuota(l) = false        
  * Postcondizione: p = pos(1)    
* finelista(l, p) = b
  * Precondizione: p = pos(i) con 1 <= i <= n+1    
     * Includo n+1 perchè devo poter accedere anche all'ultima posizione        
  * Postcondizione: b = true se p = pos(n+1); b = false altrimenti    
* succlista(l, p) = q
   * Precondizione: p = pos(i) con 1 <= i <= n    
      * Posso arrivare solo fino alla penultima posizione        
   * Postcondizione: q = pos(i+1)    
* predlista(l, p) = q
   * Precondizione: p = pos(i) con 1 < i <= n    
      * Posso partire solo dalla seconda posizione        
   * Postcondizione: q = pos(i-1)    
* inslista(l, p, a) = l'
   * Precondizione: p = pos(i) con 1 <= i <= n+1    
      * Posso inserire qualcosa anche in ultima posizione        
   * Postcondizione: l' = < a1, a2, ..., ai, ..., an >    
      * Se ne possono aggiungere altre 2 per i casi i = n+1 e i = 1        
* canclista(l, p) = l'
   * Precondizione: p = pos(i) con 1 <= i <= n    
   * Postcondizione: l' = < a1, a2, ..., a(i-1), a(i+1), ..., an>

### Realizzazioni
Le liste si possono rappresentare sia in maniera sequenziale mediante un vettore che attraverso una rappresentazione collegata, memorizzando i suoi elementi associando ad ognuno di essi una particolare informazione (riferimento) che permetta di individuare la locazione in cui è memorizzato l'elemento successivo. Per visualizzare tale rappresentazione si usa una notazione grafica in cui:
* Gli elementi sono rappresentati mediante **nodi**
* I riferimenti mediante **archi** che collegano nodi

[Rappresentazione collegata]

Si può anche rappresentare mediante cursori utilizzando un vettore per la lista e realizzando i riferimenti mediante cursori il cui valore è interpretato come indice di un vettore.

[Rappresentazione con cursori]

Un'altra rappresentazione è quella con puntatori e la struttura record per realizzare una lista collegata. Una possibile realizzazione prevede una lista monodirezionale semplificata in cui vi è una struttura di *n* elementi o "celle", tale che l'*i*-esima cella contiene l'*i*-esimo elemento della lista e l'indirizzo della cella che contiene l'elemento successivo.
* La prima cella è indirizzata da una variabile *l* di tipo puntatore
* L'ultima cella punta a un valore convenzionale *nil*
* Gli indirizzi sono noti alla macchina ma non al programmatore
* La posizione *pos(i)* è uguale al valore del puntatore alla cella che contiene l'*i*-esimo elemento con 1 <= *i* <= n

[Rappresentazione collegata mediante puntatori]

Una variante della precedente rappresentazione è quella a doppi puntatori (o simmetrica) in cui ogni elemento contiene, oltre al riferimento al nodo successivo, anche il riferimento al precedente. La lista può essere "espansa" con una cella in più per la realizzazione circolare.

## Pila
Una pila è una sequenza di elementi di un certo tipo.

[Notazione pila]
Indichiamo la pila con la notazione

> P = < a1, a2, ..., an > con n >= 0

### Accesso pila
Gli accessi possibili sono applicati unicamente ad un solo estremo, ovvero la "testa" (accesso agli estremi).

### Operazioni pila
Tutte le operazioni vanno effettuate solo all'estremo superiore della pila, ovvero alla sua sommità. Può essere vista come un caso speciale di lista in cui l'ultimo elemento inserito è il primo ad essere rimosso (LIFO) e non è possibile accedere ad alcun elemento che non sia quello in testa.

### Specifica sintattica
Tipi: pila, boolean, tipoelem
Operatori:
* creapila: ( ) -> pila
* pilavuota: (pila) -> boolean
* leggipila: (pila) -> tipoelem
* fuoripila: (pila) -> pila
* inpila: (pila, tipoelem) -> pila

### Specifica semantica
Tipi:
* pila: insieme delle sequenze P = < a1, a2, ..., an > con n >= 0 di elementi di tipo tipoelem gestita con accesso LIFO
* boolean: insieme dei valori di verità

Operatori:
* creapila() = P
  * Precondizione: nessuna
  * Postcondizione: P = < >
* pilavuota(P) = b
  * Precondizione: nessuna
  * Postcondizione: b = true se P = < >; b = false altrimenti
* leggipila(P) = a
  * Precondizione: P = < a1, a2, ..., an> con n >= 1
  * Postcondizione: a = a1
* fuoripila(P) = P'
  * Precondizione: P = < a1, a2, ..., an > con n >= 1
  * Postcondizione: P' = < a2, a3, ..., an >
    * P' = < > se n = 1
* inpila(P, a) = P'
  * Precondizione: P = < a1, a2, ..., an > con n >= 0
  * Postcondizione: P' = < a, a1, a2, ..., an >
  
### Realizzazioni
La pila è un caso particolare di lista e possiamo definire la seguente corripondenza tra gli operatori:
* creapila() -> crealista()
* pilavuota(p) -> listavuota(p)
* leggipila(p) -> leggilista(primolista(p), p)
* fuoripila(p) -> canclista(primolista(p), p)
* inpila(p, a) -> inslista(primolista(p), p, a)

Le pile si possono rappresentare mediante vettore memorizzando gli *n* elementi della pila, in **ordine inverso**, nelle prime n posizioni del vettore, mantenendo un cursore alla testa della pila. Questa implementazione è svantagiosa perchè richiede di definire una dimensione degli elementi massimi della pila.

[Realizzazione con vettore]

Si possono anche implementare utilizzando i puntatori, riferendosi alla cella che si trova in cima con un puntatore.

[Realizzazione con puntatori]

### Pile e procedure ricorsive
L'esecuzione di una procedura ricorsiva prevede il salvataggio dei dati su cui lavora la procedura al momento della chiamata ricorsiva. Tali dati vengono "ripristinati" quando la computazione "interna" termina in quanto è un meccanismo LIFO. Le diverse chiamate attive sono organizzate in una pila. Nella pila vanno salvati i parametri (e le eventuali variabili locali), il punto di ritorno, cioè l'etichetta della istruzione da cui ripartire al termine della computazione "interna". Grazie alle pile è sempre possibile, dato un programma ricorsivo, trasformarlo in uno iterativo.

## Coda
Una coda è un tipo astratto che consente di rappresentare una sequenza di elementi in un cui è possibile aggiungere elementi dal "fondo" e toglierli dalla "testa".

[Notazione coda]
Indichiamo la coda con la notazione

> q = < a1, a2, ..., an> con n >= 0

### Accesso coda
Per poter aggiungere elementi si accede ad un estremo ("fondo") mentre per poterli togliere si accede all'estremo opposto ("testa"). Il funzionamento è identico a quello di una fila ad una cassa (accesso agli estremi).

### Operazioni coda
Le operazioni vengono effettuate solo in prima ed ultima posizione.

### Specifica sintattica
Tipi: coda, boolean, tipoelem
Operatori:
* creacoda: ( ) -> coda
* codavuota: (coda) -> boolean
* leggicoda: (coda) -> tipoelem
* fuoricoda: (coda) -> coda
* incoda: (coda, tipoelem) -> coda

### Specifica semantica
* creacoda() = q
  * Precondizione: nessuna
  * Postcondizione: q = < >
* codavuota(q) = b
  * Precondizione: nessuna
  * Postcondizione: b = true se q = < >; b = false altrimenti
* leggicoda(q) = a
  * Precondizione: q = < a1, a2, ..., an> con n >= 1
  * Postcondizione: a = a1
* fuoricoda(q) = q'
  * Precondizione: q = < a1, a2, ..., an > con n >= 1
  * Postcondizione: q' = < a2, ..., an >
    * q' = < > se n = 1
* incoda(q, a) = q'
  * Precondizione: q = < a1, a2, ..., an > con n >= 0
  * Postcondizione: q' = < a1, a2, ..., an, a >
  
### Realizzazioni
In generale le possibili rappresentazioni delle code sono analoghe a quelle delle pile consentendo solo l'accesso sia all'elemento inserito per primo sia all'elemento inserito per ultimo.

La coda può essere rappresentata con *n* celle, la prima delle quali è indirizzata da un puntatore "testa" e l'ultima da un puntatore "fondo". La coda vuota è individuata dal valore nullo *null* del puntatore di testa.

[Realizzazione con puntatori]

Per le code la rappresentazione sequenziale non è agevole come per le pile, quindi è utile gestire l'array in modo circolare. Il vettore circolare è inteso come un array di *maxlung* elementi, con indice da 0 a *maxlung - 1*, in cui consideriamo l'elemento di indice 0 come successore di quello di indice *maxlung - 1*. Si utilizzano due variabili:
1. Primo: indica la posizione dell'array in cui è memorizzato l'elemento inserito per primo
2. Ultimo: si riferisce all'ultimo elemento inserito (oppure definisce la lunghezza della coda)

[Realizzazione con vettore circolare]
