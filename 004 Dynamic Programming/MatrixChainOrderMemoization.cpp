/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

As per the Cormen book "Introduction to Algorithms", pseudocode arrays start at 1

RMCInit()

c[n+1][n+1]
for i = 0 to n
    for j = 0 to n
        c[i][j] = -1


RMCMem(p, i, j)

if(c[i][j] != -1)
    return c[i][j]

if(i == j)
    c[i][j] = 0
    return c[i][j]

c[i][j] = oo

for k = i to j-1
    q = RMCMem(p, i, k) + RMCMem(p, k+1, j) + (p[i-1]*p[k]*p[j])
    if(q < c[i][j])
        c[i][j] = q


return c[i][j]
            

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
#include<limits>

const int MAX_ROWS = 1000;
const int MAX_COLS = 1000;
std::vector<std::vector<long long>> c(MAX_ROWS, std::vector<long long>(MAX_COLS, -1));

long long RMC(const std::vector<int>& p, int i, int j)
{
    // Already there case
    if(c[i][j] != -1)
        return c[i][j];

    // Base case
    if(i == j)
    {
        c[i][j] = 0;
        return c[i][j];
    }

    // Compute c[i][j]
    c[i][j] = std::numeric_limits<int>::max();

    for(int k = i; k < j; k++)
    {
        long long q = RMC(p, i, k) + RMC(p, k+1, j) + (p[i-1]*p[k]*p[j]); // the indexes of the multiplication needs to consider the chain 

        // Update for the optimal value of k
        if(q < c[i][j])
            c[i][j] = q;
    }

    return c[i][j];
}

int main()
{
    std::vector<int> p = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200};

    std::cout << RMC(p, 1, p.size()-1) << std::endl;
}
