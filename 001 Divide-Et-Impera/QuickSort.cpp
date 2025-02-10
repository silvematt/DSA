/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

As per the Cormen book "Introduction to Algorithms", pseudocode arrays start at 1
----------------------------------------------------------------------------------

QuickSort(A, p, r)

if(p < r)
    q = Partition(A, p, r)
    QuickSort(A, p, q-1)
    QuickSort(A, q+1, r)



int Partition(A, p, r)
    pivot = A[r]
    i = p-1

    for j = p to r-1
        if(A[j] <= pivot)
            i++
            Swap(A[i], A[j])

    Swap(A[i+1], A[r])
    return i+1

----------------------
    TIME COMPLEXITY
----------------------
Best case:      Θ(n logn)       (pivot is selected such that the two subarrays are almost even)
Average case:   Θ(n logn)       (pivot is selected such that even if the two subarrays are not very balanced (99 to 1), the depth of tree still grows logarithmically Θ(logn), and the cost of each level is Θ(n))
Worst case:     Θ(n^2)          (pivot is selected such it's always the biggest (or smallest) element, so one subarray will have size n-1 while the other will have size 0, so it doesn't divide the problem at all)

Recurrence Relation:
Θ(n) =  {   c                           if  n = 1
        {   T(q) + T(n-q-1) + cn        n > 1

            We have the worst case when q = 0 or q = n-1 (pivot is at the extremes)   ->   max(0 <= q < n-1) : T(q) + T(n-q-1) + cn
            And it result in: T(n-1) + cn = Θ(n^2)
                                                             
*/

#include <iostream>
#include <vector>
#include <utility>

// Forward declaration
int Partition(std::vector<int>& a, int p, int r);


void QuickSort(std::vector<int>& a, int p, int r)
{
    // Base case
    if(p < r)
    {
        // Divide
        int q = Partition(a, p, r);

        // Impera
        QuickSort(a, p, q-1);
        QuickSort(a, q+1, r);

        // Combine is implicit
    }
}

int Partition(std::vector<int>& a, int p, int r)
{
    // Select the pivot
    int pivot = a[r];

    // i is used to keep the length p...i of the left subarray, the one that has all the elements <= than the pivot
    int i = p-1;

    // Go through all the array
    for(int j = p; j < r; j++)
    {
        // If an element is <= than the pivot, then it must be located in the left subarray and the subarray size must increase
        if(a[j] <= pivot)
        {
            i++;
            std::swap(a[i], a[j]);
        }
    }

    // Move the pivot between the two subarrays (left one elements <= pivot, right one elements > pivot)
    std::swap(a[i+1], a[r]);
    return i+1;
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
    QuickSort(a, 0, n-1);

    // Print sorted array
    for(int i = 0; i < n; i++)
        std::cout << a[i] << " ";

    return 0;
}
