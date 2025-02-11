/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

As per the Cormen book "Introduction to Algorithms", pseudocode arrays start at 1


LCS(X, m, Y, n)

create C[0...m][0...n] // 0 is the extra row and col to account for the base case

for i = 0 to m
    c[i][0] = 0

for j = 1 to n      // c[0][0] is already 0 so j starts at 1
    c[0][j] = 0

for i = 1 to m
    for j = 1 to n
        if(X[i] == Y[j])
            c[i][j] = c[i-1][j-1]+1
        else
            c[i][j] = max(c[i][j-1], c[i-1][j])

return c[m][n]


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
#include <iostream>
#include <vector>
#include <string>

int LCSTab(const std::string& X, int sX, const std::string& Y, int sY)
{
    // 2D vector for LCS
    std::vector<std::vector<int>> c(sX+1, std::vector<int>(sY+1));

    // Base cases, i or j = 0
    for(int i = 0; i <= sX; i++)
        c[i][0] = 0;

    for(int j = 1; j <= sY; j++)
        c[0][j] = 0;

    // Compute the LCS bearing in mind we have an extra col and row of 0s
    for(int i = 1; i <= sX; i++)
        for(int j = 1; j <= sY; j++)
        {
            if(X[i-1] == Y[j-1])            // Account for the extra row and col
                c[i][j] = c[i-1][j-1] + 1;
            else if(c[i-1][j] >= c[i][j-1])
                c[i][j] = c[i-1][j];
            else
                c[i][j] = c[i][j-1];
        }
    
    return c[sX][sY];
}

int LCSTabWithPath(const std::string& X, int sX, const std::string& Y, int sY)
{
    // 2D vector for LCS, extra row and col is for the base case
    std::vector<std::vector<int>> c(sX+1, std::vector<int>(sY+1));

    // 2D vector for path
    std::vector<std::vector<char>> p(sX+1, std::vector<char>(sY+1, ' '));

    // Base cases, i or j = 0
    for(int i = 0; i <= sX; i++)
        c[i][0] = 0;

    for(int j = 1; j <= sY; j++)
        c[0][j] = 0;

    // Compute the LCS bearing in mind we have an extra col and row of 0s
    for(int i = 1; i <= sX; i++)
        for(int j = 1; j <= sY; j++)
        {
            if(X[i-1] == Y[j-1])            // Account for the extra row and col
            {
                c[i][j] = c[i-1][j-1] + 1;
                p[i][j] = '\\';
            }
            else if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                p[i][j] = '|';
            }
            else
            {
                c[i][j] = c[i][j-1];
                p[i][j] = '-';
            }
        }
    
    return c[sX][sY];
}

int main()
{
    std::string X("MATTIA");
    std::string Y("MARTINA");

    std::cout << "LCS of '" << X << "' and '" << Y << "' is: " << LCSTab(X, X.length(), Y, Y.length()) << std::endl;
}
