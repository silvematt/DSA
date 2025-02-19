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

#include <iostream>
#include <vector>
#include <queue>

enum Color
{
    WHITE = 0,
    GREY,
    BLACK
};

struct Node
{
    char label;
    Color color;
    Node* parent;
    int d;

    std::vector<Node*> adj;

    Node(char l) : label(l), color(WHITE), parent(nullptr), d(0) {}
};

struct Arc
{
    Node* u;
    Node* v;

    Arc(Node* a, Node* b) : u(a), v(b) {}
};

struct Graph
{
    std::vector<Node> v;
    std::vector<Arc> e;
};

void MakeArc(Graph& g, Node& u, Node& v)
{
    // Oriented graph, also add v.adj.push_back(&u) to make it non-oriented
    u.adj.push_back(&v);

    g.e.push_back(Arc(&u, &v));
}

void BFS(Graph& g, Node& s)
{
    // Initialization
    for(int i = 0; i < g.v.size(); i++)
    {
        g.v[i].color = WHITE;
        g.v[i].parent = nullptr;
        g.v[i].d = 0;
    }

    // Initialize source
    s.color = GREY;
    s.d = 0;
    s.parent = nullptr;

    // Initialize queue
    std::queue<Node*> q;
    q.push(&s);

    // BFS-logic
    while(!q.empty())
    {
        // Take the front node
        Node* u = q.front();
        q.pop();
        
        std::cout << u->label << std::endl;

        // Expand
        for(int i = 0; i < u->adj.size(); i++)
        {
            Node* v = u->adj[i];
            
            if(v->color == WHITE)
            {
                v->parent = u;
                v->d = u->d+1;
                v->color = GREY;
                q.push(v);
            }
        }

        u->color = BLACK;
    }
}

int main()
{
    Graph g;

    g.v.push_back(Node('1'));       // v[0]
    g.v.push_back(Node('2'));       // v[1]
    g.v.push_back(Node('3'));       // v[2]
    g.v.push_back(Node('4'));       // v[3]
    g.v.push_back(Node('5'));       // v[4]
    g.v.push_back(Node('6'));       // v[5]

    MakeArc(g, g.v[0], g.v[1]);     // A-B
    MakeArc(g, g.v[0], g.v[2]);     // A-C
    MakeArc(g, g.v[1], g.v[3]);     // B-D
    MakeArc(g, g.v[3], g.v[4]);     // D-E
    MakeArc(g, g.v[2], g.v[5]);     // C-E

    BFS(g, g.v[0]);
}
