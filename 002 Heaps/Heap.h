/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

As per the Cormen book "Introduction to Algorithms", pseudocode arrays start at 1

MaxHeapify(A, i)

l = Left(i)
r = Right(i)

max = i;

if(l <= A.heapsize && A[max] < A[l])
    max = l;

if(r <= A.heapsize && A[max] < A[r])
    max = r;

if(max != i)
    Swap(A[i], A[max])
    MaxHeapify(A, max)



BuildMaxHeap(A)

A.heapsize = A.size;
for i = A.size/2 down to 1  // All the nodes from A.size/2 going back are internal nodes, while after A.size/2 we have leaves (which are already valid heaps)
    MaxHeapify(A, i)



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

class Heap
{
public:
    Heap(std::vector<int>& elements) : el(elements), heapSize(el.size()) 
    {
        BuildMaxHeap();
    }

protected:
    std::vector<int>& el;
    int heapSize;

    // Time complexity O(n)
    void BuildMaxHeap()
    {
        heapSize = el.size();

        for(int i = el.size() / 2; i >= 0; i--)
            MaxHeapify(i);
    }

public:

    // Time complexity Θ(log n)
    void MaxHeapify(int i)
    {
        // Indexes
        int l = LeftIndx(i);
        int r = RightIndx(i);
        
        // Current max index
        int max = i;

        // Check left child
        if(l < heapSize && el[max] < el[l])
            max = l;
        
        // Check right child
        if(r < heapSize && el[max] < el[r])
            max = r;

        // If there was a child with a bigger value
        if(max != i)
        {
            std::swap(el[i], el[max]);
            MaxHeapify(max);
        }
    }

    int ParentIndx(int i)  
    {
        return (i-1) / 2;
    }

    int LeftIndx(int i)
    {
        return (2*i) + 1;
    }

    int RightIndx(int i)
    {
        return (2*i) + 2;
    }

    int Size()
    {
        return el.size();
    }

    int HeapSize()
    {
        return heapSize;
    }

    void DecreaseHeapSize()
    {
        heapSize--;
    }
};
