# Tecniche algoritmiche

## Classificazione dei problemi: problemi di ricerca, di decisione, di ottimizzazione

I problemi si possono classificare in:
* Problemi di **ricerca**;
* Problemi di **decisione**;
* Problemi di **ottimizzazione**.

Nella **concettualizzazione** si fornisce una specifica del problema, si stabiliscono le caratteristiche strutturali del problema senza fare riferimeento ai metodi per la risoluzione.
Nella **realizzazione** si passa dalla specifica del problema alle scelte per la sua risoluzione, che coinvolgono la definizione dell'algoritmo risolutivo e la realizzazione del programma.

La **specifica del problema** richiede:
* La **scelta dell'input**: si stabilisce che i valori di alcune variabili in gioco siano i dati di ingresso del problema. 
  * L'insieme di tali valori è lo *spazio di input del problema*;
* La **scelta dello scopo della risoluzione**: si stabilisce che i valori di alcune variabili in gioco rappresentino le soluzioni del problema. 
  * L'insieme di tali valori è lo *spazio delle soluzioni*;
* L'identificazione del **legame che i vincoli del problema impongono tra i valori dello spazio di input e i valori dello spazio delle soluzioni**.
  * Ciò conduce alla definizione della *relazione caratteristica* del problema;
* La determinazione di quali **informazioni in uscita** si vuole che il processo risolutivo del problema produca.
  * Queste informazioni stabiliscono lo *spazio di outpout* e il **quesito del problema**.
  
#### Esempio
**Determinare la posizione di un numero intero in un vettore di numeri interi.
Variabili:** 
* Un vettore **v**;
* Un indice **k**;
* Un numero intero **m**.

| Spazio di input | Spazio delle soluzioni | Relazione caratteristica | Spazio di output |
|-----------------|------------------------|--------------------------|------------------|
Insieme delle possibili coppie formate da un vettore **v** e un numero intero **m** | Insieme degli indici di ogni possibile vettore | Associa ad ogni coppia (**v**, **m**) una posizione **k** se e solo se il **k**-esimo elemento di **v** coincide con **m**; la relazione la chiamiamo **r<sub>vett</sub>** | Contiene lo spazio delle soluzioni più un particolare simbolo che denota l'assenza di soluzioni |

Il **quesito** stabilisce che, per ogni configurazione che ammette soluzione, vogliamo come output un qualunque elemento dello spazio delle soluzioni legato a quella configurazione dalla relazione caratteristica.

Sia `V = [7, 5, 3, 7, 2]` con
r<sub>vett</sub>:
`< [7, 5, 3, 7, 2], 7 > = 1`
`< [7, 5, 3, 7, 2], 5 > = 2`
`...`
`< [7, 5, 3, 7, 2], 7 > = 4`
`...`

Poichè esiste un numero infinito di vettori, **r<sub>vett</sub> è di **dimensione infinita**. Consideriamo l'elemento dello spazio di input formato dal vettore **v** e dal numero **m = 7**.

**r<sub>vett</sub>** associa e tale elemento due possibili valori dello spazio delle soluzioni: `1` e `4`.

Il quesito stabilisce che, nel problema considerato, possiamo essere interesati a una qualunque soluzione, a tutte le solzioni, alla "migliore" soluzione ecc...

### Specifica di un problema: definizione
La specifica di un problema è una quintupla `< I, S, R, O, Q >` dove:
* `I` è lo **spazio di input**;
* `S` è lo **spazio delle soluzioni**;
* `R` &subset; `I x S` è una relazione su `I` ed `S` detta **relazione caratteristica**;
* `O` è lo **spazio di output**;
* `Q` è una regola, detta **quesito**, che sulla base della relazione caratteristica `R`, consente di definire una relazione du `I` e `O`: `R`<sub>q</sub> &subset; `I x O`

Una particolare istanza del problema si ottiene ogni volta che scegliamo un particolare valore dei dati in ingresso. In relazione ad un problema e ad una sua istanza, diamo la nozione di **soluzione**.

