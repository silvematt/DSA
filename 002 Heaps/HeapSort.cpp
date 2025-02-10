/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

As per the Cormen book "Introduction to Algorithms", pseudocode arrays start at 1

HeapSort(A)

BuildMaxHeap(A)

for i = A.size down to 2
    Swap(A[1], A[i])
    A.heapsize--
    MaxHeapify(A, 1)


----------------------
    TIME COMPLEXITY
----------------------
MaxHeapify:     Θ(log n)
BuildMaxHeap:   O(n)
HeapsSort:      Θ(n log n)

----------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <utility>

#include "Heap.h"

// Time Complexity: Θ(n logn)
void HeapSort(std::vector<int>& a)
{
    Heap h = Heap(a);
    
    // h.el(ements) and 'a' are the same, so we can use 'a' directly
    for(int i = a.size()-1; i >= 0; i--)
    {
        std::swap(a[0], a[i]);
        h.DecreaseHeapSize();
        h.MaxHeapify(0);
    }
}

int main()
{
    // Define structures
    std::vector<int> a = {53, 21, 4, 2, 104, 20, 5, 18};
    int n = a.size();

    // Print array
    for(int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    // Sort
    HeapSort(a);

    // Print sorted array
    for(int i = 0; i < n; i++)
        std::cout << a[i] << " ";

    return 0;
}
