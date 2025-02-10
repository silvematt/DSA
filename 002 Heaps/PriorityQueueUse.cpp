#include <iostream>
#include "PriorityQueue.h"

void PrintQueue(std::vector<int>& a, int n)
{
    // Print queue
    std::cout << "Priority Queue: " << std::endl;

    for(int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

int main()
{
    // Define structures
    std::vector<int> a = {53, 21, 4, 2, 104, 20, 5, 18};
    
    std::cout << "Original Array: " << std::endl;
    // Print array
    for(int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl << std::endl;

    PriorityQueue p = PriorityQueue(a);

    // p.el(ements) and 'a' are the same, so we can use 'a' directly

    // Print queue
    PrintQueue(a, p.HeapSize());

    std::cout << "Extracting max..." << std::endl;
    p.ExtractMax();

    PrintQueue(a, p.HeapSize());

    std::cout << "Inserting value '50'..." << std::endl;
    p.Insert(50);

    PrintQueue(a, p.HeapSize());

    std::cout << "Increase value of element at index 3 to be '49'..." << std::endl;
    p.IncreasePriority(3, 49);

    PrintQueue(a, p.HeapSize());

    return 0;
}
