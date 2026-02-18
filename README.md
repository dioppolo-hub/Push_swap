# Push_swap
## 1. Il Concetto: 
## Pre-ordinamento per Intervalli
Invece di cercare il valore minimo assoluto (che richiederebbe troppe rotazioni), l'algoritmo divide l'insieme dei numeri in "intervalli" (chunk) basati sulla loro posizione finale una volta ordinati. 

### Indicizzazione: 
Prima di iniziare, copia i numeri in un array temporaneo, ordinali (es. con QuickSort) e sostituisci ogni numero originale con la sua posizione nell'ordine (0, 1, 2...). In questo modo, se hai 500 numeri, saprai esattamente che i numeri del primo chunk sono quelli da 0 a 19.
### Spostamento in Stack B:
Scansiona la Pila A. Se il numero in cima appartiene al chunk corrente, spostalo nella Pila B. Se appartiene alla metà inferiore del chunk corrente, puoi anche eseguire una rotazione su B (rb) per pre-ordinarlo grossolanamente. 

## 2. Parametri Ottimali (Quanti Chunk?)
La dimensione dei chunk influenza drasticamente il punteggio. Valori comunemente accettati dalla community di 42 per ottimizzare le mosse sono:
- `Per 100 numeri:`
Circa 5 chunk (blocchi da 20 numeri ciascuno).
- `Per 500 numeri:`
Circa 11-13 chunk (blocchi da circa 40 numeri).

## 3. Fasi dell'Algoritmo
- `Suddivisione:`
Dividi i numeri in chunk.
- `Push a blocchi (A->B):`
Sposta tutti i numeri del Chunk 1 dalla Pila A alla Pila B, poi passa al Chunk 2, e così via, finché A non è vuota (o ne restano solo 3, da ordinare con un algoritmo specifico).
- `Ricomposizione (B->A):`
In questa fase, B contiene tutti i numeri ma non è ordinata correttamente. Devi cercare ogni volta il numero più grande in B, portarlo in cima con il minor numero di rotazioni (rb o rrb) e riportarlo in A (pa). 

## 4. Operazioni Chiave da Gestire in C
Per implementare questo sistema in C, la tua struttura dati deve supportare:
- `rotazione (ra, rb):` Sposta il primo elemento in fondo.
- `Reverse Rotate (rra, rrb):` Sposta l'ultimo elemento in cima.
- `Push (pa, pb):` Sposta l'elemento tra le pile. 
