/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

As per the Cormen book "Introduction to Algorithms", pseudocode arrays start at 1

Priority Queue implemented are implemented as an extension of a MaxHeap

Max(A)
return A[1]



ExtractMax(A)

if(A.heapsize < 1)
    error()

max = A[1]
swap(A[1], A[A.heapsize])
A.heapsize--;
MaxHeapify(A, 1)

return max




IncreasePriority(A, i, k)

if(A[i] > k)
    error()

A[i] = k

while(i > 1 && A[Parent(i)] < A[i])
    swap(A[i], A[Parent(i)])
    i = Parent(i)




Insert(A, k)

A.heapsize++
A[A.heapsize] = -oo
IncreasePriority(A, A.heapsize, k)


----------------------
    TIME COMPLEXITY
----------------------
Max: O(1)
ExtractMax:         O(log n)
IncreasePriority:   O(log n)
Insert:             O(log n)
----------------------------------------------------------------------------------
*/

#include "Heap.h"
#include <limits>

class PriorityQueue : public Heap
{
public:
    PriorityQueue(std::vector<int>& elements) : Heap(elements) {}

    // Time Complexity: O(1)
    int Max()
    {
        return el[0];
    }

    // Time Complexity: O(log n)
    int ExtractMax()
    {
        int max = el[0];

        // Swap the last element with the first
        std::swap(el[0], el[heapSize-1]);

        // Extract the last element
        el.erase(el.begin() + heapSize-1);
        heapSize--;

        // Make sure the max-heap property is respected after  the swap 
        MaxHeapify(0);

        return max;
    }

    // Time Complexity: O(log n)
    void IncreasePriority(int i, int k)
    {
        // If the new priority is lesser than the new 'k', it's an error
        if(k <= el[i])
            return;

        // Set the new priority
        el[i] = k;

        // "Bubble up" the new priority until the right spot is found
        while(i > 0 && el[i] > el[ParentIndx(i)])
        {
            std::swap(el[i], el[ParentIndx(i)]);
            i = ParentIndx(i);
        }
    }

    // Time Complexity: O(log n)
    void Insert(int k)
    {
        // Add a new element and set it to be the lowest possible value
        heapSize++;
        el.push_back(std::numeric_limits<int>::min());

        // Then increase its priority by bubbling it up
        IncreasePriority(heapSize-1, k);
    }

};
