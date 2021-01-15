# Calcolo della complessità

Nel calcolo della complessità si usano le seguenti notazioni:
* **O (O-grande)**
  * Utilizzata per il calcolo del **caso pessimo** di un algoritmo; corrisponde al limite superiore della sua complessità (**&ge;**)
* **&Omega; (Omega-grande)**
  * Utilizzata per il calcolo del **caso ottimo** di un algoritmo; corrisponde al limite inferiore della sua complessità (**&le;**)
* **&Theta; (Theta-grande)**
  * Utilizzata quando il limite inferiore e il limite superiore coincidono (**=**)

Per risolvere un problema, si cerca di scoprire algoritmi di complessità sempre più bassa. Se si riesce a dimostrare che qualunque algoritmo per il problema in esame deve avere complessità **&Omega;(f(n))**, allora si è stabilita una limitazione inferiore alla complessità del problema.
Se **f(n) = g(n)**, allora l'algoritmo è detto **ottimo**, perchè la sua complessità e, in ordine di grandezza, la migliore possibile.

## Lista
Per valutare la complessità di una procedura che utilizzi le operazioni di una struttura dati lista, occorre prima conoscere la complessità di ogni operazione impiegata, ovvero conoscere la realizzazione della struttura dati di tipo "lista".

Le possibili realizzazioni sono:
* **Memorizzare gli elementi della lista in un vettore**
  * Permette agevolmente, in tempo O(1), di passare da un elemento al successivo o al precedente, di accorgersi se si tenta di superare un estremo della lista, di leggere o modificare il valore di un elemento
  * Presenta due svantaggi, il vettore è a dimensione fissa mentre la lista è a dimensione variabile quindi il numero di elementi della lista deve essere prefissato, inoltre, l'inserzione di un nuovo elemento o la cancellazione di uno vecchio richiedono un tempo O(*n*), poichè è necessario scalare tutti gli elementi di una posizione
* **Realizzazione con puntatori**      
  * In questo caso, la contiguità degli elementi non corrisponde ad una contiguità di memorizzazione; permette di ottenere complessità O(1) per tutte le operazioni, sia di non limitare il massimo numero di elementi presenti nella lista
  * A scapito di un lieve spreco di memoria, utilizzando una realizzazione bidirezionale circolare con sentinella, si ottiene una complessità O(1) per ciascuna operazione; in realtà basta anche una realizzazione monodirezionale circolare per ottenere questo tipo di complessità
  * Solo le operazioni `ultimolista` e `predlista` mantengono una complessità O(*n*)
* **Realizzazione con cursori**
  * Stessi vantaggi dell'uso dei puntatori
  * Anche in questo caso si può fare uso della realizzazione circolare e ottenere gli stessi vantaggi
        
| Realizzazione | Vantaggi | Svantaggi |
|---------------|----------|-----------|
| Vettore | Molte operazioni base con costo O(1) | Inserimento e cancellazione hanno costo O(*n*) |
| Puntatori | Tutte le operazioni hanno costo O(1) | Lieve spreco di memoria per rappresentazioni mono/bidirezionali circolari |
| Cursori | Tutte le operazioni hanno costo O(1) | Lieve spreco di memoria per rappresentazioni circolari |

## Pila e coda
Le possibili realizzazioni sono:
* Fare uso di un vettore
 * Oltre alle realizzazioni per pile e code che si basano su quelle descritte per le lista, ci sono due realizzazioni specifiche, che utilizzano vettori, in cui tutte le operazioni delle pile e delle code continuano ad avere complessità O(1). Tali implementazioni sono utilizzabili quando si è in grado di limitare superiormente con un opportuno valore il numero massimo di elementi che possono essere presenti nella pila o nella coda
* Fare uso di un vettore circolare
 * La complessità di `incoda` è O(1) se viene usata una realizzazione bidirezionale circolare (con o senza sentinella) della lista, altrimenti diventa &Theta;(*n*) usando le altre realizzazioni
* Fare uso dei puntatori
 * Usando le realizzazioni delle liste con puntatori, la complessità di ciascuna operazione per le pile è O(1)

| Realizzazione | Vantaggi | Svantaggi |
|---------------|----------|-----------|
| Vettore | Tutte le operazioni hanno costo O(1) | Sono utilizzabili solo quando si può limitare superiormente il numero massimo di elementi presenti |
| Vettore circolare | Il costo di `incoda` passa da &Theta;(*n*) a O(1) | Lieve spreco di memoria |
| Cursori | Tutte le operazioni hanno costo O(1) | Lieve spreco di memoria |

## Alberi
Gli alberi possiedono tre tipi di visite (previsita, postvisita, invisita) che fanno uso di chiamate ricorsive per ciascun nodo, per un totale di *n* chiamate, dove *n* è il numero di nodi dell'albero. Pertanto, la complessità delle tre procedure di visita è &Theta;(n), purchè si fornisca una realizzazione in cui gli operatori utilizzati nelle procedure di visita richiedano ciascuno O(1) tempo.

Le possibili realizzazioni sono:
* Realizzazione con vettore dei padri
  * Con questa realizzazione è facile visitare i nodi lungo percorsi che vadano dal basso verso l'alto; l'operazione `padre` richiede tempo O(1)
  * Non è chiara la relazione di precedenza tra fratelli, a meno che non se ne assuma una implicitamente, per esempio imponendo che un figlio abbia sempre un numero maggiore del padre e che nodi fratelli siano numerati in modo crescente da sinistra verso destra
  * Ad esempio, la funzione `primofiglio` possiede una complessità O(n)
* Realizzazione con liste di figli
  * Presenta il vantaggio di poter scorrere velocemente tutti i figli di un dato nodo, ma non permette di realizzare efficientemente altri operatori come `padre` o `succfratello`.
  * Anche assumento una realizzazione efficiente per le liste, le complessità di `padre` e `succfratello` non scendono sotto O(n)
  * Per trovare un nodo *u* occorre scandire nel caso pessimo tutte le *n* liste dei figli, per un totale di O(n) tempo
* Realizzazione con puntatori padre/primofiglio/fratello
  * Con questa realizzazione a puntatori (o cursori) padre/primofiglio/fratello, nodo e valore vengono ad assumere, rispettivamente, ruoli analoghi a quelli di posizione e elemento nelle liste
  * Utilizzando i puntatori, ogni operatore, tranne `cancsottoalbero`, richiede tempo O(1) per essere eseguito
  * Per realizzare `cancsottoalbero` in tempo O(1), occorre che ogni cella, oltre a contenere un puntatore (o cursore) al padre e al fratello successivo, contenga anche un puntatore (o cursore) al fratello precedente

| Realizzazione | Vantaggi | Svantaggi |
|---------------|----------|-----------|
| Vettore dei padri | L'operazione padre costa O(1) | Non è chiara la relazione di precedenza tra fratelli |
| Liste dei figli | Scorre molto velocemente tutti i figli | Il costo di `padre` e `succfratello` non scende sotto O(n) |
| Puntatori padre/primofiglio/fratello | Tutte le operazioni hanno costo O(1) tranne `cancsottoalbero` | Aumento dello spreco di memoria, per far scendere il costo di `cancsottoalbero` |

## Alberi binari
La complessità di tutti gli operatori è O(1).
Per calcolare la profondità di un albero ordinato (ovvero il massimo livello delle sue foglie) richiede tempo O(n) poichè presenta una limitazione inferiore &Omega;(n) per la dimensione dei dati.

| Realizzazione | Vantaggi | Svantaggi |
|---------------|----------|-----------|
| Qualsiasi | Tutti gli operatori hanno costo O(1) | Il calcolo della profondità richiede semrpe O(n) |

## Insiemi
Le possibili realizzazioni sono:
* Realizzazione con vettore booleano
  * La complessità di `appartiene`, `inserisci` e `cancella` è O(1), mentre quella di `creainsieme`, `insiemevuoto`, `unione`, `intersezione` e `differenza` è &Theta;(N), perchè occorre scandire l'intero vettore
  * Questa implementazione presenta molti svantaggi:
    * Vi è un notevole spreco di memoria, poichè ogni insieme richiede sempre &Theta;(N) spazio per la sua memorizzazione
    * Alcune operazioni sono troppo lente, perchè richiedono O(N) tempo, anche per insiemi con pochissimi elementi
    * La cardinalità dell'insieme non può superare la costante N
* Realizzazione con liste non ordinate
  * L'occupazione di memoria dell'insieme, anzichè essere semrpe &Theta;(N), cresce linearmente col numero degli elementi effettivamente presenti nell'insieme
  * La complessità di `creainsieme`, `insiemevuoto` è O(1) mentre quella di `appartiene`, `inserisci`, `cancella` è O(n) dove n = |A|, cioè il numero di elementi presenti nell'insieme
  * Qualora la non appartenenza all'insieme sia nota a priori, la complessità di `inserisci` può essere abbassata ad O(1)
* Realizzazione con liste ordinate
  * La complessità degli operatori `unione`, `intersezione` e `differenza` può essere abbassata a O(n+m)
  * La complessità di `inserisci` non può scendere sotto O(n), perchè quando si inserisce un elemento bisogna rispettare l'ordinamento della lista
  * Il tempo richiesto da `appartiene` e `cancella` resta ovviamente O(n)
  
| Realizzazione | Vantaggi | Svantaggi |
|---------------|----------|-----------|
| Vettore booleano | O(1): `appartiene`, `inserisci`, `cancella`; O(N): `creainsieme`, `insiemevuoto`, `unione`, `intersezione`, `differenza` | Spreco di memoria, alcune operazioni sono troppo lente poichè richiedono O(N) tempo; la cardinalità dell'insieme non può superare N |
| Liste non ordinate | O(1): `creainsieme`, `insiemevuoto`; O(n): `appartiene`, `inserisci`, `cancella`; la complessità di `inserisci` può essere abbassata ad O(1) | L'occupazione di memoria cresce linearmente con il numero degli elementi |
| Liste ordinate | `unione`, `intersezione` e `differenza` può essere abbassata a O(n+m); `appartiene` e `cancella` resta O(n) | `inserisci` non può scendere sotto O(n) |

## Dizionari
Le possibili realizzazioni sono:
* Realizzazione con vettore ordinato
  * Si utilizza un vettore con un cursore all'ultima posizione occupata e le chiavi sono memorizzate nel vettore in posizioni contigue e in ordine crescente a partire dalla prima posizione
* Realizzazione con tabella hash
  * La realizzazione del dizionario con tabelle hash si basa sul concetto di ricavare direttamente dal valore della chiave la posizione che la chiave stessa dovrebbe occupare in un vettore
  * Ciascuna operazione, pur avendo complessità O(n) nel caso pessimo, richiede tempo O(1) nel caso medio.
  * Utilizzando un vettore con m = |K| posizioni, si potrebbe accedere direttamente alla posizione contenente la chiave in tempo O(1)
  * Se |K| è grande, questo metodo è improponibile perchè richiede uno spreco enorme di memoria
  
| Realizzazione | Vantaggi | Svantaggi |
|---------------|----------|-----------|
| Vettore ordinato | Implementazione semplice | Costo delle operazioni molto alto |
| Tabella hash | Ogni operazione, pur avento O(n) nel caso pessimo, richiede O(1) nel caso medio | Se il numero delle chiavi è grande, c'è spreco di memoria |
