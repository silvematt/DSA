/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE


RELAX(u,v,w)

if(v.d > u.d + w(u,v))
    v.d = u.d + w(u,v)
    v.parent = u



BellmanFord(g, s, w)

for each v in g.v
    v.d = oo
    v.parent = null

s.d = 0
s.parent = null

for i = 1 to |g.v|-1
    for each (u,v) in G.E
        RELAX(u, v, w)

for each (u,v) in G.E
    if(v.d > u.d + w(u,v))
        return false

return true

*/