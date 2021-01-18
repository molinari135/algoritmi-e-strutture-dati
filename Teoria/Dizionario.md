# Dizionario
Il dizionario è un sottotipo del tipo insieme i cui elementi sono generalmente tipi strutturati ai quali si accede per mezzo di un riferimento a un campo chiave.

## Indice
1. **[Notazione di un dizionario](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Dizionario.md#notazione-di-un-dizionario)**
2. **[Operazioni in un dizionario](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Dizionario.md#operazioni-in-un-dizionario)**
3. **[Specifica sintattica](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Dizionario.md#specifica-sintattica)**
4. **[Specifica semantica](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Dizionario.md#specifica-semantica)**
5. **[Rappresentazione di un dizionario](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Dizionario.md#rappresentazione-di-un-dizionario)**
6. **[Collisioni](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Dizionario.md#collisioni)**
7. **[Metodi di scansione](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Dizionario.md#metodi-di-scansione)**
8. **[Complessità di un dizionario](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Complessit%C3%A0Computazionale.md#dizionari)**

## Notazione di un dizionario
Gli elementi assumono la forma di una coppia costituita da coppie

> <chiave, valore>

- La caratteristica della **chiave** è legata alla applicazione
- Il **valore** associato rappresenta l'informazione associata per scopi di gestinone o manutenzione

## Operazioni in un dizionario
Poichè possiamo definirli un caso particolare di **insieme**, la specifica per i dizionari è molto simile a quella del tipo di dato insieme. Le operazioni ammesse sono:
* crea, appartiene, inserisci, cancella
E in alcuni casi troviamo anche le operazioni:
* recupera, aggiorna

## Specifica sintattica
**Tipi**:
* dizionaio, boolean, chiave, valore

**Operatori**:
* creadizionario: ( ) &rightarrow; dizionario
* dizionariovuoto: (dizionario) &rightarrow; boolean
* appartiene: (dizionario, chiave) &rightarrow; boolean
* inserisci: (dizionario, <chiave, valore>) &rightarrow; dizionario
* cancella: (dizionario, chiave) &rightarrow; dizionario
* recupera: (dizionario, chiave) &rightarrow; valore

## Specifica semantica
**Tipi**:
* **dizionario**: collezione di dizionari costituita da coppie di tipo **<chiave, valore>**
* **boolean**: insieme dei valori di verità

**Operatori**:
* `creadizionario() = D`
  * **Precondizione:** *(nessuna)*
  * **Postcondizione:** D = { }
* `dizionariovuoto(D) = b`
  * **Precondizione:** *(nessuna*)
  * **Postcondizione:** D = { }
    * **Vero**, b = true
    * **Falso**, b = false
* `appartiene(D, k) = b`
  * **Precondizione:** *(nessuna)*
  * **Postcondizione:** <k', v> &in; D tale che k' = k
    * **Esiste**, b = true
    * **Non esiste**, b = false
* `inserisci(D, <k, v>) = D'`
  * **Precondizione:** *(nessuna)*
  * **Postcondizione:** <k', v'> &in; D tale che k' = k
    * **Esiste**, D' = D \ {<k', v'} &cup; {<k, v>}
    * **Non esiste**, D' = D &cup; {<k, v>}
* `cancella(D, k) = D'`
  * **Precondizione:** &exists; <k', v> &in; D tale che k' = k
  * **Postcondizione:** D' = D \ {<k, v>}
* `recupera(D, k) = v`
  * **Precondizione:** &exists; <k', v'> &in; D tale che k' = k
  * **Postcondizione:** v = v'

## Rappresentazione di un dizionario
Oltre alla rappresentazione con **vettore booleano** e mediante **lista**, ci sono quelle mediante **vettori ordinati** e **tabelle hash**.

### Rappresentazione con vettore ordinato
Si utilizza un **vettore con un cursore all'ultima posizione occupata**. Avendo definito una **relazione di ordinamento totale &le;** sulle chiavi, queste si memorizzano in posizioni contigue in ordine crescente. Per verificare l'appartenenza di un elemento o di una chiave, si utiilzza la **ricerca binaria**, si confronta il valore da ricercare k con il valore v che occupa la posizione centrale del vettore e si stabilisce in quale metà continuare la ricerca.

### Rappresentazione con tabella hash
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

## Collisioni
Una **collisione** si verifica quando chiavi diverse producono lo **stesso risultato della funzione**. Esistono funzioni hash più o meno buone anche se le collisioni non si potranno mai evitare del tutto.

Quale che sia la funzione hash adottata, deve essere prevista una strategia per gestire il problema degli agglomerati e delle collisioni. In definitiva:
- Occorre una **funzione hash**, calcolabile velocemente e che distribuisca le chiavi uniformemente in v, in modo da ridurre le collisioni;
- Occorre un **metodo di scansione** per la soluzione delle collisioni utile a reperire chiavi che hanno trovato a posizione occupata e che non provochi la formazione di agglomerati di chiavi;
- La **dimensione m del vettore v** deve essere una sovrastima del numero delle chiavi attese, per evitare di riempire v completamente.

Alcuni buoni metodi di generazione hash con **b = bin(k)**:
* **h(k) = int(b)**
  * b è un sottoinsieme di p bit di bin(k), solitamente estratti nelle posizioni centrali
* **h(k) = int(b)**
  * b è dato dalla somma modulo 2, effettuata bit a bit, di diversi sottoinsiemi di p bit di bin(k)
* **h(k) uguale al resto della divisione int(bin(k)) / m**
  * m è dispari; se fosse uguale a 2p, due numeri con gli stessi p bit finali darebbero sempre luogo a una collisione
  
L'ultima funzione hash è la migliore dal punto di vista probabilistico e fornisce un'eccellente distribuzione degli indirizzi h(k) nell'intervallo da 0 a m-1.

### Hash aperto
Una tecnica che **evita la formazione di agglomerati** è quella dell'hash aperto che richiede che la tabella hash mantenga la lista degli elementi le cui chiavi producono lo stesso valore di funzione. La tabella di hash viene realizzata definendo un array di liste di bucket dette **liste di trabocco**.

La funzione di hash viene utilizzata per **determinare quale lista potrbbe contenere l'elemento** che possiede una determinata chiave in modo da poter attivare una successiva operazione di ricerca nella lista corrispondente e da restituire la posizione del bucket che contiene la chiave.

## Metodi di scansione
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
