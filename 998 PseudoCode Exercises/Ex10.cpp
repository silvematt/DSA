/*
Exercises are relevant and kinda specific for the exam 

Dato un grafo non orientato G=(V,E) pesato con funzione peso ω:E->R.
Si scriva in pseudocodice un algoritmo che restituisca l’arco leggero e non sicuro di peso mediano

MST_Kruskal(g)

A = empty_set

for each v in g.v
    MakeSet(v)

E = g.e
Sort(E) // by ascending order considering the weight

list = empty_list_of_arcs

for each e in E
    if(FindSet(e.u) != FindSet(e.v))
        Union(e.u, e.v)
        A = A U {e}
    else
        list.add(e)

if(list.size > 0)
    return list[list.size/2]
return null
*/