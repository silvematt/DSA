/*
Exercises are relevant and kinda specific for the exam 

Dato un albero MinHeap H di grandezza Heapsize+1, si estragga il minimo e losi  scambi con l'ultimo elemento. 
Si scriva un algoritmo che prendendo in input H e la grandezza Heapsize, restituisce il numero di scambi in H 
necessari a ripristinare la proprietà dell'Heap. Qualora l'albero soddisfi la priorità dell'Heap, 
l'algoritmo deve restituire valore 0.


int nScambi = 0 // variabile globale

MinHeapify(H, heapsize, i)

l = Left(i)
r = Right(i)
min = i

if(l <= heapsize && H[min] > H[l])
    min = l
if(r <= heapsize && H[min] > H[r])
    min = r

if(min != i)
    swap(H[min], H[i])
    nScambi += 1
    MinHeapify(H, heapsize, min)

return nScambi

EXTRACT_MIN(H, heapsize)

min = H[0]

swap(H[0], H[heapsize])
heapsize--;
nScambi = 0
return MinHeapify(H, heapsize, 0)


Main(H, heapsize)

m = EXTRACT_MIN(H, heapsize)

*/