/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

As per the Cormen book "Introduction to Algorithms", pseudocode arrays start at 1
----------------------------------------------------------------------------------

RandomizedQuickSort(A, p, r)

if(p < r)
    q = RandomizedPartition(A, p, r)
    RandomizedQuickSort(A, p, q-1)
    RandomizedQuickSort(A, q+1, r)



int RandomizedPartition(A, p, r)
    i = rand(p, r)
    swap(A[i], A[r])
    return Partition(A, p, r)



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

HOWEVER, for the RandomizedQuickSort, we have an expected T(n) = Θ(n logn), because due to the nature of the random pivot selection, it's extremely unlikely that the worse possible pivot will be selected for every iteration.
This can be demonstrated using the concept of E(x) (expected value)
*/

#include <iostream>
#include <vector>
#include <utility>
#include <ctime>
#include <cstdlib>

// Forward declaration
int Partition(std::vector<int>& a, int p, int r);
int RandomizedPartition(std::vector<int>& a, int p, int r);

void RandomizedQuickSort(std::vector<int>& a, int p, int r)
{
    // Base case
    if(p < r)
    {
        // Divide
        int q = RandomizedPartition(a, p, r);

        // Impera
        RandomizedQuickSort(a, p, q-1);
        RandomizedQuickSort(a, q+1, r);

        // Combine is implicit
    }
}

int RandomizedPartition(std::vector<int>& a, int p, int r)
{
    // Select a random element and swap it with the element at the position r before calling Partition
    int i = p + rand() % (r+1 - p);
    std::swap(a[i], a[r]);
    return Partition(a, p, r);
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
    srand(time(NULL));

    // Define structures
    std::vector<int> a = {53, 21, 4, 2, 104, 20, 5, 18};
    int n = a.size();

    // Print array
    for(int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    // Sort
    RandomizedQuickSort(a, 0, n-1);

    // Print sorted array
    for(int i = 0; i < n; i++)
        std::cout << a[i] << " ";

    return 0;
}
