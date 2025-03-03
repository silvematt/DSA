/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

As per the Cormen book "Introduction to Algorithms", pseudocode arrays start at 1

ActivitySelector(a)

Sort(a); // sort a by finish time, ascending, so that the first finish time is the first element in the array

n = a.size();

A = {a[1]}
k = 1

for j = 2 to n
    if(a[k].finishTime <= a[j].startTime)
        k = j
        A = A U {a[j]}


return A

----------------------
    TIME COMPLEXITY
----------------------
T(n):     O(n logn)
*/
#include <iostream>
#include <vector>

struct Activity
{
    char id;
    int start;
    int end;

    Activity(char id, int s, int e) : id(id), start(s), end(e) {}
};

std::vector<Activity> GreedyActivitySelection(const std::vector<Activity>& a)
{
    std::vector<Activity> o = {};

    // Empty case
    if(a.size() < 1)
        return std::move(o);

    o.push_back(a[0]);  // insert first activity
    int k = 0;

    // Check for activies compatibile with the current element, greedy choice
    for(int m = 1; m < a.size(); m++)
    {
        if(a[m].start >= o[k].end)
        {
            o.push_back(a[m]);
            k = m;
        }
    }

    return std::move(o);
}

// Sorts activities by end time
void InsertionSort(std::vector<Activity>& a, int n)
{
    // First element is already sorted
    for(int j = 1; j < n; j++)
    {
        // Select the current element
        Activity key = a[j];

        // Select the index of the "current hand" (the sorted portion) to make comparisons
        int i = j-1;

        // Find (and make) the correct spot for the 'key' element
        while(i >= 0 && a[i].end > key.end)
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
    std::vector<Activity> a = {Activity('A', 1, 3), Activity('B', 5, 6), Activity('C', 7, 10), Activity('D', 6, 7)};

    // Sort by end time
    InsertionSort(a, a.size());

    // Compute the selection
    std::vector<Activity> selection = GreedyActivitySelection(a);

    // Print the result
    for(int i = 0; i < selection.size(); i++)
    {
        std::cout << selection[i].id << " -> ";
    }

    std::cout << "END" << std::endl;
}
