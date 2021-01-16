# Albero binario

## Indice
1. **[Specifica sintattica](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/AlberoBinario.md#specifica-sintattica)**
2. **[Specifica semantica](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/AlberoBinario.md#specifica-semantica)**
3. **[Operatori aggiuntivi - Specifica sintattica](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/AlberoBinario.md#operatori-aggiuntivi---specifica-sintattica)**
4. **[Operatori aggiungivi - Specifica semantica](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/AlberoBinario.md#operatori-aggiuntivi---specifica-semantica)**
5. **[Note sugli alberi binari](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/AlberoBinario.md#note-sugli-alberi-binari)**
6. **[Nuovi operatori - Specifica sintattica](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/AlberoBinario.md#nuovi-operatori---specifica-sintattica)**
7. **[Nuovi operatori - Specifica semantica](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/AlberoBinario.md#nuovi-operatori---specifica-semantica)**
8. **[Visite](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/AlberoBinario.md#visite)**
9. **[Rappresentazione di un albero binario](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/AlberoBinario.md#rappresentazione-di-un-albero-binario)**
10. **[Complessità di un albero binario](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Complessit%C3%A0.md#alberi-binari)**

Un **albero binario** è un albero ordinato in cui ogni nodo ha al più **due** figli e si fa distinzione tra il **figlio sinistro** ed il **figlio destro** di un nodo.

Due alberi T e U aventi gli stessi nodi, gli stessi figli per ogni nodo e la stessa radice, sono distinti qualora un nodo u sia designato come figlio sinistro di un nodo v in T e come figlio destro del medesimo nodo in U.

[Immagine albero binario]

Ogni albero *n*-ario ordinato T si può rappresentare con un albero binario B avente gli stessi nodi e la stessa radice: in B ogni nodo ha come figlio sinistro il primo figlio in T e come figlio destro il fratello successivo in T. L'equivalenza vale ai fini della **previsita**. Le sequenze di nodi esaminati su T e B coincidono se T e B sono visitati in previsita.

## Specifica sintattica
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

## Specifica semantica
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
  
## Operatori aggiuntivi - Specifica sintattica
**Tipi**:
* tipoelem

**Operatori**:
* legginodo: (alberobin, nodo) &rightarrow; tipoelem
* scrivinodo: (alberobin, nodo, tipoelem) &rightarrow; alberobin

## Operatori aggiuntivi - Specifica semantica
**Tipi**:
* **tipoelem**: tipo dell'etichetta del nodo (int, char, ...)

**Operatori**:
* `legginodo(T, u) = a`
  * **Precondizione:** T &ne; &wedge;, u &in; N, u è un nodo di T
  * **Postcondizione:** a è il valore associato al nodo n in T
* `scrivinodo(T, u, a) = T'`
  * **Precondizione:** T &ne; &wedge;, n &in; N, n è un nodo di T
  * **Postcondizione:** T' si ottiene assegnando al nodo n il valore a nell'albero T
  
## Note sugli alberi binari
Nell'algebra precedente si enfatizza la natura **ricorsiva** degli alberi e di costruire l'albero binario dal basso verso l'alto, cioè dal livello delle foglie verso la radice. Questa scelta non sempre è opportuna e occorre sostituire l'operatore di costruzione con tre operatori nuovi:

## Nuovi operatori - Specifica sintattica
**Operatori**:
* insbinradice: (alberobin, nodo) &rightarrow; alberobin
* insfigliosinistro: (alberobin, nodo) &rightarrow; alberobin
* insfigliodestro: (alberobin, nodo) &rightarrow; alberobin

## Nuovi operatori - Specifica semantica
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
  
## Visite
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
        
## Rappresentazione di un albero binario
### Rappresentazione con vettore
Una possibile rappresentazione di un albero binario è quella **sequenziale** mediante vettore. La radice è in prima posizione; per il generico non p memorizzato in posizione i, se esiste il figlio sinistro è memorizzato in posizione 2i, se esiste il figlio destro è memorizzato in posizione 2i+1. Se l'albero è vuoto, alcune celle del vettore non corrispondono a nulla. Questo potrebbe essere un problema con linguaggi a tipizzazione forte. Conviene utilizzare un **boolean** per indicare che effettivamente in quella posizione c'è un nodo.

### Rappresentazione con lista
Nella realizzazione con lista valgono le stesse considerazioni fatte per gli alberi *n*-ari ma in questo caso se l'albero è vuoto, la lista è vuota. Se l'albero non è vuoto, contiene:
* La **radice**
* Una lista che rappresenta il **sotto-albero sinistro** nello stesso modo
* Una lista che rappresenta il **sotto-albero destro** nello stesso modo

### Rappresentazione con lista attraverso puntatori
Gli alberi binari si possono anche rappresentare attraverso una lista con puntatori per rendere **dinamica** l'implementazione.
