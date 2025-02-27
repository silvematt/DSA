/*
Exercises are relevant and kinda specific for the exam 

Dato un grafo non orientato G=(V,E) e non pesato, un nodo sorgente s E V ed u un numero intero K
Scrivere un algoritmo, in pseudocodice, che restituisca la lista dei nodi il cui cammino minimo dal nodo
sorgente s sia minore di k


BFS(g, s, k)

list = empty

for each u in g.v
    u.color = WHITE
    u.d = 0
    u.parent = null

s.color = GREY
s.d = 0
s.parent = null

Q = empty
ENQUEUE(Q, s)

while(Q is not empty)
    u = DEQUEUE(Q)
    for each v in u.adj
        if(v.color == WHITE)
            v.parent = u
            v.color = GREY
            v.d = u.d+1
            if(v.d < k)
                list.add(v)
            ENQUEUE(Q, v)
    u.color = BLACK

return list
*/