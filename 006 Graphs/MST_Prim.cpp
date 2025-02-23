/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

MST_Prim(g, w, r)

for each u in g.v
    u.parent = null
    u.key = oo

r.key = 0
Q = g.v // Q is a min priority queue

while(Q is not empty)
    u = EXTRACT_MIN(Q)
    for each v in u.adj
        if(v is in Q && v.key > w(u, v))
            v.parent = u
            v.key = w(u,v) // decrease key

*/