/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

BFS(G, s)

// Initialize all the nodes to WHITE and with default settings
for each u (in G.V - {s})
    u.color = WHITE
    u.pi = NULL
    u.d = oo

// Init the source
s.color = GREY
s.pi = NULL
s.d = 0

// Queue initialized to empty
Q = EMPTY

ENQUEUE(Q, s)

while(Q IS NOT EMPTY)
    u = DEQUEUE(Q)
    for each v in u.adj
        if v.color = WHITE 
            v.color = GREY
            v.pi = u
            v.d = u.d+1
            ENQUEUE(Q, v)

    u.color = BLACK

----------------------
    TIME COMPLEXITY
----------------------
T(n):     O(V + E)
*/

