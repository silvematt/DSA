/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

MST_Kruskal(g)

A = empty

for each v in g.v
    MakeSet(v)

E = g.e // list of arcs
Sort(E) // non-desc order

for each e in E
    if(FindSet(e.u) != FindSet(e.v))
        A = A U {e}
        Union(e.u, e.v)

return A
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

    Node(char l) : label(l), rank(0), parent(nullptr) {}
};

class Arc
{
public:
    Node* u;
    Node* v;
    int weight;

    Arc(Node* a, Node* b, int w) : u(a), v(b), weight(w) {}
};

class Graph
{
public:
    std::vector<Node> v;
    std::vector<Arc> e;
};

void MakeArc(Graph& g, Node* u, Node* v, int w)
{
    g.e.push_back(Arc(u, v, w));

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
    else
        return x->parent = FindSet(x->parent);
}

void Union(Node* x, Node* y)
{
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
    else // y->rank > x->rank
        x->parent = y;
}

void InsertionSort(std::vector<Arc>& a)
{
    for(int j = 1; j < a.size(); j++)
    {
        Arc key = a[j];
        int i = j-1;

        while(i >= 0 && a[i].weight > key.weight)
        {
            a[i+1] = a[i];
            i--;
        }

        a[i+1] = key;
    }
}

std::vector<Arc> MST_Kruskal(Graph& g)
{
    std::vector<Arc> A;

    // Initialize the DisjointSet used for kruskal
    for(Node& n : g.v)
        MakeSet(&n);

    // E is the sorted list of arcs
    std::vector<Arc> E = g.e;
    InsertionSort(E); // non desc

    // Build MST
    int costOfTree = 0;
    for(int i = 0; i < E.size(); i++)
    {
        if(FindSet(E[i].u) != FindSet(E[i].v))
        {
            costOfTree += E[i].weight;
            A.push_back(E[i]);
            Union(E[i].u, E[i].v);
        }
    }

    std::cout << "Total cost of MST: " << costOfTree << std::endl;

    for(auto& a : A)
        std::cout << a.u->label << " -> " << a.v->label << std::endl;

    return A;
}

int main()
{
    Graph g;
    g.v.push_back(Node('A'));
    g.v.push_back(Node('B'));
    g.v.push_back(Node('C'));
    g.v.push_back(Node('D'));

    MakeArc(g, &g.v[0], &g.v[1], 10);
    MakeArc(g, &g.v[1], &g.v[3], 15);
    MakeArc(g, &g.v[2], &g.v[3], 4);
    MakeArc(g, &g.v[2], &g.v[0], 6);
    MakeArc(g, &g.v[0], &g.v[3], 5);

    std::vector<Arc> mst = MST_Kruskal(g);
}
