/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

As per the Cormen book "Introduction to Algorithms", pseudocode arrays start at 1


MCTab(p)

n = p.size()-1 // number of matrices

// c[i][j] will hold the minimum number of multiplications needed to multiply matrices A_i...A_j.
c[1...n][1...n]

// s[i][j] will store the index k that achieved the optimal split.
s[1...n][1...n]

for i = 1 to n
    c[i][i] = 0

// The key point is that we have to consider the chain length that gets progressively bigger
for l = 2 to n
    for i = 1 to n-l+1      // Select the starting index i for the chain.
        j = i+l-1           // j is the end index of the current chain
        c[i][j] = oo


        // Try for every split value
        for(k = i to j-1)
            q = c[i][k] + c[k+1][j] + (p[i-1]*p[k]*p[j])
            if(q < c[i][j])
                c[i][j] = q
                s[i][j] = k

return c and s // cost and split value (k) tables

----------------------
    RECURRENCE
----------------------

            {   0                                                           i == j
c[i][j] =   {   min        (c[i][k] + c[k+1][j] + (p[i-1]*p[k]*p[j]) )      otherwise
                for i<=k<j                                                                           

----------------------
    TIME COMPLEXITY
----------------------
T(n):     O(n^3)


----------------------------------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <limits>

long long MCTab(std::vector<int>& p)
{
    int n = p.size()-1; // number of matrices

    // Define the matrices
    std::vector<std::vector<long long>> c(n+1, std::vector<long long>(n+1, 0));
    std::vector<std::vector<long long>> s(n+1, std::vector<long long>(n+1, 0));

    // Base case
    for(int i = 0; i < n; i++)
        c[i][i] = 0;

    // Consider the chain the gets progressively longer
    for(int l = 2; l <= n; l++)
        for(int i = 1; i <= n-l+1; i++) // first element of the chain
        {
            int j = i+l-1;  // last element of the chain

            c[i][j] = std::numeric_limits<int>::max();
            
            // Try for every split value 
            for(int k = i; k < j; k++)
            {
                int q = c[i][k] + c[k+1][j] + (p[i-1]*p[k]*p[j]);
                
                // Save the best solution and the split value that brought to that
                if(q < c[i][j])
                {
                    c[i][j] = q;
                    s[i][j] = k;
                }
            }
        }

    return c[1][n];
}

int main()
{
    std::vector<int> p = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200};

    std::cout << MCTab(p) << std::endl;
}
