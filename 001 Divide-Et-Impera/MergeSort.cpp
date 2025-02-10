/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

As per the Cormen book "Introduction to Algorithms", pseudocode arrays start at 1
----------------------------------------------------------------------------------

MergeSort(A, p, r)
    
if(p < r)
    q = floor((p + r) / 2)
    MergeSort(A, p, q)
    MergeSort(A, q+1, r)
    Merge(A, p, q, r)



Merge(A, p, q, r)

    n1 = q-p+1
    n2 = r-q

    L[1...n1 +1]        // +1 is for the sentries
    R[1...n2 +1]

    for i = 1 to n1
        L[i] = A[p+i-1]

    for j = 1 to n2
        R[j] = A[q+j]

    L[n1+1] = oo
    R[n2+1] = oo

    i = 1
    j = 1

    for(k = p to r)
        if(L[i] <= R[j])
            A[k] = L[i]
            i++
        else
            A[k] = R[j]
            j++

----------------------
    TIME COMPLEXITY
----------------------

Recurrence Relation:

Θ(n) =  {   c               if  n = 1
        {   2T(n/2) + cn        n > 1


Θ(n logn)    (Input-form independent)
(log is in base 2)

*/

#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

// Forward declaration
void Merge(std::vector<int>& a, int p, int q, int r);


void MergeSort(std::vector<int>& a, int p, int r)
{
    // Base case
    if(p < r)
    {
        // Divide
        int q = ((p+r) / 2);

        // Impera
        MergeSort(a, p, q);
        MergeSort(a, q+1, r);
        
        // Combine
        Merge(a, p, q, r);
    }
}

void Merge(std::vector<int>& a, int p, int q, int r)
{
    // Define sizes
    int sizeL = q-p+1;
    int sizeR = r-q;

    // Define sub arrays
    std::vector<int> L;
    std::vector<int> R;

    // Fill sub arrays
    for(int i = 0; i < sizeL; i++)
        L.push_back(a[p+i]);

    for(int j = 0; j < sizeR; j++)
        R.push_back(a[q+1 +j]);

    // Add sentries
    L.push_back(std::numeric_limits<int>::max());
    R.push_back(std::numeric_limits<int>::max());

    // Index to scan the sub arrays
    int i = 0;
    int j = 0;

    // Merge cycle
    for(int k = p; k <= r; k++)
    {
        if(L[i] <= R[j])
        {
            // Select left element
            a[k] = L[i];
            i++;
        }
        else
        {
            // Select right element
            a[k] = R[j];
            j++;
        }
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
    MergeSort(a, 0, n-1);

    // Print sorted array
    for(int i = 0; i < n; i++)
        std::cout << a[i] << " ";

    return 0;
}
