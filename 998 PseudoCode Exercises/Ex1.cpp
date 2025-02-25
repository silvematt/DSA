/*
Exercises are relevant and kinda specific for the exam 

Dato un grafo orientato G=(V,E) e pesato con funzione peso w: E->R, scrivere un algoritmo, in pseudocodice, 
che restituisca TRUE se ogni nodo è raggiungibile da ogni altro nodo e FALSE altrimenti. (7 punti)

1. Compute DFS and save by order of finish, topological sort
2. Compute Trasposed Graph
3. Compute DFS with the nodes from topological sort
4. Collect the commponents

TopologicalSort_Visit(g, s, u)

u.color = GREY
u.d = time = time + 1

for each v in u.adj
    if(v.color == WHITE)
        v.parent = u
        TopologicalSort_Visit(g,s,v)

u.f = time = time +1;
u.color = BLACK
s.push(u)

    
TopologicalSort(g, s)

for each u in g.v
    u.color = WHITE
    u.d = u.f = 0
    u.parent = null

for each u in g.v
    if(u.color == WHITE)
        TopologicalSort_Visit(g, s, u)

return s;


DFS_Visit(t, u, c)

u.color = GREY
u.d = time = time + 1

for each v in u.adj
    if(v.color == WHITE)
        c.add(v)
        DFS_Visit(t, v, c)

u.color = BLACK
u.f = time = time + 1


DFS(t, s, comp)

for each v in t.g 
    v.color = WHITE
    v.parent = null
    v.d = v.f = 0

while(!s.empty())
    u = s.front()
    s.pop()

    if(u.color == WHITE)
        c = comp.add_new
        c.add(u)
        DFS_Visit(t, u, c)


IsConnected(g) 

s = TopologicalSort(g) // topological sort effettua il DFS e salva in 's' i nodi ordinadoli per tempo di fine
t = g.Traspose();

comp = vuoto // array di componenti
DFS(t, s, comp)

if comp.size == 1
    return true
else
    return false

*/