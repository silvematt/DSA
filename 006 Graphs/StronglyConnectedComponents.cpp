#include <iostream>
#include <vector>
#include <stack>

enum Colors
{
    NOT_SET = 0,
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

    Node(char l) : label(l), color(WHITE), d(0), f(0), parent(nullptr) {}
};

class Arc
{
public:
    Node* u;
    Node* v;

    Arc(Node* a, Node* b) : u(a), v(b) {}
};

class Graph;
void MakeArc(Graph& g, Node* a, Node* b);

class Graph
{
public:
    std::vector<Node> v;
    std::vector<Arc> e;

    Graph GetTransposed()
    {
        Graph t;

        // Make a shallow copy
        for(int i = 0; i < this->v.size(); i++)
        {
            t.v.push_back(Node(this->v[i].label));
        }
        
        // Remap the arcs
        for(int i = 0; i < this->e.size(); i++)
        {
            Arc* a = &this->e[i];

            int indexU = a->u - &this->v[0];
            int indexV = a->v - &this->v[0];

            MakeArc(t, &t.v[indexV], &t.v[indexU]);
        }

        return t;
    }
};

void MakeArc(Graph& g, Node* a, Node* b)
{
    g.e.push_back(Arc(a, b));
    a->adj.push_back(b);
}

int time = 0;

void TPS_DFSVisit(std::stack<Node*>& s, Graph& g, Node& u)
{
    u.color = GREY;
    u.d = time = time + 1;

    for(int i = 0; i < u.adj.size(); i++)
    {
        Node* v = u.adj[i];
        if(v->color == WHITE)
        {
            v->parent = &u;
            TPS_DFSVisit(s, g, *v);
        }
    }

    u.f = time = time + 1;
    u.color = BLACK;

    s.push(&u);
}

void TPS_DFS(std::stack<Node*>& s, Graph& g)
{
    // init
    for(int i = 0; i < g.v.size(); i++)
    {
        Node* n = &g.v[i];
        
        n->parent = nullptr;
        n->color = WHITE;
        n->d = n->f = 0;
    }

    for(int i = 0; i < g.v.size(); i++)
    {
        if(g.v[i].color == WHITE)
            TPS_DFSVisit(s, g, g.v[i]);
    }
}

void SCC_DFSVisit(Graph& g, Node& u, std::vector<char>& components)
{
    u.color = GREY;
    u.d = time = time + 1;

    for(int i = 0; i < u.adj.size(); i++)
    {
        Node* v = u.adj[i];
        if(v->color == WHITE)
        {
            v->parent = &u;
            components.push_back(v->label);
            SCC_DFSVisit(g, *v, components);
        }
    }

    u.f = time = time + 1;
    u.color = BLACK;
}

void SCC_DFS(std::stack<Node*>& s, Graph& t, Graph& g) // g is only used to remap the elements of the stack, could have remapped by label but i like pointers arithmetic... std::vector guarantees contiguous memory, so it will work in this case
{
    // init
    for(int i = 0; i < t.v.size(); i++)
    {
        Node* n = &t.v[i];
        
        n->parent = nullptr;
        n->color = WHITE;
        n->d = n->f = 0;
    }

    while(!s.empty())
    {
        // This still points to the normal (non transposed) graph, so we need to remap it
        Node* n = s.top();

        // Stack references to prevous graph, not the transposed, quickly re-reference pointer arithmetic
        int index = n - &g.v[0];
        n = &t.v[index];

        std::vector<char> components;
        components.push_back(n->label);
        if(n->color == WHITE)
        {
            SCC_DFSVisit(t, *n, components);

            std::cout << "SCC(" << n->label << "): ";
            for(auto& l: components)
                std::cout << l << " ";
        
            std::cout << std::endl;
        }

        s.pop();
    }
}

int main()
{
    // Set time
    time = 0;

    // Make graph
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
    MakeArc(g, &g.v[0], &g.v[2]);
    MakeArc(g, &g.v[2], &g.v[3]);
    MakeArc(g, &g.v[3], &g.v[5]);
    MakeArc(g, &g.v[5], &g.v[9]);
    MakeArc(g, &g.v[9], &g.v[2]);
    MakeArc(g, &g.v[0], &g.v[7]);
    MakeArc(g, &g.v[7], &g.v[5]);
    MakeArc(g, &g.v[1], &g.v[0]);
    MakeArc(g, &g.v[1], &g.v[6]);
    MakeArc(g, &g.v[4], &g.v[0]);
    MakeArc(g, &g.v[4], &g.v[8]);
    MakeArc(g, &g.v[7], &g.v[6]);
    MakeArc(g, &g.v[8], &g.v[7]);
    MakeArc(g, &g.v[6], &g.v[8]);

    // Valid sequence stack, result of topological sort
    std::stack<Node*> s;

    TPS_DFS(s, g);

    // D is used for strongly connected components
    std::stack<Node*> d = s;

    // Valid sequence is
    while(!s.empty())
    {
        Node* u = s.top();

        std::cout << u->label << " -> ";

        s.pop();
    }
    std::cout << "END\n\n";

    // Compute strongly connected components
    Graph t = g.GetTransposed();
    
    // Reset time
    time = 0;

    SCC_DFS(d, t, g);

    return 0;
}
