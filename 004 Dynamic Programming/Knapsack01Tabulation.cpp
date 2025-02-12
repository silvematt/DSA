/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

As per the Cormen book "Introduction to Algorithms", pseudocode arrays start at 1

Knapsack_01(W, v, w, n)

for i = 0 to n
    c[i][0] = 0

for j = 1 to W
    c[0][j] = 0

for i = 1 to n
    for j = 1 to W
        if(w[i] <= j)
            c[i][j] = max(c[i-1][j], c[i-1][j-w[i]] + v[i])
        else
            c[i][j] = c[i-1][j]

return c[n][W]


----------------------
    RECURRENCE
----------------------

            {   0                                           if  i = 0 || j = 0
c[i][w] =   {   max(c[i-1][w], c[i-1][W-wi] + vi)           wi <= W
            {   c[i-1][w]                                   otherwise

                
----------------------
    TIME COMPLEXITY
----------------------
T(n):     Θ(n*w)
*/
#include <iostream>
#include <vector>

int Knapsack01(int W, const std::vector<int>& v, const std::vector<int>& w, int n)
{
    std::vector<std::vector<int>> c(n+1, std::vector<int>(W+1));

    // Base cases
    for(int i = 0; i <= n; i++)
        c[i][0] = 0;

    for (int j = 0; j <= W; j++)
        c[0][j] = 0;

    // Compute table
    for(int i = 1; i <= n; i++) // for every item
        for(int j = 1; j <= W; j++) // for every weight value
        {
            if(w[i-1] <= j) // When we access the w and v vectors, we have to account for the extra row and col
                c[i][j] = std::max(c[i-1][j], c[i-1][j-w[i-1]] + v[i-1]);
            else
                c[i][j] = c[i-1][j];
        }

    return c[n][W];
} 

int main()
{
    std::vector<int> v = {4, 6, 11, 7, 3, 2};
    std::vector<int> w = {1, 2, 7, 2, 2, 3};
    int W = 8;

    std::cout << "With a knapsack of size: '" << W << "', given the items [value, weight]: " << std::endl;
    for(int i = 0; i < v.size(); i++)
        std::cout << "[" << v[i] << ", " << w[i] << "]" << std::endl;

    std::cout << "Max value possible is: " << Knapsack01(W, v, w, v.size()) << std::endl;
}
