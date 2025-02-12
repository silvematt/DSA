/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

As per the Cormen book "Introduction to Algorithms", pseudocode arrays start at 1

KnapsackInit()
for i = 0 to n
    for j = 0 to W
        c[i][j] = -1 // -1 means not calculated

Knapsack_01Mem(v, w, i, j)

if(c[i][j] != -1)
    return c[i][j]

if(i == 0)
    c[i][j] = 0
    return c[i][j]

if(j == 0)
    c[i][j] = 0
    return c[i][j]

if (w[i] <= j)
    c[i][j] = max(Knapsack_01Mem(W, v, w, i-1, j), Knapsack_01Mem(W, v, w, i-1, j-w[i]) + v[i])
else
    c[i][j] = Knapsack_01Mem(W, v, w, i-1, j)

return c[i][j]


----------------------
    RECURRENCE
----------------------

            {   0                                           if  i = 0 || j = 0
c[i][w] =   {   max(c[i-1][w], c[i-1][W-wi] + vi)           wi <= W
            {   c[i-1][w]                                   otherwise

                
----------------------
    TIME COMPLEXITY
----------------------
T(n):     Θ(n*W)
*/
#include <iostream>
#include <vector>

const int MAX_ROWS = 1000;
const int MAX_COLS = 1000;

std::vector<std::vector<int>> c(MAX_ROWS, std::vector<int>(MAX_COLS, -1));

int Knapsack01Mem(const std::vector<int>& v, const std::vector<int>& w, int i, int j)
{
    // Already there case
    if(c[i][j] != -1)
        return c[i][j];

    // Base cases
    if(i == 0)
    {
        c[i][j] = 0;
        return c[i][j];
    }

    if(j == 0)
    {
        c[i][j] = 0;
        return c[i][j];
    }

    if(w[i-1] <= j) // When we access the w and v vectors, we have to account for the extra row and col
        c[i][j] = std::max(Knapsack01Mem(v, w, i-1, j), Knapsack01Mem(v, w, i-1, j-w[i-1]) + v[i-1]);
    else
        c[i][j] = Knapsack01Mem(v, w, i-1, j);

    return c[i][j];
}

int main()
{
    std::vector<int> v = {4, 6, 11, 7, 3, 2};
    std::vector<int> w = {1, 2, 7, 2, 2, 3};
    int W = 8;

    std::cout << "With a knapsack of size: '" << W << "', given the items [value, weight]: " << std::endl;
    for(int i = 0; i < v.size(); i++)
        std::cout << "[" << v[i] << ", " << w[i] << "]" << std::endl;

    std::cout << "Max value possible is: " << Knapsack01Mem(v, w, v.size(), W) << std::endl;
}
