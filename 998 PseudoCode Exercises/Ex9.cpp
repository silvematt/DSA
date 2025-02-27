/*
Exercises are relevant and kinda specific for the exam 

Dato un grafo non orientato G=(V,E) pesato, con funzione peso w:E->R.
Si scriva in pseudocodice un algoritmo che restituisca l’arco leggero non sicuro di peso minimo. (7 punti)

MST_Kruskal(g)

A = empty_set

for each v in g.v
    MakeSet(v)

E = g.e
Sort(E) // by ascending order, considering the weight

for each e in E
    if(FindSet(e.v) != FindSet(e.u))
        A = A U {e}
        UNION(e.v, e.u)
    else
        return e

return null
*/