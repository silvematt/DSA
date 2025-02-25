/*
Exercises are relevant and kinda specific for the exam 

Dato un grafo orientato G = (V,E), scrivere un algoritmo, in pseucodice, 
che calcoli il numero dei cicli, di lunghezza maggiore di 1, presenti nel grafo (7 punti). 


// solution may presents overcount of cycles

DFS_Visit(g, u, cyclesCount)

u.color = GREY
u.d = time = time + 1

for each v in u.adj
    if(v.color == WHITE)
        v.parent = u
        DFS_Visit(g, v, cyclesCount)
    else if (v.color == GREY && u != v)
        cyclesCount += 1

u.color = BLACK
u.f = time = time + 1

CycleCounter(g)

cyclesCount = 0
time = 0

for each u in g.v
    u.color = WHITE
    u.parent = NULL
    u.d = u.f = 0


for each u in g.v
    if(u.color == WHITE)
        DFS_Visit(g, u, cyclesCount)

return cyclesCount
*/