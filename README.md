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
* lista, posizione, boolean, tipoelem

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
  * Postcondizione: se l = < >
    * Vero, b = true
    * Falso, b = false
* leggilista(l, p) = a
  * Precondizione: p = pos(i) con 1 <= i <= n    
  * Postcondizione: a = a(i)    
* scrivilista(l, p, a) = l'
  * Precondizione: p = pos(i) con 1 <= i <= n    
  * Postcondizione: l' = < a1, a2, ..., a, ..., an >    
* primolista(l) = p
  * Precondizione: p = pos(i) con 1 <= i <= n    
     * Oppure si può scrivere come, listavuota(l) = false        
  * Postcondizione: p = pos(1)    
* finelista(l, p) = b
  * Precondizione: p = pos(i) con 1 <= i <= n+1    
     * Includo n+1 perchè devo poter accedere anche all'ultima posizione        
  * Postcondizione: se p = pos(n+1)
    * Vero, b = true
    * False, b = false
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
Tipi: 
* pila, boolean, tipoelem

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
  * Postcondizione: se P = < >
    * Vero, b = true
    * Falso, b = false
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
Tipi: 
* coda, boolean, tipoelem

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
  * Postcondizione: se q = < >
    * Vero, b = true
    * Falso, b = false
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

## Insieme
Un insieme è una collezione di elementi di tipo omogeneo. A differenza delle liste, gli elementi non sono caratterizzati da una posizione nè possono apparire più di una volta.

[Notazione insieme]
In matematica possono essere definiti *estensionalmente*

> A = { giallo, rosso, blu }

oppure *intensionalmente* attraverso le proprietà che devono avere i componenti

> B = { numeri reali compresi tra 0 e 1 }

In informatica ci riferiamo al modo **estensionale**

### Operazioni insieme
Le operazioni principali sono **unione, intersezione e differenza**.

### Specifica sintattica
Tipi:
* insieme, boolean, tipoelem

Operatori:
* creainsieme: ( ) -> insieme
* insiemevuoto: (insieme) -> boolean
* appartiene: (insieme, tipoelem) -> boolean
* inserisci: (insieme, tipoelem) -> insieme
* cancella: (insieme, tipoelem) -> insieme
* unione: (insieme, insieme) -> insieme
* intersezione: (insieme, insieme) -> insieme
* differenza: (insieme, insieme) -> insieme

### Specifica semantica
Tipi:
* insieme: collezione di elementi di tipo tipoelem
* boolean: insieme dei valori di verità

Operatori:
* creainsieme() = A
  * Precondizione: nessuna
  * Postcondizione: A = { }
* insiemevuoto(A) = b
  * Precondizione: nessuna
  * Postcondizione: se A = { }
    * Vero, b = true
    * Falso, b = false
* appartiene(A, x) = b
  * Precondizione: nessuna
  * Postcondizione: se x appartiene ad A
    * Vero, b = true
    * Falso, b = false
* inserisci(A, x) = A'
  * Precondizione: x non appartiene ad A
  * Postcondizione: A' = A U {x}
* cancella(A, x) = A'
  * Precondizione: x appartiene ad A
  * Postcondizione: A' = A \ {x}
* unione(A, B) = C
  * Precondizione: nessuna
  * Postcondizione: C = A U B
* intersezione(A, B) = C
  * Precondizione: nessuna
  * Postcondizione: C = A int. B
* differenza(A, B) = C
  * Precondizione: nessuna
  * Postcondizione: C = A \ B
  
### Realizzazioni
Un insieme si può rappresentare con un vettore booleano se il linguaggio utilizzato non prevede il tipo insieme. Per rappresentare un insieme A di interi, si fa uso di un vettore booleano di *n* bit, il cui *k*-esimo valore sarà *vero* se k appartiene ad A e *falso* altrimenti.
Un'altra rappresentazione si avvale di una lista i cui elementi sono quelli dell'insieme, così da evitare che gli elementi siano assolutamente degli interi.

[Realizzazioni con liste non ordinate]

Gli elementi della lista sono quelli dell'insieme. Nel caso si usino realizzazioni con strutture dinamiche, l'occupazione di memoria è proporzionale al numero degli elementi presenti nell'insieme. Si fa uso delle seguenti classi (OOP):

`class Cella {
  tipoelem elemento;
  posizione successivo;
}`

`class Insieme {
  Cella* posizione;
}`

L'inserimento avviene in testa alla lista semplice con cui è realizzato l'insieme sempre dopo aver controllato se l'elemento da inserire non sia già presente nella struttura.

- L'operatore *appartiene* deve scorrere tutta la lista per verificare se l'elemento è presente;
- L'operatore *inserisci* deve chiamare *appartiene* e se l'elemento non è presente nella lista lo deve inserire;
- L'operatore *cancella* è simila ad *appartiene*, dopo aver individuato l'elemento lo deve rimuovere dalla lista;
- Gli operatori *insersezione, unione e differenza* devono scandire la lista:
  - *Unione*: inserisci in C tutti gli elementi di B, poi inserisci gli elementi di A se non appartiengono a C;
  - *Intersezione*: C vuoto, scorri A se l'elemento è in B lo metti in C;
  - *Differenza*: C vuoto, scorri A se l'elemento non è in B lo metti in C;

[Realizzazione con liste ordinate]

Se è definita una relazione <= di ordinamento totale sugli elementi dell'insieme, esso può essere rappresentato con una lista ordinata per valori crescenti degli elementi utilizzando due puntatori che scorrono ognuno su un insieme.

- L'operatore *appartiene* effettua una ricerca in una lista ordinata;
- L'operatore *inserimento* richiede di scandire tutta la lista, nella peggiore delle ipotesi;
- L'operatore *cancellazione* effettua una ricerca in una lista ordinata;
- Le operazioni *unione, intersezione, differenza* sono facilitate dal fatto di poter scorrere due liste ordinate;

### Altre implementazioni
Esistono altri modi per rappresentare gli insiemi tramite dizionario e con un albero bilanciato. Quando si fa uso del dizionario, esso conterrà solo chiavi, ovvero gli elementi dell'insieme.

## Dizionario
Il dizionario è un sottotipo del tipo insieme i cui elementi sono generalmente tipi strutturati ai quali si accede per mezzo di un riferimento a un campo chiave.

[Notazione dizionario]
Gli elementi assumono la forma di una coppia costituita da coppie

> <chiave, valore>

- La caratteristica della chiave è legata alla applicazione
- Il valore associato rappresenta l'informazione associata per scopi di gestinone o manutenzione

### Operazioni insieme
Poichè possiamo definirli un caso particolare di insieme, la specifica per i dizionari è molto simile a quella del tipo di dato insieme. Le operazioni ammesse sono:
* crea, appartiene, inserisci, cancella
E in alcuni casi troviamo anche le operazioni:
* recupera, aggiorna

### Specifica sintattica
Tipi:
* dizionaio, boolean, chiave, valore

Operatori:
* creadizionario: ( ) -> dizionario
* dizionariovuoto: (dizionario) -> boolean
* appartiene: (dizionario, chiave) -> boolean
* inserisci: (dizionario, <chiave, valore>) -> dizionario
* cancella: (dizionario, chiave) -> dizionario
* recupera: (dizionario, chiave) -> valore

### Specifica semantica
Tipi:
* dizionario: collezione di dizionari costituita da coppie di tipo <chiave, valore>
* boolean: insieme dei valori di verità

Operatori:
* creadizionario() = D
  * Precondizione: nessuna
  * Postcondizione: D = { }
* dizionariovuoto(D) = b
  * Precondizione: nessuna
  * Postcondizione: se D = { }
    * Vera, b = true
    * Falsa, b = false
* appartiene(D, k) = b
  * Precondizione: nessuna
  * Postcondizione: se <k', v> in D tale che k' = k
    * Esiste, b = true
    * Non esiste, b = false
* inserisci(D, <k, v>) = D'
  * Precondizione: nessuna
  * Postcondizione: se <k', v'> in D tale che k' = k
    * Esiste, D' = D \ {<k', v'} U {<k, v>}
    * Non esiste, D' = D U {<k, v>}
* cancella(D, k) = D'
  * Precondizione: esiste <k', v> in D tale che k' = k
  * Postcondizione: D' = D \ {<k, v>}
* recupera(D, k) = v
  * Precondizione: esiste <k', v'> in D tale che k' = k
  * Postcondizione: v = v'

### Rappresentazioni
Oltre alla rappresentazione con vettore booleano e mediante lista, ci sono quelle mediante vettori ordinati e tabelle hash.

[Rappresentazione con vettore ordinato]

Si utilizza un vettore con un cursore all'ultima posizione occupata. Avendo definito una relazione di ordinamento totale <= sulle chiavi, queste si memorizzano in posizioni contigue in ordine crescente. Per verificare l'appartenenza di un elemento o di una chiave, si utiilzza la **ricerca binaria**, si confronta il valore da ricercare k con il valore v che occupa la posizione centrale del vettore e si stabilisce in quale metà continuare la ricerca.

[Rappresentazione con tabella hash]

Esiste una tecnica denominata **hash** che si appoggia su una struttura di dati tabellare. Con questa struttura le operazioni di ricerca e di modifica possono operare in tempi costanti e indipendenti dalla dimensione del dizionario.

* Idea base: ricavare la posizione che la chiave occupa in un vettore dalla chiave stessa

Esistono diverse varianti che si possono far risalire ad una forma statica e ad una forma dinamica.

L'hash statico può essere a sua volta:
* **hash chiuso**: consente di inserire un insieme limitato di valori in uno spazio a dimensione fissa
  * La struttura sarà composta da un certo numero di contenitori di uguale dimensione denominati *bucket*
* **hash aperto**: consente di memorizzare un insieme di valori di dimensione qualsiasi in uno spazio potenzialmente illimitato
  * La struttura sarà composta da un certo numero indeterminato di contenitori *bucket*
  
Entrambe le varianti però utilizzano una sottostante tabella hash a dimensione fissa costituita da una struttura allocata sequenzialmente in memoria e che assume la forma di un array.

Ognuno di questi contenitori può mantenere al proprio interno al massimo un numero 
*nb* di elementi che comprenderanno la chiave e il corrispondente valore.

Viene usata una funzione aritmetica allo scopo di calcolare, partendo dalla chiave, la posizione in tabella delle informazioni contenute nell'attributo collegato alla chiave.

Se *k* è l'insieme di tutte le possibili chiavi distinte e *v* è il vettore di dimensione *m* in cui si memorizza il dizionario, la soluzione ideale è la funzione di accesso

> h: K -> { 1, ..., m }

che permette di ricavare la posizione

> h(k)

della chiave *k* nel vettore *v* così che, se

> k1 appartiene a K, k2 appartiene a K, k1 <> k2

si ha che 

> h(k1) <> h(k2)

Utilizzando m = |K| si ha garanzia di biunivocità e di poter accedere direttamente alla posizione contenente la chiave. Però se |K| è grande, si ha uno spreco di memoria.

La soluzione di compromesso è scegliere un m maggiore di 1 ma molto minore di |K|.

### Collisioni
Una collisione si verifica quando chiavi diverse producono lo stesso risultato della funzione. Esistono funzioni hash più o meno buone anche se le collisioni non si potranno mai evitare del tutto.

Quale che sia la funzione hash adottata, deve essere prevista una strategia per gestire il problema degli agglomerati e delle collisioni. In definitiva:
- Occorre una funziona hash, calcolabile velocemente e che distribuisca le chiavi uniformemente in v, in modo da ridurre le collisioni;
- Occorre un metodo di scansione per la soluzione delle collisioni utile a reperire chiavi che hanno trovato a posizione occupata e che non provochi la formazione di agglomerati di chiavi;
- La dimensione m del vettore v deve essere una sovrastima del numero delle chiavi attese, per evitare di riempire v completamente.

Alcuni buoni metodi di generazione hash con b = bin(k):
* h(k) = int(b)
  * b è un sottoinsieme di p bit di bin(k), solitamente estratti nelle posizioni centrali
* h(k) = int(b)
  * b è dato dalla somma modulo 2, effettuata bit a bit, di diversi sottoinsiemi di p bit di bin(k)
* h(k) uguale al resto della divisione int(bin(k)) / m
  * m è dispari; se fosse uguale a 2p, due numeri con gli stessi p bit finali darebbero sempre luogo a una collisione
  
L'ultima funzione hash è la migliore dal punto di vista probabilistico e fornisce un'eccellente distribuzione degli indirizzi h(k) nell'intervallo da 0 a m-1.

[Hash aperto]

Una tecnica che evita la formazione di agglomerati è quella dell'hash aperto che richiede che la tabella hash mantenga la lista degli elementi le cui chiavi producono lo stesso valore di funzione.

La tabella di hash viene realizzata definendo un array di liste di bucket dette **liste di trabocco**.

La funzione di hash viene utilizzata per determinare quale lista potrbbe contenere l'elemento che possiede una determinata chiave in modo da poter attivare una successiva operazione di ricerca nella lista corrispondente e da restituire la posizione del bucket che contiene la chiave.

[Lista di trabocco]

### Metodi di scansione
I metodi di scansione si distinguono in:
- Scansione esterna
- Scansione interna
  - Scansione lineare
    - Non riduce la formazione di agglomerati
  - Scansione quadratica
    - La sequenza di scansione non include tutte le posizioni di v (trascurabile per m non troppo piccolo)
  - Scansione pseudocasuale
    - Genera interi tra 1 e m una sola volta in un ordine qualunque
  - Hashing doppio
    - Genera due funzioni di hash, l'una diversa dall'altra e le usa per effettuare dei calcoli
   
Usando metodi di scansione interna e potendo cancellare chiavi, non si è mai sicuri che, raggiunta una posizione vuota nella ricerca di k, tale chiave non si trovi in un'altra posizione di v, poichè la posizione ora vuota era occupata quando k è stata inserita. Se sono previste molte cancellazioni, conviene usare un metodo di scansione esterno.

## Albero

