/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

As per the Cormen book "Introduction to Algorithms", pseudocode arrays start at 1

BucketSort(A)

n = a.size
B[0...n-1] // is the buckets array

for(i = 0 to n-1)
    B[i] is an empty array list of numbers

for (i = 1 to n)
    Insert element A[i] in B[A[i] / maxValue * n]

for (i = 0 to n-1)
    InsertionSort(B[i])

Combine the lists B[0], ..., B[n-1] to have the sorted array

----------------------
    TIME COMPLEXITY
----------------------
Max: O(1)
ExtractMax:         O(log n)
IncreasePriority:   O(log n)
Insert:             O(log n)
----------------------------------------------------------------------------------
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

        // Select the index of the "current hand" (the sorted portion) to make comparisons
        int i = j-1;

        // Find (and make) the correct spot for the 'key' element
        while(i >= 0 && a[i] > key)
        {
            a[i+1] = a[i];
            i--;
        }

        // Place the key in the right spot
        a[i+1] = key;
    }
}

void BucketSort(std::vector<int>& a, int maxValue)
{
    std::vector<std::vector<int>> buckets;

    // Create n buckets
    for(int i = 0; i < a.size(); i++)
        buckets.push_back(std::vector<int>());

    // Fill the buckets
    for(int i = 0; i < buckets.size(); i++)
        buckets[(a[i] * (a.size()-1)) / maxValue].push_back(a[i]);

    // Sort the buckets
    for(int i = 0; i < a.size(); i++)
        InsertionSort(buckets[i], buckets[i].size());

    // Combine
    int k = 0;
    for(int i = 0; i < buckets.size(); i++)
        for(int j = 0; j < buckets[i].size(); j++)
            a[k++] = buckets[i][j];
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
    BucketSort(a, 104);

    // Print sorted array
    for(int i = 0; i < n; i++)
        std::cout << a[i] << " ";

    return 0;
}
