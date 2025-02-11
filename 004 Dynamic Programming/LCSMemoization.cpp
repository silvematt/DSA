/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

As per the Cormen book "Introduction to Algorithms", pseudocode arrays start at 1

LCSInit(int m, int n)
for i = 0 to m
    for j = 0 to n
        c[i][j] = -1



LCSMem(X, Y, i, j)

if(c[i][j] != -1)
    return c[i][j]

if(i == 0 || j == 0)
    c[i][j] = 0
else
    if(X[i] == Y[j])
        c[i][j] = LCSMem(X, Y, i-1, j-1)+1;
    else if(LCSMem(X, Y, i-1, j) >= LCSMem(X, Y, i, j-1))
        c[i][j] = LCSMem(X, Y, i-1, j);
    else
        c[i][j] = LCSMem(X, Y, i, j-1);

return c[i][j]

----------------------
    RECURRENCE
----------------------

            {   0                            if i or j = 0
c[i][j] =   {   c[i-1][j-1]+1                   X(i) == Y(j)
            {   max(c[i][j-1], c[i-1][j])       otherwise

----------------------
    TIME COMPLEXITY
----------------------
T(n):     Θ(m*n)


----------------------------------------------------------------------------------
*/


#include <iostream>
#include <vector>
#include <string>

const int MAX_ROWS = 1000;
const int MAX_COLS = 1000;

std::vector<std::vector<int>> c(MAX_ROWS, std::vector<int>(MAX_COLS, -1));

int LCSMem(const std::string& X, const std::string& Y, int i, int j)
{
    // Already-there solution
    if(c[i][j] != -1)
        return c[i][j];

    // Base case
    if(i == 0 || j == 0)
        c[i][j] = 0;
    else // Calculate c[i][j] using previous solutions
    {
        if(X[i-1] == Y[j-1])
            c[i][j] = LCSMem(X, Y, i-1, j-1) + 1;
        else if(LCSMem(X, Y, i-1, j) >= LCSMem(X, Y, i, j-1))
            c[i][j] = LCSMem(X, Y, i-1, j);
        else
            c[i][j] = LCSMem(X, Y, i, j-1);
    }

    return c[i][j];
}


int main()
{
    std::string X("MATTIA");
    std::string Y("MARTINA");

    std::cout << "LCS of '" << X << "' and '" << Y << "' is: " << LCSMem(X, Y, X.length(), Y.length()) << std::endl;
}
