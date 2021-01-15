# Calcolo della complessità

## Lista
Per valutare la complessità di una procedura che utilizzi le operazioni di una struttura dati lista, occorre prima conoscere la complessità di ogni operazione impiegata, ovvero conoscere la realizzazione della struttura dati di tipo "lista".

Le possibili realizzazioni sono:
* Memorizzare gli elementi della lista in un vettore
  * Permette agevolmente, in tempo O(1), di passare da un elemento al successivo o al precedente, di accorgersi se si tenta di superare un estremo della lista, di leggere o modificare il valore di un elemento
  * Presenta due svantaggi, il vettore è a dimensione fissa mentre la lista è a dimensione variabile quindi il numero di elementi della lista deve essere prefissato, inoltre, l'inserzione di un nuovo elemento o la cancellazione di uno vecchio richiedono un tempo O(n), poichè è necessario scalare tutti gli elementi di una posizione
* Fare uso dei puntatori      
  * In questo caso, la contiguità degli elementi non corrisponde ad una contiguità di memorizzazione; permette di ottenere complessità O(1) per tutte le operazioni, sia di non limitare il massimo numero di elementi presenti nella lista
  * A scapito di un lieve spreco di memoria, utilizzando una realizzazione bidirezionale circolare con sentinella, si ottiene una complessità O(1) per ciascuna operazione; in realtà basta anche una realizzazione monodirezionale circolare per ottenere questo tipo di complessità
  * Solo le operazioni `ultimolista` e `predlista` mantengono una complessità O(n)
* Fare uso dei cursori
  * Stessi vantaggi dell'uso dei puntatori
  * Anche in questo caso si può fare uso della realizzazione circolare e ottenere gli stessi vantaggi
        
## Pila
