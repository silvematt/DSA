#include <iostream>
#include <vector>

class Node
{
public:
    int rank;
    Node* parent;
};

void MakeSet(Node* x)
{
    x->rank = 0;
    x->parent = x;
}

Node* FindSet(Node* x)
{
    // x is representative
    if(x->parent == x)
        return x;
    else
        return x->parent = FindSet(x->parent); // path compression
}

void Union(Node* x, Node* y)
{
    x = FindSet(x);
    y = FindSet(y);

    // Same set check
    if(x == y)
        return;

    // Union by rank
    if(x->rank == y->rank)
    {
        y->parent = x;
        x->rank++;
    }
    else if(x->rank > y->rank)
        y->parent = x;
    else // y.rank > x.rank
        x->parent = y;
}


int main()
{
    Node a, b, c, d, e, f, g;
    MakeSet(&a);
    MakeSet(&b);
    MakeSet(&c);
    MakeSet(&d);
    MakeSet(&e);
    MakeSet(&f);
    MakeSet(&g);

    Union(&a,&b); 
    Union(&b,&c); 
    Union(&d,&e); 
    Union(&f,&g); 
    Union(&e,&f);
    Union(&c,&g);

    // Print rank of the representative set
    std::cout << FindSet(&a)->rank;
}