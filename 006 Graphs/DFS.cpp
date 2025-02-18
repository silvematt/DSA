/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

DFS(G)

for each v in G.V
    v.d = 0
    v.pi = NULL
    v.color = WHITE

time = 0

for each v in G.V
    if(v.color == WHITE)
        DFS_VISIT(v)


DFS_VISIT(v)

v.d = time = time+1
v.color = GREY

for each u in v.adj
    if(u.color == WHITE)
        u.pi = v
        DFS_VISIT(u)

v.color = BLACK
v.f = time = time +1
    

----------------------
    TIME COMPLEXITY
----------------------
T(n):     O(V + E)
*/
