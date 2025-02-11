/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

As per the Cormen book "Introduction to Algorithms", pseudocode arrays start at 1

LevInit()
for i = 0 to m
    for j = 0 to n
        c[i][j] = -1 

LevMem(X, Y, i, j)

// Already there case 
if (c[i][j] != -1)
    return c[i][j]

// Base cases
if (j == 0)
    c[i][j] = i
    return c[i][j]

if (i == 0)
     c[i][j] = j
     return c[i][j]

// Compute

delta = (X[i] == Y[j]) ? 0 : 1
            
c[i][j] = min(LevMem(X,Y, i-1, j)+1, LevMem(X,Y, i, j-1)+1, LevMem(X,Y, i-1, j-1)+delta)

return c[i][j];

----------------------
    RECURRENCE
----------------------

            {   i                                                                           if j = 0
c[i][j] =   {   j                                                                           i = 0
            {   min(c[i][j-1]+1, c[i-1][j]+1, c[i-1][j-1] + δ(X[i], Y[j]))                  otherwise

                Where   δ(X[i], Y[j]) = 0, IF X[i] == Y[j]
                        δ(X[i], Y[j]) = 1, otherwise
----------------------
    TIME COMPLEXITY
----------------------
T(n):     Θ(m*n)
*/
#include <iostream>
#include <string>
#include <vector>

// We can (and should, in a real application) use an Init function with m and n passed as parameters to allocate only the strictly needed size for c instead of using the oversized matrix 
// This is just for simplification and to keep the focus on the algorithm
const int MAX_ROWS = 1000;
const int MAX_COLS = 1000;

std::vector<std::vector<int>> c(MAX_ROWS, std::vector<int>(MAX_COLS, -1));

int LevDistMem(const std::string& X, const std::string& Y, int i, int j)
{
    // Already computed case
    if(c[i][j] != -1)
        return c[i][j];

    // Base cases
    if(j == 0)
    {
        c[i][j] = i;
        return c[i][j];
    }

    if(i == 0)
    {
        c[i][j] = j;
        return c[i][j];
    }

    int delta = (X[i-1] == Y[j-1]) ? 0 : 1;

    c[i][j] = std::min(std::min(LevDistMem(X,Y,i-1,j)+1, LevDistMem(X,Y,i,j-1)+1), LevDistMem(X,Y,i-1,j-1)+delta);

    return c[i][j];
}

int main()
{
    std::string X("MATTIA");
    std::string Y("MARTINA");

    std::cout << "Levenshtein distance of '" << X << "' and '" << Y << "' is: " << LevDistMem(X, Y, X.length(), Y.length()) << std::endl;
}
