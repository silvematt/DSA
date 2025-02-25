/*
Exercises are relevant and kinda specific for the exam 

L'aereoporto di Capodichino ha fatto costruire una nuova pista di decollo e di atterraggio. 
Il direttore dell'aereoporto decide di utilizzare la pista per servire i nuovi N aerei che dovranno decollare dall'aereoporto.

Supponiamo che t¡ sia il tempo necessario all'i-simo aereo per decollare, scrivere un algoritmo, 
in pseudocodice, che utilizzando la struttura dati coda di priorità minimizzi il tempo totale di attesa (o turnaround) 
degli N aerei per decollare (7 punti).

MinHeapify(q, i)

l = Left(i)
r = Right(i)
min = i

if(l <= q.heapsize && q[min] > q[l])
    min = l

if (r <= q.heapsize && q[min] > q[r])
    min = r

if(min != i)
    swap(q[i], q[min])
    MinHeapify(q, min)



BuildMinHeap(v)

q = new heap
q.a = v
q.heapsize = v.size;
for i = v.size / 2 -1 down to 0
    MinHeapify(q, i)


EXTRACT_MIN(q)

min = q[0]

swap(q[0], q[q.heapsize-1])
q.heapsize--
MinHeapify(q, 0)

return min;



MinimizeTurnaround(planes)

timePassed = 0
turnAroundTime = 0
q = BuildMinHeap(planes) // q è una coda di prorità di minimo

while(!q.empty())
    p = EXTRACT_MIN(q)
    TakeOff(p)
    timePassed += p.key
    turnAroundTime += timePassed

return turnAroundTime
*/