/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

As per the Cormen book "Introduction to Algorithms", pseudocode arrays start at 1

FractionalKnapsack(W, v, w) // items sorted by v/w ratio

n = v.size()

x[1...n] // x[i] can be 0 (item not taken), 1 (item taken wholly), 0 < t < 1 (item taken fractionally)

for i = 1 to n
    x[i] = 0

curCapacity = W
curValue = 0

i = 1;
while(i <= n && curCapacity > 0.0)
{
    // If item fits, insert wholly
    if(curCapacity >= w[i])
        curValue += v[i]
        x[i] = 1.0
        curCapacity -= w[i]
    else                        // item doesn't fit wholly, but only partially
        x[i] = curCapacity/w[i];
        curCapacity = 0.0;
        curValue += x[i] * v[i]

    i++;
}

return x


----------------------
    TIME COMPLEXITY
----------------------
T(n):     O(n logn)
*/
#include <iostream>
#include <vector>

// Item definition
struct Item
{
    char id;
    float value;
    float weight;

    Item(char id, float v, float w) : id(id), value(v), weight(w) {}
};

std::vector<float> FractionalKnapsack(std::vector<Item> items, float W)
{
    std::vector<float> o (items.size(), 0.0);
    
    float curWeight = W;
    float curValue = 0;

    int i = 0;
    while(i < items.size() && curWeight > 0.0)
    {
        // Check if item fits wholly
        if(curWeight >= items[i].weight)
        {
            o[i] = 1.0;
            curWeight -= items[i].weight;
            curValue += items[i].value;
        }
        else // insert only a fraction
        {
            o[i] = curWeight / items[i].weight;
            curWeight = 0.0;
            curValue += o[i] * items[i].value;
        }

        i++;
    }

    std::cout << "Profit: " << curValue << std::endl;

    return std::move(o);
}

// Sorts items by v/w, DESCENDING ORDER!
void InsertionSort(std::vector<Item>& a, int n)
{
    // First element is already sorted
    for(int j = 1; j < n; j++)
    {
        // Select the current element
        Item key = a[j];

        // Select the index of the "current hand" (the sorted portion) to make comparisons
        int i = j-1;

        // Find (and make) the correct spot for the 'key' element
        while(i >= 0 && (a[i].value / a[i].weight) <= (key.value/key.weight))
        {
            a[i+1] = a[i];
            i--;
        }

        // Place the key in the right spot
        a[i+1] = key;
    }
}


int main()
{
    // Activities
    std::vector<Item> items = {Item('A', 4.0f, 2.2f), Item('B', 5.0, 3.0), Item('C', 7.2, 5.1), Item('D', 1, 0.5f), Item('E', 4, 5.5f)};
    float capacity = 8.5f;

    // Sort by v/k ratio, descending order!
    InsertionSort(items, items.size());

    // Compute the selection
    std::vector<float> selection = FractionalKnapsack(items, capacity);

    // Print the result
    for(int i = 0; i < selection.size(); i++)
        std::cout << items[i].id << " = " << selection[i] << std::endl;
}
