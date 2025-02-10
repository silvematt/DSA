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

        std::swap(el[0], el[heapSize-1]);
        el.erase(el.begin() + heapSize-1);
        heapSize--;
        MaxHeapify(0);

        return max;
    }

    // Time Complexity: O(log n)
    void IncreasePriority(int i, int k)
    {
        if(k <= el[i])
            return;

        el[i] = k;

        while(i > 0 && el[i] > el[ParentIndx(i)])
        {
            std::swap(el[i], el[ParentIndx(i)]);
            i = ParentIndx(i);
        }
    }

    // Time Complexity: O(log n)
    void Insert(int k)
    {
        heapSize++;
        el.push_back(std::numeric_limits<int>::min());
        IncreasePriority(heapSize-1, k);
    }

};
