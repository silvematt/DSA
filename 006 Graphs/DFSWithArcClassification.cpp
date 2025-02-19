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

    Arc a = GetArc(v, u)
    if(u.color == WHITE)
        a.type = TREE_ARC
        u.pi = v
        DFS_VISIT(u)
    else if(u.color == GREY)
        a.type = BACKWARDS_ARC
    else
        if(v.d < u.d && u.f < v.f)
            a.type = FORWARD_ARC
        else
            a.type = TRAVERSAL_ARC

v.color = BLACK
v.f = time = time +1
    

----------------------
    TIME COMPLEXITY
----------------------
T(n):     O(V + E)
*/
#include <iostream>
#include <vector>

enum Colors
{
    WHITE = 0,
    GREY,
    BLACK
};

struct Node
{
    char label;
    Colors color;
    Node* parent;
    int d, f;
    
    std::vector<Node*> adj;

    Node(char l) : label(l), color(WHITE), parent(nullptr), d(0), f(0) {}
};

enum ArcType
{
    NULL_ARC = 0,
    TREE_ARC,
    BACKWARD_ARC,
    FORWARD_ARC,
    TRAVERSAL_ARC
};

struct Arc
{
    ArcType type;
    Node* u;
    Node* v;

    Arc(Node* a, Node* b) : u(a), v(b) {}
};

struct Graph
{
    std::vector<Node> v;
    std::vector<Arc> e;
};

int time = 0; // global time

void MakeArc(Graph& g, Node& u, Node& v)
{
    // Oriented graph, also add v.adj.push_back(&u) to make it non-oriented
    u.adj.push_back(&v);

    g.e.push_back(Arc(&u, &v));
}

Arc* GetArc(Graph* g, Node* u, Node* v)
{
    for(int i = 0; i < g->e.size(); i++)
    {
        if(g->e[i].u == u && g->e[i].v == v) // compare pointers to get the correct arc
            return &g->e[i];
    }

    return nullptr;
}

void DFS_Visit(Graph& g, Node& n)
{
    n.color = GREY;
    n.d = time = time + 1;

    std::cout << n.label << std::endl;

    for(int i = 0; i < n.adj.size(); i++)
    {
        Node& u = *n.adj[i];
        Arc* a = GetArc(&g, &n, &u);

        if(a == nullptr)
        {
            std::cout << "Error while getting arc! Malformed graph." << std::endl;
            return;
        }

        if(u.color == WHITE)
        {
            a->type = TREE_ARC;

            u.parent = &n;
            DFS_Visit(g, u);
        }
        else if(u.color == GREY)
            a->type = BACKWARD_ARC;
        else
        {
            // Check if this is a forward or traversal arc
            if(n.d < u.d && u.f < n.f) // if it's a descendant
                a->type = FORWARD_ARC;
            else
                a->type = TRAVERSAL_ARC;
        }
    }

    n.f = time = time + 1;
    n.color = BLACK;
}

void DFS(Graph& g)
{
    // Initialize
    for(int i = 0; i < g.v.size(); i++)
    {
        g.v[i].color = WHITE;
        g.v[i].parent = nullptr;
        g.v[i].d = g.v[i].f = 0;
    }

    time = 0;

    for(int i = 0; i < g.v.size(); i++)
    {
        if(g.v[i].color == WHITE)
            DFS_Visit(g, g.v[i]);
    }
}

int main()
{
    // Build a graph
    Graph g;

    // Nodes
    g.v.push_back(Node('A'));       // v[0]
    g.v.push_back(Node('B'));       // v[1]
    g.v.push_back(Node('C'));       // v[2]
    g.v.push_back(Node('D'));       // v[3]
    g.v.push_back(Node('E'));       // v[4]
    g.v.push_back(Node('F'));       // v[5]

    // Arcs
    MakeArc(g, g.v[0], g.v[1]);     // A-B
    MakeArc(g, g.v[0], g.v[2]);     // A-C
    MakeArc(g, g.v[1], g.v[3]);     // B-D
    MakeArc(g, g.v[3], g.v[4]);     // D-E
    MakeArc(g, g.v[2], g.v[5]);     // C-F

    DFS(g);
}
