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
#include <iostream>
#include <vector>

class Node
{
public:
    char label;
    int rank;
    Node* parent;
    std::vector<Node*> adj;

    Node(char l) : label(l), parent(nullptr) {}
};

class Arc
{
public:
    Node* u;
    Node* v;

    Arc(Node* a, Node* b) : u(a), v(b) {}
};  

class Graph
{
public:
    std::vector<Node> v;
    std::vector<Arc> e;
};

void MakeArc(Graph& g, Node* u, Node* v)
{
    g.e.push_back(Arc(u, v));

    u->adj.push_back(v);
    v->adj.push_back(u);
}

void MakeSet(Node* x)
{
    x->rank = 0;
    x->parent = x;
}

Node* FindSet(Node* x)
{
    if(x->parent == x)
        return x;

    return x->parent = FindSet(x->parent); // path compression
}

void Union(Node* x, Node* y)
{
    // always union the roots
    x = FindSet(x);
    y = FindSet(y);

    if(x == y)
        return;

    // Union by rank
    if(x->rank == y->rank)
    {
        x->rank++;
        y->parent = x;
    }
    else if(x->rank > y->rank)
        y->parent = x;
    else
        x->parent = y;
}

// returns true if the 'sets' contains the address 'val', used to count the components
bool AnalyzedContains(std::vector<Node*>& sets, Node* val)
{
    for(Node* cur : sets)
        if(cur == val)
            return true;

    return false;
}

void ConnectedComponents(Graph& g)
{
    for(int i = 0; i < g.v.size(); i++)
    {
        MakeSet(&g.v[i]);
    }

    for(Arc& arc : g.e)
    {
        if(FindSet(arc.u) != FindSet(arc.v))
        {
            Union(arc.u, arc.v);
        }
    }

    // Count the components 
    int connectedNum = 0;
    Node* curSet = nullptr;
    std::vector<Node*> analyzedSets;
    for(int i = 0; i < g.v.size(); i++)
    {
        if((!AnalyzedContains(analyzedSets, FindSet(&g.v[i]))))
        {
            connectedNum++;
            analyzedSets.push_back(FindSet(&g.v[i]));
        }
    }
    std::cout << "N of connected components: " << connectedNum;
}

int main()
{
    Graph g;

    g.v.push_back(Node('A')); // g.v[0]
    g.v.push_back(Node('B')); // g.v[1]
    g.v.push_back(Node('C')); // g.v[2]
    g.v.push_back(Node('D')); // g.v[3]
    g.v.push_back(Node('E')); // g.v[4]
    g.v.push_back(Node('F')); // g.v[5]
    g.v.push_back(Node('G')); // g.v[6]
    g.v.push_back(Node('H')); // g.v[7]
    g.v.push_back(Node('I')); // g.v[8]
    g.v.push_back(Node('J')); // g.v[9]

    // Make arcs
    //MakeArc(g, &g.v[0], &g.v[2]);
    MakeArc(g, &g.v[2], &g.v[3]);
    MakeArc(g, &g.v[3], &g.v[5]);
    MakeArc(g, &g.v[5], &g.v[9]);
    MakeArc(g, &g.v[9], &g.v[2]);
    MakeArc(g, &g.v[0], &g.v[7]);
    //MakeArc(g, &g.v[7], &g.v[5]);
    MakeArc(g, &g.v[1], &g.v[0]);
    MakeArc(g, &g.v[1], &g.v[6]);
    MakeArc(g, &g.v[4], &g.v[0]);
    //MakeArc(g, &g.v[4], &g.v[8]);
    MakeArc(g, &g.v[7], &g.v[6]);
    //MakeArc(g, &g.v[8], &g.v[7]);
    //MakeArc(g, &g.v[6], &g.v[8]);

    ConnectedComponents(g);
}