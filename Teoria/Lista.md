# Lista

## Indice
1. **[Notazione di una lista](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Lista.md#notazione-di-una-lista)**
2. **[Accesso ad una lista](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Lista.md#accesso-ad-una-lista)**
3. **[Operazioni in una lista](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Lista.md#operazioni-in-una-lista)**
4. **[Lunghezza della lista e sottoliste](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Lista.md#lunghezza-della-lista-e-sottoliste)**
5. **[Specifica sintattica](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Lista.md#specifica-sintattica)**
6. **[Specifica semantica](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Lista.md#specifica-semantica)**
7. **[Rappresentazione di una lista](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Lista.md#rappresentazione-di-una-lista)**
8. **[Complessità di una lista](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Complessit%C3%A0.md#lista)**

Una lista è una sequenza **finita**, anche vuota, di elementi dello **stesso tipo** che possono comparire anche più volte in posizioni diverse (è differente rispetto al concetto di insieme).
Gli elementi della lista, cui sono associate informazioni, sono definiti **atomi** o **nodi**.

## Notazione di una lista
Indichiamo la lista con la notazione

> l = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > con n &ge; 0

Ad ogni elemento della lista viene associata

> una **posizione** (cursore) pos(i)

> un **valore** a(i)

## Accesso ad una lista
Si può accedere **direttamente solo al primo elemento** della sequenza (**accesso diretto**); per accedere al generico elemento occorre **scandire sequenzialmente** gli elementi della lista che lo precedono (**accesso per scansione**).

## Operazioni in una lista
Nelle operazioni, è possibile **inserire** e **cancellare** elementi; poichè la lista è a **dimensione variabile**, essa è una struttura dati **dinamica**.

## Lunghezza della lista e sottoliste
La **lunghezza di una lista** è il numero dei suoi elementi. Se il numero di elementi è zero, la lista si dice **vuota**.
La lunghezza conta le posizioni, non i simboli distinti, così un simbolo che compare *k* volte, contribuisce con *k* unità alla lunghezza della lista (ad esempio, se il valore '210' compare *10* volte nella lista, verrà contato *10* volte).

Se l = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > è una lista, allora per ogni *i* e *j* tali che

> 1 &le; *i* &le; *j* &le; n

La sottolista

> < a<sub>i</sub>, ..., a<sub>j</sub> >

si ottiene partendo dalla posizione *i* e prendendo tutti gli elementi fino alla posizione *j* ed è **sottolista** di l

La lista vuota < > è sottolista di qualsiasi lista.

## Specifica sintattica
**Tipi**:
* lista, posizione, boolean, tipoelem

**Operatori**:
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

## Specifica semantica
**Tipi**:
* **lista**: insieme delle sequenze l = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> > con n &ge; 0 di elementi di tipo **tipoelem** dove l'elemento *i*-esimo ha valore *a(i)* e **posizione** *pos(i)*
* **boolean**: insieme dei valori di verità

**Operatori**:
* `crealista() = l'`
  * **Precondizione:** *(nessuna)*    
  * **Postcondizione:** l' = < >    
* `listavuota(l) = b`
  * **Precondizione:** *(nessuna)*    
  * **Postcondizione:** se l = < >
    * Vero, b = true
    * Falso, b = false
* `leggilista(l, p) = a`
  * **Precondizione:** p = pos(i) con 1 &le; i &le; n    
  * **Postcondizione:** a = a(i)    
* `scrivilista(l, p, a) = l'`
  * **Precondizione:** p = pos(i) con 1 &le; i &le; n    
  * **Postcondizione:** l' = < a<sub>1</sub>, a<sub>2</sub>, ..., **a**, ..., a<sub>n</sub> >    
* `primolista(l) = p`
  * **Precondizione:** p = pos(i) con 1 &le; i &le; n    
     * Oppure si può scrivere come, listavuota(l) = false        
  * **Postcondizione:** p = pos(1)    
* `finelista(l, p) = b`
  * **Precondizione:** p = pos(i) con 1 &le; i &le; n+1    
     * Includo n+1 perchè devo poter accedere anche all'ultima posizione        
  * **Postcondizione:** se p = pos(n+1)
    * Vero, b = true
    * False, b = false
* `succlista(l, p) = q`
   * **Precondizione:** p = pos(i) con 1 &le; i &le; n    
      * Posso arrivare solo fino alla penultima posizione        
   * **Postcondizione:** q = pos(i+1)    
* `predlista(l, p) = q`
   * **Precondizione:** p = pos(i) con 1 < i &le; n    
      * Posso partire solo dalla seconda posizione        
   * **Postcondizione:** q = pos(i-1)    
* `inslista(l, p, a) = l'`
   * **Precondizione:** p = pos(i) con 1 &le; i &le; n+1    
      * Posso inserire qualcosa anche in ultima posizione        
   * **Postcondizione:** l' = < a<sub>1</sub>, a<sub>2</sub>, ..., **a<sub>i</sub>**, ..., a<sub>n</sub> >    
      * Se ne possono aggiungere altre 2 per i casi i = n+1 e i = 1        
* `canclista(l, p) = l'`
   * **Precondizione:** p = pos(i) con 1 &le; i &le; n    
   * **Postcondizione:** l' = < a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>i-1</sub>, a<sub>i+1</sub>, ..., a<sub>n</sub> >

| Caso | Complessità |
|------|-------------|
| Memorizzare gli elementi della lista in un vettore | O(1) |
| Inserzione o cancellazione di un elemento | O(n) |
| Rappresentazione con con puntatori/cursori | O(1) per tutte le operazioni |

## Rappresentazione di una lista

### Rappresentazione collegata
Le liste si possono rappresentare sia in maniera **sequenziale** mediante un vettore che attraverso una rappresentazione **collegata**, memorizzando i suoi elementi associando ad ognuno di essi una particolare informazione (riferimento) che permetta di individuare la locazione in cui è memorizzato l'elemento successivo. Per visualizzare tale rappresentazione si usa una notazione grafica in cui:
* Gli elementi sono rappresentati mediante **nodi**
* I riferimenti mediante **archi** che collegano nodi

### Rappresentazione con cursori
Si può anche rappresentare mediante **cursori** utilizzando un vettore per la lista e realizzando i riferimenti mediante cursori il cui valore è interpretato come indice di un vettore (ad esempio, pos(i) è un cursore).

### Rappresentazione collegata mediante puntatori
Un'altra rappresentazione è quella con **puntatori** e la struttura record per realizzare una **lista collegata**. Una possibile realizzazione prevede una lista monodirezionale semplificata in cui vi è una struttura di *n* elementi o **"celle"**, tale che l'*i*-esima cella contiene l'*i*-esimo elemento della lista e l'indirizzo della cella che contiene l'elemento successivo. In tal modo:
* La **prima cella** è indirizzata da una variabile *l* di tipo puntatore
* L'**ultima cella** punta a un valore convenzionale *nil*
* Gli indirizzi sono noti alla macchina ma non al programmatore
* La posizione *pos(i)* è uguale al valore del puntatore alla cella che contiene l'*i*-esimo elemento con 1 &le; *i* &le; n

Una variante della precedente rappresentazione è quella a **doppi puntatori** (o simmetrica) in cui ogni elemento contiene, oltre al riferimento al nodo successivo, anche il riferimento al precedente. La lista può essere "espansa" con una cella in più per la **realizzazione circolare**.
