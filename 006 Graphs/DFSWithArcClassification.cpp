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

arcsToCheck = empty_queue_of_arcs

for each u in v.adj

    Arc a = GetArc(v, u)
    if(u.color == WHITE)
        a.type = TREE_ARC
        u.pi = v
        DFS_VISIT(u)
    else if(u.color == GREY)
        a.type = BACKWARDS_ARC
    else
        ENQUEUE(arcsToCheck, a)
        

v.color = BLACK
v.f = time = time +1
    
while(!arcsToCheck.empty())
    a = DEQUEUE(arcsToCheck)
    if(a.u.d < a.v.d && a.v.f < a.u.f)
        a.type = FORWARD_ARC
    else
        a.type = TRAVERSAL_ARC

----------------------
    TIME COMPLEXITY
----------------------
T(n):     O(V + E)
*/
#include <iostream>
#include <vector>
#include <queue>

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

void DFS_Visit(Graph& g, Node& u)
{
    u.color = GREY;
    u.d = time = time + 1;

    std::cout << u.label << std::endl;

    std::queue<Arc*> arcsToCheck;

    for(int i = 0; i < u.adj.size(); i++)
    {
        Node& v = *u.adj[i];
        Arc* a = GetArc(&g, &u, &v);

        if(a == nullptr)
        {
            std::cout << "Error while getting arc! Malformed graph." << std::endl;
            return;
        }

        if(v.color == WHITE)
        {
            a->type = TREE_ARC;

            v.parent = &u;
            DFS_Visit(g, v);
        }
        else if(v.color == GREY)
            a->type = BACKWARD_ARC;
        else
        {
            // Check if this is a forward or traversal arc, this needs to be done AFTER n.f is set, so let's save this arc
            arcsToCheck.push(a);
        }
    }

    u.f = time = time + 1;
    u.color = BLACK;

    while(!arcsToCheck.empty())
    {
        Arc* a = arcsToCheck.front();
        arcsToCheck.pop();

        if(a->u->d < a->v->d && a->v->f < a->u->f) // check if it's descendant
            a->type = FORWARD_ARC;
        else
            a->type = TRAVERSAL_ARC;
    }
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

    // Make a backward arc
    MakeArc(g, g.v[5], g.v[2]);

    // Make a traversal arc
    MakeArc(g, g.v[2], g.v[1]);

    // Make a forward arc
    MakeArc(g, g.v[0], g.v[4]);

    DFS(g);

    // Print arc classifications
    for(int i = 0; i < g.e.size(); i++)
    {
        switch(g.e[i].type)
        {
            case TREE_ARC:
                std:: cout << g.e[i].u->label << " -> " << g.e[i].v->label << " is a TREE ARC" << std::endl;
                break;
            case BACKWARD_ARC:
                std:: cout << g.e[i].u->label << " -> " << g.e[i].v->label << " is a BACKWARDS ARC" << std::endl;
                break;
            case FORWARD_ARC:
                std:: cout << g.e[i].u->label << " -> " << g.e[i].v->label << " is a FORWARD ARC" << std::endl;
                break;
            case TRAVERSAL_ARC:
                std:: cout << g.e[i].u->label << " -> " << g.e[i].v->label << " is a TRAVERSAL ARC" << std::endl;
                break;

        }
    }
}
