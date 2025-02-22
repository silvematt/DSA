/*
// Connected components in a non-oriented graph

COMPUTE_CONNECTED_COMPONENTS(g)

for each v in g.v
    MAKE_SET(v)

for each a in g.e
    if(FIND_SET(a.u) != FIND_SET(a.v))
        UNION(a.u, a.v)


GET_CONNECTED_COMPONENTS(v, u)

if(FIND_SET(v) == FIND_SET(u))
    return true
else
    return false

*/