/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

As per the Cormen book "Introduction to Algorithms", pseudocode arrays start at 1
----------------------------------------------------------------------------------

InsertionSort(A)

for j = 2 to A.lenght
    key = A[j]
    i = j-1

    while(i > 0 && A[i] > key)
        A[i+1] = A[i]
        i--

    A[i+1] = key;

*/

#include <iostream>
#include <vector>

void InsertionSort(std::vector<int>& a, int n)
{
    // First element is already sorted
    for(int j = 1; j < n; j++)
    {
        // Select the current element
        int key = a[j];

        // Select the index of the "current hand" to make comparison
        int i = j-1;

        // Find (and make) the spot for the 'key' element
        while(i >= 0 && a[i] > key)
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
    // Define structures
    std::vector<int> a = {53, 21, 4, 2, 104, 20, 5, 18};
    int n = a.size();

    // Print array
    for(int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    // Sort
    InsertionSort(a, n);

    // Print sorted array
    for(int i = 0; i < n; i++)
        std::cout << a[i] << " ";

    return 0;
}
