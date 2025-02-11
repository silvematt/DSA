/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

As per the Cormen book "Introduction to Algorithms", pseudocode arrays start at 1


LevDistance(X, m, Y, n)

Make c[0...m][0...n] // 0 is for the extra row and col

for i = 0 to m
    c[i][0] = i

for j = 0 to n
    c[0][j] = j

for i = 1 to m
    for j = 1 to n
        delta = (X[i] == X[j]) ? 0 : 1
        c[i][j] = min(c[i][j-1]+1, c[i-1][j]+1, c[i-1][j-1] + δ(X[i], Y[j])

return c[m][n]
            

----------------------
    RECURRENCE
----------------------

            {   i                                                                           if j = 0
c[i][j] =   {   j                                                                           i = 0
            {   min(c[i][j-1]+1, c[i-1][j]+1, c[i-1][j-1] + δ(X[i], Y[j]))                  otherwise

                Where   δ(X[i], Y[j]) = 1, IF X[i] == Y[j]
                        δ(X[i], Y[j]) = 0, otherwise
----------------------
    TIME COMPLEXITY
----------------------
T(n):     Θ(m*n)


----------------------------------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <string>

int LevDistTab(const std::string& X, int m, const std::string& Y, int n)
{
    // 2D vector for distance
    std::vector<std::vector<int>> c(m+1, std::vector<int>(n+1));

    // Base cases
    for(int i = 0; i <= m; i++)
        c[i][0] = i;

    for(int j = 0; j <= n; j++)
        c[0][j] = j;


    // Compute c[i][j] bearing in mind we have an extra col and row
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            int delta = (X[i-1] == Y[j-1]) ? 0 : 1;     // X[i-1] Y[j-1] is used to compensate for the extra col and row

            c[i][j] = std::min(std::min(c[i-1][j] + 1, c[i][j-1] + 1), c[i-1][j-1] + delta);
        }
    
    return c[m][n];
}

int main()
{
    std::string X("MATTIA");
    std::string Y("MARTINA");

    std::cout << "Levenshtein distance of '" << X << "' and '" << Y << "' is: " << LevDistTab(X, X.length(), Y, Y.length()) << std::endl;
}
