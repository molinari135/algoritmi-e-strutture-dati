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

## Lista
Una lista è una sequenza finita, anche vuota, di elementi dello stesso tipo che possono comparire anche più volte in posizioni diverse (è differente rispetto al concetto di insieme).
Gli elementi della lista, cui sono associate informazioni, sono definiti **atomi** o **nodi**.

#### Notazione di una lista

Indichiamo la lista con la notazione

> l = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > con n &ge; 0

Ad ogni elemento della lista viene associata una posizione (cursore)

> pos(i)

e un valore

> a(i)

### Accesso ad una lista
Si può accedere **direttamente solo al primo elemento** della sequenza (**accesso diretto**); per accedere al generico elemento occorre **scandire sequenzialmente** gli elementi della lista che lo precedono (**accesso per scansione**).

### Operazioni in una lista
Nelle operazioni, è possibile **inserire** e **cancellare** elementi; poichè la lista è a **dimensione variabile**, essa è una struttura dati **dinamica**.

### Lunghezza della lista e sottoliste
La **lunghezza di una lista** è il numero dei suoi elementi. Se il numero di elementi è zero, la lista si dice **vuota**.
La lunghezza conta le posizioni, non i simboli distinti, così un simbolo che compare *k* volte, contribuisce con *k* unità alla lunghezza della lista (ad esempio, se il valore '210' compare *10* volte nella lista, verrà contato *10* volte).

Se l = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > è una lista, allora per ogni *i* e *j* tali che

> 1 &le; *i* &le; *j* &le; n

La sottolista

> < a<sub>i</sub>, ..., a<sub>j</sub> >

si ottiene partendo dalla posizione *i* e prendendo tutti gli elementi fino alla posizione *j* ed è **sottolista** di l

La lista vuota < > è sottolista di qualsiasi lista.

### Specifica sintattica
Tipi:
* lista, posizione, boolean, tipoelem

Operatori:
* crealista: ( ) &rightarrow; lista
* listavuota: (lista) &rightarrow; boolean
* leggilista: (lista, posizione) &rightarrow; tipoelem
* scrivilista: (lista, posizione, tipoelem) &rightarrow; lista
* primolista: (lista) &rightarrow; posizione
* finelista: (lista, posizione) &rightarrow; boolean
* succlista: (lista, posizione) &rightarrow; posizione
* predlista: (lista, posizione) &rightarrow; posizione
* inslista: (lista, posizione, tipoelem) &rightarrow; lista
* canclista: (lista, posizione) &rightarrow; lista

### Specifica semantica
Tipi:
* lista: insieme delle sequenze l = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > con n &ge; 0 di elementi di tipo tipoelem dove l'elemento *i*-esimo ha valore *a(i)* e posizione *pos(i)*
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
  * Precondizione: p = pos(i) con 1 &le; i &le; n    
  * Postcondizione: a = a(i)    
* scrivilista(l, p, a) = l'
  * Precondizione: p = pos(i) con 1 &le; i &le; n    
  * Postcondizione: l' = < a<sub>1</sub>, a<sub>2</sub>, ..., **a**, ..., a<sub>n</sub> >    
* primolista(l) = p
  * Precondizione: p = pos(i) con 1 &le; i &le; n    
     * Oppure si può scrivere come, listavuota(l) = false        
  * Postcondizione: p = pos(1)    
* finelista(l, p) = b
  * Precondizione: p = pos(i) con 1 &le; i &le; n+1    
     * Includo n+1 perchè devo poter accedere anche all'ultima posizione        
  * Postcondizione: se p = pos(n+1)
    * Vero, b = true
    * False, b = false
* succlista(l, p) = q
   * Precondizione: p = pos(i) con 1 &le; i &le; n    
      * Posso arrivare solo fino alla penultima posizione        
   * Postcondizione: q = pos(i+1)    
* predlista(l, p) = q
   * Precondizione: p = pos(i) con 1 < i &le; n    
      * Posso partire solo dalla seconda posizione        
   * Postcondizione: q = pos(i-1)    
* inslista(l, p, a) = l'
   * Precondizione: p = pos(i) con 1 &le; i &le n+1    
      * Posso inserire qualcosa anche in ultima posizione        
   * Postcondizione: l' = < a<sub>1</sub>, a<sub>2</sub>, ..., **a<sub>i</sub>**, ..., a<sub>n</sub> >    
      * Se ne possono aggiungere altre 2 per i casi i = n+1 e i = 1        
* canclista(l, p) = l'
   * Precondizione: p = pos(i) con 1 &le; i &le; n    
   * Postcondizione: l' = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>i-1</sub>, a<sub>i+1</sub>, ..., a<sub>n</sub> >

### Realizzazione di una lista

#### Rappresentazione collegata
Le liste si possono rappresentare sia in maniera **sequenziale** mediante un vettore che attraverso una rappresentazione **collegata**, memorizzando i suoi elementi associando ad ognuno di essi una particolare informazione (riferimento) che permetta di individuare la locazione in cui è memorizzato l'elemento successivo. Per visualizzare tale rappresentazione si usa una notazione grafica in cui:
* Gli elementi sono rappresentati mediante **nodi**
* I riferimenti mediante **archi** che collegano nodi

#### Rappresentazoine con cursori

Si può anche rappresentare mediante **cursori** utilizzando un vettore per la lista e realizzando i riferimenti mediante cursori il cui valore è interpretato come indice di un vettore (ad esempio, pos(i) è un cursore).

#### Rappresentazione collegata mediante puntatori

Un'altra rappresentazione è quella con **puntatori** e la struttura record per realizzare una **lista collegata**. Una possibile realizzazione prevede una lista monodirezionale semplificata in cui vi è una struttura di *n* elementi o **"celle"**, tale che l'*i*-esima cella contiene l'*i*-esimo elemento della lista e l'indirizzo della cella che contiene l'elemento successivo. In tal modo:
* La **prima cella** è indirizzata da una variabile *l* di tipo puntatore
* L'**ultima cella** punta a un valore convenzionale *nil*
* Gli indirizzi sono noti alla macchina ma non al programmatore
* La posizione *pos(i)* è uguale al valore del puntatore alla cella che contiene l'*i*-esimo elemento con 1 &le; *i* &le; n

Una variante della precedente rappresentazione è quella a **doppi puntatori** (o simmetrica) in cui ogni elemento contiene, oltre al riferimento al nodo successivo, anche il riferimento al precedente. La lista può essere "espansa" con una cella in più per la **realizzazione circolare**.

## Pila
Una **pila** è una sequenza di elementi di un certo tipo.

#### Notazione di una pila

Indichiamo la pila con la notazione

> P = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > con n &ge; 0

### Accesso ad una pila
Gli accessi possibili sono applicati unicamente **ad un solo estremo**, ovvero la "testa" (**accesso agli estremi**).

### Operazioni in una pila
Tutte le operazioni vanno effettuate **solo all'estremo superiore** della pila, ovvero alla sua sommità. Può essere vista come un **caso speciale di lista** in cui l'ultimo elemento inserito è il primo ad essere rimosso (**LIFO**) e non è possibile accedere ad alcun elemento che non sia quello in testa.

###### LIFO: Last In, First Out (L'ultimo inserito è il primo che viene tirato fuori)

### Specifica sintattica
Tipi: 
* pila, boolean, tipoelem

Operatori:
* creapila: ( ) &rightarrow; pila
* pilavuota: (pila) &rightarrow; boolean
* leggipila: (pila) &rightarrow; tipoelem
* fuoripila: (pila) &rightarrow; pila
* inpila: (pila, tipoelem) &rightarrow; pila

### Specifica semantica
Tipi:
* pila: insieme delle sequenze P = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > con n &ge; 0 di elementi di tipo tipoelem gestita con accesso LIFO
* boolean: insieme dei valori di verità

Operatori:
* creapila() = P
  * Precondizione: *(nessuna)*
  * Postcondizione: P = < >
* pilavuota(P) = b
  * Precondizione: *(nessuna)*
  * Postcondizione: se P = < >
    * Vero, b = true
    * Falso, b = false
* leggipila(P) = a
  * Precondizione: P = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > con n &ge; 1
  * Postcondizione: a = a<sub>1</sub>
* fuoripila(P) = P'
  * Precondizione: P = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > con n &ge; 1
  * Postcondizione: P' = < a<sub>2</sub>, a<sub>3</sub>, ..., a<sub>n</sub> >
    * P' = < > se n = 1
* inpila(P, a) = P'
  * Precondizione: P = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > con n &ge; 0
  * Postcondizione: P' = < **a**, a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> >
  
### Realizzazioni di una pila

La pila è un caso particolare di **lista** e possiamo definire la seguente corripondenza tra gli operatori:
* creapila() &rightarrow; crealista()
* pilavuota(p) &rightarrow; listavuota(p)
* leggipila(p) &rightarrow; leggilista(**primolista(p)**, p)
* fuoripila(p) &rightarrow; canclista(**primolista(p)**, p)
* inpila(p, a) &rightarrow; inslista(**primolista(p)**, p, a)

#### Realizzazione con vettore
Le pile si possono rappresentare mediante vettore memorizzando gli *n* elementi della pila, in **ordine inverso**, nelle prime n posizioni del vettore, mantenendo un **cursore alla testa della pila**. Questa implementazione è svantagiosa perchè richiede di definire una dimensione degli elementi massimi della pila.

#### Realizzazione con puntatori
Si possono anche implementare utilizzando i **puntatori**, riferendosi alla cella che si trova in cima con un puntatore.

### Pile e procedure ricorsive
L'esecuzione di una procedura ricorsiva prevede il salvataggio dei dati su cui lavora la procedura al momento della chiamata ricorsiva. Tali dati vengono "ripristinati" quando la computazione "interna" termina in quanto è un meccanismo **LIFO**. Le diverse chiamate attive sono organizzate in una pila. Nella pila vanno salvati i **parametri** (e le eventuali variabili locali), il **punto di ritorno**, cioè l'etichetta della istruzione da cui ripartire al termine della computazione "interna". Grazie alle pile è sempre possibile, dato un programma ricorsivo, trasformarlo in uno iterativo.

## Coda
Una **coda** è un tipo astratto che consente di rappresentare una sequenza di elementi in un cui è possibile aggiungere elementi dal "fondo" e toglierli dalla "testa".

#### Notazione di una coda

Indichiamo la coda con la notazione

> q = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > con n &ge; 0

### Accesso ad una coda
Per poter **aggiungere** elementi si accede ad un estremo ("fondo") mentre per poterli **togliere** si accede all'estremo opposto ("testa"). Il funzionamento è identico a quello di una fila ad una cassa (**accesso agli estremi**).

### Operazioni in una coda
Le operazioni vengono effettuate solo **in prima ed ultima posizione**.

### Specifica sintattica
Tipi: 
* coda, boolean, tipoelem

Operatori:
* creacoda: ( ) &rightarrow; coda
* codavuota: (coda) &rightarrow; boolean
* leggicoda: (coda) &rightarrow; tipoelem
* fuoricoda: (coda) &rightarrow; coda
* incoda: (coda, tipoelem) &rightarrow; coda

### Specifica semantica
* creacoda() = q
  * Precondizione: *(nessuna)*
  * Postcondizione: q = < >
* codavuota(q) = b
  * Precondizione: *(nessuna)*
  * Postcondizione: se q = < >
    * Vero, b = true
    * Falso, b = false
* leggicoda(q) = a
  * Precondizione: q = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > con n &ge; 1
  * Postcondizione: a = a<sub>1</sub>
* fuoricoda(q) = q'
  * Precondizione: q = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > con n &ge; 1
  * Postcondizione: q' = < a<sub>2</sub>, ..., a<sub>n</sub> >
    * q' = < > se n = 1
* incoda(q, a) = q'
  * Precondizione: q = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > con n &ge; 0
  * Postcondizione: q' = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>, **a**>
  
### Realizzazioni di una coda

In generale le possibili rappresentazioni delle code sono analoghe a quelle delle **pile** consentendo solo l'accesso sia all'elemento inserito per primo sia all'elemento inserito per ultimo.

#### Rappresentazione con puntatori
La coda può essere rappresentata con *n* celle, la prima delle quali è indirizzata da un **puntatore "testa"** e l'ultima da un **puntatore "fondo"**. La coda vuota è individuata dal valore nullo *null* del puntatore di testa.

#### Rappresentazione con vettore circolare
Per le code la rappresentazione sequenziale non è agevole come per le pile, quindi è utile **gestire l'array in modo circolare**. Il vettore circolare è inteso come un array di *maxlung* elementi, con indice da 0 a *maxlung - 1*, in cui consideriamo l'elemento di indice 0 come successore di quello di indice *maxlung - 1*. Si utilizzano due variabili:
- **Primo**: indica la posizione dell'array in cui è memorizzato l'elemento inserito per primo
- **Ultimo**: si riferisce all'ultimo elemento inserito (oppure definisce la lunghezza della coda)

## Insieme
Un **insieme** è una collezione di elementi di tipo omogeneo. A differenza delle liste, **gli elementi non sono caratterizzati da una posizione** nè possono apparire più di una volta.

#### Notazione di un insieme
In matematica possono essere definiti *estensionalmente*

> A = { giallo, rosso, blu }

oppure *intensionalmente* attraverso le proprietà che devono avere i componenti

> B = { numeri reali compresi tra 0 e 1 }

In informatica ci riferiamo al modo **estensionale**.

### Operazioni in un insieme
Le operazioni principali sono **unione, intersezione e differenza**.

### Specifica sintattica
Tipi:
* insieme, boolean, tipoelem

Operatori:
* creainsieme: ( ) &rightarrow; insieme
* insiemevuoto: (insieme) &rightarrow; boolean
* appartiene: (insieme, tipoelem) &rightarrow; boolean
* inserisci: (insieme, tipoelem) &rightarrow; insieme
* cancella: (insieme, tipoelem) &rightarrow; insieme
* unione: (insieme, insieme) &rightarrow; insieme
* intersezione: (insieme, insieme) &rightarrow; insieme
* differenza: (insieme, insieme) &rightarrow; insieme

### Specifica semantica
Tipi:
* **insieme**: collezione di elementi di tipo **tipoelem**
* **boolean**: insieme dei valori di verità

Operatori:
* creainsieme() = A
  * Precondizione: *(nessuna)*
  * Postcondizione: A = { }
* insiemevuoto(A) = b
  * Precondizione: *(nessuna)*
  * Postcondizione: se A = { }
    * Vero, b = true
    * Falso, b = false
* appartiene(A, x) = b
  * Precondizione: *(nessuna)*
  * Postcondizione: x &in; A
    * Vero, b = true
    * Falso, b = false
* inserisci(A, x) = A'
  * Precondizione: x &notin; A
  * Postcondizione: A' = A &cup; {x}
* cancella(A, x) = A'
  * Precondizione: x &in; A
  * Postcondizione: A' = A \ {x}
* unione(A, B) = C
  * Precondizione: *(nessuna)*
  * Postcondizione: C = A &cup; B
* intersezione(A, B) = C
  * Precondizione: *(nessuna)*
  * Postcondizione: C = A &cap; B
* differenza(A, B) = C
  * Precondizione: *(nessuna)*
  * Postcondizione: C = A \ B
  
### Realizzazioni di un insieme

#### Realizzazione con liste non ordinate
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

- L'operatore *appartiene* deve scorrere tutta la lista per verificare se l'elemento è presente;
- L'operatore *inserisci* deve chiamare *appartiene* e se l'elemento non è presente nella lista lo deve inserire;
- L'operatore *cancella* è simila ad *appartiene*, dopo aver individuato l'elemento lo deve rimuovere dalla lista;
- Gli operatori *insersezione, unione e differenza* devono scandire la lista:
  - *Unione*: inserisci in C tutti gli elementi di B, poi inserisci gli elementi di A se non appartiengono a C;
  - *Intersezione*: C vuoto, scorri A se l'elemento è in B lo metti in C;
  - *Differenza*: C vuoto, scorri A se l'elemento non è in B lo metti in C;

#### Realizzazione con liste ordinate
Se è definita una relazione &le; di ordinamento totale sugli elementi dell'insieme, esso può essere rappresentato con una lista ordinata per valori crescenti degli elementi utilizzando due puntatori che scorrono ognuno su un insieme.

- L'operatore *appartiene* effettua una ricerca in una lista ordinata;
- L'operatore *inserimento* richiede di scandire tutta la lista, nella peggiore delle ipotesi;
- L'operatore *cancellazione* effettua una ricerca in una lista ordinata;
- Le operazioni *unione, intersezione, differenza* sono facilitate dal fatto di poter scorrere due liste ordinate;

### Altre implementazioni
Esistono altri modi per rappresentare gli insiemi tramite **dizionario** e con un **albero bilanciato**. Quando si fa uso del dizionario, esso conterrà solo chiavi, ovvero gli elementi dell'insieme.

## Dizionario
Il dizionario è un sottotipo del tipo insieme i cui elementi sono generalmente tipi strutturati ai quali si accede per mezzo di un riferimento a un campo chiave.

#### Notazione dizionario
Gli elementi assumono la forma di una coppia costituita da coppie

> <chiave, valore>

- La caratteristica della **chiave** è legata alla applicazione
- Il **valore** associato rappresenta l'informazione associata per scopi di gestinone o manutenzione

### Operazioni in un dizionario
Poichè possiamo definirli un caso particolare di **insieme**, la specifica per i dizionari è molto simile a quella del tipo di dato insieme. Le operazioni ammesse sono:
* crea, appartiene, inserisci, cancella
E in alcuni casi troviamo anche le operazioni:
* recupera, aggiorna

### Specifica sintattica
Tipi:
* dizionaio, boolean, chiave, valore

Operatori:
* creadizionario: ( ) &rightarrow; dizionario
* dizionariovuoto: (dizionario) &rightarrow; boolean
* appartiene: (dizionario, chiave) &rightarrow; boolean
* inserisci: (dizionario, <chiave, valore>) &rightarrow; dizionario
* cancella: (dizionario, chiave) &rightarrow; dizionario
* recupera: (dizionario, chiave) &rightarrow; valore

### Specifica semantica
Tipi:
* **dizionario**: collezione di dizionari costituita da coppie di tipo **<chiave, valore>**
* **boolean**: insieme dei valori di verità

Operatori:
* creadizionario() = D
  * Precondizione: *(nessuna)*
  * Postcondizione: D = { }
* dizionariovuoto(D) = b
  * Precondizione: *(nessuna*)
  * Postcondizione: D = { }
    * Vero, b = true
    * Falso, b = false
* appartiene(D, k) = b
  * Precondizione: *(nessuna)*
  * Postcondizione: <k', v> &in; D tale che k' = k
    * Esiste, b = true
    * Non esiste, b = false
* inserisci(D, <k, v>) = D'
  * Precondizione: *(nessuna)*
  * Postcondizione: <k', v'> &in; D tale che k' = k
    * Esiste, D' = D \ {<k', v'} &cup; {<k, v>}
    * Non esiste, D' = D &cup; {<k, v>}
* cancella(D, k) = D'
  * Precondizione: &exists; <k', v> &in; D tale che k' = k
  * Postcondizione: D' = D \ {<k, v>}
* recupera(D, k) = v
  * Precondizione: &exists; <k', v'> &in; D tale che k' = k
  * Postcondizione: v = v'

### Rappresentazioni di un dizionario
Oltre alla rappresentazione con **vettore booleano** e mediante **lista**, ci sono quelle mediante **vettori ordinati** e **tabelle hash**.

#### Rappresentazione con vettore ordinato
Si utilizza un **vettore con un cursore all'ultima posizione occupata**. Avendo definito una **relazione di ordinamento totale &le;** sulle chiavi, queste si memorizzano in posizioni contigue in ordine crescente. Per verificare l'appartenenza di un elemento o di una chiave, si utiilzza la **ricerca binaria**, si confronta il valore da ricercare k con il valore v che occupa la posizione centrale del vettore e si stabilisce in quale metà continuare la ricerca.

#### Rappresentazione con tabella hash
Esiste una tecnica denominata **hash** che si appoggia su una struttura di dati tabellare. Con questa struttura le operazioni di ricerca e di modifica possono operare in **tempi costanti e indipendenti dalla dimensione** del dizionario.

> **Idea base**: ricavare la posizione che la chiave occupa in un vettore dalla chiave stessa.

Esistono diverse varianti che si possono far risalire ad una forma statica e ad una forma dinamica.

L'hash statico può essere a sua volta:
* **hash chiuso**: consente di inserire un insieme limitato di valori in uno spazio a dimensione fissa
  * La struttura sarà composta da un certo numero di contenitori di uguale dimensione denominati *bucket*
* **hash aperto**: consente di memorizzare un insieme di valori di dimensione qualsiasi in uno spazio potenzialmente illimitato
  * La struttura sarà composta da un certo numero indeterminato di contenitori *bucket*
  
Entrambe le varianti però utilizzano una sottostante **tabella hash a dimensione fissa** costituita da una struttura allocata sequenzialmente in memoria e che assume la forma di un array. Ognuno di questi contenitori può mantenere al proprio interno al massimo un numero *nb* di elementi che comprenderanno la chiave e il corrispondente valore.

Viene usata una **funzione aritmetica** allo scopo di calcolare, partendo dalla chiave, la posizione in tabella delle informazioni contenute nell'attributo collegato alla chiave.

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
Una **collisione** si verifica quando chiavi diverse producono lo **stesso risultato della funzione**. Esistono funzioni hash più o meno buone anche se le collisioni non si potranno mai evitare del tutto.

Quale che sia la funzione hash adottata, deve essere prevista una strategia per gestire il problema degli agglomerati e delle collisioni. In definitiva:
- Occorre una **funzione hash**, calcolabile velocemente e che distribuisca le chiavi uniformemente in v, in modo da ridurre le collisioni;
- Occorre un **metodo di scansione** per la soluzione delle collisioni utile a reperire chiavi che hanno trovato a posizione occupata e che non provochi la formazione di agglomerati di chiavi;
- La **dimensione m del vettore v** deve essere una sovrastima del numero delle chiavi attese, per evitare di riempire v completamente.

Alcuni buoni metodi di generazione hash con **b = bin(k)**:
* h(k) = int(b)
  * b è un sottoinsieme di p bit di bin(k), solitamente estratti nelle posizioni centrali
* h(k) = int(b)
  * b è dato dalla somma modulo 2, effettuata bit a bit, di diversi sottoinsiemi di p bit di bin(k)
* h(k) uguale al resto della divisione int(bin(k)) / m
  * m è dispari; se fosse uguale a 2p, due numeri con gli stessi p bit finali darebbero sempre luogo a una collisione
  
L'ultima funzione hash è la migliore dal punto di vista probabilistico e fornisce un'eccellente distribuzione degli indirizzi h(k) nell'intervallo da 0 a m-1.

#### Hash aperto
Una tecnica che **evita la formazione di agglomerati** è quella dell'hash aperto che richiede che la tabella hash mantenga la lista degli elementi le cui chiavi producono lo stesso valore di funzione. La tabella di hash viene realizzata definendo un array di liste di bucket dette **liste di trabocco**.

La funzione di hash viene utilizzata per **determinare quale lista potrbbe contenere l'elemento** che possiede una determinata chiave in modo da poter attivare una successiva operazione di ricerca nella lista corrispondente e da restituire la posizione del bucket che contiene la chiave.

### Metodi di scansione
I metodi di scansione si distinguono in:
- **Scansione esterna**
- **Scansione interna**
  - **Scansione lineare**
    - Non riduce la formazione di agglomerati
  - **Scansione quadratica**
    - La sequenza di scansione non include tutte le posizioni di v (trascurabile per m non troppo piccolo)
  - **Scansione pseudocasuale**
    - Genera interi tra 1 e m una sola volta in un ordine qualunque
  - **Hashing doppio**
    - Genera due funzioni di hash, l'una diversa dall'altra e le usa per effettuare dei calcoli
   
Usando metodi di scansione interna e potendo cancellare chiavi, non si è mai sicuri che, raggiunta una posizione vuota nella ricerca di k, tale chiave non si trovi in un'altra posizione di v, poichè la posizione ora vuota era occupata quando k è stata inserita. Se sono previste molte cancellazioni, conviene usare un metodo di scansione esterno.

## Albero

### Definizione di grafo

#### Notazione di un grafo
Un **grafo** G è definito dalla coppia **<N, A>** dove
* **N** è l'insieme dei **nodi**
* **A** è l'insieme degli **archi**

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
Tipi:
* albero, boolean, nodo

Operatori:
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
Tipi:
* **albero**: insieme degli alberi ordinati T = <N, A> in cui ad ogni nodo n in N è associato il livello(n)
* **boolean**: insieme dei valori di verità
* **nodo**: insieme qualsiasi (finito)

Operatori:
* creaalbero() = T'
  * Precondizione: *(nessuna)*
  * Postcondizione: T' = (&emptyset;, &emptyset;) = &wedge;
* alberovuoto(T) = b
  * Precondizione: *(nessuna)*
  * Postcondizione: se T = &wedge;
    * Vero, b = true
    * Falso, b = false
* insradice(T, u) = T'
  * Precondizione: T = &wedge;
  * Postcondizione: T' = (N, A), N = {u}, livello(u) = 0, A &ne; (0, 0)
* radice(T) = u
  * Precondizione: T &ne; &wedge;, &exists; v tale che livello(v) = 0
  * Postcondizione: u = v
* padre(T, u) = v
  * Precondizione: T &ne; &wedge;, u &in; N, livello(u) > 0
  * Postcondizione: <v, u> &in; A, livello(u) = livello(v) + 1
* foglia(T, u) = b
  * Precondizione: T &ne; &wedge;, u &in; N
  * Postcondizione: &exists; v &in; A con livello(v) = livello(u) + 1
    * Non esiste, b = true
    * Esiste, b = false
* primofiglio(T, u) = v
  * Precondizione: T &ne; &wedge;, u &in; N, foglia(T, u) = false
  * Postcondizione: <u, v> &in; A, livello(v) = livello(u) + 1
* ultimofratello(T, u) = b
  * Precondizione: T &ne; &wedge;, u &in; N
  * Postcondizione: se altri fratelli di u che lo seguono nella relazione d'ordine
    * Non esistono, b = true
    * Esistono, b = false
* succfratello(T, u) = v
  * Precondizione: T &ne; &wedge;, u &in; N, ultimofratello(T, u) = false
  * Postcondizione: v è il fratello di u che lo segue nella relazione d'ordine
* insprimosottoalbero(T, T', u) = T''
  * Precondizione: T &ne; &wedge;, T' &ne; &wedge;, u &in; N
  * Postcondizione: T'' è l'albero ottenuto da T aggiungendo l'albero T' di radice r'
    * r' diventa nuovo primo figlio di u
* inssottoalbero(T, T', u) = T''
  * Precondizione: T &ne; &wedge;, T' &ne; &wedge;, u &in; N, u non è radice di T
  * Postcondizione: T'' è l'albero ottenuto da T aggiungendo il sottoalbero T' di radice r'
    * r' diventa il nuovo fratello che segue u nella relazione d'ordine
* cansottoalbero(T, u) = T'
  * Precondizione: T &ne; &wedge;, u &in; N
  * Postcondizione: T' è ottenuto da T rimuovendo il sottoalbero di radice u
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
        
### Realizzazioni

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
  
## Albero binaro
Un **albero binario** è un albero ordinato in cui ogni nodo ha al più **due** figli e si fa distinzione tra il **figlio sinistro** ed il **figlio destro** di un nodo.

Due alberi T e U aventi gli stessi nodi, gli stessi figli per ogni nodo e la stessa radice, sono distinti qualora un nodo u sia designato come figlio sinistro di un nodo v in T e come figlio destro del medesimo nodo in U.

[Immagine albero binario]

Ogni albero *n*-ario ordinato T si può rappresentare con un albero binario B avente gli stessi nodi e la stessa radice: in B ogni nodo ha come figlio sinistro il primo figlio in T e come figlio destro il fratello successivo in T. L'equivalenza vale ai fini della **previsita**. Le sequenze di nodi esaminati su T e B coincidono se T e B sono visitati in previsita.

### Specifica sintattica
Tipi:
* alberobin, boolean, nodo

Operatori:
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
Tipi:
* **alberobin**: insieme degli alberi binari T = (N, A), nei quali ad ogni nodo è associato un livello
* **boolean**: insieme dei valori di verità
* **nodo**: unità dell'albero

Operatori:
* creabinalbero() = T'
  * Precondizione: *(nessuna*)
  * Postcondizione: T' = (&emptyset;, &emptyset;) = &wedge;
* binalberovuoto(T) = b
  * Precondizione: *(nessuna*)
  * Postcondizione: T = &wedge;
    * Vero, b = true
    * Falso, b = false
* binradice(T) = u
  * Precondizione: T &ne; &wedge;
  * Postcondizione: livello(u) = 0
    * u &rightarrow; radice di T
* binpadre(T, u) = v
  * Precondizione: T &ne; &wedge;, u &in; N, livello(u) > 0
  * Postcondizione: (v, u) &in; A, livello(v) = livello(u) - 1
    * v &rightarrow; padre di u
* figliosinistro(T, u) = v
  * Precondizione: T &ne; &wedge;, u &in; N, sinistrovuoto(T, u) = false
  * Postcondizione: v &rightarrow; figlio sinistro di u in T
* figliodestro(T, u) = v
  * Precondizione: T &ne; &wedge;, u &in; N, destrovuoto(T, u) = false
  * Postconizione: v &rightarrow; figlio destro di u in T
* sinistrovuoto(T, u) = b
  * Precondizione: T &in; &wedge;, u &in; N
  * Postcondizione: u ha un figlio sinistro
    * Vero, b = false
    * Falso, b = true
* destrovuoto(T, u) = b
  * Precondizione: T &ne; &wedge;, u &in; N
  * Postcondizione: u ha un figlio destro
    * Vero, b = false
    * Falso, b = true
* costrbinalbero(T, T') = T''
  * Precondizione: *(nessuna)*
  * Postcondizione: T'' si ottiene da T e T' introducendo automaticamente un nuovo nodo r'' (radice di T'') che avrà come sottoalbero sinistro T e sottoalbero destro T'
    * Se T e T' sono vuoti, l'operatore inserisce la sola radice r''
    * Se solo T è vuoto, r'' non avrà figlio sinistro
    * Se solo T' è vuoto, r'' non avrà figlio destro
 * cancsottobinalbero(T, u) = T'
  * Precondizione: T &ne; &wedge;
  * Postcondizione: T' si ottiene da T eliminando il sottoalbero di radice u, con tutti i suoi discendenti
  
### Operatori aggiuntivi - Specifica sintattica
Tipi:
* tipoelem

Operatori:
* legginodo: (alberobin, nodo) &rightarrow; tipoelem
* scrivinodo: (alberobin, nodo, tipoelem) &rightarrow; alberobin

### Operatori aggiuntivi - Specifica semantica
Tipi:
* **tipoelem**: tipo dell'etichetta del nodo (int, char, ...)

Operatori:
* legginodo(T, u) = a
  * Precondizione: T &ne; &wedge;, u &in; N, u è un nodo di T
  * Postcondizione: a è il valore associato al nodo n in T
* scrivinodo(T, u, a) = T'
  * Precondizione: T &ne; &wedge;, n &in; N, n è un nodo di T
  * Postcondizione: T' si ottiene assegnando al nodo n il valore a nell'albero T
  
### Note sugli alberi binari
Nell'algebra precedente si enfatizza la natura **ricorsiva** degli alberi e di costruire l'albero binario dal basso verso l'alto, cioè dal livello delle foglie verso la radice. Questa scelta non sempre è opportuna e occorre sostituire l'operatore di costruzione con tre operatori nuovi:

### Nuovi operatori - Specifica sintattica
Operatori:
* insbinradice: (alberobin, nodo) &rightarrow; alberobin
* insfigliosinistro: (alberobin, nodo) &rightarrow; alberobin
* insfigliodestro: (alberobin, nodo) &rightarrow; alberobin

### Nuovi operatori - Specifica semantica
Operatori:
* insbinradice(T, u) = T'
  * Precondizione: T = &wedge;
  * Postcondizione: T' = (N, A), N = {u}, livello(u) = 0, A = &emptyset;
* insfigliosinistro(T, u) = T'
  * Precondizione: T &ne; &wedge;, u &in; N, sinistrovuoto(T, u) = true
  * Postcondizione: N' = N &cup; {v}, T' si ottiene da T aggiungendo v come figlio sinistro di u
* insfigliodestro(T, u) = T'
  * Precondizione: T &ne; &wedge;, u &in; N, destrovuoto(T, u) = true
  * Postcondizione: N' = N &cup; {v}, T' si ottiene da T aggiungendo v come figlio destro di u
  
### Visite
Oltre alle visite per gli alberi n-ari, ci sono:
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
        
### Realizzazione di un albero binario

#### Realizzazione con vettore
Una possibile rappresentazione di un albero binario è quella **sequenziale** mediante vettore. La radice è in prima posizione; per il generico non p memorizzato in posizione i, se esiste il figlio sinistro è memorizzato in posizione 2i, se esiste il figlio destro è memorizzato in posizione 2i+1. Se l'albero è vuoto, alcune celle del vettore non corrispondono a nulla. Questo potrebbe essere un problema con linguaggi a tipizzazione forte. Conviene utilizzare un **boolean** per indicare che effettivamente in quella posizione c'è un nodo.

#### Realizzazione con lista
Nella realizzazione con lista valgono le stesse considerazioni fatte per gli alberi *n*-ari ma in questo caso se l'albero è vuoto, la lista è vuota. Se l'albero non è vuoto, contiene:
* La **radice*
* Una lista che rappresenta il **sotto-albero sinistro** nello stesso modo
* Una lista che rappresenta il **sotto-albero destro** nello stesso modo

#### Realizzazione con lista attraverso puntatori
Gli alberi binari si possono anche rappresentare attraverso una lista con puntatori per rendere **dinamica** l'implementazione.

## Grafo
Il **grafo** è una struttura composta da **nodi** e **archi** che rappresenta una relazione binaria sull'insieme costituito dai nodi. 
* I nodi sono usati per rappresentare oggetti;
* Gli archi per rappresentare relazioni tra coppie di oggetti.

#### Notazione grafo
Indichiamo il grafo con

> G = (N, A)

Dove

> **N** è l'insieme finito dei **nodi**

> **A** è un insieme finito di coppie ordinate di nodi rappresentanti gli **archi orientati**

### Specifica sintattica
Tipi:
* grafo, boolean, nodo, lista, tipoelem

Operatori:
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
Tipi:
* **grafo**: insieme G = (N, A) con N sottoinsieme finito di elementi di tipo **nodo**
* **nodo**: insieme finito qualsiasi
* **lista**: lista di elementi di tipo **nodo**
* **boolean**: insieme dei valori di verità

Operatori:
* crea() = G
  * Precondizione: *(nessuna)*
  * Postcondizione: G = (N, A) con N = &emptyset; e A = &emptyset;
* vuoto(G) = b
  * Precondizione: *(nessuna)*
  * Postcondizione: G = (N, A) con N = &emptyset; e A = &emptyset;
    * Vero, b = true
    * Falso, b = false
* insnodo(G, u) = G'
  * Precondizione: G = (N, A), u &in; N
  * Postcondizione: G' = (N', A) con N' = N &cup; {u}
* insarco(G, u, v) = G'
  * Precondizione: G = (N, A), u &in; N, v &in; N, {u, v} &notin; A
  * Postcondizione: G' = (N, A') con A' = A &cup; {(u, v)}
* cancnodo(G, u) = G'
  * Precondizione: G = (N, A), u &in; N
  * Postcondizione: G' = (N', A) con N' = N \ {u}
* cancarco(G, u, v) = G'
  * Precondizione: G = (N, A), u &in; N, v &in; N, (u, v) &in; A
  * Postcondizione: G' = (N, A') con A' = A \ {(u, v)}
* adiacenti(G, u) = L
  * Precondizione: G = (N, A), u &in; N
  * Postcondizione: L è una lista che contiene una e una sola volta gli elmenti di A(u) = {v &in; N | (u, v) &in; A}
* esistenodo(G, u) = b
  * Precondizione: G = (N, A)
  * Postcondizione: u &in; N
    * Vero, b = true
    * Falso, b = false
* esistearco(G, u, v) = b
  * Precondizione: G = (N, A), u &in; N, v &in; N
  * Postcondizione: (u, v) &in; A
    * Vero, b = true
    * Falso, b = false
* legginodo(G, u) = a
  * Precondizione: G = (N, A), u &in; N
  * Postcondizione: a è il valore del nodo n in G
* scrivinodo(G, u, a) = G'
  * Precondizione: G = (N, A), u &in; N
  * Postcondizione: G' si ottiene da G aggiungendo il valore di a al nodo u
  
####### Oltre ai già considerati *legginodo* e *scrivinodo*, potrebbero avere senso altri due operatori denominati *leggiarco* e *scriviarco*.

### Realizzazione

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
                
### Algoritmo generale di visita

        repeat
          "SCEGLI UN NODO j DA Q"
          if (ESISTE UN NODO NON VISITATO ADIACENTE A j) then
            "VISITA E PONI IN R E IN Q UNO O PIU' NODI k1, k2, ... ADIACENTI A j E NON ANCORA VISITATI"
            "PONI IN B GLI ARCHI (j, k1), (j, k2), ..."
          else "ELIMINA j DA Q"
        until (Q = {})
  
