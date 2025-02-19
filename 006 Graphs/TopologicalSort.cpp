/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

TPS_DFS(G)

Stack s = empty

for each v in G.V
    v.color = WHITE
    v.d = 0
    v.f = 0
    v.pi = nullptr

time = 0 // time is global variable

for each v in G.V
    if(v.color == WHITE)
        TPS_DFSVisit(G, v, s)



TPS_DFSVisit(G, v, s)

v.color = GREY
v.d = time = time +1

for each u in v.adj
    if(u.color == WHITE)
        u.pi = v
        TPS_DFSVisit(G, u, s)

v.color = BLACK
v.f = time = time+1;
s.push(v)

----------------------
    TIME COMPLEXITY
----------------------
T(n):     O(V + E)
*/
#include <iostream>
#include <vector>
#include <stack>

enum Colors
{
    EMPTY = 0,
    WHITE,
    GREY,
    BLACK
};

class Node
{
public:
    char label;

    Colors color;
    int d, f;
    Node* parent;

    std::vector<Node*> adj;

    Node(char l) : label(l), d(0), f(0), parent(nullptr) {}
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

int time; // global time

void MakeArc(Graph& g, Node* u, Node* v)
{
    u->adj.push_back(v);

    g.e.push_back(Arc(u, v));
}

void TPS_DFSVisit(Graph& g, Node& u, std::stack<Node*>& s)
{
    u.color = GREY;
    u.d = time = time +1;
    
    for(int i = 0; i < u.adj.size(); i++)
    {
        Node* v = u.adj[i];

        if(v->color == WHITE)
        {
            v->parent = &u;
            TPS_DFSVisit(g, *v, s);
        }
    }

    u.f = time = time + 1;
    u.color = BLACK;

    // Save the node in the sequence
    s.push(&u);
}

void TPS_DFS(Graph& g, std::stack<Node*>& s)
{
    for(int i = 0; i < g.v.size(); i++)
    {
        g.v[i].color = WHITE;
        g.v[i].d = 0;
        g.v[i].f = 0;
    }

    for(int i = 0; i < g.v.size(); i++)
        if(g.v[i].color == WHITE)
            TPS_DFSVisit(g, g.v[i], s);
}


int main()
{
    time = 0;

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
    g.v.push_back(Node('K')); // g.v[10]

    // Make arcs
    MakeArc(g, &g.v[0], &g.v[1]);
    MakeArc(g, &g.v[0], &g.v[3]);
    MakeArc(g, &g.v[0], &g.v[2]);
    MakeArc(g, &g.v[1], &g.v[4]);
    MakeArc(g, &g.v[1], &g.v[5]);
    MakeArc(g, &g.v[5], &g.v[8]);
    MakeArc(g, &g.v[5], &g.v[9]);
    MakeArc(g, &g.v[9], &g.v[10]);
    MakeArc(g, &g.v[2], &g.v[6]);
    MakeArc(g, &g.v[6], &g.v[10]);
    MakeArc(g, &g.v[3], &g.v[7]);

    std::stack<Node*> s;

    TPS_DFS(g, s);

    while(!s.empty())
    {
        std::cout << s.top()->label << " -> ";
        s.pop();
    }
    
    std::cout << "END" << std::endl;

    return 0;
}
