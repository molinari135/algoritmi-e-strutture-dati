# Code con priorità

## Indice
1. **[Specifica sintattica](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/CodeConPriorit%C3%A0.md#specifica-sintattica)**
2. **[Specifica semantica](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/CodeConPriorit%C3%A0.md#specifica-semantica)** 
3. **[Rappresentazione di una coda con priorità](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/CodeConPriorit%C3%A0.md#rappresentazione-di-una-coda-con-priorit%C3%A0)**
4. **[Realizzazione degli operatori](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/CodeConPriorit%C3%A0.md#realizzazione-degli-operatori)**
5. **[Osservazioni](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/CodeConPriorit%C3%A0.md#osservazioni)**
6. **[Realizzazione con heap](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/CodeConPriorit%C3%A0.md#realizzazione-con-heap)**
7. **[Complessità di una coda con priorità](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Complessit%C3%A0.md#code-con-priorit%C3%A0)**

## Specifica sintattica
**Tipi:**
* prioricoda, tipoelem

**Operatori:**
* creaprioricoda: () &rightarrow; prioricoda
* inserisci: (tipoelem, prioricoda) &rightarrow; prioricoda
* min: (prioricoda) &rightarrow; tipoelem
* cancellamin: (prioricoda) &rightarrow; prioricoda

## Specifica semantica
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

## Rappresentazione di una coda con priorità
### Rappresentazione con strutture sequenziali
Si pul rappresentare una coda con priorità di *n* elementi utilizzando le strutture sequenziali come liste ordinate e liste non ordinate.
La coda con priorità è costituita da un insieme di atomi linearmente ordinati, ma **senza alcuna relazione strutturale** sull'insieme delle posizioni.
La sua rappresentazione è quasi sempre associata ad un unico modello concettuale, quello di **albero binario**.

### Rappresentazione con alberi binari
Gli elementi di una coda con priorità C possono essere memorizzati nei nodi di un albero binario B che deve avere le seguenti proprietà:
* L'albero B è quesi perfettamente bilanciato
* Se *k* è il livello massimo delle foglie, allora B ha esattamente 2<sup>k</sup>-1 nodi di livello minore di *k*
  * **Proprietà 1**: Tutte le sue foglie di livello *k* sono addossate a sinistra
* L'albero B è parzialmente ordinato
  * **Proprietà 2**: Ogni nodo contiene un elemento maggiore di quello del padre

## Realizzazione degli operatori
* `min`: restituisce il contenuto della radice dell'albero B
* `inserisci`: inserisce una nuova foglia in modo da mantenere verificata la proprietà (1) e quindi far "salire" l'elemento introdotto fino a verificare la proprietà (2)
* `cancellamin`: deve effettuare due operazioni
  * cancella la foglia di livello massimo più a destra, in modo da mantenere verificata la proprietà (1)
  * reinserisce il contenuto della foglia cancellata nell'albero partendo dalla radice e facendolo "scendere" in modo che l'albero così modificato verifichi anche la proprietà (2)

## Osservazioni
`inserisci` e `cancellamin` prevedono due fasi:
* Modifica della struttura dell'albero (condizionata dalla proprietà 1)
* Aggiustamento degli elementi in base alle priorità (proprietà 2)

Nella prima fase si deve necessariamente fare riferimento alla foglia all'estrema destra dell'ultimo livello. Questo evidenzia l'utilità di mantenere traccia di tale foglia e di conseguenza la definizione di un attributo che punti all'ultimo elemento (ultima foglia a destra).

Analizziamo più nel dettaglio `inserisci`.
La prima fase, quella di modifica della struttura dell'albero, prevede l'inserimento di una foglia "dopo" l'ultima. Casi particolarmente semplici sono:
* **Albero vuoto**: bast aggiungere l'elemento come radice
* **Albero costituito dalla sola radice**: l'elemento viene aggiunto come figlio sinistro della radice
* **Ultima foglia nodo figlio sinistro**: l'elemento viene aggiunto come fratello destro

### I fase: modifica della struttura
Nel caso generale, la fase di modifica della struttura prevede un primo passo di **"salita a destra"** ed uno successivo di **"discesa verso sinistra"** allo scopo di individuare dove posizionare il nuovo nodo.
* Il processo di salita (si passa da figlio a padre) prosegue fintantochè il nodo considerato è un figlio destro (livello completo) oppure non è stata raggiunta la radice
* Il processo di discesa (si passa dal padre al figlio sinistro) viene iterato fino a quando non si trova una foglia, solo a questo punto si può aggiungere il nuovo nodo come foglia
  * Nel caso il livello non sia completo, il nuovo nodo verrà aggiunto a completarlo.
  * Nel secondo caso, o non si giunge alla radice, oppure **si giunge alla radice dal figlio sinistro**: si scende partendo dal fratello destro dell'ultimo nodo che è stato visitato in salita come figlio sinistro

### II fase: aggiustamento
Nella seconda fase di `inserisci`, cioè l'aggiustamento degli elementi **in base alle priorità**:
* Si parte dalla foglia inserita e si confronta il valore di profondità del nodo figlio con quello del nodo padre: i valori vengono scambiati se non sodisfano la proprietà (2) quindi si risale l'albero verso la radice
* Questo processo di confronto-scambi si ripete fino a quando non si trovano due elementi che soddisfano già la proprietà (2) oppure non si arriva alla radice

### Algoritmo di `inserisci`

    if {albero vuoto} then
     else
      if {albero ha solo la radice} then
       {inserisci l'elemento come figlio sinistro della radice}
      else
       if {ultimo figlio sinistro} then
        {inserisci l'elemento come suo fratello destro}
       else 
        while {nodo figlio destro}
         {risali}
        if {nodo non è la radice} then
         {passa al fratello destro}
        {scendi verso sinistra fino ad arrivare ad una foglia}
        {inserisci l'elemento come figlio sinistro}
    {ultimo diventa la foglia inserita}
    while {nodo non è la radice e la sua priorità è minore del padre}
     {scambia padre e figlio}
     
Analizziamo più nel dettaglio `cancellamin`.
La prima fase, quella di modifica della struttura dell'albero, prevede la cancellazione della foglia di livello massimo più a destra, mentre nella seconda fase va risistemato il contenuto. Casi particolarmente semplici sono:
* **Albero costituito dalla sola radice**: si cancella l'intero albero e non è necessaria la seconda fase
* **Ultima foglia o nodo figlio destro**: dopo la cancellazione, l'ultima foglia diventa nodo fratello sinistro

### I fase: modifica
Si procede attravero passi di **"salita da sinistra"** e successivi passi di **"discesa verso destra"** alla ricerca della nuova ultima foglia.
* Il processo di salita (si passa da figlio a padre) prosegue fintantochè il nodo considerato è un figlio sinistro oppure non è stata raggiunta la radice
* Il processo di discesa (si passa dal padre al figlio destro) viene iterato fino a quando non si trova una foglia. Quello che differenzia i due casi è se il livello massimo viene o meno svuotato.
  * Nel primo caso si giunge alla radice dal figlio sinistro: si scende quindi partendo dalla radice
  * Nel secondo caso, o non si giunge alla radice, oppure si giunge alla radice dal figlio destro: si scende partendo dal fratello sinistro dell'ultimo nodo che è stato visitato in salita come figlio destro
  
### II fase: aggiustamento
L'**aggiustamento** degli elementi avviene in base alle priorità:
* Il valore del nodo foglia da rimuovere sostituisce la radice
* Si parte dalla radice e si ricerca la posizione dove inserire il contenuto della foglia cancellata in modo che sia soddisfatta la proprietà (2)
* Per ogni nodo esaminato se ne considerano i figli e, se il contenuto del nodo cancellato ha priorità minore, si scrive nel nodo attuale il conenuto del figlio con priorità maggiore, valutando se la posizione di tale figlio può accogliere il contenuto del nodo cancellato
Questo processo si ripete fino a quando non si trova una configurazione che soddisfa già la proprietà (2).

### Algoritmo di `cancellamin`

    if {albero non vuoto} then
     if {albero con solo radice} then
      {cancella tutto l'albero}
     else
      {copia il contenuto dell'ultima foglia nella radice}
      {cancella la foglia}
    // inizio della fase di modifica della struttura
    if {ultimo è figlio destro}
     {il nuovo ultimo sarà fratello sinistro}
    else
     while {nodo è un figlio sinistro}
      {risali}
     if {non si è raggiunta la radice} then
      {passa al fratello sinistro}
     {scendi verso destra fino ad arrivare ad una foglia}
     {impostala come nuovo ultimo}
    // inizio della fase di aggiornamento delle priorità dalla radice
    while {il nodo attuale non è una foglia e la sua priorità è minore dei figli} do
     if {sono presenti entrambi i figli} do
      {scegli il figlio con priorità maggiore}
     else
      {seleziona l'unico figlio (che è il sinistro)}
     {scambia il contenuto del nodo attuale con quello del figlio selezionato}
     {spostati sul figlio selezionato}
     
## Realizzazione con heap
Gli elementi di B possono essere disposti in un vettore H (heap) nell'ordine in cui si incontrano visitando l'albero per livelli crescenti ed esaminando da sinistra verso destro i nodi allo stesso livello. In tal caso, si ha che:
* `H[1]` è l'elemento contenuto nella radice di B
* `H[2i]` e `H[2i+1]` sono gli elementi corrispondenti al figlio sinistro e al figlio destro di `H[i]`
* Se B contiene *n* elementi:
  * Il figlio sinistro (destro) di `H[i]` non esiste nell'albero se e solo se
    * 2i > n (2i+1 > n)
  * Per la proprietà (2), se il figlio sinistro (destro) di `H[i]` esiste, allora
    * `H[2i] > H[i] (H[2i+1] > H[i])
    
### Esempio di heap
Gli elementi dell'albero B si memorizzano nell'heap H come segue:

    H[1] = 3
    H[2] = 5
    H[3] = 9
    H[4] = 6
    H[5] = 8
    H[6] = 13
    H[7] = 12
    H[8] = 11
    H[9] = 18
    H[10] = 10
   
```
                  [3]
                 /    \
              [5]      [9]
             /    \   /   \
           [6]    [8] [13] [12]
          /  \    /
      [11] [18] [10]
```
