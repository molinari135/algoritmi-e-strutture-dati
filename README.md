# Algoritmi e strutture dati
###### Realizzazioni di varie strutture dati con specifica sintattica e semantica e algoritmi

## Indice
1. **[Lista](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Lista.md)**
2. **[Pila](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Pila.md)**
3. **[Coda](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Coda.md)**
4. **[Insieme](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Insieme.md)**
5. **[Dizionario](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Dizionario.md)**
6. **[Albero](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Albero.md)**
7. **[Albero binario](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/AlberoBinario.md)**
8. **[Grafo](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/Grafo.md)**
9. **[Code con priorità](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/Teoria/CodeConPriorit%C3%A0.md)**
10. **[Complessità delle strutture dati](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/ComplessitàComputazionale.md)**
11. **[Tecniche algoritmiche](https://github.com/burraco135/algoritmi-e-strutture-dati/blob/main/TecnicheAlgoritmiche.md)**

## Tipi di strutture dati
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
