/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE


RELAX(u,v,w)

if(v.d > u.d + w(u,v))
    v.d = u.d + w(u,v)      // if v is in a min priority queue, need to DECREASE_KEY
    v.parent = u


Dijkstra(g, s, w)

for each v in g.v
    v.d = oo
    v.parent = null

s.d = 0
s.parent = null

Q = g.v // is is a min priority queue
S = empty_set

while(Q is not empty)
    u = EXTRACT_MIN(Q)
    S = S U {u}
    for each v in u.adj
        RELAX(u, v, w)

*/